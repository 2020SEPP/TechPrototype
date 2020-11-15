#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>
#include <QScreen>
#include <QGuiApplication>
#include <QDebug>

#include "homepage.h"
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
    CodEditor *editor;
    HomePage *home;

private slots:
    void CodeEditor();
};
#endif // MAINWINDOW_H
