#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <window.h>
#include <qpushbutton.h>
#include <userinfo.h>

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
    userinfo *userinfoWidget;
    Window window;
    QPushButton *solo;
    QPushButton *pk;
    QPushButton *avatar;
};
#endif // MAINWINDOW_H
