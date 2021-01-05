#ifndef UNITTEST_H
#define UNITTEST_H
#include <QtTest>
#include <QObject>
#include "user.h"
#include "loginwidget.h"
#include "mainwindow.h"
#include "homepage.h"
class uniT:public QObject{
    Q_OBJECT
private slots:
    void _User();
    void _User_data();
    void _signinwidget_basic();
    void _signinwidget_basic_data();
    void _signinwidget_ui();
    void _signinwidget_ui_data();
    void _signinwidget_advance();
    void _signinwidget_advance_data();
private:
    User  user;
//    MainWindow w;
//    HomePage h;
//    LoginDialog login;




};

#endif // UNITTEST_H
