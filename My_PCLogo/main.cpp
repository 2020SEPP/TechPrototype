#include "mainwindow.h"
#include <QFont>
#include <QApplication>
#include <QFontDatabase>
#include <QDebug>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);


    int fontID=QFontDatabase::addApplicationFont(":/Font/newfont.ttf");
    qDebug() << "fontId = "<< fontID;
    QString msyh=QFontDatabase::applicationFontFamilies ( fontID ).at(0);
    qDebug() <<"msyh = " <<msyh;
    QFont font(msyh);
    QApplication::setFont(font);




    MainWindow w;
    w.show();
    return a.exec();
}
