#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QObject>
#include <QDialog>
#include <window.h>
#include <region.h>
#include <QLabel>
#include <QLineEdit>
#include <lineedit_my.h>

class LoginDialog :public QDialog
{
private:
    int width;
    int height;
    Window window;

    QLabel *usrlabel;
    QLabel *psdlabel;
    LineEdit  *usrinput;
    QLineEdit *psdinput;
//    QPushButton *login;
//    QPushButton *quit;
public:
    LoginDialog();
    LoginDialog(int widght,int height,QWidget *p);
};

#endif // LOGINWIDGET_H
