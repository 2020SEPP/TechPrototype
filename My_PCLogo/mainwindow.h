#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include "CodEditor.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    int WIN_W;
    int WIN_H;

private:
    void Window_Pixels_Init()
    {
        QScreen *screen = QGuiApplication::primaryScreen();
        QRect mm = screen->availableGeometry() ;
        WIN_W = mm.width();
        WIN_H = mm.height();
    }

private:
    HttpRequest http;
    userinfo *userinfoWidget;
    LoginDialog *logindialog;
//    Window window;
    CodEditor *editor;
    QPushButton *solo;
    QPushButton *pk;
    QPushButton *avatar;

private slots:
    void avatarClicked();
    void soloClicked();
    void pkPressed();
    void pkReleased();
};
#endif // MAINWINDOW_H
