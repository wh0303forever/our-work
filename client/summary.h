#ifndef SUMMARY_H
#define SUMMARY_H

#include<QString>
#include<QIcon>
#include<QImage>

class summary{
public:
    QString username;//用户名
    QString number;//编号
    QString text;//文本
    QString symbol;
    QIcon image;//头像
    summary();
    void load(QString un,QString number1,QString text1,QIcon image1);
};

#endif // SUMMARY_H
