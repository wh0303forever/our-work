#include"database_control.h"

database_control::database_control()
{
    //以下，如果不是要绑定自己的电脑数据库，就千万别动
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    if(db.isValid()){
    QString dsn = QString::fromLocal8Bit("SERVER");      //数据源名称
    db.setHostName("localhost");                        //选择本地主机，127.0.1.1
    db.setDatabaseName(dsn);                            //设置数据源名称
    db.setUserName("server");                               //登录用户
    db.setPassword("wh33foreverwith");                      //密码
    if(!db.open())                                      //打开数据库
    {
     QMessageBox::critical(0, QObject::tr("Database error"), db.lastError().text());
    }
    }
}

void database_control::deletemessage(QString usern)
{
    QString sqlRequest=QString("delete from xinxi where exist(select* from xinxi,published where xinxi.number=published.number and xinxi.classification=published.classification and published.username='%1')").arg(usern);
    QSqlQuery query;
    query.exec(sqlRequest);
}

QString database_control::SearchSummary(int class1)//搜索概览信息
{


    //QString droporder="DROP TABLE #temp";
    QString sqlRequest2;
    sqlRequest2=QString("select published.number,published.username,published.usernamelen,text,textlen,image0 from published,users where classification=%1 and users.username=published.username").arg(class1);

    //----------------------------------------------------------------------------------------
    //return 类别 编号 头像 用户名 text
    QString sqlRequest;
    sqlRequest=QString("select published.number,published.username,published.usernamelen,text,textlen,image0 from published,users where classification=%1 and users.username=published.username").arg(class1);
    QSqlQuery query(db);
    query.exec(sqlRequest);
    //int summary_num;

    //aaaaaaa以下几行是增加查询了概览信息的数量，用于客户端的数组下标
    QString summary_num=QString("select count(*) from published,users where classification=%1 and users.username=published.username").arg(class1);
    QSqlQuery query2(db);
    query2.exec(summary_num);
    int s_num=0;
    if(query2.first()){s_num=query2.value(0).toInt();qDebug()<<s_num;}
    QString re=QString("returnzcmwxkysjwh")+getclassification(class1)+"zcmwxkysjwh"+QString("%1").arg(s_num);
    int num=0;
    while(query.next()){
        qDebug()<<222;
        num++;
        re+="zcmwxkysjwh";
        int number=query.value(0).toInt();
        re+=QString("%1").arg(number);
        re+="zcmwxkysjwh";
        QByteArray image;
        QDataStream data_stream(&image,QIODevice::ReadWrite);
        data_stream<<query.value(5).toByteArray();
        QString image0;
        if(image!=NULL){
        image0=pixmapTostring(image);
        re+=image0;
        }
        re+="zcmwxkysjwh";
        QString username;
        int usernamelen=query.value(2).toInt();

        for(int i=0;i<usernamelen;i++){
            username+=query.value(1).toString()[i];
        }
        re+=username+"zcmwxkysjwh";
        QString text;
        int textlen=query.value(4).toInt();
        if(textlen>=30)textlen=30;
        for(int i=0;i<textlen;i++){
            text+=query.value(3).toString()[i];
        }
        re+=text;
    }
    return re;
}


QString database_control::loadImage(int number1, int classification1){
    QString sqlRequest=QString("select image1 from published where number=%1 and classification=%2").arg(number1).arg(classification1);
    QSqlQuery query;
    QString image;

    query.exec(sqlRequest);
    if(query.first()){
        QByteArray s;
        QDataStream data_stream(&s,QIODevice::ReadWrite);
        data_stream<<query.value(0).toByteArray();

        image=pixmapTostring(s);
    }
    return image;
}

QString database_control::searchParticular(int number1, int class1)
{
    QString sqlRequest=QString("select text,textlen,image1,image2,image3,imagenum,likenum from published where number=%1 and classification=%2").arg(number1).arg(class1);
    QSqlQuery query;
    query.exec(sqlRequest);
    QString re=QString("returnparticularzcmwxkysjwh");
    if(query.first()){
        int textlen=query.value(1).toInt();
        for(int i=0;i<textlen;i++)re+=query.value(0).toString()[i];
        re+="zcmwxkysjwh";
        int imagenum=query.value(5).toInt();
        re+=QString("%1zcmwxkysjwh").arg(imagenum);
        for(int i=1;i<4;i++){
            QString image0;
            QByteArray image;
            QDataStream data_stream(&image,QIODevice::ReadWrite);
            data_stream<<query.value(1+i).toByteArray();
            image0=pixmapTostring(image);
            re+=image0+QString("zcmwxkysjwh");
        }
        re+=QString("%1").arg(query.value(6).toInt());
        re+="zcmwxkysjwh";
    }
    int num=0;
    QString comment;
    QString sqlRequest1=QString("select username,usernamelen,text,textlen from comment where publishednumber=%1 and classification=%2").arg(number1).arg(class1);
    QSqlQuery query1;
    query1.exec(sqlRequest1);
    while(query1.next()){
        num++;
        comment+="zcmwxkysjwh";
        int len=query1.value(1).toInt();
        for(int i=0;i<len;i++){comment+=query1.value(0).toString()[i];}
        comment+=":";
        len=query1.value(3).toInt();
        for(int i=0;i<len;i++){comment+=query1.value(2).toString()[i];}

    }
    re+=QString("%1").arg(num);
    re+=comment;
    return re;
}

QString database_control::ReturnPassword(QString username1)//检索到密码则返回 1|密码；否则返回0|
{
    QString sqlRequest=QString("select password,passwordlen from users where username like '%1'").arg(username1);
    QSqlQuery query;
    QString image;
    query.exec(sqlRequest);
    if(query.first()){
        int len=query.value(1).toInt();
        image+=QString("1|");
        for(int i=0;i<len;i++){
        image+=query.value(0).toString()[i];
        }
    }
    else{
        image+="0|";
    }
    return image;
}

void database_control::InsertImage()
{
    QByteArray data;//存储图片的字节流对象
    QFile *file=new QFile("D:/1.jpg"); //fileName为二进制数据文件名
    file->open(QIODevice::ReadOnly);
    data = file->readAll();
    QVariant  var_0_0(data);
    QVariant var_5=var_0_0;
    file->close();

    QSqlQuery query;
    //插入操作，仅为测试
    query.prepare("INSERT INTO published VALUES ('离川',2,2,3,'初次见面请多关照',8,:MyImage1,:MyImage2,:MyImage3,3,29)");
    query.bindValue(":MyImage1", var_5);
    query.bindValue(":MyImage2", var_5);
    query.bindValue(":MyImage3", var_5);
    query.exec();
}

QString database_control::searchImage(QString name)
{
    QString sqlRequest=QString("select image0 from users where username like '%1'").arg(name);
    QSqlQuery query;
    QPixmap photo;
    QString s;
    query.exec(sqlRequest);
    if(query.first()){
        QByteArray a;
        QDataStream data_stream(&a,QIODevice::ReadWrite);
        data_stream<<query.value(0).toByteArray();
        s=pixmapTostring(a);
    }
    return s;

}

QString database_control::pixmapTostring( QByteArray byte_array )
{
  QString res = QString::fromLocal8Bit(byte_array.toBase64());
  return res;

}

QPixmap database_control::stringTopixmap( const QString& pic )

{
  QByteArray byte_array = QByteArray::fromBase64(pic.toLocal8Bit());
  QPixmap pix;
  QDataStream data_stream(&byte_array,QIODevice::ReadOnly);
  data_stream>>pix;
  return pix;

}

bool database_control::updatepassword(QString username,QString password,int passwordlen)
{
    QSqlQuery query;
    QString sqlRequest=QString("update users set password='%1',passwordlen=%2 where username='%3'").arg(password).arg(passwordlen).arg(username);
    query.exec(sqlRequest);
    return true;
}

void database_control::updatesex(QString username, QString sex)
{
    QSqlQuery query;
    QString sqlRequest=QString("update users set sex=%1 where username='%2'").arg(sex).arg(username);
    query.exec(sqlRequest);
}

QString database_control::p_info(QString username)
{
    QString s="p_infozcmwxkysjwh";
    QSqlQuery query;
    QString sqlRequest=QString("select sex,nickname,major from users where username='%1'").arg(username);
    query.exec(sqlRequest);
    if(query.first()){
        int age=query.value(0).toInt();
        switch(age){
            case 0:s+="保密zcmwxkysjwh";break;
            case 1:s+="男zcmwxkysjwh";break;
            case 2:s+="女zcmwxkysjwh";break;
        }
        s+=query.value(1).toString()+"zcmwxkysjwh"+query.value(2).toString();
    }
    return s;
}

QString database_control::getclassification(int class1)
{
    QString classification;
    switch(class1){
    case 1:
        classification="wanted";
        break;
    case 2:
        classification="confession";
        break;
    case 3:
        classification="consult";
        break;
    case 4:
        classification="group";
        break;
    case 5:
        classification="recruit";
        break;
    case 6:
        classification="recruit";
        break;
    case 7:
        classification="ad";
        break;
    case 8:
        classification="study";
        break;
    }
    return classification;
}

void database_control::insertcomment(int number1, int class1, QString username, int usernamelen, QString text, int textlen)
{
    QString sqlRequest=QString("insert into comment values(%1,%2,'%3',%4,'%5',%6)").arg(number1).arg(class1).arg(username).arg(usernamelen).arg(text).arg(textlen);
    QSqlQuery query;
    query.exec(sqlRequest);
    QString s1=QString("insert into xinxi values(%1,%2)").arg(number1).arg(class1);
    QSqlQuery query1;
    query1.exec(s1);
}

void database_control::handlelike(QString username,int number1, int class1)//点赞
{
    QString sqlRequest=QString("update published set likenum=likenum+1 where number=%1 and classification=%2").arg(number1).arg(class1);
    QSqlQuery query;
    query.exec(sqlRequest);
    QString s1=QString("insert into xinxi values(%1,%2)").arg(number1).arg(class1);
    QSqlQuery query1;
    query1.exec(s1);
}

void database_control::handlerelase(QString username, int usernamelen, int classification, QString text, int textlen, int imagenum, QPixmap image1, QPixmap image2, QPixmap image3)
{   
    QByteArray byteArray1 = QByteArray();
    QBuffer buffer1(&byteArray1);
    buffer1.open(QIODevice::WriteOnly);
    image1.save(&buffer1,"png",0);
    QByteArray byteArray2 = QByteArray();
    QBuffer buffer2(&byteArray2);
    buffer2.open(QIODevice::WriteOnly);
    image2.save(&buffer2,"png",0);
    QByteArray byteArray3 = QByteArray();
    QBuffer buffer3(&byteArray3);
    buffer3.open(QIODevice::WriteOnly);
    image3.save(&buffer3,"png",0);


    QVariant  var_1(byteArray1);
    QVariant  var_2(byteArray2);
    QVariant  var_3(byteArray3);
    int number=getmaxpublishednumber(classification)+1;
    QString sqlRequest=QString("insert into published values('%1',%2,%3,%4,'%5',%6,:MyImage1,:MyImage2,:MyImage3,%7,0)")
            .arg(username).arg(usernamelen).arg(number).arg(classification).arg(text).arg(textlen).arg(imagenum);
    QSqlQuery query;
    query.prepare(sqlRequest);
    query.bindValue(":MyImage1", var_1);
    query.bindValue(":MyImage2", var_2);
    query.bindValue(":MyImage3", var_3);
    query.exec();
}

int database_control::getmaxpublishednumber(int class1)
{
        QString sqlRequest=QString("select max(number) from published where classification=%1").arg(class1);
        QSqlQuery query;
        query.exec(sqlRequest);
        if(query.first()){
            return query.value(0).toInt();
        }
        return 0;
}

int database_control::handleregister(QString username,QString password,int usernamelen,int passwordlen){//注册
    QString sqlRequest=QString("select * from users where username='%1'").arg(username);
    QSqlQuery query;
    query.exec(sqlRequest);
    if(query.first()){
        return 0;
    }
    else{
        QString sqlRequest1=QString("insert into users(username,usernamelen,password,passwordlen) values('%1',%2,'%3',%4)").arg(username).arg(usernamelen).arg(password).arg(passwordlen);
        QSqlQuery query1;
        query1.exec(sqlRequest1);
        return 1;
    }
}

int database_control::handlelogin(QString username, QString password)//处理登录
{
    QString sqlRequest=QString("select password,passwordlen from users where username='%1'").arg(username);
    QSqlQuery query;
    query.exec(sqlRequest);
    if(query.first()){
        QString password1;
        int passwordlen=query.value(1).toInt();
        for(int i=0;i<passwordlen;i++){
            password1+=query.value(0).toString()[i];
        }
        if(password==password1)return 1;
        else return 0;
    }
    else return 0;
}

void database_control::insertusers()//加入新用户，仅测试
{
        QByteArray data;//存储图片的字节流对象
        QFile *file=new QFile("D:/1.jpg"); //fileName为二进制数据文件名
        file->open(QIODevice::ReadOnly);
        data = file->readAll();
        QVariant  var_0_0(data);
        QVariant var_5=var_0_0;
        file->close();

        QSqlQuery query;
        //插入操作，仅为测试
        query.prepare("INSERT INTO users VALUES ('出野1',3,'123456',6,1,'出野',2,'软件工程',4,:MyImage1,20)");
        query.bindValue(":MyImage1", var_5);
        query.exec();
}

QString database_control::searchxinxi(QString username)      //从数据库中检索被赞的，被评论的信息，需要创建一个新表xinxi   aaaaaa
{
    QString res="returnzcmwxkysjwhcomment";
    QString sqlRequest=QString("select xinxi.number from published,xinxi where published.username='%1' and published.number=xinxi.number and published.classification=xinxi.classification").arg(username);
    QSqlQuery query;
    query.exec(sqlRequest);
    while(query.next())
    {
        res+="zcmwxkysjwh";
        int temp=query.value(0).toInt();
        res+=QString("%1").arg(temp);
    }
    return res;
}

void database_control::handlep_image(QString username, QString image)//处理上传头像
{
    QByteArray byteArray1 = QByteArray();
    QBuffer buffer1(&byteArray1);
    buffer1.open(QIODevice::WriteOnly);
    QPixmap p=stringTopixmap(image);
    p.save(&buffer1,"png",0);
    QVariant  var_1(byteArray1);

    QSqlQuery query;
    QString request=QString("update users set image0=:MyImage1 where username='%1'").arg(username);
    query.prepare(request);
    query.bindValue(":MyImage1", var_1);
    query.exec();
}

void database_control::handlenickname(QString username, QString nickname)
{
    int len=nickname.size();
    QString sqlRequest=QString("update users set nickname='%1',nicknamelen=%2 where username='%3'").arg(nickname).arg(len).arg(username);
    QSqlQuery query;
    query.exec(sqlRequest);
}

void database_control::hanldemajor(QString username, QString major)
{
    int len=major.size();
    QString sqlRequest=QString("update users set major='%1',majorlen=%2 where username='%3'").arg(major).arg(len).arg(username);
    QSqlQuery query;
    query.exec(sqlRequest);
}

QString database_control::handle_p_message(QString username)
{
    QString sqlRequest0=QString("select count(*) from published where username='%1'").arg(username);
    QString sqlRequest=QString("select text,textlen,number,classification from published where username='%1'").arg(username);
    QSqlQuery query;
    QSqlQuery query1;
    query.exec(sqlRequest0);
    int num=0;
    QString re="returnp_messagezcmwxkysjwh";
    if(query.first()){
        num=query.value(0).toInt();
        re+=QString("%1").arg(num);
    }
    query1.exec(sqlRequest);
    while(query1.next()){
        re+="zcmwxkysjwh";
        int len=query1.value(1).toInt();
        QString temp;
        for(int i=0;i<len;i++){
            re+=query1.value(0).toString()[i];
        }
        int number=query1.value(2).toInt();
        int class0=query1.value(3).toInt();
        re+=QString("zcmwxkysjwh%1zcmwxkysjwh%2").arg(number).arg(class0);
    }
    return re;
}

QString database_control::handle_p_m(QString username)
{
    QString sqlRequest=QString("select image0,nickname,nicknamelen from users where username='%1'").arg(username);
    QSqlQuery query;
    QString re="p_mzcmwxkysjwh";
    query.exec(sqlRequest);
    if(query.first()){
        QByteArray image;
        QDataStream data_stream(&image,QIODevice::ReadWrite);
        data_stream<<query.value(0).toByteArray();
        QString image0;
        if(image!=NULL){
        image0=pixmapTostring(image);
        re+=image0;
        }
        re+="zcmwxkysjwh";
        int len=query.value(2).toInt();
        for(int i=0;i<len;i++){
            re+=query.value(1).toString()[i];
        }
    }
    return re;
}
// aaaaa   新表的名字叫xinxi，第一列是username，存放用户户名，第二列是info_num,存放已发布的信息编码，第三列是赞信息，第四列是评论信息
//收到客户端的限制  ，目前先不区分被赞的和被评论的，一股脑先发过来
