#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QObject>
#include <QDialog>
#include <window.h>
#include <region.h>

class LoginDialog :public QDialog
{
private:
    int width;
    int height;
    Window window;
    Region *re;
public:
    LoginDialog();
    LoginDialog(int widght,int height,QWidget *p);
};

#endif // LOGINWIDGET_H
