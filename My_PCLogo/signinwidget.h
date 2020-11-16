#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include "window.h"
#include "region.h"
#include "singlewidget.h"
#include "LineEdit.h"
#include "HttpRequest.h"
#include "user.h"

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class LoginDialog : public QDialog
{
    Q_OBJECT

private:
    int width;
    int height;
    Window window;

    QLabel *usrlabel;
    QLabel *pwdlabel;
    LineEdit  *usrinput;
    QLineEdit *pwdinput;
    QPushButton *login;
    QPushButton *quit;
    SingleWidget *single;

    HttpRequest http;

private slots:
    void loginClicked();
    void quitClicked();

public:
    LoginDialog();
    LoginDialog(int widght,int height,QWidget *p);
    ~LoginDialog();

signals:
    void LoginResponse(bool);
};

#endif // LOGINWIDGET_H
