/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_release;
    QTextEdit *textEdit_publish;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_4;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QWidget *page_glance;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QStackedWidget *stackedWidget_3;
    QWidget *page_3;
    QWidget *page_4;
    QListWidget *listWidget_glance;
    QWidget *page_message;
    QListWidget *listWidget_message;
    QPushButton *pushButton_31;
    QWidget *page_personal;
    QLabel *label_5;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QLabel *label_7;
    QStackedWidget *stackedWidget_2;
    QWidget *page;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *line_7;
    QPushButton *pushButton_24;
    QFrame *line;
    QPushButton *pushButton_26;
    QFrame *line_2;
    QPushButton *pushButton_25;
    QFrame *line_3;
    QPushButton *pushButton_23;
    QFrame *line_4;
    QPushButton *pushButton_22;
    QFrame *line_6;
    QPushButton *pushButton_21;
    QFrame *line_5;
    QWidget *page_6;
    QLabel *label_13;
    QLineEdit *lineEdit_old;
    QLabel *label_14;
    QLineEdit *lineEdit_new1;
    QLabel *label_15;
    QLineEdit *lineEdit_new2;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLabel *label_16;
    QWidget *page_2;
    QListWidget *listWidget;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_19;
    QPushButton *pushButton_18;
    QWidget *page_comment;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QWidget *page_particular;
    QLabel *label_9;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_11;
    QLabel *label_10;
    QFrame *frame_2;
    QPushButton *pushButton_20;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QLabel *label_12;
    QLabel *label_text;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_image1;
    QLabel *label_image2;
    QLabel *label_image3;
    QListWidget *listWidget_2;
    QWidget *page_5;
    QLabel *label_8;
    QFrame *frame;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        Widget->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 800, 540));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page_release = new QWidget();
        page_release->setObjectName(QStringLiteral("page_release"));
        textEdit_publish = new QTextEdit(page_release);
        textEdit_publish->setObjectName(QStringLiteral("textEdit_publish"));
        textEdit_publish->setGeometry(QRect(10, 20, 781, 281));
        horizontalLayoutWidget_2 = new QWidget(page_release);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 320, 551, 191));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(page_release);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(650, 340, 131, 22));
        label_4 = new QLabel(page_release);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(650, 320, 111, 16));
        pushButton_15 = new QPushButton(page_release);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(650, 370, 131, 28));
        pushButton_16 = new QPushButton(page_release);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(650, 410, 131, 28));
        pushButton_17 = new QPushButton(page_release);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(650, 450, 131, 28));
        stackedWidget->addWidget(page_release);
        page_glance = new QWidget();
        page_glance->setObjectName(QStringLiteral("page_glance"));
        horizontalLayoutWidget = new QWidget(page_glance);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 781, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_8 = new QPushButton(horizontalLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        horizontalLayout->addWidget(pushButton_8);

        pushButton_7 = new QPushButton(horizontalLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(horizontalLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(horizontalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(horizontalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        stackedWidget_3 = new QStackedWidget(page_glance);
        stackedWidget_3->setObjectName(QStringLiteral("stackedWidget_3"));
        stackedWidget_3->setGeometry(QRect(10, 50, 781, 481));
        stackedWidget_3->setStyleSheet(QStringLiteral(""));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        stackedWidget_3->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        listWidget_glance = new QListWidget(page_4);
        listWidget_glance->setObjectName(QStringLiteral("listWidget_glance"));
        listWidget_glance->setGeometry(QRect(0, 0, 781, 481));
        listWidget_glance->setStyleSheet(QLatin1String("background-color: rgb(240, 240, 240);\n"
"border-color: rgb(240, 240, 240);"));
        stackedWidget_3->addWidget(page_4);
        stackedWidget->addWidget(page_glance);
        page_message = new QWidget();
        page_message->setObjectName(QStringLiteral("page_message"));
        listWidget_message = new QListWidget(page_message);
        listWidget_message->setObjectName(QStringLiteral("listWidget_message"));
        listWidget_message->setGeometry(QRect(10, 20, 781, 461));
        pushButton_31 = new QPushButton(page_message);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));
        pushButton_31->setGeometry(QRect(680, 500, 93, 28));
        stackedWidget->addWidget(page_message);
        page_personal = new QWidget();
        page_personal->setObjectName(QStringLiteral("page_personal"));
        label_5 = new QLabel(page_personal);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 100, 100));
        verticalLayoutWidget = new QWidget(page_personal);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(150, 10, 271, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        stackedWidget_2 = new QStackedWidget(page_personal);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(10, 180, 771, 341));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        stackedWidget_2->setFont(font);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayoutWidget_2 = new QWidget(page);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 231, 331));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        line_7 = new QFrame(verticalLayoutWidget_2);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_7);

        pushButton_24 = new QPushButton(verticalLayoutWidget_2);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));

        verticalLayout_2->addWidget(pushButton_24);

        line = new QFrame(verticalLayoutWidget_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        pushButton_26 = new QPushButton(verticalLayoutWidget_2);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));

        verticalLayout_2->addWidget(pushButton_26);

        line_2 = new QFrame(verticalLayoutWidget_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        pushButton_25 = new QPushButton(verticalLayoutWidget_2);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));

        verticalLayout_2->addWidget(pushButton_25);

        line_3 = new QFrame(verticalLayoutWidget_2);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        pushButton_23 = new QPushButton(verticalLayoutWidget_2);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));

        verticalLayout_2->addWidget(pushButton_23);

        line_4 = new QFrame(verticalLayoutWidget_2);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_4);

        pushButton_22 = new QPushButton(verticalLayoutWidget_2);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));

        verticalLayout_2->addWidget(pushButton_22);

        line_6 = new QFrame(verticalLayoutWidget_2);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_6);

        pushButton_21 = new QPushButton(verticalLayoutWidget_2);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));

        verticalLayout_2->addWidget(pushButton_21);

        line_5 = new QFrame(verticalLayoutWidget_2);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_5);

        stackedWidget_2->addWidget(page);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        label_13 = new QLabel(page_6);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(50, 50, 91, 31));
        label_13->setFont(font);
        lineEdit_old = new QLineEdit(page_6);
        lineEdit_old->setObjectName(QStringLiteral("lineEdit_old"));
        lineEdit_old->setGeometry(QRect(160, 50, 300, 30));
        label_14 = new QLabel(page_6);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(50, 120, 72, 15));
        lineEdit_new1 = new QLineEdit(page_6);
        lineEdit_new1->setObjectName(QStringLiteral("lineEdit_new1"));
        lineEdit_new1->setGeometry(QRect(160, 110, 300, 30));
        label_15 = new QLabel(page_6);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 170, 131, 16));
        lineEdit_new2 = new QLineEdit(page_6);
        lineEdit_new2->setObjectName(QStringLiteral("lineEdit_new2"));
        lineEdit_new2->setGeometry(QRect(160, 160, 300, 30));
        pushButton_11 = new QPushButton(page_6);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(640, 280, 93, 28));
        pushButton_12 = new QPushButton(page_6);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(510, 280, 93, 28));
        label_16 = new QLabel(page_6);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(470, 120, 221, 16));
        stackedWidget_2->addWidget(page_6);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        listWidget = new QListWidget(page_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 771, 341));
        listWidget->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        stackedWidget_2->addWidget(page_2);
        horizontalLayoutWidget_3 = new QWidget(page_personal);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 140, 781, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_19 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));

        horizontalLayout_3->addWidget(pushButton_19);

        pushButton_18 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));

        horizontalLayout_3->addWidget(pushButton_18);

        stackedWidget->addWidget(page_personal);
        page_comment = new QWidget();
        page_comment->setObjectName(QStringLiteral("page_comment"));
        textEdit_2 = new QTextEdit(page_comment);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(20, 30, 761, 261));
        pushButton_29 = new QPushButton(page_comment);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));
        pushButton_29->setGeometry(QRect(662, 340, 111, 31));
        pushButton_30 = new QPushButton(page_comment);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));
        pushButton_30->setGeometry(QRect(662, 380, 111, 28));
        stackedWidget->addWidget(page_comment);
        page_particular = new QWidget();
        page_particular->setObjectName(QStringLiteral("page_particular"));
        label_9 = new QLabel(page_particular);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 60, 80, 80));
        verticalLayoutWidget_3 = new QWidget(page_particular);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(130, 60, 331, 81));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_3->addWidget(label_11);

        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_3->addWidget(label_10);

        frame_2 = new QFrame(page_particular);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 801, 41));
        frame_2->setStyleSheet(QStringLiteral("background-color: rgb(228, 244, 255);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        pushButton_20 = new QPushButton(frame_2);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(20, 10, 81, 28));
        pushButton_27 = new QPushButton(frame_2);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        pushButton_27->setGeometry(QRect(610, 10, 61, 28));
        pushButton_28 = new QPushButton(frame_2);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        pushButton_28->setGeometry(QRect(700, 10, 51, 28));
        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(430, 10, 161, 20));
        label_text = new QLabel(page_particular);
        label_text->setObjectName(QStringLiteral("label_text"));
        label_text->setGeometry(QRect(10, 150, 731, 21));
        horizontalLayoutWidget_4 = new QWidget(page_particular);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 280, 481, 131));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_image1 = new QLabel(horizontalLayoutWidget_4);
        label_image1->setObjectName(QStringLiteral("label_image1"));

        horizontalLayout_4->addWidget(label_image1);

        label_image2 = new QLabel(horizontalLayoutWidget_4);
        label_image2->setObjectName(QStringLiteral("label_image2"));

        horizontalLayout_4->addWidget(label_image2);

        label_image3 = new QLabel(horizontalLayoutWidget_4);
        label_image3->setObjectName(QStringLiteral("label_image3"));

        horizontalLayout_4->addWidget(label_image3);

        listWidget_2 = new QListWidget(page_particular);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(10, 420, 481, 118));
        listWidget_2->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        stackedWidget->addWidget(page_particular);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        label_8 = new QLabel(page_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(90, 250, 641, 61));
        label_8->setStyleSheet(QString::fromUtf8("font: 28pt \"\351\232\266\344\271\246\";"));
        stackedWidget->addWidget(page_5);
        frame = new QFrame(Widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 540, 800, 60));
        frame->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_9 = new QPushButton(frame);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(210, 10, 180, 40));
        pushButton_10 = new QPushButton(frame);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(10, 10, 180, 40));
        pushButton_13 = new QPushButton(frame);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(410, 10, 180, 40));
        pushButton_14 = new QPushButton(frame);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(610, 10, 180, 40));

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(2);
        stackedWidget_3->setCurrentIndex(1);
        stackedWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        textEdit_publish->setPlaceholderText(QApplication::translate("Widget", "\350\257\267\345\234\250\346\255\244\350\276\223\345\205\245\346\226\207\346\234\254", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "image1", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "image2", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "image3", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "\346\202\254\350\265\217", Q_NULLPTR)
         << QApplication::translate("Widget", "\350\241\250\347\231\275", Q_NULLPTR)
         << QApplication::translate("Widget", "\345\222\250\350\257\242", Q_NULLPTR)
         << QApplication::translate("Widget", "\347\273\204\351\230\237", Q_NULLPTR)
         << QApplication::translate("Widget", "\346\213\274\345\233\242", Q_NULLPTR)
         << QApplication::translate("Widget", "\346\213\233\350\201\230", Q_NULLPTR)
         << QApplication::translate("Widget", "\345\271\277\345\221\212", Q_NULLPTR)
         << QApplication::translate("Widget", "\345\255\246\344\271\240", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("Widget", "\351\200\211\346\213\251\345\210\206\345\214\272\357\274\232", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("Widget", "\346\267\273\345\212\240\345\233\276\347\211\207", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("Widget", "\347\241\256\350\256\244\345\217\221\345\270\203", Q_NULLPTR));
        pushButton_17->setText(QApplication::translate("Widget", "\345\217\226\346\266\210\345\217\221\345\270\203", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Widget", "\346\202\254\350\265\217", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Widget", "\350\241\250\347\231\275", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Widget", "\345\222\250\350\257\242", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Widget", "\347\273\204\351\230\237", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Widget", "\346\213\274\345\233\242", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Widget", "\346\213\233\350\201\230", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "\345\271\277\345\221\212", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "\345\255\246\344\271\240", Q_NULLPTR));
        pushButton_31->setText(QApplication::translate("Widget", "\345\210\240\351\231\244", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "image4", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_7->setText(QApplication::translate("Widget", "\346\230\265\347\247\260", Q_NULLPTR));
        pushButton_24->setText(QApplication::translate("Widget", "\344\270\212\344\274\240\345\244\264\345\203\217", Q_NULLPTR));
        pushButton_26->setText(QApplication::translate("Widget", "\346\233\264\346\224\271\346\200\247\345\210\253", Q_NULLPTR));
        pushButton_25->setText(QApplication::translate("Widget", "\346\233\264\346\224\271\346\230\265\347\247\260", Q_NULLPTR));
        pushButton_23->setText(QApplication::translate("Widget", "\346\233\264\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        pushButton_22->setText(QApplication::translate("Widget", "\346\233\264\346\224\271\344\270\223\344\270\232", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("Widget", "\346\237\245\347\234\213\350\265\204\346\226\231", Q_NULLPTR));
        label_13->setText(QApplication::translate("Widget", "\346\227\247\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("Widget", "\346\226\260\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_15->setText(QApplication::translate("Widget", "\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("Widget", "\347\241\256\350\256\244\344\277\256\346\224\271", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("Widget", "\345\217\226\346\266\210\344\277\256\346\224\271", Q_NULLPTR));
        label_16->setText(QApplication::translate("Widget", "8~16\344\275\215\344\273\273\346\204\217\345\255\227\347\254\246", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("Widget", "\344\270\252\344\272\272\344\277\241\346\201\257", Q_NULLPTR));
        pushButton_18->setText(QApplication::translate("Widget", "\345\267\262\345\217\221\345\270\203", Q_NULLPTR));
        textEdit_2->setPlaceholderText(QApplication::translate("Widget", "\350\257\267\345\234\250\346\255\244\350\276\223\345\205\245\350\257\204\350\256\272", Q_NULLPTR));
        pushButton_29->setText(QApplication::translate("Widget", "\345\217\226\346\266\210\345\217\221\345\270\203", Q_NULLPTR));
        pushButton_30->setText(QApplication::translate("Widget", "\347\241\256\350\256\244\345\217\221\345\270\203", Q_NULLPTR));
        label_9->setText(QApplication::translate("Widget", "image5", Q_NULLPTR));
        label_11->setText(QApplication::translate("Widget", "\346\230\265\347\247\260", Q_NULLPTR));
        label_10->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        pushButton_20->setText(QApplication::translate("Widget", "<<<", Q_NULLPTR));
        pushButton_27->setText(QApplication::translate("Widget", "\347\202\271\350\265\236", Q_NULLPTR));
        pushButton_28->setText(QApplication::translate("Widget", "\350\257\204\350\256\272", Q_NULLPTR));
        label_12->setText(QApplication::translate("Widget", "\346\234\21128\344\275\215\347\224\250\346\210\267\350\265\236\344\272\206\350\257\245\345\206\205\345\256\271", Q_NULLPTR));
        label_text->setText(QApplication::translate("Widget", "text", Q_NULLPTR));
        label_image1->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_image2->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_image3->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_8->setText(QApplication::translate("Widget", "\346\254\242\350\277\216\344\275\277\347\224\250\345\244\247\345\255\246\347\224\237\346\240\241\345\233\255\344\272\222\345\212\251\347\263\273\347\273\237", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("Widget", "\345\217\221\345\270\203\344\277\241\346\201\257", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("Widget", "\346\265\217\350\247\210\344\277\241\346\201\257", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("Widget", "\346\266\210\346\201\257", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("Widget", "\344\270\252\344\272\272\344\270\255\345\277\203", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
