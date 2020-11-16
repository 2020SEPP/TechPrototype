#include "userinfo.h"

UserInfo::UserInfo(QWidget *parent) : QWidget(parent)
{
    WIN_W = window.getW();
    WIN_H = window.getH();
    visible = false;

    this->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    this->setGeometry(-WIN_W/3, 0, WIN_W/3, WIN_H);
}

UserInfo::UserInfo(QWidget *parent, int w, int h) : QWidget(parent), WIN_W(w), WIN_H(h)
{
    visible = false;

    this->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    this->setGeometry(-WIN_W/3, 0, WIN_W/3, WIN_H);
}

void UserInfo::annimation()
{
    qDebug() << 1;
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");

    animation->setDuration(100); //设置窗口进入的起始位置
    if (visible)
    {
        animation->setStartValue(QRect(0,0,WIN_W/3,WIN_H));
        animation->setEndValue(QRect(-WIN_W/3,0,WIN_W/3,WIN_H));
        animation->start();
    }
    else
    {
        animation->setStartValue(QRect(-WIN_W/3,0,WIN_W/3,WIN_H));
        animation->setEndValue(QRect(0,0,WIN_W/3,WIN_H));
//        animation->setEasingCurve(QEasingCurve::OutBounce);
        animation->start();
    }

    this->visible = !(this->visible);
    this->setWindowModality(Qt::ApplicationModal);
}
