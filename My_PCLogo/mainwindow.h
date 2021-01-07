#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>
#include <QScreen>
#include <QGuiApplication>
#include <QDebug>

#include "homepage.h"
#include "singlewidget.h"
#include "pvpwidget.h"
#include "window.h"
#include "userinfo.h"
#include "CmdFileWidget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
  public:
    friend class uniT;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() {}

  public:
    int WIN_W;
    int WIN_H;

  private:
    Window window;
    CmdFileWidget *cmdfile;
    SingleWidget *single;
    PvpWidget *pvp;
    HomePage *home;
    UserInfo *usrinfo;

  private slots:
    void CommandFile();
    void CommandLine();
    void PVP(int, int);
    void SwitchWidget(int);
};
#endif // MAINWINDOW_H
