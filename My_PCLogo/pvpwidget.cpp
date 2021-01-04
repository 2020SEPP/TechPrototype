#include "pvpwidget.h"
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
    canvas = new Canvas(this, 0, 0, width / 2, (height * 3) / 4);
    canvas->setGeometry(0, 0, width / 2, (height * 3) / 4);
    enermy = new Canvas(this, width / 2, 0, width / 2, (height * 3) / 4);
    enermy->setGeometry(width / 2, 0, width / 2, (height * 3) / 4);
    setCanvasBG("ffffff");
    console = new Console(this);
    console->setGeometry(0, (height * 3) / 4, width, height / 4);
    console->setStyleSheet(QString::fromUtf8("border: 2px solid gray;"));
    console->write("Welcome to the PC Logo!\nPlease type your code.\n>> ");
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
    connect(console, SIGNAL(newLine(QString)), canvas, SLOT(parse_line(QString)));
    connect(console, SIGNAL(drawLine(qreal, bool)), canvas, SLOT(drawLine(qreal, bool)));
    connect(console, SIGNAL(turnDirection(qreal, bool)), canvas, SLOT(turnDirection(qreal, bool)));
    connect(console, SIGNAL(setXT(qreal, qreal)), canvas, SLOT(setXT(qreal, qreal)));
    connect(console, SIGNAL(setPC(uint)), canvas, SLOT(setPC(uint)));
    connect(console, SIGNAL(setBG(QString)), this, SLOT(setCanvasBG(QString)));
    connect(console, SIGNAL(stampoval(qreal, qreal)), canvas, SLOT(stampoval(qreal, qreal)));
    connect(canvas, SIGNAL(setBG(QString)), this, SLOT(setCanvasBG(QString)));
    connect(exit, SIGNAL(clicked()), this, SLOT(exitClicked()));
}

// SLOT
void
PvpWidget::setCanvasBG(QString color) {
    QString qss = "border: 2px solid darkgray; background-color: #";
    qss.append(color);
    canvas->setStyleSheet(qss);
    enermy->setStyleSheet(qss);
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
    }
}

void
PvpWidget::exitClicked() {
    emit ClosePvP(3);
}
