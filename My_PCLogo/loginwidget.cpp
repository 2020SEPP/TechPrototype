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
    this->setStyleSheet("border-image:url(:images/fyh.jpg);border-radius:30px");
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    this->re= new Region(width,height,width/25,this);
    this->raise();
}
