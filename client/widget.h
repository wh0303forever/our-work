#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QIcon>
#include<QPaintEvent>
#include<QPainter>
#include<QPixmap>
#include<QListWidgetItem>
#include<QMessageBox>
#include<QFileDialog>
#include<QInputDialog>
#include<QPushButton>
#include<QtNetwork>
#include<summary.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    void getport(int port)
    {
        this->now_port=port;          //aaaaa
    }

    void getip(QString ip)
    {
        this->now_ip=ip;
    }
    void getUser(QString name,QString pwd){
        username=name;
        password=pwd;
    }

    ~Widget();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    //void on_pushButton_11_clicked();

    //void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void ReadMessage();//接收并读取从服务器返回的信息

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void ShowParticular(QListWidgetItem*);//显示详细信息

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_31_clicked();

private:
    //以下为正在查看的信息相关
    int nowNumber;//此时正在查看的信息下标
    int nowclass;//此时正在查看的信息分类
    int likenum;//正在查看的信息点赞数量

    QPixmap image0;//用户头像

    Ui::Widget *ui;

    int blockSize;//用于接收数据时判断是否完全接收

    summary *summarypublished;//存储概览信息的数组，每次仅存储5项
    summary*p_message;//用户已经发布的信息
    int p_message_num;//已发布信息的数量

    void show_p_summary();//显示已发布的信息

    QString username;//储存用户名
    QString password;

    QString *images;//储存将要发布的图片

    int publish_image;//将要发布的图片数量

    QString message;//储存从服务器接收到的字符串

    void ShowSummary();//显示概览信息

    void RequireSummary();//请求概览信息

    QTcpSocket*TcpSocket;//通信

    void SendToHost(QString message);//向服务器发送信息

    void loadusername(QString usern);

    void topbuttonsetable();

    QString pixmapTostring( const QPixmap& pixmap )     //图片转string
    {
      QByteArray byte_array;
      QDataStream data_stream(&byte_array,QIODevice::WriteOnly);
      data_stream<<pixmap;
      QString res = QString::fromLocal8Bit(byte_array.toBase64());
      return res;
    }

    QPixmap stringtomap(QByteArray buf)      //字节流转换为图片
    {
        QPixmap pix;
        pix.loadFromData(buf);
        return pix;
    }

    QPixmap stringTopixmap( const QString& pic )//实现字符串到图片的转换
    {
      QByteArray byte_array = QByteArray::fromBase64(pic.toLocal8Bit());
      QPixmap pix;
      QDataStream data_stream(&byte_array,QIODevice::ReadOnly);
      data_stream>>pix;
      return pix;
    }

    int summary_num;  //存储的概览信息数量，此数据由服务器返回

    int symbol;
    //用于浏览概览信息翻页时区分是翻的那种类型的页面
    // 悬赏  表白  咨询  组队  拼团  招聘  广告  学习
    //  1     2    3    4     5    6     7    8

    int NowPage;    //记录一下现在是第几页

    bool releasing;//是否正在发布消息
    void whethersave();

    int now_port;            //aaaaa
    QString now_ip;


};

#endif // WIDGET_H
