#include "log_in.h"
#include "ui_log_in.h"

log_in::log_in(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::log_in)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    setWindowTitle("客户端");
    tcpsocket=NULL;
    tcpsocket =new QTcpSocket(this);
    blockSize=0;
    ui->editpassword->setEchoMode(QLineEdit::Password);
    connect(tcpsocket,&QTcpSocket::connected,[=]()              //如果成功连接的服务器就会触发conneted函数
    {
        //QMessageBox::information(NULL, "提示信息", "成功连接至服务器，欢迎使用互助系统！");
    });
    connect(tcpsocket,&QTcpSocket::readyRead,[=]()
    {
        QString message;
        QDataStream in(tcpsocket);
        in.setVersion(QDataStream::Qt_4_6);
        //设置数据流版本，这里要和服务器端相同
        if(blockSize==0) //如果是刚开始接收数据
        {
        //判断接收的数据是否有两字节，也就是文件的大小信息
        //如果有则保存到blockSize变量中，没有则返回，继续接收数据
            if(tcpsocket->bytesAvailable() < (int)sizeof(int)) return;
            in >> blockSize;
        }
        if(tcpsocket->bytesAvailable() < blockSize) return;
        //如果没有得到全部的数据，则返回，继续接收数据
        in>>message;
        //ui->editread->append(message);
        //aaaaaaaa看下这里还有服务器端处理登陆注册的函数，是不是判断逻辑有问题
        if(message=="1"){QMessageBox::information(NULL, "提示信息", "用户名或密码错误！");}
        if(message=="2"){QMessageBox::information(NULL, "提示信息", "用户名与他人重复！");}
        if(message=="0"){

            QString ip=ui->editip->text();
            int port=ui->editport->text().toInt();            //aaaaa
            w.getip(ip);
            w.getport(port);
            QString usern=ui->editusername->text();
            QString pwd=ui->editpassword->text();
            w.getUser(usern,pwd);

            this->hide();
            w.show();
            this->close();
        }
        if(message=="3"){

            QString ip=ui->editip->text();
            int port=ui->editport->text().toInt();                 //aaaaa
            w.getip(ip);
            w.getport(port);
            QString usern=ui->editusername->text();
            QString pwd=ui->editpassword->text();
            w.getUser(usern,pwd);
            this->hide();
            //QMessageBox::information(NULL, "提示信息", "注册成功");
            w.show();
            this->close();
        }
        tcpsocket->disconnectFromHost();
        tcpsocket->close();
    });
}

log_in::~log_in()
{
    delete ui;
}


void log_in::on_btnlogin_clicked()        //登录按钮
{
    if(ui->editip->text().isEmpty()||ui->editport->text().isEmpty())           //aaaaa
    {
        QMessageBox::information(NULL, "提示信息", "请完善ip和端口信息");
        return;
    }
    QString head="login";
    head+="zcmwxkysjwh"+ui->editusername->text()+"zcmwxkysjwh"+ui->editpassword->text();
    SendToHost(head);
    QString ip=ui->editip->text();
    int port=ui->editport->text().toInt();
    w.getip(ip);
    w.getport(port);
    QString usern=ui->editusername->text();
    QString pwd=ui->editpassword->text();
    w.getUser(usern,pwd);
   //this->hide();
   //w.show();
   //this->close();
}


void log_in::on_btnregister_clicked()     //注册按钮
{
    if(ui->editip->text().isEmpty()||ui->editport->text().isEmpty())
    {
        QMessageBox::information(NULL, "提示信息", "请完善ip和端口信息");
        return;
    }
    QMessageBox::StandardButton rb = QMessageBox::question(NULL, "注册须知", "用户名格式为数字加字母 \n密码格式同上，大于8位小于16位 \n是否继续注册？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
    {
        if(ui->editusername->text().size()<=1||ui->editusername->text().size()>16||ui->editpassword->text().size()<8||ui->editpassword->text().size()>16)
        {
            QMessageBox::information(NULL, "提示信息", "用户名或密码不符合规格");
        }
        else
        {
            //QMessageBox::aboutQt(NULL, "About Qt");
            //实现和上面的login一样，先加上头部信息，然后把用户名，密码分次发送，中间加上换行符
            //服务器端收到消息后提取并判断
            QString head="register";
            head+="zcmwxkysjwh"+ui->editusername->text();
            head+="zcmwxkysjwh"+ui->editpassword->text();
            SendToHost(head);
        }

    }

    QString ip=ui->editip->text();           //aaaaa
    int port=ui->editport->text().toInt();
    QString usern=ui->editusername->text();
    QString pwd=ui->editpassword->text();
    w.getip(ip);
    w.getport(port);
    w.getUser(usern,pwd);
}

void log_in::SendToHost(QString message)//不要多次发送，将数据整合在一个QString字符串中，以某个标志符号隔开，一次性发送
{
    blockSize=0;
    QByteArray block;

    //使用数据流写入数据
    QDataStream out(&block,QIODevice::WriteOnly);

    //设置数据流的版本，客户端和服务器端使用的版本要相同
    out.setVersion(QDataStream::Qt_4_6);

    out<<(int) 0;
    out<<message;
    out.device()->seek(0);
    out<<(int) (block.size() - sizeof(int));
    tcpsocket->connectToHost(ui->editip->text(),ui->editport->text().toInt());            //aaaaa
    //tcpsocket->connectToHost("localhost",8888);//连接到服务器  假设服务器在本机8888端口
    tcpsocket->waitForConnected(1000);
    tcpsocket->write(block);
}
