#ifndef SIGNINWIDGET_H
#define SIGNINWIDGET_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>

#include "window.h"
#include "region.h"

class LoginDialog : public QDialog
{
private:
    int width;
    int height;
    Window window;

    QLabel *usrlabel;
    QLabel *psdlabel;
    QLineEdit *usrinput;
    QLineEdit *psdinput;
//    QPushButton *login;
//    QPushButton *quit;
public:
    LoginDialog();
    LoginDialog(int widght,int height,QWidget *p);
};

#endif // SIGNINWIDGET_H
