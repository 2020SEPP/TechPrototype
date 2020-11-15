#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QObject>
#include <QDialog>
#include <window.h>
#include <region.h>
#include <QLabel>
#include <QLineEdit>
#include <lineedit_my.h>
#include <painter.h>

class LoginDialog :public QDialog
{
    Q_OBJECT

private:
    int width;
    int height;
    Window window;

    QLabel *usrlabel;
    QLabel *psdlabel;
    LineEdit  *usrinput;
    QLineEdit *psdinput;
    QPushButton *login;
    QPushButton *quit;
    SingleWidget *single;
private slots:
    void loginClicked();
    void quitClicked();
public:
    LoginDialog();
    LoginDialog(int widght,int height,QWidget *p);
    ~LoginDialog();
};

#endif // LOGINWIDGET_H
