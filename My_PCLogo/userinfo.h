#ifndef USERINFO_H
#define USERINFO_H

#include <QObject>
#include <QWidget>
#include <window.h>
class userinfo:public QWidget
{
private:
    int WIN_W;
    int WIN_H;
    bool visible;
public:
    userinfo(QWidget *Parent, int, int);
public slots:
    void annimation();
};

#endif // USERINFO_H
