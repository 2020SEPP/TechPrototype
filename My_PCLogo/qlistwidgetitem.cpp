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
                       "border-image:url(:/images/image/turtle.png)"
                       "}");
    add->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    QLabel *name = new QLabel(this);
//    name->setStyleSheet("QLabel{background:rgb(255,244,0)}");
    name->setFixedSize(150, 50);
    mlayout->addWidget(ava);
    mlayout->addWidget(name);
    mlayout->addWidget(add);
    mlayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(mlayout);
    this-> setStyleSheet("QWidget{"
                         "background:rgba(255,255,255,0.3)"
                         "}"
                         "QWidget:hover{"
                         "background:rgba(255,255,255,0.6)"
                         "}");
}


ListWidgetItem::ListWidgetItem(User *u, QWidget *p ): QWidget(p) {
    this->user = *u;
    QHBoxLayout *mlayout = new QHBoxLayout(this);
    QLabel *ava = new QLabel;
    QPushButton *add = new QPushButton;;
    ava->setStyleSheet("QLabel{background:rgba(255,255,255,0.3)}");
    ava->setFixedSize(50, 50);
    ava->setMask(QRegion(0, 0, 50, 50, QRegion::Ellipse));
    add->setFixedSize(50, 50);
    add->setStyleSheet("QPushButton{"
                       "border:0px;"
                       "background:rgba(255,255,255,0.3);"
                       "border-image:url(:/images/image/turtle.png)"
                       "}");
    QPixmap avat;
    avat.loadFromData(QByteArray::fromBase64(u->getavatar().section(",", 1).toLocal8Bit()));
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
    this-> setStyleSheet("QWidget{"
                         "background:rgba(255,255,255,0.3)"
                         "}"
                         "QWidget:hover{"
                         "background:rgba(255,255,255,0.6)"
                         "}");
    add->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    connect(add, SIGNAL(clicked()), this, SLOT(addClicked()));
}


void ListWidgetItem::addClicked() {
    HttpRequest *http = new HttpRequest(token);
    QString url = ADDR + "/user/jiahaoyou?uid=" + QString::number(ID) + "&touid=" + QString::number(user.getId());
    QJsonObject res = http->get_json(url);
}
