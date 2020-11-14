#include "userinfo.h"
#include <QPropertyAnimation>
#include <QDebug>

userinfo::userinfo(QWidget *parent)
{
    this->setFixedSize(window.winWidth/3,window.winHeight);
    this->setGeometry(-window.winWidth/3,0,window.winWidth/3,window.winHeight);
    this->setParent(parent);
    visible = false;
}

void userinfo::annimation(){
   qDebug()<<"1";
   QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");

   //设置窗口进入的起始位置
   animation->setDuration(100);
   if (this->visible)
   {
       animation->setStartValue(QRect(0,0,window.winWidth/3,window.winHeight));
       animation->setEndValue(QRect(-window.winWidth/3,0,window.winWidth/3,window.winHeight));
       animation->start();
   }
   else
   {
       animation->setStartValue(QRect(-window.winWidth/3,0,window.winWidth/3,window.winHeight));
       animation->setEndValue(QRect(0,0,window.winWidth/3,window.winHeight));
       //选择特效
       //        animation->setEasingCurve(QEasingCurve::OutBounce);
       //开始播放特效
       animation->start();
   }

   this->visible = !(this->visible);
   this->setWindowModality(Qt::ApplicationModal);
}
