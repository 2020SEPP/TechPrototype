#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include <QPushButton>
#include <QRect>
#include <QScreen>
#include <QGuiApplication>
#include <QDebug>

#include "window.h"
#include "userinfo.h"
#include "loginwidget.h"
#include "matchwidget.h"
#include "HttpRequest.h"
#include "helpText.h"
class HomePage : public QWidget {
    Q_OBJECT
  private:
    friend class uniT;
    Window window;
    bool logined = false;

    UserInfo *usrinfo;
    LoginDialog *logindialog;
    MatchDialog *matchdialog;
    QPushButton *line;
    QPushButton *text;
    QPushButton *pvp;
    QPushButton *avatar;
    QPushButton *help;
    SingleWidget *single;
    QWidget *w;
    QLabel *ava_border;
    HelpText *helpText;
public:

    HomePage(QWidget *);
    ~HomePage() {}
    int WIN_W;
    int WIN_H;
    User *USER;
  private slots:
    void avatarClicked();
    void pvpPressed();
    void dialogResponse(User * u);
    void lineClicked();
    void textClicked();
    void helpClicked();

  signals:
    void CommandFile();
    void CommandLine();
    void SingleMode();
    void PVPMode();
};

#endif // HOMEPAGE_H
