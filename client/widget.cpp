#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    publish_image=0;
    images=new QString[3];
    summarypublished=new summary[5];
    username="10001";
    summary_num=1;
    NowPage=1;    //当前是第一页
    p_message=nullptr;
    p_message_num=0;
    nowNumber=0;
    likenum=0;
    releasing=false;

    ui->stackedWidget_3->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(6);

    //ui->label_text->setMaximumWidth(700);
    //ui->label_text->setMaximumHeight(110);

    ui->lineEdit_old->setEchoMode(QLineEdit::Password);
    ui->lineEdit_new1->setEchoMode(QLineEdit::Password);
    ui->lineEdit_new2->setEchoMode(QLineEdit::Password);

    ui->label_text->setGeometry(QRect(10, 150, 790, 110)); //四倍行距
    ui->label_text->setWordWrap(true);
    ui->label_text->setAlignment(Qt::AlignTop);

    //绑定对概览信息的点击
    connect(ui->listWidget_glance,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(ShowParticular(QListWidgetItem*)));

    //初始化TCP模块
    TcpSocket=new QTcpSocket(this);
    connect(TcpSocket,SIGNAL(readyRead()),this,SLOT(ReadMessage()));//一旦从服务器收到信息则启用ReadMessage事件
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ShowSummary()
{
    ui->listWidget_glance->clear();
    qDebug()<<"正在显示概览信息";
    ui->listWidget_glance->setIconSize(QSize(60,60));//设置表项图片尺寸
    qDebug()<<summary_num;
    //在实际应用中，summarypublished存储从服务器获取的信息，以下则显示summarypublished中的信息，每次最多存储5项，也最多显示5项，不要改动
    for(int i=0;i<summary_num;i++){
        QString str3="用户名：";
        str3+=summarypublished[i].username+"\n内容："+summarypublished[i].text;
        qDebug()<<str3;
        QListWidgetItem*lst=new QListWidgetItem(summarypublished[i].image,str3, ui->listWidget_glance);
        lst->setSizeHint(QSize(740,95));//设置表项尺寸
        ui->listWidget_glance->insertItem(i, lst);
    }
}

void Widget::on_pushButton_8_clicked()//悬赏按钮
{
    topbuttonsetable();
    ui->pushButton_8->setEnabled(false);
    symbol=1;
    QString re="browsezcmwxkysjwhwantedzcmwxkysjwh0";
    SendToHost(re);
}

void Widget::on_pushButton_7_clicked()//表白按钮
{
    topbuttonsetable();
    ui->pushButton_7->setEnabled(false);
    symbol=2;
    QString re="browsezcmwxkysjwhconfessionzcmwxkysjwh0";
    SendToHost(re);
}

void Widget::on_pushButton_6_clicked()//咨询按钮
{
    qDebug()<<now_ip<<now_port;
    topbuttonsetable();
    ui->pushButton_6->setEnabled(false);
    symbol=3;
    QString re="browsezcmwxkysjwhconsultzcmwxkysjwh0";
    SendToHost(re);
}

void Widget::on_pushButton_5_clicked()//组队按钮
{
    topbuttonsetable();
    ui->pushButton_5->setEnabled(false);
    symbol=4;
    QString re="browsezcmwxkysjwhgroupzcmwxkysjwh0";
    SendToHost(re);
}

void Widget::on_pushButton_4_clicked()//拼团按钮
{
    topbuttonsetable();
    ui->pushButton_4->setEnabled(false);
    symbol=5;
    QString re="browsezcmwxkysjwhshopzcmwxkysjwh0";
    SendToHost(re);
}

void Widget::on_pushButton_3_clicked()//招聘按钮
{
    topbuttonsetable();
    ui->pushButton_3->setEnabled(false);
    symbol=6;
    QString re="browsezcmwxkysjwhrecruitzcmwxkysjwh0";
    SendToHost(re);
}

void Widget::on_pushButton_2_clicked()//广告按钮
{
    topbuttonsetable();
    ui->pushButton_2->setEnabled(false);
    symbol=7;
    QString re="browsezcmwxkysjwhadzcmwxkysjwh0";
    SendToHost(re);
}

void Widget::on_pushButton_clicked()//学习按钮
{
    topbuttonsetable();
    ui->pushButton->setEnabled(false);
    symbol=8;
    QString re="browsezcmwxkysjwhstudyzcmwxkysjwh0";
    SendToHost(re);
}

void Widget::on_pushButton_10_clicked()//浏览概览信息
{
    releasing=false;
    ui->stackedWidget_3->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(1);

}

void Widget::on_pushButton_9_clicked()//发布信息按钮
{
    releasing=false;
    releasing=true;
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_pushButton_13_clicked()//消息按钮
{
    releasing=false;
    ui->stackedWidget->setCurrentIndex(2);
    QString re="requirezcmwxkysjwh"+username;     //不区分是请求被赞过的消息还是被评论的消息，服务器统统发过来
    SendToHost(re);
}

void Widget::on_pushButton_14_clicked()//个人中心
{

    QString message="p_mzcmwxkysjwh"+username;
    SendToHost(message);
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->pushButton_18->setEnabled(true);
    ui->pushButton_19->setEnabled(false);
}

void Widget::on_pushButton_18_clicked()//已发布的信息
{
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->pushButton_18->setEnabled(false);
    ui->pushButton_19->setEnabled(true);
    QString message="p_messagezcmwxkysjwh"+username;
    qDebug()<<message;
    SendToHost(message);
}

void Widget::on_pushButton_19_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->pushButton_19->setEnabled(false);
    ui->pushButton_18->setEnabled(true);
}

void Widget::ReadMessage(){
    QDataStream in(TcpSocket);
    in.setVersion(QDataStream::Qt_4_6);
    //设置数据流版本，这里要和服务器端相同
    if(blockSize==0) //如果是刚开始接收数据
    {
    //判断接收的数据是否有两字节，也就是文件的大小信息
    //如果有则保存到blockSize变量中，没有则返回，继续接收数据
        if(TcpSocket->bytesAvailable() < (int)sizeof(int)) return;
        in >> blockSize;
    }
    if(TcpSocket->bytesAvailable() < blockSize) return;
    //如果没有得到全部的数据，则返回，继续接收数据
    in>>message;

    QStringList list=message.split("zcmwxkysjwh");
    QString cl=list.at(0);

    qDebug()<<"收到服务器信息";

    //头部是return则是服务器反馈的概览信息
    //return 类别  编号 头像 用户名 text
    if(cl=="return")//返回的是概览信息
    {
        if(list.at(1)=="wanted"||list.at(1)=="confession"||list.at(1)=="consult"||list.at(1)=="group"||list.at(1)=="shop"||list.at(1)=="recruit"||list.at(1)=="ad"||list.at(1)=="study")
        {
            qDebug()<<"返回的是概览信息";
            QString temp=list.at(2);
            summary_num=temp.toInt();
            summarypublished=new summary[summary_num];
            for(int j=3,i=0;i<summary_num;j+=4,i++)
                {
                     QPixmap pix=stringTopixmap(list.at(j+1));
                     QIcon p(pix);
                     summarypublished[i].load(QString(list.at(j+2)),QString(list.at(j)),QString(list.at(j+3)),p);//用户名 编号 文本 头像
                }
            ui->stackedWidget_3->setCurrentIndex(1);
            ui->listWidget_glance->clear();
            ShowSummary();
        }

        if(list.at(1)=="praised"||list.at(1)=="comment")
                {
                   ui->stackedWidget->setCurrentIndex(2);
                   ui->listWidget_message->clear();
                   int last=list.size();
                   for(int i=2;i<last;i++)
                   {
                       QString res=QString("你发布的编号为%1的信息被赞/评论了").arg(list.at(i));
                       ui->listWidget_message->insertItem(i,res);

                   }

                }
    }


    if(cl=="returnparticular")  //返回的是详细信息
    {
        ui->label_image1->clear();
        ui->label_image2->clear();
        ui->label_image3->clear();
        ui->label_text->clear();
        ui->label_12->clear();

        ui->label_text->setText(list.at(1));//显示文本
        ui->label_text->adjustSize();
        int num=list.at(2).toInt();
        //图片显示
        if(num==0){
            ui->label_image2->clear();
            ui->label_image2->clear();
            ui->label_image3->clear();
        }
        if(num==1){
            QPixmap i=stringTopixmap(list.at(3));
            i=i.scaled(158,129);
            ui->label_image1->setPixmap(i);
            ui->label_image1->adjustSize();
            ui->label_image2->clear();
            ui->label_image3->clear();
        }
        if(num==2){

           QPixmap i=stringTopixmap(list.at(3));
           QPixmap i2=stringTopixmap(list.at(4));
           i = i.scaled(158, 129);
           i2 = i2.scaled(158, 129);
           ui->label_image1->setPixmap(i);
           ui->label_image2->setPixmap(i2);
           ui->label_image1->adjustSize();
           ui->label_image2->adjustSize();
           ui->label_image3->clear();
        }
        if(num==3){
            QPixmap i=stringTopixmap(list.at(3));
            QPixmap i2=stringTopixmap(list.at(4));
            QPixmap i3=stringTopixmap(list.at(5));
            i = i.scaled(158, 129);
            i2 = i2.scaled(158, 129);
            i3 = i3.scaled(158, 129);
            ui->label_image1->setPixmap(i);
            ui->label_image2->setPixmap(i2);
            ui->label_image3->setPixmap(i3);
            ui->label_image1->adjustSize();
            ui->label_image2->adjustSize();
            ui->label_image3->adjustSize();
        }
        ui->label_12->setText("有"+list.at(6)+"位用户点赞了");//显示点赞人数
        likenum=list.at(6).toInt();
        int c_num=list.at(7).toInt();
        ui->listWidget_2->clear();
        for(int i=0;i<c_num;i++){
            QString str3=list.at(8+i);
            QListWidgetItem*lst=new QListWidgetItem(list.at(8+i), ui->listWidget_2);
            ui->listWidget_2->insertItem(i, lst);
        }
        ui->stackedWidget->setCurrentIndex(5);
    }
    if(cl=="p_info")  //返回的是个人信息
    {
        QString major=list.at(3);
        QString sex=list.at(1);
        QString s="专业："+major+"\n";
        s+="性别："+sex+"\n";
        s+="用户名："+username+"\n";
        QMessageBox::information(NULL, "个人资料",s);
    }
    if(cl=="returnp_message"){
        p_message_num=list.at(1).toInt();
        p_message=new summary[p_message_num];
        for(int i=0,j=2;i<p_message_num;i++,j+=3){
            p_message[i].number=list.at(j+1);
            p_message[i].symbol=list.at(j+2);
            p_message[i].text=list.at(j);
        }
        show_p_summary();
    }
    if(cl=="p_m"){
        QString nickname=list.at(2);
        image0=stringTopixmap(list.at(1));
        ui->label_7->setText("昵称："+nickname);
        ui->label_5->setPixmap(image0);
        ui->label_6->setText("用户名："+username);
    }
    TcpSocket->disconnectFromHost();
}

void Widget::SendToHost(QString message)//不要多次发送，将数据整合在一个QString字符串中，以某个标志符号隔开，一次性发送
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
    TcpSocket->connectToHost(now_ip,now_port);        //aaaaa
    //TcpSocket->connectToHost("localhost",8888);//连接到服务器  假设服务器在本机8888端口
    TcpSocket->waitForConnected(1000);
    TcpSocket->write(block);
}

void Widget::loadusername(QString usern)
{
    username=usern;
}

void Widget::topbuttonsetable()
{
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);

    //ui->pushButton_10->setEnabled(true);
    //ui->pushButton_9->setEnabled(true);
    //ui->pushButton_13->setEnabled(true);
    //ui->pushButton_14->setEnabled(true);
}

void Widget::whethersave()
{

}

void Widget::on_pushButton_15_clicked()//发布信息界面 添加图片按钮
{
    QString fileName = QFileDialog::getOpenFileName(
                    this, tr("open image file"),
                    "./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)"));

        if(fileName.isEmpty())return;

        //以下为显示选择的图片
        QPixmap p(fileName);
        QString pic=pixmapTostring(p);
        p=p.scaled(178,189);
        publish_image++;
        switch(publish_image){
        case 1:ui->label_2->setPixmap(p);images[0]=pic;break;
        case 2:ui->label_3->setPixmap(p);images[1]=pic;break;
        case 3:ui->label->setPixmap(p);images[2]=pic;break;

        }

        //限于时间问题，最多选择3张图片
        if(publish_image==3)ui->pushButton_15->setEnabled(false);
}

void Widget::on_pushButton_17_clicked()//取消发布
{
    //转回浏览信息界面
    ui->stackedWidget->setCurrentIndex(1);

    //置空发布图片的数量
    publish_image=0;

    //清空显示区
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label->clear();
    ui->textEdit_publish->clear();
    QString s=NULL;
    images[0]=s;
    images[1]=s;
    images[2]=s;

    //添加图片按钮启用
    ui->pushButton_15->setEnabled(true);
}

void Widget::on_pushButton_16_clicked()//确认发布按钮
{
    QString temp=ui->textEdit_publish->toPlainText();
    if(temp.length()>255){
        QMessageBox::information(NULL, "提示信息","文字数量不能超过255");
        return;
    }
    if(temp.length()==0){
        QMessageBox::information(NULL, "提示信息","文本不能为空");
        return;
    }
    QString s="relasezcmwxkysjwh";
    s+=ui->comboBox->currentText()+"zcmwxkysjwh";
    s+=ui->textEdit_publish->toPlainText();
    s+="zcmwxkysjwh"+QString("%1").arg(publish_image)+"zcmwxkysjwh";
    s+=images[0]+"zcmwxkysjwh"+images[1]+"zcmwxkysjwh"+images[2]+"zcmwxkysjwh";
    s+=username;
    //qDebug()<<s;
    SendToHost(s);

    QMessageBox::information(NULL, "提示信息","信息发布成功");
    ui->stackedWidget->setCurrentIndex(1);
    //置空发布图片的数量
    publish_image=0;

    //清空显示区
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label->clear();
    ui->textEdit_publish->clear();
    QString s1=NULL;
    images[0]=s1;
    images[1]=s1;
    images[2]=s1;

    //添加图片按钮启用
    ui->pushButton_9->setEnabled(true);
}

void Widget::ShowParticular(QListWidgetItem*p)//显示详细信息
{

    int row1=ui->listWidget_glance->row(p);//获取点击的行号，用以向服务器端请求信息
    nowNumber=row1;
    ui->stackedWidget->setCurrentIndex(5);
    ui->label_9->setPixmap(summarypublished[row1].image.pixmap(80,80));//设置头像
    ui->label_10->setText("用户名："+summarypublished[row1].username);//设置用户名
    //此处从服务器请求
    QString require;
    QString number=summarypublished[row1].number;
    QString class1=QString("%1").arg(symbol);
    require+="particularzcmwxkysjwh"+number+"zcmwxkysjwh"+class1;
    SendToHost(require);
}

void Widget::on_pushButton_24_clicked()//上传头像
{
    //显示一个选择框并返回选择的文件路径
    QString fileName = QFileDialog::getOpenFileName(
                    this, tr("open image file"),
                    "./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)"));

        if(fileName.isEmpty())return;

        //界面更新头像为新头像
        QPixmap p(fileName);
        p=p.scaled(100,100);
        ui->label_5->setPixmap(p);

        QString re="updateimagezcmwxkysjwh";
        re+=username+"zcmwxkysjwh";
        QString temp=pixmapTostring(p);
        re+=temp;
        SendToHost(re);

        QMessageBox::information(this,"提示","上传头像成功",QMessageBox::Yes);
}

void Widget::on_pushButton_25_clicked()//更改昵称
{
    //显示一个输入框并获取输入
    bool ok;
    QString sName = QInputDialog::getText(this,
                                             "更改昵称",
                                             "请输入姓名",
                                             QLineEdit::Normal,
                                             "张三",
                                             &ok
                                             );

    //此处在个人中心界面显示更改后的昵称
    if(sName!=NULL){
       ui->label_7->setText(sName);
    }
    if(sName.length()>8){
        QMessageBox::information(NULL, "提示信息","昵称长度不能大于8");
        return;
    }
    //此处为向服务器发送更改昵称请求，待实现，实现时应先于显示
    QString request="updatenicknamezcmwxkysjwh";
    request+=username+"zcmwxkysjwh";
    request+=sName;
    SendToHost(request);
}

void Widget::on_pushButton_26_clicked()//更改性别
{
    bool ok;
    QStringList list;
    list<<"男"<<"女"<<"保密";
    QString sex = QInputDialog::getItem(this,
                                             QString("更改性别"),
                                             QString("请选择性别"),
                                             list,
                                             0,
                                             false,
                                             &ok,
                                        Qt::WindowFlags(),
                                        Qt::ImhNone
                                          );
    if(!ok)return;
    QString message="updatesexzcmwxkysjwh"+username+"zcmwxkysjwh";
    message+=sex;
    qDebug()<<message;
    SendToHost(message);
    QMessageBox::information(NULL, "提示信息","更改性别成功");
}

void Widget::on_pushButton_23_clicked()//更改密码
{
    ui->lineEdit_new1->clear();
    ui->lineEdit_new2->clear();
    ui->lineEdit_old->clear();
    ui->stackedWidget_2->setCurrentIndex(1);
}

void Widget::on_pushButton_22_clicked()//更改专业
{
    //显示一个输入框并获取输入
    bool ok;
    QString sName = QInputDialog::getText(this,
                                             "更改专业",
                                             "请输入专业",
                                             QLineEdit::Normal,
                                             "**",
                                             &ok
                                             );

    //此处在个人中心界面显示更改后的昵称
    //此处为向服务器发送更改昵称请求，待实现，实现时应先于显示
    if(ok){
        if(sName=="**"||sName.length()==0){
            QMessageBox::information(NULL, "提示信息","专业不能为空");
            return;
        }
        if(sName.length()>8){
            QMessageBox::information(NULL, "提示信息","专业长度不能大于8");
            return;
        }
    QString request="updatemajorzcmwxkysjwh";
    request+=username+"zcmwxkysjwh";
    request+=sName;
    SendToHost(request);
    }
}

void Widget::on_pushButton_21_clicked()
{
    QString message="personalinformationzcmwxkysjwh";
    message+=username;
    SendToHost(message);
}

void Widget::show_p_summary()
{
    ui->listWidget->setIconSize(QSize(60,60));//设置表项图片尺寸
    ui->listWidget->clear();
    for(int i=0;i<p_message_num;i++){

        QIcon image(image0);
        QString str3="用户名：";
        str3+=username+"\n内容："+p_message[i].text;
        QListWidgetItem*lst=new QListWidgetItem(image,str3, ui->listWidget);
        lst->setSizeHint(QSize(750,95));//设置表项尺寸
        ui->listWidget->insertItem(i, lst);
    }

}

void Widget::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_pushButton_27_clicked()//点赞
{
    QString message="likezcmwxkysjwh";
    message+=username+"zcmwxkysjwh";
    QString number1=QString("%1").arg(summarypublished[nowNumber].number);
    message+=number1+"zcmwxkysjwh"+QString("%1").arg(symbol);
    SendToHost(message);
    qDebug()<<message;
    ui->label_12->setText(QString("有%1位用户点赞了").arg(++likenum));
}

void Widget::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Widget::on_pushButton_29_clicked()
{
    ui->textEdit_2->clear();
    ui->stackedWidget->setCurrentIndex(5);
}

void Widget::on_pushButton_30_clicked()//确认发布评论
{
    QString comment=ui->textEdit_2->toPlainText();
    if(comment.length()>=50){
        QMessageBox::information(NULL, "提示信息","评论字数不能超过50");
        return;
    }
    if(comment.length()==0){
        QMessageBox::information(NULL, "提示信息","评论不能为空");
        return;
    }
    else{
        QString message="commentzcmwxkysjwh";
        message+=username+"zcmwxkysjwh";
        QString number1=QString("%1").arg(summarypublished[nowNumber].number);
        message+=number1+"zcmwxkysjwh"+QString("%1").arg(symbol)+"zcmwxkysjwh";
        message+=comment;
        qDebug()<<message;
        SendToHost(message);
        QMessageBox::information(NULL, "提示信息","评论发布成功");
        QListWidgetItem*lst=new QListWidgetItem(username+":"+comment, ui->listWidget_2);
        ui->listWidget_2->insertItem(0, lst);
        ui->textEdit_2->clear();
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void Widget::on_pushButton_12_clicked()//取消更改密码
{
    ui->lineEdit_new1->clear();
    ui->lineEdit_new2->clear();
    ui->lineEdit_old->clear();
    ui->stackedWidget_2->setCurrentIndex(0);
}

void Widget::on_pushButton_11_clicked()//确认修改密码
{
    QString old1=ui->lineEdit_old->text();
    QString new1=ui->lineEdit_new1->text();
    QString new2=ui->lineEdit_new2->text();

    if(old1.length()==0){
        QMessageBox::information(NULL, "提示信息","旧密码不能为空");
        return;
    }
    if(new1.length()==0){
        QMessageBox::information(NULL, "提示信息","新密码不能为空");
        return;
    }
    if(new2.length()==0){
        QMessageBox::information(NULL, "提示信息","新密码不能为空");
        return;
    }
    if(new1!=new2){
        QMessageBox::information(NULL, "提示信息","两次新密码不相等");
        return;
    }
    if(new1.length()<8||new1.length()>16){
        QMessageBox::information(NULL, "提示信息","新密码长度不符合规定");
        return;
    }
    if(old1!=password){
        QMessageBox::information(NULL, "提示信息","旧密码错误");
        return;
    }
    QString message="passwordzcmwxkysjwh";
    message+=username+"zcmwxkysjwh";
    message+=new1+"zcmwxkysjwh";
    SendToHost(message);
    QMessageBox::information(NULL, "提示信息","密码修改成功，请妥善保管您的密码");
    password=new1;
    ui->lineEdit_new1->clear();
    ui->lineEdit_new2->clear();
    ui->lineEdit_old->clear();
    ui->stackedWidget_2->setCurrentIndex(0);
}

void Widget::on_pushButton_31_clicked()//删除消息
{
    QString s="deletezcmwxkysjwh"+username;
    SendToHost(s);
    ui->listWidget_message->clear();
}
