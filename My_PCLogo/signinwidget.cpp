#include "signinwidget.h"
#include "Network.h"
#include "region.h"

#include <QBrush>
#include <QPalette>
#include <QtCore>

LoginDialog::LoginDialog()
{
}

LoginDialog::LoginDialog(int width, int height, QWidget *)
{
    this->width = width;
    this->height = height;
    this->setWindowModality(Qt::ApplicationModal);
    this->setStyleSheet("QDialog{border-image:url(:images/bk.png)}");
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    Region *Re= new Region(width,height,width/25);
    Re->mask(this);
    this->raise();

    QFont font;
    font.setWeight(30);
    font.setPixelSize(30);

    usrlabel = new QLabel(this);
    psdlabel = new QLabel(this);
    usrlabel->setFont(font);
    psdlabel->setFont(font);
    usrlabel->setAttribute(Qt::WA_TranslucentBackground, true);//透明
    usrlabel->setAlignment(Qt::AlignCenter|Qt::AlignCenter);
    psdlabel->setAttribute(Qt::WA_TranslucentBackground,true);
    psdlabel->setAlignment(Qt::AlignCenter|Qt::AlignCenter);
    usrlabel->setGeometry(1*width/15,height/5,width/5,height/10);
    psdlabel->setGeometry(1*width/15,2*height/5,width/5,height/10);
    usrlabel->setText("用户名:");
    psdlabel->setText("密码:");


    usrinput = new QLineEdit(this);
    psdinput = new QLineEdit(this);
    usrinput->setStyleSheet(
                            "QLineEdit{border-image:url(:/images/input.png);background:rgb(0,255,255);padding-left:30px}"
                            );
    usrinput->setGeometry(width/4+50,height*13/60,width/2,height/15);
    usrinput->setAttribute(Qt::WA_MacShowFocusRect, 0);
    usrinput->setFont(font);
    usrinput->setMaxLength(16);

    psdinput->setStyleSheet(
                            "QLineEdit{border-image:url(:/images/input.png);background:rgb(0,255,255);padding-left:30px;}"
                            );
    psdinput->setAttribute(Qt::WA_MacShowFocusRect, 0);
    psdinput->setGeometry(width/4+50,height*25/60,width/2,height/15);
    psdinput->setFont(font);
    psdinput->setMaxLength(16);

//    login = new QPushButton(this);

//    login->setGeometry(width/2 - 100, height*2/3, 200, 50);

//    login->setText("登录");

//    login->setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:30px;}");

//    login->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

//    login->setFlat(1);

//    connect(login,SIGNAL(clicked()),this,SLOT(loginClicked()));

//    login->show();

    login->setText("登陆");
    quit->setText("返回");


    login-> setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:20px;}");
    quit-> setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:20px;}");


    usrinput = new LineEdit(this);
    psdinput =new LineEdit(this);



    usrinput->setGeometry(width/4+50,height*13/60,width/2,height/15);
    usrinput->setFont(font);
    usrinput->setMaxLength(16);


    psdinput->setGeometry(width/4+50,height*25/60,width/2,height/15);
    psdinput->setFont(font);
    psdinput->setMaxLength(16);
    psdinput->setEchoMode(QLineEdit::Password);

    connect(login,SIGNAL(clicked()),this,SLOT(loginClicked()));
    connect(quit,SIGNAL(clicked()),this,SLOT(quitClicked()));
    login   ->   setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    quit ->   setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    login->setFont(font);
    quit->setFont(font);
}
