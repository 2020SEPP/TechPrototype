#include "pvpwidget.h"
#include <QApplication>
#include <QDebug>
#include <QPropertyAnimation>

PvpWidget::PvpWidget(QWidget *parent) : QWidget(parent)
{
    WIN_H = window.getH();
    WIN_W = window.getW();

    this->setFixedSize(WIN_W,WIN_H);
    this->setWindowTitle("My PC Logo");
    this->setFocus();
    this->setGeometry(WIN_W,0,WIN_W,WIN_H);
    this->visible = false;

    QFont font;
    font.setFamily("concolas");
    font.setBold(true);
    font.setPixelSize(20);
    this->setFont(font);

    canvas = new Canvas(this);
    canvas->setGeometry(0, 0, WIN_W, (WIN_H * 3) / 4);
    canvas->setStyleSheet("border: 2px solid darkgray; background");
    setCanvasBG("ffffff");

    console = new Console(this);
    console->setGeometry(0, (WIN_H * 3) / 4, WIN_W, WIN_H / 4);
    console->setStyleSheet(QString::fromUtf8("border: 2px solid gray;"));
    console->write("Welcome to the PC Logo!\nPlease type your code.\n");


//    connect(console, SIGNAL(newLineWriten(QStringList)), canvas, SLOT(draw(qreal, qreal)));
    connect(console, SIGNAL(newLine(QString)), canvas, SLOT(parse_line(QString)));
    connect(console, SIGNAL(drawLine(qreal, bool)), canvas, SLOT(drawLine(qreal, bool)));
    connect(console, SIGNAL(turnDirection(qreal, bool)), canvas, SLOT(turnDirection(qreal, bool)));
//    connect(console, SIGNAL(penDownUp(bool)), canvas, SLOT(penDownUp(bool)));
    connect(console, SIGNAL(setXT(qreal, qreal)), canvas, SLOT(setXT(qreal, qreal)));
    connect(console, SIGNAL(setPC(uint)), canvas, SLOT(setPC(uint)));
    connect(console, SIGNAL(setBG(QString)), this, SLOT(setCanvasBG(QString)));
    connect(console, SIGNAL(stampoval(qreal, qreal)), canvas, SLOT(stampoval(qreal, qreal)));
    connect(canvas, SIGNAL(setBG(QString)), this, SLOT(setCanvasBG(QString)));
}

// SLOT
void
PvpWidget::setCanvasBG(QString color)
{
    QString qss = "border: 2px solid darkgray; background-color: #";
    qss.append(color);
    canvas->setStyleSheet(qss);
}

void
PvpWidget::InAnnimation()
{
   QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
   animation->setDuration(100);
   if(this->visible)
   {
       animation->setStartValue(QRect(0,0,WIN_W,WIN_H));
       animation->setEndValue(QRect(WIN_W,0,WIN_W,WIN_H));
       animation->start();
   }
   else
   {
       animation->setStartValue(QRect(WIN_W,0,WIN_W,WIN_H));
       animation->setEndValue(QRect(0,0,WIN_W,WIN_H));
       animation->start();
   }
   this->visible = !this->visible;
   this->setWindowModality(Qt::ApplicationModal);
}

void PvpWidget::keyPressEvent(QKeyEvent *ev)
{
    if (ev->key() == Qt::Key_Escape)
    {
        emit ClosePvP(3);
    }
}
