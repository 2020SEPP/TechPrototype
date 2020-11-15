#include "homepage.h"

HomePage::HomePage(QWidget *parent, int w, int h) : QWidget(parent), WIN_W(w), WIN_H(h)
{
    this->resize(WIN_W, WIN_H);
    this->setFocus();

    userinfoWidget = new userinfo(this, WIN_W, WIN_H);
    userinfoWidget->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    userinfoWidget->setStyleSheet("QWidget{ border :1px; border-image:url(:images/sidenav.png); }");

    logindialog = new LoginDialog(WIN_W/2, WIN_H*2/3, this);
    logindialog->setGeometry(WIN_W/4, WIN_H/6, WIN_W/2, WIN_H*2/3);

    line   = new QPushButton(this);
    text   = new QPushButton(this);
    solo   = new QPushButton(this);
    pk     = new QPushButton(this);
    avatar = new QPushButton(this);

    line->setGeometry(2*WIN_W/5, WIN_H/10, WIN_W/5, WIN_H/10);
    text->setGeometry(2*WIN_W/5, 3*WIN_H/10, WIN_W/5, WIN_H/10);
    solo->setGeometry(2*WIN_W/5, 5*WIN_H/10, WIN_W/5, WIN_H/10);
    pk->setGeometry(2*WIN_W/5, 7*WIN_H/10, WIN_W/5, WIN_H/10);
    avatar->setGeometry(1*WIN_W/10, 1*WIN_H/10, WIN_W/10, WIN_W/10);

    line->setText("命令行绘图");
    text->setText("命令文件绘图");
    pk->setText("PVP对战");
    solo->setText("SOLO");

    avatar->setStyleSheet("QPushButton {\
                            background-color: white;\
                            border-style: solid;\
                            border-width:1px;\
                            border-radius:" + QString::number(WIN_W/20) + ";\
                            border-color: red;\
                            border-image: url(:/images/log-green.png);\
                            }\
                            QPushButton:hover {\
                             border-image: url(:/images/log-yellow.png);\
                            }");

    line->setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:30px;}");
    text->setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:30px;}");
    pk->setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:30px;}");
    solo->setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:30px;}");

    avatar->setMask(QRegion(0,0,WIN_W/10,WIN_W/10,QRegion::Ellipse));

    line->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    text->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    pk->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    solo->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    avatar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

    line->setFlat(false);
    text->setFlat(false);
    pk->setFlat(false);
    solo->setFlat(1);

    line->stackUnder(userinfoWidget);
    text->stackUnder(userinfoWidget);
    pk->stackUnder(userinfoWidget);
    solo->stackUnder(userinfoWidget);

    connect(avatar,SIGNAL(clicked()),this,SLOT(avatarClicked()));
    connect(line, SIGNAL(clicked()), this, SLOT(lineClicked()));
    connect(text, SIGNAL(clicked()), this, SLOT(textClicked()));
    connect(solo,SIGNAL(clicked()),this,SLOT(soloClicked()));
    connect(pk,SIGNAL(clicked()),this,SLOT(pkPressed()));

    pk->show();
    line->show();
    text->show();
    solo->show();
    avatar->show();
    userinfoWidget->show();
}

HomePage::~HomePage()
{
}

void HomePage::avatarClicked(){
    userinfoWidget->annimation();
}

void HomePage::soloClicked(){
    logindialog->show();
}

void HomePage::pkPressed(){
    /* qDebug() << http.get(ADDR);

    qDebug() << http.post(ADDR + "/param?name=djw&pwd=250", "");

    QString json = "{\"name\": \"fyh\", \"pwd\": \"123\"}";

    qDebug() << qPrintable(json);

    qDebug() << http.post(ADDR + "/body", json);*/

    logindialog->show();
    return;
}

void HomePage::lineClicked()
{
    emit CommandLine();
}

void HomePage::textClicked()
{
    emit CodeEditor();
}
