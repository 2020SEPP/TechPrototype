#include "singlewidget.h"
#include <QApplication>
#include <QDebug>
#include <QPropertyAnimation>

SingleWidget::SingleWidget(QWidget *parent) : QWidget(parent)
{
    this->height = window.winHeight;
    this->width = window.winWidth;

    this->setFixedSize(width,height);
    this->setWindowTitle("My PC Logo");
    this->setFocus();
    this->setGeometry(width,0,width,height);
    this->visible = false;

    QFont font;
    font.setFamily("concolas");
    font.setBold(true);
    font.setPixelSize(20);
    this->setFont(font);

    canvas = new Canvas(this);
    canvas->setGeometry(0, 0, width, (height * 3) / 4);
    canvas->setStyleSheet("border: 2px solid darkgray; background");
    setCanvasBG("ffffff");

    console = new Console(this);
    console->setGeometry(0, (height * 3) / 4, width, height / 4);
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
SingleWidget::setCanvasBG(QString color)
{
    QString qss = "border: 2px solid darkgray; background-color: #";
    qss.append(color);
    canvas->setStyleSheet(qss);
}

void
SingleWidget::InAnnimation()
{
   QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
   animation->setDuration(100);
   if(this->visible)
   {
       animation->setStartValue(QRect(0,0,width,height));
       animation->setEndValue(QRect(width,0,width,height));
       animation->start();
   }
   else
   {
       animation->setStartValue(QRect(width,0,width,height));
       animation->setEndValue(QRect(0,0,width,height));
       animation->start();
   }
   this->visible = !this->visible;
   this->setWindowModality(Qt::ApplicationModal);
}
