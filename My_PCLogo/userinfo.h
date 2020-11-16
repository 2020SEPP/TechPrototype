#ifndef USERINFO_H
#define USERINFO_H

#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QPropertyAnimation>
#include "window.h"

class UserInfo : public QWidget
{
    Q_OBJECT
private:
    Window window;
    int WIN_W;
    int WIN_H;
    bool visible;

public:
    explicit UserInfo(QWidget *parent = nullptr);
    UserInfo(QWidget *, int, int);
    ~UserInfo() {}
public slots:
    void annimation();
};

#endif // USERINFO_H
