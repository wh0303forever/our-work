#include "widget.h"
#include <QApplication>
#include"log_in.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
    log_in l;
    l.show();

    return a.exec();
}
