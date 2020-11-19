#include "friendList.h"
#include <QPropertyAnimation>
#include <QHBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <QListWidgetItem>
#include <QWidget>
#include <QDebug>
#include "qlistwidgetitem.h"
#include "token.h"
FriendList::FriendList(QWidget *p, int w, int h): QWidget(p), WIN_W(w), WIN_H(h / 3 * 2 - 50), p_H(h) {
    QWidget *bk = new QWidget(this);
    bk->setStyleSheet("QWidget {border-image:url(:/images/image/friend3.jpeg);}");
    bk->setGeometry(WIN_W / 20, 0, WIN_W / 20 * 18, WIN_H);
    bk->show();
    this->visible = false;
    this->setGeometry(0, p_H, WIN_W, WIN_H);
    this->friends = new QListWidget(this);
    friends->setStyleSheet("QWidget{ border-image:none}");
    sb = new Searchbar(this, WIN_H / 15, WIN_H / 15);
    sb->setStyleSheet("QLineEdit {border-image:url(:/images/image/input.png);}");
    sb->setGeometry(WIN_W / 10, WIN_H / 20, WIN_W / 10 * 8, WIN_H / 10);
    friends->setGeometry(WIN_W / 20, WIN_H / 6, WIN_W / 20 * 18, WIN_H / 30 * 22);
    friends->setStyleSheet("QWidget {border-image:url(:/images/image/space.png);}");
    friends->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    friends->show();
    reset();
    connect(sb, SIGNAL(Search(QString)), this, SLOT(search(QString)));
}

void FriendList::annimation() {
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(100); //设置窗口进入的起始位置
    if (visible) {
        animation->setStartValue(QRect(0, p_H - WIN_H - 15, WIN_W, WIN_H));
        animation->setEndValue(QRect(0, p_H, WIN_W, WIN_H));
        animation->start();
    } else {
        animation->setStartValue(QRect(0, p_H, WIN_W, WIN_H));
        animation->setEndValue(QRect(0, p_H - WIN_H - 15, WIN_W, WIN_H));
        animation->start();
    }
    this->visible = !(this->visible);
}


void FriendList::setFriends(QList<User> FL) {
    int n = FL.length();
    for(int i = 0; i < n; ++i) {
        if(FL[i].getName() == "") return;
        QListWidgetItem  *d = new QListWidgetItem(friends);
        d->setSizeHint(QSize(0, 60));
//        d->setFlags(d->flags()&~Qt::ItemIsSelectable);
        friends->addItem(d);
        friends->setItemWidget(d, new ListWidgetItem(&FL[i], friends));
    }
}

void FriendList:: search(QString s) {
    if(s == "") {
        this->reset();
        return ;
    }
    http = new HttpRequest(token);
    QString url = ADDR + "/user/searchByPhone?friendPhone=" + s;
    QJsonObject res = http->get_json(url);
    delete http;
    User *user = new User(res);
    QList<User> fl;
    fl.append(*user);
    this->friends->clear();
    this->setFriends(fl);
}

void FriendList::reset() {
    http = new HttpRequest(token);
    QString url = ADDR + "/user/getFriend?uid=" + QString::number(ID);
    QJsonArray res = http->get_array(url);
    delete http;
    QJsonObject qo;
    QList<User> fl;
    for(int i = 0; i < res.count(); ++i) {
        qo = res[i].toObject();
        User * user = new User(qo);
        fl.append(*user);
    }
    this->friends->clear();
    this->setFriends(fl);
}
