#ifndef DATABASE_CONTROL_H
#define DATABASE_CONTROL_H

#include <QApplication>
#include<QSql>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include<QSqlError>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QString>
#include<QFile>
#include<QPixmap>
#include<QBuffer>

class database_control{
public:
    database_control();
    void deletemessage(QString usern);
    QString SearchSummary(int class1);//根据编号和分类查询一条信息，返回其昵称、文本，格式为 昵称|text
    QString loadImage(int i,int j);//查询一张图片并返回
    QString searchParticular(int number1,int class1);//查询一条详略信息并返回 昵称|文本|点赞人数|图片数目|图片1|图片2|图片3|
    QString ReturnPassword(QString username1);
    void InsertImage();
    QString searchImage(QString name);
    QString pixmapTostring( QByteArray byte_array );
    QPixmap stringTopixmap( const QString&);
    bool updatepassword(QString username,QString password,int passwordlen);
    void updatesex(QString username,QString sex);
    QString p_info(QString username);
    QString getclassification(int class1);
    void insertcomment(int number1,int class1,QString username,int usernamelen,QString text,int textlen);
    void handlelike(QString username,int number1,int class1);
    void handlerelase(QString username,int usernamelen,
                      int classification,QString text,int textlen,int imagenum,QPixmap image1,QPixmap image2,QPixmap image3);
    int getmaxpublishednumber(int class1);

    int handleregister(QString username,QString password,int usernamelen,int passwordlen);
    int handlelogin(QString username,QString password);
    void insertusers();
   // QString searchxinxi(QString username);   //从数据库中搜索“某个用户被赞过的，被评论过的信息”aaaaa
    void handlep_image(QString,QString);
    void handlenickname(QString username,QString nickname);
    void hanldemajor(QString username,QString major);
    QString handle_p_message(QString username);
    QString handle_p_m(QString);
    QString searchxinxi(QString username);
private:
    QString s;
    QSqlDatabase db;
    QString qpixmapTostring( const QPixmap& pixmap )
    {
      QByteArray byte_array;
      QDataStream data_stream(&byte_array,QIODevice::WriteOnly);
      data_stream<<pixmap;
      QString res = QString::fromLocal8Bit(byte_array.toBase64());
      return res;
    }

};


#endif // DATABASE_CONTROL_H
