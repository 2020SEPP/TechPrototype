#include "loginwidget.h"
#include <QBrush>
#include <QPalette>
#include <qpalette.h>
LoginDialog::LoginDialog()
{

}

LoginDialog::LoginDialog(int width,int height,QWidget *p){

    this->width=width;
    this->height=height;
    this->setWindowModality(Qt::ApplicationModal);
    this->setStyleSheet("border-image:url(:images/fyh.jpg)");
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    Region *Re= new Region(width,height,width/25);
    Re->mask(this);
    this->raise();

    QFont font;
    font.setWeight(30);
    font.setPixelSize(30);

    usrlabel = new QLabel(this);
    psdlabel= new QLabel(this);
    usrlabel->setFont(font);
    psdlabel->setFont(font);
    usrlabel->setAttribute(Qt::WA_TranslucentBackground, true);//透明
    usrlabel->setAlignment(Qt::AlignRight|Qt::AlignCenter);
    psdlabel->setAttribute(Qt::WA_TranslucentBackground,true);
    psdlabel->setAlignment(Qt::AlignRight|Qt::AlignCenter);
    usrlabel->setGeometry(1*width/20,height/5,width/5,height/10);
    psdlabel->setGeometry(1*width/20,2*height/5,width/5,height/10);
    usrlabel->setText("用户名:");
    psdlabel->setText("密码:");


    usrinput = new QLineEdit(this);
    psdinput =new QLineEdit(this);
    usrinput->setStyleSheet("QLineEdit{background:transparent;border-width:0;border-style:outset;}"
//                            "border-image:url(:/images/input.png)}"
                            );
    usrinput->setAttribute(Qt::WA_TranslucentBackground, true);
    usrinput->setGeometry(width/4,height/5,width*2/5,height/10);


}
