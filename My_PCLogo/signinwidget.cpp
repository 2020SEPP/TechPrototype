#include "signinwidget.h"
#include <QBrush>
#include <QPalette>
#include <qpalette.h>
#include <QtCore>
LoginDialog::LoginDialog()
{
}

LoginDialog::LoginDialog(int width,int height,QWidget *p){
    p->setVisible(1);
    this->width=width;
    this->height=height;
    this->setWindowModality(Qt::ApplicationModal);
//    this->setStyleSheet("QDialog{border-image:url(:images/bk.png)}");
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    Region *Re= new Region(width,height,width/25);
    Re->mask(this);
    this->raise();

    QFont font;
    font.setWeight(30);
    font.setPixelSize(30);

    usrlabel = new QLabel(this);
    psdlabel= new QLabel(this);
    login=new QPushButton(this);
    quit=new QPushButton(this);
    usrlabel->setFont(font);
    psdlabel->setFont(font);
    login->setGeometry(width/4,6*height/10,width/5,height/10);
    quit->setGeometry(11*width/20,6*height/10,width/5,height/10);
    usrlabel->setAttribute(Qt::WA_TranslucentBackground, true);//透明
    usrlabel->setAlignment(Qt::AlignCenter|Qt::AlignCenter);
    psdlabel->setAttribute(Qt::WA_TranslucentBackground,true);
    psdlabel->setAlignment(Qt::AlignCenter|Qt::AlignCenter);
    usrlabel->setGeometry(1*width/15,height/5,width/5,height/10);
    psdlabel->setGeometry(1*width/15,2*height/5,width/5,height/10);
    usrlabel->setText("用户名:");
    psdlabel->setText("密  码:");
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



void LoginDialog::loginClicked(){
    return;
}

void LoginDialog::quitClicked(){
    this->hide();
}

LoginDialog::~LoginDialog(){

}
