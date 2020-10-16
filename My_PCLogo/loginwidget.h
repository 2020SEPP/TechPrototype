#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QObject>
#include <QWidget>

class LoginWidget :public QWidget
{
private:
    int width;
    int height;

public:
    LoginWidget();
    LoginWidget(int widght,int height,QWidget *p);
};

#endif // LOGINWIDGET_H
