#include "mainwindow.h"
#include <QtGlobal>
#include <qdebug.h>
#include <qpropertyanimation.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
//        QRect screenRect = QApplication::desktop()->screenGeometry();
    this->setWindowTitle("My PCLogo");

    this->setFixedSize(window.winWidth,window.winHeight);
    QPixmap pixmap = QPixmap(":/images/bk.png").scaled(this->size());
        QPalette palette(this->palette());
        palette.setBrush(QPalette::Background, QBrush(pixmap));
        this->setPalette(palette);
        this->setWindowState(Qt::WindowFullScreen);
        this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    this->setFocus();


    userinfoWidget = new userinfo(this);
    userinfoWidget->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    userinfoWidget->setStyleSheet("QWidget{border :1px;                                                    \
                                                                  border-image:url(:images/sidenav.png);                 \
                                                        }");



    logindialog = new LoginDialog(this->window.winWidth/2,this->window.winHeight*2/3,this);
    logindialog->setGeometry(this->window.winWidth/4,this->window.winHeight/6,this->window.winWidth/2,this->window.winHeight*2/3);

    solo  =   new QPushButton(this);
    pk     =   new QPushButton(this);
    avatar=  new QPushButton(this);
    solo ->  setGeometry(3*window.winWidth/10,2*window.winHeight/5,2*window.winWidth/5,window.winHeight/10);
    pk    ->  setGeometry(3*window.winWidth/10,6*window.winHeight/10,4*window.winWidth/10,window.winHeight/10);
    avatar-> setGeometry(1*window.winWidth/10,1*window.winHeight/10,window.winWidth/10,window.winWidth/10);
    pk    ->   setText("PK");
    solo ->   setText("SOLO");

    avatar    ->  setStyleSheet("QPushButton{background-color: white;                                     \
                            border-style: solid;                                                                                             \
                            border-width:1px;                                                                                           \
                            border-radius:"+QString::number(window.winWidth/20)+
                            ";                                                                                                                      \
                            border-color: red;      border-image: url(:/images/log-green.png);           }            \
                            QPushButton:hover{border-image: url(:/images/log-yellow.png);  \
                                                                      }                     \
                                                     ");
    pk ->  setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:30px;}");
    solo ->  setStyleSheet("QPushButton{border-image: url(:/images/button.png);border-radius:30px;}");

//    solo  ->  setStyleSheet("QPushButton{border-image: url(:/images/zyc.jpg);}"
//                            "QPushButton:hover{border-image: url(:/images/fyh.jpg);}");

    avatar->setMask(QRegion(0,0,window.winWidth/10,window.winWidth/10,QRegion::Ellipse));
    pk    ->   setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    solo ->   setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    avatar->   setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

    pk->setFlat(false);
    solo->setFlat(1);

    pk->stackUnder(userinfoWidget);
    solo->stackUnder(userinfoWidget);

    connect(avatar,SIGNAL(clicked()),this,SLOT(avatarClicked()));
    connect(solo,SIGNAL(clicked()),this,SLOT(soloClicked()));
    connect(pk,SIGNAL(clicked()),this,SLOT(pkPressed()));

    pk    ->  show();
    solo ->  show();
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
    return;
}

void MainWindow::pkReleased(){

}
