#include "matchwidget.h"

#include <QBrush>
#include <QPainter>
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
    this->height = height;
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    Region *Re = new Region(width, height, width / 25);
    Re->mask(this);
    this->raise();
    QFont font;
    font.setWeight(30);
    font.setPixelSize(30);
    createRoom  = new QPushButton(this);
    certainRoom = new QPushButton(this);
    randomRoom  = new QPushButton(this);
    quitRoom    = new QPushButton(this);
    cnfm        = new QPushButton(this);
    back        = new QPushButton(this);
    stat = MODE;
    createRoom->setGeometry(width * 2 / 15, height * 2 / 15, height / 3, height / 3);
    certainRoom->setGeometry(width * 13 / 15 - height / 3, height * 2 / 15, height / 3, height / 3);
    randomRoom->setGeometry(width * 2 / 15, height * 8 / 15, height / 3, height / 3);
    quitRoom->setGeometry(width * 13 / 15 - height / 3, height * 8 / 15, height / 3, height / 3);
    createRoom->setStyleSheet("QPushButton{border-image: url(:/images/image/room.png);border-radius:10px;}");
    createRoom->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    certainRoom->setStyleSheet("QPushButton{border-image: url(:/images/image/certain.png);border-radius:10px;}");
    certainRoom->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    randomRoom->setStyleSheet("QPushButton{border-image: url(:/images/image/random.png);border-radius:10px;}");
    randomRoom->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    quitRoom->setStyleSheet("QPushButton{border-image: url(:/images/image/exit.png);border-radius:10px;}");
    quitRoom->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    quitRoom->show();
    roominput = new LineEdit(this);
    roominput->setGeometry(width / 6, height / 3, width * 2 / 3, 100);
    QFont font1;
    font1.setWeight(60);
    font1.setPixelSize(60);
    roominput->setFont(font1);
    roominput->setMaxLength(4);
    roominput->hide();
    cnfm->setGeometry(width / 5, 7 * height / 10, width / 5, height / 10);
    cnfm->setText("确认");
    cnfm->setStyleSheet("QPushButton{border-image: url(:/images/image/button.png);border-radius:20px;}");
    cnfm->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    cnfm->setFont(font);
    cnfm->hide();
    back->setGeometry(width * 3 / 5, 7 * height / 10, width / 5, height / 10);
    back->setText("返回");
    back->setStyleSheet("QPushButton{border-image: url(:/images/image/button.png);border-radius:20px;}");
    back->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    back->setFont(font);
    back->hide();
    connect(createRoom, SIGNAL(clicked()), this, SLOT(createClicked()));
    connect(certainRoom, SIGNAL(clicked()), this, SLOT(certainClicked()));
    connect(randomRoom, SIGNAL(clicked()), this, SLOT(randomClicked()));
    connect(quitRoom, SIGNAL(clicked()), this, SLOT(quitClicked()));
    connect(cnfm, SIGNAL(clicked()), this, SLOT(cnfmClicked()));
    connect(back, SIGNAL(clicked()), this, SLOT(backClicked()));
}

void MatchDialog::btnDisplay(bool flag) {
    if (flag) {
        createRoom->show();
        certainRoom->show();
        randomRoom->show();
        quitRoom->show();
    } else {
        createRoom->hide();
        certainRoom->hide();
        randomRoom->hide();
        quitRoom->hide();
    }
}

void MatchDialog::createClicked() {
    stat = CREATE;
    this->hide();
}

void MatchDialog::certainClicked() {
    stat = CERTAIN;
    roominput->show();
    cnfm->show();
    back->show();
    btnDisplay(false);
}

void MatchDialog::randomClicked() {
    stat = RANDOM;
    this->hide();
}

void MatchDialog::quitClicked() {
    stat = MODE;
    this->hide();
}

void MatchDialog::cnfmClicked() {
    this->hide();
}

void MatchDialog::backClicked() {
    roominput->hide();
    cnfm->hide();
    back->hide();
    btnDisplay(true);
}

MatchDialog::~MatchDialog() {
}

void MatchDialog::paintEvent(QPaintEvent *) {
//    QPainter painter;
//    painter.begin(this);
//    painter.setRenderHints(QPainter::Antialiasing, true);
//    QPainterPath path;
//    path.addEllipse(width / 8, height / 6, width / 6, width / 6);
//    painter.setClipPath(path);
//    painter.drawPixmap(QRect(width / 8, height / 6, width / 6, width / 6), QPixmap(":/images/image/friend.png"));
//    painter.end();
//    if (stat == MATCH) {
//        painter.begin(this);
//        painter.setRenderHints(QPainter::Antialiasing, true);
//        QPainterPath path1;
//        path1.addEllipse((width * 17) / 24, height / 6, width / 6, width / 6);
//        painter.setClipPath(path1);
//        painter.drawPixmap(QRect((width * 17) / 24, height / 6, width / 6, width / 6), QPixmap(":/images/image/friend.png"));
//        painter.end();
//    } else {
//        return;
//    }
}
