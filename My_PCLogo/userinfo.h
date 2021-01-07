#ifndef USERINFO_H
#define USERINFO_H

#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QPropertyAnimation>
#include <QDialog>
#include <QLabel>
#include <QTimer>
#include <QPushButton>
#include "window.h"
#include "user.h"
#include "friendList.h"

class UserInfo : public QWidget {
    Q_OBJECT
  private:
    friend class uniT;
    Window window;
    int WIN_W;
    int WIN_H;
    bool visible;
    User *user;
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
    QPushButton *inviteList;
    FriendList *fl;
    bool f, v;
    QTimer *timer;

  public:
    void setUser(User *U);
    UserInfo(QWidget *, int, int, User *U);
    void updateFL(int mode = 0) {
        fl->reset(mode);
    }
    ~UserInfo() {}
  public slots:
    void listen();
    void annimation();
    void friendListClicked();
    void inviteListClicked();
};

#endif // USERINFO_H
