#include "userinfo.h"
#include "token.h"

UserInfo::UserInfo(QWidget *parent, int w, int h, User *) : WIN_W(w / 10 * 3), WIN_H(h) {
    QFont font;
    font.setPixelSize(30);
    font.setWeight(30);
    this->setFont(font);
    this->setParent(parent);
//    this->setUser(U);
    visible = false;
    f = false;
    v = false;
    this->setGeometry(0, 0, -WIN_W, WIN_H);
    this->w = new QWidget(this);
    this->w->lower();
    this->w->setGeometry(0, 0, WIN_W, WIN_H);
    this->id = new QLabel(this->w);
    this->username = new QLabel(this->w);
    this->Vid = new QLabel(this->w);
    this->Vusername = new QLabel(this->w);
    this->phone = new QLabel(this->w);
    this->Vphone = new QLabel(this->w);
    this->friendList = new QPushButton(this->w);
    friendList->setGeometry(WIN_W / 15, WIN_H - WIN_W / 7, WIN_W / 10, WIN_W / 10);
    friendList->setMask(QRegion(0, 0, WIN_W / 10, WIN_W / 10, QRegion::Ellipse));
    friendList->setStyleSheet("QPushButton{border-image: url(:/images/image/friendlist.png);}");
    friendList->setCursor(Qt::PointingHandCursor);
    this->inviteList = new QPushButton(this->w);
    inviteList->setGeometry(WIN_W * 11 / 15, WIN_H - WIN_W / 7, WIN_W / 10, WIN_W / 10);
    inviteList->setMask(QRegion(0, 0, WIN_W / 10, WIN_W / 10, QRegion::Ellipse));
    inviteList->setStyleSheet("QPushButton{border-image: url(:/images/image/invitelist.png);}");
    inviteList->setCursor(Qt::PointingHandCursor);
    fl = new FriendList(this->w, WIN_W, WIN_H);
    fl->show();
    fl->stackUnder(inviteList);
    inviteList->stackUnder(friendList);
    id->setText("账 号：");
    username->setText("用户名：");
    phone->setText("手 机：");
    Vid->setText("-1");
    Vusername->setText("-1");
    Vphone->setText("-1");
    id->setAttribute(Qt::WA_TranslucentBackground, true);
    Vid->setAttribute(Qt::WA_TranslucentBackground, true);
    username->setAttribute(Qt::WA_TranslucentBackground, true);
    Vusername->setAttribute(Qt::WA_TranslucentBackground, true);
    phone->setAttribute(Qt::WA_TranslucentBackground, true);
    Vphone->setAttribute(Qt::WA_TranslucentBackground, true);
    username->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    id->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    phone->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    Vusername->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    Vid->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    Vphone->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    id->setGeometry(WIN_W / 5, WIN_H * 5 / 10, WIN_W / 4, WIN_H / 15);
    username->setGeometry(WIN_W / 5, WIN_H * 6 / 10, WIN_W / 4, WIN_H / 15);
    phone->setGeometry(WIN_W / 5, WIN_H * 7 / 10, WIN_W / 4, WIN_H / 15);
    Vid->setGeometry(WIN_W / 3, WIN_H * 5 / 10, WIN_W / 2, WIN_H / 15);
    Vusername->setGeometry(WIN_W / 3, WIN_H * 6 / 10, WIN_W / 2, WIN_H / 15);
    Vphone->setGeometry(WIN_W / 3, WIN_H * 7 / 10, WIN_W / 2, WIN_H / 15);
    id->show();
    Vid->show();
    phone->show();
    Vphone->show();
    username->show();
    Vusername->show();
    this->w->show();
    this->w->raise();
    this->w->setStyleSheet("QWidget{border-image: url(:/images/image/sidenav.png);}");
    this->fl->setStyleSheet("QWidget{border-image: url(:/images/image/sidenav.png);}");
    connect(friendList, SIGNAL(clicked()), this, SLOT(friendListClicked()));
    connect(inviteList, SIGNAL(clicked()), this, SLOT(inviteListClicked()));
}

void UserInfo::annimation() {
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(100);
    if (visible) {
        animation->setStartValue(QRect(0, 0, WIN_W, WIN_H));
        animation->setEndValue(QRect(-WIN_W, 0, WIN_W, WIN_H));
        animation->start();
    } else {
        animation->setStartValue(QRect(-WIN_W, 0, WIN_W, WIN_H));
        animation->setEndValue(QRect(0, 0, WIN_W, WIN_H));
        animation->start();
    }
    this->visible = !(this->visible);
    this->setWindowModality(Qt::ApplicationModal);
}

void UserInfo::setUser(User *U) {
    this->user = U;
    Vid->setText(QString::number(ID));
    this->Vusername->setText(U->getName());
    Vphone->setText(user->getPhone());
}

void UserInfo::friendListClicked() {
    updateFL(0);
    f = !f;
    if (f && v) {
        v = false;
        return;
    }
    this->fl->annimation();
    friendList->raise();
    inviteList->raise();
}

void UserInfo::inviteListClicked() {
    updateFL(1);
    v = !v;
    if (f && v) {
        f = false;
        return;
    }
    this->fl->annimation();
    friendList->raise();
    inviteList->raise();
}
