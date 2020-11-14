#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "window.h"
#include "userinfo.h"
#include "signinwidget.h"
#include "HttpRequest.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void avatarClicked();
    void soloClicked();
    void pkPressed();
    void pkReleased();

private:
    HttpRequest http;
    userinfo *userinfoWidget;
    LoginDialog *logindialog;
    Window window;
    QPushButton *solo;
    QPushButton *pk;
    QPushButton *avatar;
};
#endif // MAINWINDOW_H
