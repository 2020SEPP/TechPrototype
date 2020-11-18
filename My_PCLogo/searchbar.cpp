#include "searchbar.h"
#include <QtDebug>
Searchbar::Searchbar(QWidget *p,int w,int h)
{
    this->setParent(p);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    QPushButton *searchBtn = new QPushButton;
    searchBtn->setFixedSize(w,h);
    searchBtn->setCursor(Qt::PointingHandCursor);
    searchBtn->setStyleSheet("QPushButton{border-image:url(:/images/image/f2.png);"
                             "background:transparent;cursor:pointer;}");
    setPlaceholderText(tr("搜索"));
    mainLayout->addWidget(searchBtn);
    mainLayout->addStretch();
    mainLayout->setContentsMargins(w/3,0,0,0);
    setTextMargins(80,0,0,0);
    QFont font ;
    font.setPixelSize(25);
    setFont(font);
    setLayout(mainLayout);
    setStyleSheet("height:"+QString::number(h-10)+
                  "px;border:none solid #eaeaea;");
    this->setAttribute(Qt::WA_MacShowFocusRect, 0);
    connect(searchBtn,SIGNAL(clicked()),this,SLOT(buttonclicked()));


}


void Searchbar::buttonclicked(){
    QString name = this->text();
    qDebug()<<name;
    emit Search(name);
}
