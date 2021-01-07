#include "qlistwidgetitem.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QPushButton>
#include "token.h"

ListWidgetItem::ListWidgetItem(QWidget *p): QWidget(p) {
    QHBoxLayout *mlayout = new QHBoxLayout(this);
    QLabel *ava = new QLabel(this);
    QPushButton *add = new QPushButton(this);
    ava->setStyleSheet("QLabel{background:rgb(255,0,0)}");
    ava->setFixedSize(50, 50);
    ava->setMask(QRegion(0, 0, 50, 50, QRegion::Ellipse));
    add->setFixedSize(50, 50);
    add->setStyleSheet("QPushButton{"
                       "border:0px;"
                       "text-size:10px;"
                       "border-image:url(:/images/image/invite.png)"
                       "}");
    add->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    QLabel *name = new QLabel(this);
    name->setFixedSize(150, 50);
    mlayout->addWidget(ava);
    mlayout->addWidget(name);
    mlayout->addWidget(add);
    mlayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(mlayout);
    this->setStyleSheet("QWidget{"
                        "background:rgba(255,255,255,0.3)"
                        "}"
                        "QWidget:hover{"
                        "background:rgba(255,255,255,0.6)"
                        "}");
}

ListWidgetItem::ListWidgetItem(User *u, QWidget *p): QWidget(p) {
    this->user = *u;
    QHBoxLayout *mlayout = new QHBoxLayout(this);
    QLabel *ava = new QLabel;
    QPushButton *add = new QPushButton;
    ava->setStyleSheet("QLabel{background:rgba(255,255,255,0.3)}");
    ava->setFixedSize(50, 50);
    ava->setMask(QRegion(0, 0, 50, 50, QRegion::Ellipse));
    add->setFixedSize(50, 50);
    add->setStyleSheet("QPushButton{"
                       "border:0px;"
                       "background:rgba(255,255,255,0.3);"
                       "border-image:url(:/images/image/invite.png)"
                       "}");
    QPixmap avat;
    avat.load(":/images/image/avatar/" + getAvatarByName(u->getName()));
    avat = avat.scaled(50, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ava->setPixmap(avat);
    QLabel *name = new QLabel(this);
    name->setStyleSheet("QLabel{background:rgba(0,0,0,0);"
                        "font-weight:bold;"
                        "font-size:30px;"
                        "}");
    name->setAlignment(Qt::AlignCenter);
    name->setFixedSize(200, 50);
    name->setText(u->getName());
    mlayout->addWidget(ava);
    mlayout->addWidget(name);
    mlayout->addWidget(add);
    mlayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(mlayout);
    this->setStyleSheet("QWidget{"
                        "background:rgba(255,255,255,0.3)"
                        "}"
                        "QWidget:hover{"
                        "background:rgba(255,255,255,0.6)"
                        "}");
    add->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    connect(add, SIGNAL(clicked()), this, SLOT(addClicked()));
}

ListWidgetItem::ListWidgetItem(User *u, int flag, QWidget *p): QWidget(p) {
    this->user = *u;
    QHBoxLayout *mlayout = new QHBoxLayout(this);
    QLabel *ava = new QLabel;
    ava->setStyleSheet("QLabel{background:rgba(255,255,255,0.3)}");
    ava->setFixedSize(50, 50);
    ava->setMask(QRegion(0, 0, 50, 50, QRegion::Ellipse));
    QPixmap avat;
    avat.load(":/images/image/avatar/" + getAvatarByName(u->getName()));
    avat = avat.scaled(50, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ava->setPixmap(avat);
    QLabel *name = new QLabel(this);
    name->setStyleSheet("QLabel{background:rgba(0,0,0,0);"
                        "font-weight:bold;"
                        "font-size:30px;"
                        "}");
    name->setAlignment(Qt::AlignCenter);
    name->setFixedSize(200, 50);
    name->setText(u->getName());
    mlayout->addWidget(ava);
    mlayout->addWidget(name);
    // flag: 0 添加好友按钮; 1 无按钮; 2 邀请的接受和拒绝按钮
    if (flag == 0) {
        QPushButton *add = new QPushButton;
        add->setFixedSize(50, 50);
        add->setStyleSheet("QPushButton{"
                           "border:0px;"
                           "background:rgba(255,255,255,0.3);"
                           "border-image:url(:/images/image/invite.png)"
                           "}");
        mlayout->addWidget(add);
        add->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        connect(add, SIGNAL(clicked()), this, SLOT(addClicked()));
    } else if (flag == 2) {
        QPushButton *accept = new QPushButton;
        accept->setFixedSize(50, 50);
        accept->setStyleSheet("QPushButton{"
                              "border:0px;"
                              "background:rgba(255,255,255,0.3);"
                              "border-image:url(:/images/image/accept.png)"
                              "}");
        mlayout->addWidget(accept);
        accept->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        connect(accept, SIGNAL(clicked()), this, SLOT(acceptClicked()));
        QPushButton *reject = new QPushButton;
        reject->setFixedSize(50, 50);
        reject->setStyleSheet("QPushButton{"
                              "border:0px;"
                              "background:rgba(255,255,255,0.3);"
                              "border-image:url(:/images/image/reject.png)"
                              "}");
        mlayout->addWidget(reject);
        reject->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        connect(reject, SIGNAL(clicked()), this, SLOT(rejectClicked()));
    }
    mlayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(mlayout);
    this->setStyleSheet("QWidget{"
                        "background:rgba(255,255,255,0.3)"
                        "}"
                        "QWidget:hover{"
                        "background:rgba(255,255,255,0.6)"
                        "}");
}

void ListWidgetItem::addClicked() {
    HttpRequest *http = new HttpRequest(token);
    QString url = ADDR + "/user/sendInvite?uid=" + QString::number(ID) + "&touid=" + QString::number(user.getId());
    http->get(url);
    delete http;
}

void ListWidgetItem::acceptClicked() {
    HttpRequest *http = new HttpRequest(token);
    QString url = ADDR + "/user/acceptInvite?uid=" + QString::number(ID)
                  + "&auid=" + QString::number(user.getId())
                  + "&accept=" + QString::number(1);
    http->get(url);
    delete http;
}

void ListWidgetItem::rejectClicked() {
    HttpRequest *http = new HttpRequest(token);
    QString url = ADDR + "/user/acceptInvite?uid=" + QString::number(ID)
                  + "&auid=" + QString::number(user.getId())
                  + "&accept=" + QString::number(0);
    http->get(url);
    delete http;
}
