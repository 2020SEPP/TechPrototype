#include "userinfo.h"


UserInfo::UserInfo(QWidget *parent, int w, int h) : WIN_W(w/3), WIN_H(h)
{

    QFont font;
    font.setPixelSize(30);
    font.setWeight(30);
    this->setFont(font);
    this->setParent(parent);
    visible = false;
    this->setGeometry(0, 0, -WIN_W, WIN_H);
    this->w=new QWidget(this);
    this->w->lower();
    this->w->setGeometry(0,0, WIN_W, WIN_H);

    this->id=new QLabel(this->w);
    this->username=new QLabel(this->w);
    this->Vid=new QLabel(this->w);
    this->Vusername=new QLabel(this->w);
    this->phone=new QLabel(this->w);
    this->Vphone=new QLabel(this->w);

    id->setText("账号：");
    username->setText("用户名：");
    phone->setText("手机：");
    Vid->setText("的");
    Vusername->setText("***");
    Vphone->setText("*****");


    id->setAttribute(Qt::WA_TranslucentBackground, true);
    Vid->setAttribute(Qt::WA_TranslucentBackground, true);
    username->setAttribute(Qt::WA_TranslucentBackground, true);
    Vusername->setAttribute(Qt::WA_TranslucentBackground, true);
    phone->setAttribute(Qt::WA_TranslucentBackground, true);
    Vphone->setAttribute(Qt::WA_TranslucentBackground, true);
    username->setAlignment(Qt::AlignRight|Qt::AlignCenter);
    id->setAlignment(Qt::AlignRight|Qt::AlignCenter);
    phone->setAlignment(Qt::AlignRight|Qt::AlignCenter);
    Vusername->setAlignment(Qt::AlignCenter|Qt::AlignCenter);
    Vid->setAlignment(Qt::AlignCenter|Qt::AlignCenter);
    Vphone->setAlignment(Qt::AlignCenter|Qt::AlignCenter);

    id->setGeometry(WIN_W/5,WIN_H*5/10,WIN_W/4,WIN_H/15);
    username->setGeometry(WIN_W/5,WIN_H*6/10,WIN_W/4,WIN_H/15);
    phone->setGeometry(WIN_W/5,WIN_H*7/10,WIN_W/4,WIN_H/15);

    Vid->setGeometry(WIN_W/3,WIN_H*5/10,WIN_W/2,WIN_H/15);
    Vusername->setGeometry(WIN_W/3,WIN_H*6/10,WIN_W/2,WIN_H/15);
    Vphone->setGeometry(WIN_W/3,WIN_H*7/10,WIN_W/2,WIN_H/15);

    id->show();
    Vid->show();
    phone->show();
    Vphone->show();
    username->show();
    Vusername->show();

    this->w->show();
    this->w->raise();
    this->w->setStyleSheet("QWidget{border-image: url(:/images/sidenav.png);}");



}

void UserInfo::annimation()
{
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");

    animation->setDuration(100); //设置窗口进入的起始位置
    if (visible)
    {
        animation->setStartValue(QRect(0,0,WIN_W,WIN_H));
        animation->setEndValue(QRect(-WIN_W,0,WIN_W,WIN_H));
        animation->start();
    }
    else
    {
        animation->setStartValue(QRect(-WIN_W,0,WIN_W,WIN_H));
        animation->setEndValue(QRect(0,0,WIN_W,WIN_H));
        animation->start();
    }

    this->visible = !(this->visible);
    this->setWindowModality(Qt::ApplicationModal);
    qDebug()<<this->isVisible()<<123;

}

void UserInfo::setUser(User U){
    this->user=U;
}
