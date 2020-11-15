#ifndef SIGNINWIDGET_H
#define SIGNINWIDGET_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class LoginDialog : public QDialog
{
private:
    int width;
    int height;

    QLabel *usrlabel;
    QLabel *psdlabel;
    QLineEdit *usrinput;
    QLineEdit *psdinput;
    QPushButton *login;
    QPushButton *quit;

public:
    LoginDialog();
    LoginDialog(int widght,int height,QWidget *p);
    ~LoginDialog() {}

private slots:
    void loginClicked();
    void quitClicked();
};

#endif // SIGNINWIDGET_H
