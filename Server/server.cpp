#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    setWindowTitle("服务器");
    blockSize=0;
    tcpserver=new QTcpServer(this);
    tcpsocket=new QTcpSocket(this);
    tcpserver->listen(QHostAddress::Any,8888);
    connect(tcpserver,SIGNAL(newConnection()),this,SLOT(HandleMessage()));
    QString s=d_c.loadImage(2,3);
    QPixmap p=stringTopixmap(s);
    ui->label_3->setPixmap(p);
}

Server::~Server()
{
    delete ui;
}

void Server::handledelete(QStringList list)
{
    QString usern=list.at(1);
    d_c.deletemessage(usern);
}

void Server::handlep_image(QStringList lst)
{
    QString username=lst.at(1);
    QString image=lst.at(2);
    d_c.handlep_image(username,image);
    //ui->textEdit_requireshow->append(username);
    //ui->textEdit_requireshow->append(image);

}

void Server::handleupdate_nickname(QStringList lst)
{
    QString username=lst.at(1);
    QString nickname=lst.at(2);
    d_c.handlenickname(username,nickname);
}

void Server::handlemajor(QStringList lst)
{
    QString username=lst.at(1);
    QString major=lst.at(2);
    d_c.hanldemajor(username,major);
}

void Server::handlep_message(QStringList lst)
{
    QString username=lst.at(1);
    QString re=d_c.handle_p_message(username);
    SendToHost(re);
}

void Server::hanlep_m(QStringList lst)
{
    QString username=lst.at(1);
    QString re=d_c.handle_p_m(username);
    SendToHost(re);
}

void Server::handlelike(QStringList lst)
{
    QString username=lst.at(1);
    int number=lst.at(2).toInt();
    int class1=lst.at(3).toInt();
    d_c.handlelike(username,number,class1);
}

void Server::handlecomment(QStringList lst)
{
    QString username=lst.at(1);
    int number=lst.at(2).toInt();
    int class1=lst.at(3).toInt();
    QString message=lst.at(4);
    d_c.insertcomment(number,class1,username,username.length(),message,message.length());
}

void Server::HandleMessage()
{
    QString temp;
    message=temp;
    blockSize=0;
    tcpsocket=tcpserver->nextPendingConnection();//获取连接进来的套接字
    if(tcpsocket==NULL)return;
    ShowLink();//显示连接
    connect(tcpsocket,SIGNAL(readyRead()),this,SLOT(classfyMessage()));
}

void Server::classfyMessage()
{
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
    QStringList list=message.split("zcmwxkysjwh");
    QString head=list.at(0);   //三个QString分别保存不同信息  注意客户端发送过来的时候使一起发送过来的，到服务器端后把不同类型的信息提取出来
    //ui->textEdit_linkshow->append(message);
    if(head=="register")//如果是注册
    {
        HandleRegister(list);
    }
    if(head=="login"){//登录
        HandleLogin(list);

    }
    if(head=="password"){//更改密码
        handleupdatepassword(list);

    }
    if(head=="updatesex"){//更改性别
        handleupdatesex(list);

    }
    if(head=="personalinformation"){//查询个人信息
        handlepersonalinformation(list);

    }
    if(head=="browse"){//概览信息
        handdlebrowse(list);

    }
    if(head=="particular"){//详细信息
        handleparticular(list);

    }
    if(head=="relase"){//发布信息
        handleRelase(list);
    }
    if(head=="like"){
        handlelike(list);
    }
    if(head=="require"){    //用户发出的“被赞的、被收藏的”信息请求aaaaa
        handlexinxi(list);
    }
    if(head=="updateimage"){
        handlep_image(list);
    }
    if(head=="updatenickname"){
        handleupdate_nickname(list);
    }
    if(head=="updatemajor"){
        handlemajor(list);
    }
    if(head=="p_message"){
        handlep_message(list);
    }
    if(head=="p_m"){
        hanlep_m(list);
    }
    if(head=="comment"){
        handlecomment(list);
    }
    if(head=="delete"){

    }
    tcpsocket->disconnectFromHost();
    tcpsocket->close();
    tcpsocket=NULL;
    return;
}


void Server::handlexinxi(QStringList list)    //解决用户发出的“被赞的、被收藏的”信息请求aaaaa
{
    QString temp=list.at(1);
    QString res=d_c.searchxinxi(temp);
    SendToHost(res);
}

void Server::ShowRequire(QString array)//显示请求信息
{
   ui->textEdit_requireshow->append(array);
   ui->textEdit_requireshow->append(QString("%1").arg(array.length()));
}

void Server::HandleRegister(QStringList list)
{
    QString username=list.at(1);//用户名
    QString password=list.at(2);//密码

    int usernamelen=username.length();
    int passwordlen=password.length();
    int flag=d_c.handleregister(username,password,usernamelen,passwordlen);
    if(flag==0){
        QString str="2";
        SendToHost(str);
    }
    else{
        QString str="3";
        SendToHost(str);
    }
}

void Server::HandleLogin(QStringList list)
{
    QString username=list.at(1);//用户名
    QString password=list.at(2);//密码

    int flag=d_c.handlelogin(username,password);
    if(flag==1){
        QString str="0";
        SendToHost(str);
    }
    else{
        QString str="1";
        SendToHost(str);
    }
}

void Server::ShowLink()//显示连接信息
{
    QString ip=tcpsocket->peerAddress().toString();
    qint16 port=tcpsocket->peerPort();
    QString temp=QString("[%1:%2]:成功连接！").arg(ip).arg(port);
    ui->textEdit_linkshow->append(temp);
}

QPixmap Server::stringTopixmap( const QString& pic )//

{
  QByteArray byte_array = QByteArray::fromBase64(pic.toLocal8Bit());
  QPixmap pix;
  QDataStream data_stream(&byte_array,QIODevice::ReadOnly);
  data_stream>>pix;
  return pix;

}

void Server::handleupdatepassword(QStringList list)
{

    QString username=list.at(1);//用户名
    QString password_new=list.at(2);//密码
    int passwordlen=password_new.length();
    d_c.updatepassword(username,password_new,passwordlen);
}

void Server::handleupdatesex(QStringList list)
{
    QString username=list.at(1);//用户名
    QString sex=list.at(2);//性别
    QString s="0";
    if(sex=="男")s="1";
    if(sex=="女")s="2";
    d_c.updatesex(username,s);

}

void Server::handlepersonalinformation(QStringList list)
{
    QString username=list.at(1);
    QString str=d_c.p_info(username);
    SendToHost(str);
}

void Server::handdlebrowse(QStringList list)
{
    QString classification=list.at(1);
    QString sqlRequest;
    QString re;
    QString temp=list.at(2);   //新的信息格式 ，list.at（2）是客户端追加的请求第几到第几条信息 aaaaaa
    begin_sum=temp.toInt();
    if(classification=="wanted"){
        re=d_c.SearchSummary(1);
    }
    if(classification=="confession"){
        re=d_c.SearchSummary(2);
    }
    if(classification=="consult"){
        re=d_c.SearchSummary(3);
    }
    if(classification=="group"){
        re=d_c.SearchSummary(4);
    }
    if(classification=="shop"){
        re=d_c.SearchSummary(5);
    }
    if(classification=="recruit"){
        re=d_c.SearchSummary(6);
    }
    if(classification=="ad"){
        re=d_c.SearchSummary(7);
    }

    //aaaaaaaa
    if(classification=="study"){
        re=d_c.SearchSummary(8);
    }
    SendToHost(re);
}

void Server::handleparticular(QStringList list)
{
    QString number1=list.at(1);
    int number0=number1.toInt();
    QString class1=list.at(2);
    int class0=class1.toInt();
    QString re=d_c.searchParticular(number0,class0);
    //ui->textEdit_requireshow->append(re);
    SendToHost(re);
    //ui->textEdit_requireshow->append(re);
}

void Server::handleRelase(QStringList list)
{
    QString classification=list.at(1);
    QString text=list.at(2);
    int textlen=text.length();
    QString temp_image_num=list.at(3);
    int image_num=temp_image_num.toInt();
    QString image1=list.at(4);
    QString image2=list.at(5);
    QString image3=list.at(6);
    QPixmap p1=stringTopixmap(image1);
    QPixmap p2=stringTopixmap(image2);
    QPixmap p3=stringTopixmap(image3);
    QString username=list.at(7);
    int usernamelen=username.length();
    int class1=1;
    if(classification=="悬赏"){
        class1=1;
    }
    if(classification=="表白"){
        class1=2;
    }
    if(classification=="咨询"){
        class1=3;
    }
    if(classification=="组队"){
        class1=4;
    }
    if(classification=="拼团"){
        class1=5;
    }
    if(classification=="招聘"){
        class1=6;
    }
    if(classification=="广告"){
        class1=7;
    }
    if(classification=="学习"){
        class1=8;
    }
    d_c.handlerelase(username,usernamelen,class1,text,textlen,image_num,p1,p2,p3);
}

void Server::SendToHost(QString message)//不要多次发送，将数据整合在一个QString字符串中，以某个标志符号隔开，一次性发送
{
    //ui->textEdit_requireshow->setText(message);
    QByteArray block;
    //使用数据流写入数据
    QDataStream out(&block,QIODevice::WriteOnly);

    //设置数据流的版本，客户端和服务器端使用的版本要相同
    out.setVersion(QDataStream::Qt_4_6);
    out<<(int) 0;
    out<<message;
    out.device()->seek(0);
    out<<(int) (block.size() - sizeof(int));
    tcpsocket->write(block);

}


