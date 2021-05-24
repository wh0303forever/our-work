#ifndef LOG_IN_H
#define LOG_IN_H

#include <QWidget>
#include<QTcpSocket>
#include<QHostAddress>
#include<QMessageBox>
#include<QString>
#include<QDebug>
#include<QFile>
#include<QIODevice>
#include<QTextStream>
#include<QHostInfo>
#include"widget.h"

namespace Ui {
class log_in;
}

class log_in : public QWidget
{
    Q_OBJECT

public:
    explicit log_in(QWidget *parent = 0);
    void StartLogin();
    void StartMain();
    void StartRegister();
    void QuitRegister();
    ~log_in();

private slots:

    void on_btnlogin_clicked();

    void on_btnregister_clicked();

private:
    Ui::log_in *ui;
    QTcpSocket * tcpsocket;        //通信套接字
    Widget w;
    void SendToHost(QString);
    int blockSize;
};

#endif // LOG_IN_H
