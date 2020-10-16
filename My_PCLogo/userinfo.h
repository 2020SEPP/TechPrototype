#ifndef USERINFO_H
#define USERINFO_H

#include <QObject>
#include <QWidget>
#include <window.h>
class userinfo:public QWidget
{
private:
    Window window;
    int height;
    int width;
    bool visible;
public:
    userinfo(QWidget *Parent);
public slots:
    void annimation();
};

#endif // USERINFO_H
