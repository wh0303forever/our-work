#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include<QtNetwork>
#include<QString>
#include<QDebug>
#include<QTcpSocket>
#include<QFile>
#include<QTcpServer>
#include<QIODevice>
#include<QHostInfo>
#include<QMessageBox>
#include<QTextStream>
#include<QStringList>
#include<database_control.h>

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

private:
    Ui::Server *ui;
    QTcpServer *tcpserver;           //服务器端套接字
    QTcpSocket *tcpsocket;           //通信套接字
    QString recievedMessage;         //存储收到的信息
    database_control d_c;            //数据库控制
    int blockSize; //存放文件的大小信息
    QString message;

    int now_page;    //记录页数aaaaa

    int begin_sum;     //aaaaa  记录服务器申请的哪几条概览信息


    //暂未用到
    qint64 totalBytes;  //存放总大小信息
    qint64 bytesReceived;  //已收到数据的大小
    qint64 fileNameSize;  //文件名的大小信息

    QPixmap qstringTopixmap( const QString& pic )
    {
    QByteArray byte_array = QByteArray::fromBase64(pic.toLocal8Bit());

    QPixmap pix;

    QDataStream data_stream(&byte_array,QIODevice::ReadOnly);

    data_stream>>pix;

    return pix;

    }
    void handledelete(QStringList);
    void handlep_image(QStringList);
    void handleupdate_nickname(QStringList);
    void handlemajor(QStringList);
    void handlep_message(QStringList);
    void hanlep_m(QStringList);
    void handlelike(QStringList);
    void handlecomment(QStringList);

private slots:
    void HandleMessage();
    void classfyMessage();
    void ShowLink();
    void ShowRequire(QString);
    void HandleRegister(QStringList);
    void HandleLogin(QStringList);
    QPixmap stringTopixmap( const QString&);
    void handleupdatepassword(QStringList);
    void handleupdatesex(QStringList);
    void handlepersonalinformation(QStringList);
    void handdlebrowse(QStringList);
    void handleparticular(QStringList);
    void handleRelase(QStringList);
    void SendToHost(QString);

    void handlexinxi(QStringList);  //这个函数用于处理客户端发送的“被赞的，被收藏”的请求信息aaaaaa
};

#endif // SERVER_H
