#ifndef USERINFO_H
#define USERINFO_H

#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QPropertyAnimation>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include "window.h"
#include "user.h"
#include "friendList.h"

class UserInfo : public QWidget
{
    Q_OBJECT
private:
    Window window;
    int WIN_W;
    int WIN_H;
    bool visible;
    User user;
    QWidget *w;  //没有w会出大问题！！！！！！！！！！！！！！！！！
    QLabel  *id;
    QLabel *Vid;
    QLabel  *username;
    QLabel *Vusername;
    QLabel *phone;
    QLabel *Vphone;
    QLabel *exp;
    QLabel *Vexp;
    QPushButton *friendList;
    FriendList *fl;

public:
    void setUser(User U);
    UserInfo(QWidget *, int, int,User *U);
    ~UserInfo() {}
public slots:
    void annimation();
    void friendListClicked();
};

#endif // USERINFO_H
