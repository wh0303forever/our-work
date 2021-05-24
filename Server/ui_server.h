/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QTextEdit *textEdit_linkshow;
    QTextEdit *textEdit_requireshow;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(1000, 700);
        textEdit_linkshow = new QTextEdit(Server);
        textEdit_linkshow->setObjectName(QStringLiteral("textEdit_linkshow"));
        textEdit_linkshow->setGeometry(QRect(10, 30, 971, 171));
        textEdit_requireshow = new QTextEdit(Server);
        textEdit_requireshow->setObjectName(QStringLiteral("textEdit_requireshow"));
        textEdit_requireshow->setGeometry(QRect(10, 240, 971, 251));
        label = new QLabel(Server);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 171, 16));
        label_2 = new QLabel(Server);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 220, 181, 16));
        label_3 = new QLabel(Server);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 530, 281, 101));
        label_4 = new QLabel(Server);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(321, 534, 271, 111));

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QWidget *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", Q_NULLPTR));
        label->setText(QApplication::translate("Server", "\345\256\242\346\210\267\347\253\257\350\277\236\346\216\245\346\230\276\347\244\272\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Server", "\350\257\267\346\261\202\346\230\276\347\244\272\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Server", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("Server", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
