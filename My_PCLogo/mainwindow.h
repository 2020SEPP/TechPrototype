#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <window.h>
#include <qpushbutton.h>
#include <userinfo.h>
#include <loginwidget.h>
#include <painter.h>
class MainWindow : public QWidget
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
    userinfo *userinfoWidget;
    LoginDialog *logindialog;
    Window window;
    QPushButton *solo;
    QPushButton *pk;
    QPushButton *avatar;
    SingleWidget *single;
};
#endif // MAINWINDOW_H
