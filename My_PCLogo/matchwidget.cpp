#include "matchwidget.h"
#include <QBrush>
#include <QPainter>
#include <QPalette>
#include <QtCore>

MatchDialog::MatchDialog() {
}

MatchDialog::MatchDialog(int width, int height, QWidget *p) : QDialog(p) {
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
    font.setWeight(30);
    font.setPixelSize(30);
    battle      = new QPushButton(this);
    cooper      = new QPushButton(this);
    coming      = new QPushButton(this);
    back_1      = new QPushButton(this);
    createRoom  = new QPushButton(this);
    certainRoom = new QPushButton(this);
    randomRoom  = new QPushButton(this);
    quitRoom    = new QPushButton(this);
    cnfm        = new QPushButton(this);
    back        = new QPushButton(this);
    vs          = new QPushButton(this);
    init();
    battle->setGeometry(width * 2 / 15, height * 2 / 15, height / 3, height / 3);
    cooper->setGeometry(width * 13 / 15 - height / 3, height * 2 / 15, height / 3, height / 3);
    coming->setGeometry(width * 2 / 15, height * 8 / 15, height / 3, height / 3);
    back_1->setGeometry(width * 13 / 15 - height / 3, height * 8 / 15, height / 3, height / 3);
    battle->setStyleSheet("QPushButton{border-image: url(:/images/image/battle.png);border-radius:10px;}");
    battle->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    cooper->setStyleSheet("QPushButton{border-image: url(:/images/image/cooper.png);border-radius:10px;}");
    cooper->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    coming->setStyleSheet("QPushButton{border-image: url(:/images/image/coming.png);border-radius:10px;}");
    coming->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    back_1->setStyleSheet("QPushButton{border-image: url(:/images/image/exit.png);border-radius:10px;}");
    back_1->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    battle->show();
    cooper->show();
    coming->show();
    back_1->show();
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
    createRoom->hide();
    certainRoom->hide();
    randomRoom->hide();
    quitRoom->hide();
    title = new QLabel(this);
    title->setGeometry(width / 3, height / 8, width / 3, 60);
    room  = new QLabel(this);
    room->setGeometry(width / 3, height / 3, width / 2, 100);
    roominput = new LineEdit(this);
    roominput->setGeometry(width / 6, height / 3, width * 2 / 3, 100);
    QFont font1;
    font1.setWeight(60);
    font1.setPixelSize(60);
    QFont font2;
    font2.setWeight(70);
    font2.setPixelSize(70);
    roominput->setFont(font1);
    roominput->setMaxLength(4);
    title->setFont(font2);
    title->hide();
    room->setFont(font1);
    room->hide();
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
    vs->setGeometry(width * 2 / 5, height / 2, width / 5, width / 5);
    vs->setStyleSheet("QPushButton{border-image: url(:/images/image/vs.png);border-radius:10px;}");
    vs->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    vs->setFont(font);
    vs->hide();
    connect(battle, SIGNAL(clicked()), this, SLOT(battleClicked()));
    connect(cooper, SIGNAL(clicked()), this, SLOT(cooperClicked()));
    connect(back_1, SIGNAL(clicked()), this, SLOT(back_1Clicked()));
    connect(createRoom, SIGNAL(clicked()), this, SLOT(createClicked()));
    connect(certainRoom, SIGNAL(clicked()), this, SLOT(certainClicked()));
    connect(randomRoom, SIGNAL(clicked()), this, SLOT(randomClicked()));
    connect(quitRoom, SIGNAL(clicked()), this, SLOT(quitClicked()));
    connect(cnfm, SIGNAL(clicked()), this, SLOT(cnfmClicked()));
    connect(back, SIGNAL(clicked()), this, SLOT(backClicked()));
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(listen()));
}

void MatchDialog::init() {
    stat = MODE;
    currroom = -1;
    type = -1;
    one.load(":/images/image/avatar/" + getAvatarByName(NAME));
    two.load(":/images/image/another.jpg");
    btnDisplay(3);
}

void MatchDialog::btnDisplay(int flag) {
    switch (flag) {
    case 0: // 选好游戏模式进入匹配模式选择
        battle->hide();
        cooper->hide();
        coming->hide();
        back_1->hide();
        createRoom->show();
        certainRoom->show();
        randomRoom->show();
        quitRoom->show();
        break;
    case 1: // 进入匹配
        createRoom->hide();
        certainRoom->hide();
        randomRoom->hide();
        quitRoom->hide();
        break;
    case 2: // 退出匹配
        createRoom->show();
        certainRoom->show();
        randomRoom->show();
        quitRoom->show();
        title->hide();
        break;
    case 3: // 退出匹配模式选择
        createRoom->hide();
        certainRoom->hide();
        randomRoom->hide();
        quitRoom->hide();
        battle->show();
        cooper->show();
        coming->show();
        back_1->show();
        break;
    default:
        break;
    }
}

void MatchDialog::battleClicked() {
    type = 0;
    btnDisplay(0);
}

void MatchDialog::cooperClicked() {
    type = 1;
    btnDisplay(0);
}

void MatchDialog::back_1Clicked() {
    stat = MODE;
    this->hide();
}

void MatchDialog::createClicked() {
    stat = CREATE;
    waiting = true;
    title->setText("创建房间");
    title->show();
    btnDisplay(1);
    cnfm->show();
    back->show();
    QString url = ADDR + "/match/createRoom"
                  + "?uid=" + QString::number(ID)
                  + "&isSingle=" + QString::number(type);
    QString res = QString("%1").arg(http.get(url).toUInt(), 4, 10, QLatin1Char('0'));
    currroom = res.toInt();
    room->show();
    room->setText("房间号：" + res);
    vs->show();
    two.load(":/images/image/another.jpg");
    update();
    timer->start(5000);
}

void MatchDialog::certainClicked() {
    stat = CERTAIN;
    title->setText("输入房间");
    title->show();
    roominput->show();
    cnfm->show();
    back->show();
    btnDisplay(1);
}

void MatchDialog::randomClicked() {
    stat = RANDOM;
    title->setText("随机房间");
    title->show();
    btnDisplay(1);
    cnfm->show();
    back->show();
    QString url = ADDR + "/match/joinSrand"
                  + "?uid=" + QString::number(ID)
                  + "&isSingle=" + QString::number(type);
    QString res = QString("%1").arg(http.get(url).toUInt(), 4, 10, QLatin1Char('0'));
    currroom = res.toInt();
    room->show();
    vs->show();
    two.load(":/images/image/another.jpg");
    room->setText("房间号：" + res);
    url = ADDR + "/match" + "/getOtherPlayer?uid=" + QString::number(ID)
          + "&rid=" + QString::number(currroom);
    QJsonObject json = http.get_json(url);
    if (json.contains("name")) {
//        qDebug() << json;
        if (json.value("name").toString() != "") {
            waiting = false;
            timer->stop();
            two.load(":/images/image/avatar/" + getAvatarByName(json.value("name").toString()));
        }
    }
    update();
}

void MatchDialog::quitClicked() {
    btnDisplay(3);
}

void MatchDialog::cnfmClicked() {
    if (stat == CERTAIN) {
        QString input = roominput->text();
        currroom = input.toInt();
        QString url = ADDR + "/match" + "/joinById?uid=" + QString::number(ID)
                      + "&rid=" + QString::number(currroom)
                      + "&isSingle=" + QString::number(type);
        QString res = http.get(url);
        if (res == "false")
            return;
    }
    if (stat == CREATE) {
        if (waiting)
            return;
    }
    emit EnterRoom(currroom, type, stat == CREATE);
    this->hide();
    roominput->hide();
    room->hide();
    cnfm->hide();
    back->hide();
    title->hide();
    btnDisplay(3);
    stat = MODE;
}

void MatchDialog::backClicked() {
    if (stat == CREATE && waiting) {
        {
            QString url = ADDR + "/match" + "/removeRoom?uid=" + QString::number(ID)
                          + "&rid=" + QString::number(currroom);
            QString res = http.get(url);
        }
    }
    roominput->hide();
    room->hide();
    cnfm->hide();
    back->hide();
    vs->hide();
    btnDisplay(2);
    timer->stop();
    stat = MODE;
}

void MatchDialog::listen() {
    QString url = ADDR + "/match" + "/getOtherPlayer?uid=" + QString::number(ID)
                  + "&rid=" + QString::number(currroom);
    QJsonObject res = http.get_json(url);
    if (res.contains("name")) {
//        qDebug() << res;
        if (res.value("name").toString() != "") {
            waiting = false;
            timer->stop();
            two.load(":/images/image/avatar/" + getAvatarByName(res.value("name").toString()));
            update();
        }
    }
}

MatchDialog::~MatchDialog() {
    delete certainRoom;
    delete randomRoom;
    delete quitRoom;
    delete cnfm;
    delete back;
    delete vs;
    delete battle;
    delete cooper;
    delete coming;
    delete back_1;
    delete room;
    delete title;
    delete roominput;
    delete timer;
}

void MatchDialog::paintEvent(QPaintEvent *) {
    if (stat == CREATE || stat == RANDOM) {
        QPainter painter;
        painter.begin(this);
        painter.setRenderHints(QPainter::Antialiasing, true);
        QPainterPath path;
        path.addEllipse(width / 8, height / 6, width / 6, width / 6);
        painter.setClipPath(path);
        painter.drawPixmap(QRect(width / 8, height / 6, width / 6, width / 6), one);
        painter.end();
        painter.begin(this);
        painter.setRenderHints(QPainter::Antialiasing, true);
        QPainterPath path1;
        path1.addEllipse(width * 17 / 24, height / 6, width / 6, width / 6);
        painter.setClipPath(path1);
        painter.drawPixmap(QRect(width * 17 / 24, height / 6, width / 6, width / 6), two);
        painter.end();
        update();
    }
}
