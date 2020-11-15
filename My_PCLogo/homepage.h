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
#include "signinwidget.h"
#include "HttpRequest.h"

class HomePage : public QWidget
{
    Q_OBJECT

public:
    HomePage(QWidget *, int, int);
    ~HomePage();

public:
    int WIN_W;
    int WIN_H;

private:
    bool logined = false;
    userinfo *userinfoWidget;
    LoginDialog *logindialog;
    QPushButton *line;
    QPushButton *text;
    QPushButton *pvp;
    QPushButton *avatar;
    SingleWidget *single;

private slots:
    void avatarClicked();
    void pvpPressed();
    void dialogResponse(bool);
    void lineClicked();
    void textClicked();

signals:
    void CodeEditor();
    void CommandLine();
    void SingleMode();
    void PVPMode();
};

#endif // HOMEPAGE_H
