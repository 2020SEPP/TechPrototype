#include "mainwindow.h"
#include <QtGlobal>
#include <QPropertyAnimation>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    Window_Pixels_Init();
    this->setWindowTitle("My PC Logo");
    this->setFixedSize(WIN_W, WIN_H);
    QPixmap pixmap = QPixmap(":/images/bk.png").scaled(this->size());

    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));

    this->setPalette(palette);
//    this->setWindowState(Qt::WindowFullScreen);
//    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    this->setFocus();


    userinfoWidget = new userinfo(this, WIN_W, WIN_H);
    userinfoWidget->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    userinfoWidget->setStyleSheet("QWidget{ border :1px; border-image:url(:images/sidenav.png); }");

    logindialog = new LoginDialog(WIN_W/2, WIN_H*2/3, this);
    logindialog->setGeometry(WIN_W/4, WIN_H/6, WIN_W/2, WIN_H*2/3);

    solo   = new QPushButton(this);
    pk     = new QPushButton(this);
    avatar = new QPushButton(this);

    solo->setGeometry(3*WIN_W/10,2*WIN_H/5,2*WIN_W/5,WIN_H/10);
    pk->setGeometry(3*WIN_W/10,6*WIN_H/10,4*WIN_W/10,WIN_H/10);
    avatar->setGeometry(1*WIN_W/10,1*WIN_H/10,WIN_W/10,WIN_W/10);

    pk->setText("PK");
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
    pk->setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:30px;}");
    solo->setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:30px;}");

    avatar->setMask(QRegion(0,0,WIN_W/10,WIN_W/10,QRegion::Ellipse));
    pk->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    solo->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    avatar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

    pk->setFlat(false);
    solo->setFlat(1);

    pk->stackUnder(userinfoWidget);
    solo->stackUnder(userinfoWidget);

    connect(avatar,SIGNAL(clicked()),this,SLOT(avatarClicked()));
    connect(solo,SIGNAL(clicked()),this,SLOT(soloClicked()));
    connect(pk,SIGNAL(clicked()),this,SLOT(pkPressed()));

    pk->show();
    solo->show();
    avatar->show();
    userinfoWidget->show();
}

MainWindow::~MainWindow()
{
}


void MainWindow::avatarClicked(){
  userinfoWidget->annimation();
//    delete  animation;
}

void MainWindow::soloClicked(){
    logindialog->show();
    return;
}

void MainWindow::pkPressed(){
    /* qDebug() << http.get(ADDR);

    qDebug() << http.post(ADDR + "/param?name=djw&pwd=250", "");

    QString json = "{\"name\": \"fyh\", \"pwd\": \"123\"}";

    qDebug() << qPrintable(json);

    qDebug() << http.post(ADDR + "/body", json);*/

//    pk->hide();
//    solo->hide();
//    avatar->hide();
//    userinfoWidget->hide();

    this->hide();

    editor = new CodEditor(this, WIN_W, WIN_H);
//    editor->setGeometry(0, 0, WIN_W, WIN_H);
//    setCentralWidget(editor);
    editor->show();

    return;
}

void MainWindow::pkReleased(){

}
