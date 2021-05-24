/********************************************************************************
** Form generated from reading UI file 'log_in.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_IN_H
#define UI_LOG_IN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_log_in
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *editusername;
    QLineEdit *editpassword;
    QPushButton *btnlogin;
    QPushButton *btnregister;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *editip;
    QLineEdit *editport;
    QLabel *label_8;

    void setupUi(QWidget *log_in)
    {
        if (log_in->objectName().isEmpty())
            log_in->setObjectName(QStringLiteral("log_in"));
        log_in->resize(788, 511);
        label = new QLabel(log_in);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 10, 401, 91));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/name")));
        label->setScaledContents(true);
        label_2 = new QLabel(log_in);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(270, 110, 241, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(24);
        label_2->setFont(font);
        label_3 = new QLabel(log_in);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 200, 91, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(14);
        label_3->setFont(font1);
        label_4 = new QLabel(log_in);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 270, 91, 41));
        label_4->setFont(font1);
        editusername = new QLineEdit(log_in);
        editusername->setObjectName(QStringLiteral("editusername"));
        editusername->setGeometry(QRect(340, 210, 211, 31));
        editpassword = new QLineEdit(log_in);
        editpassword->setObjectName(QStringLiteral("editpassword"));
        editpassword->setGeometry(QRect(340, 280, 211, 31));
        btnlogin = new QPushButton(log_in);
        btnlogin->setObjectName(QStringLiteral("btnlogin"));
        btnlogin->setGeometry(QRect(330, 360, 111, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font2.setPointSize(14);
        btnlogin->setFont(font2);
        btnregister = new QPushButton(log_in);
        btnregister->setObjectName(QStringLiteral("btnregister"));
        btnregister->setGeometry(QRect(290, 420, 191, 31));
        label_5 = new QLabel(log_in);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(690, 420, 101, 91));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/symbol")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(log_in);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(600, 30, 41, 16));
        label_7 = new QLabel(log_in);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(600, 60, 41, 16));
        editip = new QLineEdit(log_in);
        editip->setObjectName(QStringLiteral("editip"));
        editip->setGeometry(QRect(670, 30, 113, 21));
        editport = new QLineEdit(log_in);
        editport->setObjectName(QStringLiteral("editport"));
        editport->setGeometry(QRect(670, 60, 113, 21));
        label_8 = new QLabel(log_in);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 490, 121, 16));

        retranslateUi(log_in);

        QMetaObject::connectSlotsByName(log_in);
    } // setupUi

    void retranslateUi(QWidget *log_in)
    {
        log_in->setWindowTitle(QApplication::translate("log_in", "Form", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("log_in", "\346\240\241\345\233\255\344\272\222\345\212\251\347\263\273\347\273\237", Q_NULLPTR));
        label_3->setText(QApplication::translate("log_in", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("log_in", "\345\257\206  \347\240\201\357\274\232", Q_NULLPTR));
        btnlogin->setText(QApplication::translate("log_in", "\347\231\273\345\275\225", Q_NULLPTR));
        btnregister->setText(QApplication::translate("log_in", "\350\277\230\346\262\241\350\264\246\345\217\267\357\274\237\347\202\271\346\210\221\345\277\253\351\200\237\346\263\250\345\206\214", Q_NULLPTR));
        label_5->setText(QString());
        label_6->setText(QApplication::translate("log_in", "IP:", Q_NULLPTR));
        label_7->setText(QApplication::translate("log_in", "Port\357\274\232", Q_NULLPTR));
        editip->setText(QApplication::translate("log_in", "127.0.0.1", Q_NULLPTR));
        editport->setText(QApplication::translate("log_in", "8888", Q_NULLPTR));
        label_8->setText(QApplication::translate("log_in", "@\351\243\237\345\240\202\344\270\211\346\245\274\345\222\226\345\225\241\347\273\204", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class log_in: public Ui_log_in {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_IN_H
