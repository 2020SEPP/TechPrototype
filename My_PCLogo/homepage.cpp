#include "homepage.h"
#include <QtGlobal>
#include <qdebug.h>

HomePage::HomePage(QWidget *parent) : QWidget(parent)
{
    WIN_W = window.getW();
    WIN_H = window.getH();

    this->resize(WIN_W, WIN_H);
    this->setFocus();



    usrinfo = new UserInfo(this,WIN_W,WIN_H);
    logindialog = new LoginDialog(WIN_W/2, WIN_H*2/3, this);
    logindialog->setGeometry(WIN_W/4, WIN_H/6, WIN_W/2, WIN_H*2/3);

    line   = new QPushButton(this);
    text   = new QPushButton(this);
    pvp    = new QPushButton(this);
    avatar = new QPushButton(this);

    line->setGeometry(2*WIN_W/5, 3*WIN_H/10, WIN_W/5, WIN_H/10);
    text->setGeometry(2*WIN_W/5, 5*WIN_H/10, WIN_W/5, WIN_H/10);
    pvp->setGeometry(2*WIN_W/5, 7*WIN_H/10, WIN_W/5, WIN_H/10);
    avatar->setGeometry(1*WIN_W/10, 1*WIN_H/10, WIN_W/10, WIN_W/10);

    line->setText("命令行绘图");
    text->setText("命令文件绘图");
    pvp->setText("PVP对战");

    avatar->setStyleSheet("QPushButton {"
                          "background-color: white;"
                          "border-style: solid;"
                          "border-width:1px;"
                          "border-radius:" + QString::number(WIN_W/20) +
                          ";"
                          "border-color: red;"
                          "border-image: url(:/images/log-green.png);"
                          "}"
                          "QPushButton:hover {"
                          "border-image: url(:/images/log-yellow.png);"
                          "}");

    line->setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:30px;}");
    text->setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:30px;}");
    pvp->setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:30px;}");

    avatar->setMask(QRegion(0,0,WIN_W/10,WIN_W/10,QRegion::Ellipse));

    line->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    text->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    pvp->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    avatar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

    line->setFlat(false);
    text->setFlat(false);
    pvp->setFlat(false);

    line->stackUnder(usrinfo);
    text->stackUnder(usrinfo);
    pvp->stackUnder(usrinfo);

    connect(avatar,SIGNAL(clicked()),this,SLOT(avatarClicked()));
    connect(line, SIGNAL(clicked()), this, SLOT(lineClicked()));
    connect(text, SIGNAL(clicked()), this, SLOT(textClicked()));
    connect(pvp, SIGNAL(clicked()), this, SLOT(pvpPressed()));
    connect(logindialog, SIGNAL(LoginResponse(bool)), this, SLOT(dialogResponse(bool)));

    pvp->show();
    line->show();
    text->show();
    avatar->show();
    usrinfo->show();
}

void HomePage::avatarClicked()
{
    if(logined)
    usrinfo->annimation();
    else logindialog->show();
    this->logined=!this->logined;
    return ;
}


void HomePage::pvpPressed()
{
    if (logined) {
        emit PVPMode();
    } else {
        logindialog->show();
    }
}

void HomePage::dialogResponse(bool res)
{
    qDebug() << res;
    if (res)
    {
        emit PVPMode();
    }

    logindialog->hide();
}

void HomePage::lineClicked()
{
    emit CommandLine();
}

void HomePage::textClicked()
{
    emit CommandFile();
}
