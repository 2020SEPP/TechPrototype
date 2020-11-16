#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QRect>
#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>
#include <QPropertyAnimation>

class Window
{
private:
//    bool visible;
    int winWidth;
    int winHeight;

public:
    Window() {
//        QScreen *screen = QGuiApplication::primaryScreen();
//        QRect mm = screen->availableGeometry() ;
//        winWidth = mm.width();
//        winHeight = mm.height();
        QRect screenRect = QApplication::desktop()->screenGeometry();
        winWidth = screenRect.width();
        winHeight = screenRect.height();
    }
    ~Window() {}

    int getW() { return winWidth; }
    int getH() { return winHeight; }
};

#endif // WINDOW_H
