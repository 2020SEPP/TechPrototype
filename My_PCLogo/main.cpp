#include "mainwindow.h"
#include <QFont>
#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int fontID = QFontDatabase::addApplicationFont(":/Font/newfont.ttf");
    QString msyh = QFontDatabase::applicationFontFamilies ( fontID ).at(0);
    QFont font(msyh);
    QApplication::setFont(font);

    MainWindow w;
    w.show();
    return a.exec();
}
