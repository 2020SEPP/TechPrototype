#include "matchwidget.h"

#include <QBrush>
#include <QPalette>
#include <QtCore>
#include "token.h"

MatchDialog::MatchDialog() {
}

MatchDialog::MatchDialog(int width, int height, QWidget *p) {
    this->setStyleSheet("QDialog{border-image:url(:/images/image/login2.png)}");
    this->setParent(p);
    this->setFocus();
    this->width = width;
    this->height = height; // 设置模量其他窗口屏蔽
    this->setWindowModality(Qt::ApplicationModal); // 取消边框
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); // 圆角遮罩
    Region *Re = new Region(width, height, width / 25);
    Re->mask(this);
    this->raise();
    QFont font;
    font.setWeight(30);
    font.setPixelSize(30);
    usrlabel = new QLabel(this);
    pwdlabel = new QLabel(this);
    btn      = new QPushButton(this);
    stat     = MATCH;
    usrlabel->setFont(font);
    pwdlabel->setFont(font);
    btn->setGeometry(4 * width / 10, 6 * height / 10, width / 5, height / 10);
    usrlabel->setAttribute(Qt::WA_TranslucentBackground, true);//透明
    usrlabel->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    pwdlabel->setAttribute(Qt::WA_TranslucentBackground, true);
    pwdlabel->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    usrlabel->setGeometry(1 * width / 15, height / 5, width / 5, height / 10);
    pwdlabel->setGeometry(1 * width / 15, 2 * height / 5, width / 5, height / 10);
    usrlabel->setText("用户名:");
    pwdlabel->setText("密  码:");
    btn->setText("匹配");
    btn->setStyleSheet("QPushButton{border-image: url(:/images/image/button.png);border-radius:20px;}");
    btn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    btn->setFont(font);
    connect(btn, SIGNAL(clicked()), this, SLOT(quitClicked()));
}

void MatchDialog::btnClicked() {
    this->hide();
}

MatchDialog::~MatchDialog() {
}
