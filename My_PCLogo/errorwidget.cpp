#include "errorwidget.h"

#include <QBrush>
#include <QPalette>
#include <QtCore>

ErrorDialog::ErrorDialog() {
}

ErrorDialog::ErrorDialog(int width, int height, QWidget *p) : QDialog(p) {
    this->setStyleSheet("QDialog{border-image:url(:/images/image/login2.png)}");
    this->setFocus();
    this->width = width;
    this->height = height;
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    Region *Re = new Region(width, height, width / 25);
    Re->mask(this);
    this->raise();
    QFont font;
    font.setWeight(40);
    font.setPixelSize(40);
    QFont font1;
    font1.setWeight(70);
    font1.setPixelSize(70);
    title = new QLabel(this);
    cntnt = new QLabel(this);
    quit = new QPushButton(this);
    cnfm = new QPushButton(this);
    title->setFont(font1);
    cntnt->setFont(font);
    cnfm->setGeometry(width / 5, 7 * height / 10, width / 5, height / 10);
    quit->setGeometry(width * 3 / 5, 7 * height / 10, width / 5, height / 10);
    title->setAttribute(Qt::WA_TranslucentBackground, true);//透明
    title->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    cntnt->setAttribute(Qt::WA_TranslucentBackground, true);
    cntnt->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    title->setGeometry(width / 6, height / 8, width * 2 / 3, height / 6);
    cntnt->setGeometry(width / 15, height / 3, width * 14 / 15, height / 6);
    title->setText("网络出现问题");
    cntnt->setText("您或您的伙伴可能遇到网络问题了呢");
    quit->setText("退出");
    cnfm->setText("等待");
    quit->setStyleSheet("QPushButton{border-image: url(:/images/image/button.png);border-radius:20px;}");
    cnfm->setStyleSheet("QPushButton{border-image: url(:/images/image/button.png);border-radius:20px;}");
    quit->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    cnfm->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    quit->setFont(font);
    cnfm->setFont(font);
    connect(quit, SIGNAL(clicked()), this, SLOT(quitClicked()));
    connect(cnfm, SIGNAL(clicked()), this, SLOT(cnfmClicked()));
}

void ErrorDialog::cnfmClicked() {
    emit cnfmed();
}

void ErrorDialog::quitClicked() {
    emit quited();
}

ErrorDialog::~ErrorDialog() {
    delete title;
    delete cntnt;
    delete quit;
    delete cnfm;
}
