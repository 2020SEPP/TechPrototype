#include "window.h"
#include <QRect>
#include <QApplication>
#include <QDesktopWidget>
#include <qpropertyanimation.h>
Window::Window()
{
    QRect screenRect = QApplication::desktop()->screenGeometry();
    this->winWidth=screenRect.width();
    this->winHeight=screenRect.height();
}

