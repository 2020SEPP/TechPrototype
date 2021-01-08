#include "pvpwidget.h"
#include "token.h"
#include <QApplication>
#include <QDebug>
#include <QPropertyAnimation>

PvpWidget::PvpWidget(QWidget *parent) : QWidget(parent) {
    height = window.getH();
    width = window.getW();
    this->setFixedSize(width, height);
    this->setWindowTitle("My PC Logo");
    this->setFocus();
    this->setGeometry(width, 0, width, height);
    this->visible = false;
    QFont font;
    font.setFamily("concolas");
    font.setBold(true);
    font.setPixelSize(20);
    this->setFont(font);
    init(-1, INIT, false);
}

void PvpWidget::init(int r, int t, bool own) {
    room = r;
    type = t;
    owner = own;
    if (type == BATTLE) {
        canvas = new Canvas(this, 0, 0, width / 2, (height * 3) / 4);
        canvas->setGeometry(0, 0, width / 2, (height * 3) / 4);
        enermy = new Canvas(this, 0, 0, width / 2, (height * 3) / 4);
        enermy->setGeometry(width / 2, 0, width / 2, (height * 3) / 4);
    } else if (type == COOPER) {
        canvas = new Canvas(this, 0, 0, width, (height * 3) / 4);
        canvas->setGeometry(0, 0, width, (height * 3) / 4);
    } else {
        return;
    }
    console = new Console(this);
    console->setGeometry(0, (height * 3) / 4, width, height / 4);
    console->setStyleSheet(QString::fromUtf8("border: 2px solid gray;"));
    console->write("欢迎来到 ");
    if (type == BATTLE)
        console->write("对战模式 ");
    else
        console->write("合作模式 ");
    console->write(QString::number(room) + " 号房间!\n");
    if (owner)
        console->write("请输入你的指令.\n>> ");
    console->setStyleSheet("QTextEdit {"
                           "border-image:url(:/images/image/paint2222.png);"
                           "}");
    console->setAttribute(Qt::WA_InputMethodEnabled, false);
    help = new QPushButton(this);
    exit = new QPushButton(this);
    help->setGeometry(width * 13 / 15, 0, height / 15, height / 15);
    exit->setGeometry(width * 14 / 15, 0, height / 15, height / 15);
    help->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    exit->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    help->setStyleSheet("QPushButton{"
                        "border-image:url(:/images/image/bangzhu.png)"
                        "}");
    exit->setStyleSheet("QPushButton{"
                        "border-image:url(:/images/image/tuichu.png)"
                        "}");
    timer = new QTimer;
    if (room > 0) {
        timer->start(5000);
        cycle = 0;
    }
    connect(console, SIGNAL(drawLine(qreal, bool)), this, SLOT(drawLine(qreal, bool)));
    connect(console, SIGNAL(turnDirection(qreal, bool)), this, SLOT(turnDirection(qreal, bool)));
    connect(console, SIGNAL(setXT(qreal, qreal)), this, SLOT(setXT(qreal, qreal)));
    connect(console, SIGNAL(setPC(uint)), this, SLOT(setPC(uint)));
    connect(console, SIGNAL(setBG(QString)), this, SLOT(setBG(QString)));
    connect(console, SIGNAL(stampoval(qreal, qreal)), this, SLOT(stampoval(qreal, qreal)));
    connect(exit, SIGNAL(clicked()), this, SLOT(exitClicked()));
    connect(timer, SIGNAL(timeout()), this, SLOT(listen()));
}

// SLOT
void PvpWidget::listen() {
    if (cycle >= 6) { // 30s
        timer->stop();
        error = new ErrorDialog(width / 2, height * 2 / 3, this);
        error->setGeometry(width / 4, height / 6, width / 2, height * 2 / 3);
        error->show();
        connect(error, SIGNAL(cnfmed()), this, SLOT(errorhandler1()));
        connect(error, SIGNAL(quited()), this, SLOT(errorhandler2()));
        return;
    }
    QString url = ADDR + "/match" + "/getCommand?uid=" + QString::number(ID)
                  + "&rid=" + QString::number(room);
    QJsonArray res = http.get_array(url);
    cycle++;
    if (res.size()) {
        qDebug() << res;
        for (int i = 0; i < res.size(); i++) {
            QString cmd = res.at(i).toString();
            if (type == BATTLE)
                enermy->parse_line(cmd);
            else if (type == COOPER) {
                canvas->parse_line(cmd);
                owner = true;
            }
            cycle = 0;
        }
    }
}

void PvpWidget::sendCommand(QString cmd) {
    QString url = ADDR + "/match"
                  + "/sendCommand?uid=" + QString::number(ID)
                  + "&rid=" + QString::number(room)
                  + "&command=" + cmd;
    http.get(url);
    if (type == COOPER) {
        console->write("\n现在轮到对方回合，请等待...");
        owner = false;
    }
}

void PvpWidget::drawLine(qreal len, bool flag) {
    if (COOPER && !owner) {
        console->write("\n当前还不是你的回合，请等待...");
        return;
    }
    canvas->drawLine(len, flag);
    QString command = (flag ? "fd " : "bk ") + QString::number(len);
    sendCommand(command);
}

void PvpWidget::turnDirection(qreal angle, bool flag) {
    if (COOPER && !owner) {
        console->write("\n当前还不是你的回合，请等待...");
        return;
    }
    canvas->turnDirection(angle, flag);
    QString command = (flag ? "rt " : "lt ") + QString::number(angle);
    sendCommand(command);
}

void PvpWidget::setXT(qreal x, qreal y) {
    if (COOPER && !owner) {
        console->write("\n当前还不是你的回合，请等待...");
        return;
    }
    canvas->setXT(x, y);
    QString command = "setxy " + QString::number(x) + " " + QString::number(y);
    sendCommand(command);
}

void PvpWidget::setPC(uint color) {
    if (COOPER && !owner) {
        console->write("\n当前还不是你的回合，请等待...");
        return;
    }
    canvas->setPC(color);
    QString command = "setpc " + QString::number(color);
    sendCommand(command);
}

void PvpWidget::setBG(QString color) {
    if (COOPER && !owner) {
        console->write("\n当前还不是你的回合，请等待...");
        return;
    }
    QString qss = "border: 2px solid darkgray; background-color: #";
    qss.append(color);
    canvas->setStyleSheet(qss);
    enermy->setStyleSheet(qss);
    QString command = "setbg " + color;
    sendCommand(command);
}

void PvpWidget::stampoval(qreal x, qreal y) {
    if (COOPER && !owner) {
        console->write("\n当前还不是你的回合，请等待...");
        return;
    }
    canvas->stampoval(x, y);
    QString command = "stampoval " + QString::number(x) + " " + QString::number(y);
    sendCommand(command);
}

void
PvpWidget::InAnnimation() {
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(100);
    if(this->visible) {
        animation->setStartValue(QRect(0, 0, width, height));
        animation->setEndValue(QRect(width, 0, width, height));
        animation->start();
    } else {
        animation->setStartValue(QRect(width, 0, width, height));
        animation->setEndValue(QRect(0, 0, width, height));
        animation->start();
    }
    this->visible = !this->visible;
    this->setWindowModality(Qt::ApplicationModal);
}

void
PvpWidget::keyPressEvent(QKeyEvent *ev) {
    if (ev->key() == Qt::Key_Escape) {
        emit ClosePvP(3);
        timer->stop();
    }
}

void
PvpWidget::exitClicked() {
    emit ClosePvP(3);
    timer->stop();
}


void
PvpWidget::errorhandler1() {
    error->hide();
    cycle = 0;
    timer->start(5000);
}

void
PvpWidget::errorhandler2() {
    error->hide();
    QString url = ADDR + "/match" + "/removeRoom?uid=" + QString::number(ID)
                  + "&rid=" + QString::number(room);
    QString res = http.get(url);
    emit ClosePvP(3);
}
