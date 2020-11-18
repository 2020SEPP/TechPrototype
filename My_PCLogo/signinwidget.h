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
#include "token.h"

class LoginDialog : public QDialog
{
    Q_OBJECT

private:
    int width;
    int height;
    bool SignUpMode=false;
    Window window;

    QLabel *usrlabel;
    QLabel *pwdlabel;
    QLabel *pholabel;
    LineEdit  *usrinput;
    LineEdit *pwdinput;
    LineEdit *phoneinput;
    QPushButton *login;
    QPushButton *quit;
    QPushButton *signup;
    SingleWidget *single;

    QLabel *Edit;

    HttpRequest http;

private slots:
    void loginClicked();
    void quitClicked();
    void signupClicked();

public:
    LoginDialog();
    LoginDialog(int widght,int height,QWidget *p);
    ~LoginDialog();

signals:
    void DialogResponse(User *);
};

#endif // LOGINWIDGET_H
