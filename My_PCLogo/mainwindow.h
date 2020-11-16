#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>
#include <QScreen>
#include <QGuiApplication>
#include <QDebug>

#include "homepage.h"
#include "CodEditor.h"
#include "singlewidget.h"
#include "pvpwidget.h"
#include "window.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() {}

public:
    int WIN_W;
    int WIN_H;

private:
    Window window;
    CodEditor *editor;
    SingleWidget *single;
    PvpWidget *pvp;
    HomePage *home;

private slots:
    void CodeEditor();
    void CommandLine();
    void PVP();

    void SwitchWidget(int);
};
#endif // MAINWINDOW_H
