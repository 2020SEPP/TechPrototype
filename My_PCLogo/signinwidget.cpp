#include "signinwidget.h"

#include <QBrush>
#include <QPalette>
#include <QtCore>

LoginDialog::LoginDialog()
{
}

LoginDialog::LoginDialog(int width, int height, QWidget *p)
{
    p->setVisible(0);
    this->setParent(p);
    this->setFocus();
    this->width=width;
    this->height=height;
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    Region *Re = new Region(width,height,width/25);
    Re->mask(this);
    this->raise();

    QFont font;
    font.setWeight(30);
    font.setPixelSize(30);

    usrlabel = new QLabel(this);
    pwdlabel = new QLabel(this);
    login    = new QPushButton(this);
    quit     = new QPushButton(this);

    usrlabel->setFont(font);
    pwdlabel->setFont(font);
    login->setGeometry(width/4,6*height/10,width/5,height/10);
    quit->setGeometry(11*width/20,6*height/10,width/5,height/10);
    usrlabel->setAttribute(Qt::WA_TranslucentBackground, true);//透明
    usrlabel->setAlignment(Qt::AlignCenter|Qt::AlignCenter);
    pwdlabel->setAttribute(Qt::WA_TranslucentBackground,true);
    pwdlabel->setAlignment(Qt::AlignCenter|Qt::AlignCenter);
    usrlabel->setGeometry(1*width/15,height/5,width/5,height/10);
    pwdlabel->setGeometry(1*width/15,2*height/5,width/5,height/10);
    usrlabel->setText("用户名:");
    pwdlabel->setText("密  码:");
    login->setText("登陆");
    quit->setText("返回");


    login->setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:20px;}");
    quit->setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:20px;}");


    usrinput = new LineEdit(this);
    pwdinput = new LineEdit(this);


    usrinput->setGeometry(width/4+50,height*13/60,width/2,height/15);
    usrinput->setFont(font);
    usrinput->setMaxLength(16);


    pwdinput->setGeometry(width/4+50,height*25/60,width/2,height/15);
    pwdinput->setFont(font);
    pwdinput->setMaxLength(16);
    pwdinput->setEchoMode(QLineEdit::Password);


    login->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    quit->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    login->setFont(font);
    quit->setFont(font);

    connect(login,SIGNAL(clicked()),this,SLOT(loginClicked()));
    connect(quit,SIGNAL(clicked()),this,SLOT(quitClicked()));
}



void LoginDialog::loginClicked()
{
    QString usr = usrinput->text();
    QString pwd = pwdinput->text();
    User user(usr, pwd);

    QString res = http.post(ADDR + "/login", user.toJsonObeject(false));

    qDebug() << res;
    emit LoginResponse(true);
}

void LoginDialog::quitClicked(){
    this->hide();
}

LoginDialog::~LoginDialog(){

}
