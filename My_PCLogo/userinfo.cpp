#include "userinfo.h"
#include <QPropertyAnimation>
#include <QDebug>

userinfo::userinfo(QWidget *parent, int w, int h)
{
    WIN_W = w;
    WIN_H = h;

    this->setFixedSize(WIN_W/3, WIN_H);
    this->setGeometry(-WIN_W/3, 0, WIN_W/3, WIN_H);
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
       animation->setStartValue(QRect(0,0,WIN_W/3,WIN_H));
       animation->setEndValue(QRect(-WIN_W/3,0,WIN_W/3,WIN_H));
       animation->start();
   }
   else
   {
       animation->setStartValue(QRect(-WIN_W/3,0,WIN_W/3,WIN_H));
       animation->setEndValue(QRect(0,0,WIN_W/3,WIN_H));
       //选择特效
       //        animation->setEasingCurve(QEasingCurve::OutBounce);
       //开始播放特效
       animation->start();
   }

   this->visible = !(this->visible);
   this->setWindowModality(Qt::ApplicationModal);
}
