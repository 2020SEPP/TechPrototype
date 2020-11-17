#include "qlistwidgetitem.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>
ListWidgetItem::ListWidgetItem(QWidget *p):QWidget(p)
{
    QHBoxLayout *mlayout=new QHBoxLayout(this);
    QLabel *ava=new QLabel(this);
    ava->setStyleSheet("QLabel{background:rgb(255,0,0)}");
    ava->setFixedSize(50,50);
    ava->setMask(QRegion(0,0,50,50,QRegion::Ellipse));
    QLabel *name=new QLabel(this);
    name->setStyleSheet("QLabel{background:rgb(255,244,0)}");
    name->setFixedSize(50,50);
    mlayout->addWidget(ava);
    mlayout->addWidget(name);
     mlayout->setContentsMargins(0,0,0,0);
    this->setLayout(mlayout);

    this-> setStyleSheet("QWidget{"
                        "background:rgba(255,255,255,0.3)"
                        "}"
                        "QWidget:hover{"
                        "background:rgba(255,255,255,0.6)"
                        "}");

}


ListWidgetItem::ListWidgetItem(User *u,QWidget *p ):QWidget(p)
{
    qDebug()<<u->getName();
    QHBoxLayout *mlayout=new QHBoxLayout(this);
    QLabel *ava=new QLabel(this);
    ava->setStyleSheet("QLabel{background:rgb(255,0,0)}");
    ava->setFixedSize(50,50);
    ava->setMask(QRegion(0,0,50,50,QRegion::Ellipse));
    QPixmap avat;
     avat.loadFromData(QByteArray::fromBase64(u->getavatar().section(",", 1).toLocal8Bit()));
     avat=avat.scaled(50,50,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
     ava->setPixmap(avat);
    QLabel *name=new QLabel(this);
    name->setStyleSheet("QLabel{background:rgb(255,244,0);"
                        "font-weight:bold;"
                        "font-size:30px;"
                        "}");
    name->setAlignment(Qt::AlignCenter);
    name->setFixedSize(200,50);
    name->setText(u->getName());

    mlayout->addWidget(ava);
    mlayout->addWidget(name);

     mlayout->setContentsMargins(0,0,0,0);
    this->setLayout(mlayout);
    this-> setStyleSheet("QWidget{"
                        "background:rgba(255,255,255,0.3)"
                        "}"
                        "QWidget:hover{"
                        "background:rgba(255,255,255,0.6)"
                        "}");
}
