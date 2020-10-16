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
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->showFullScreen(); //全屏
    this->setFocus();

    userinfoWidget = new userinfo(this);
    userinfoWidget->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    userinfoWidget->setStyleSheet("QWidget{border :1px;                                                    \
                                                                  background:red;                 \
                                                        }");
//        userinfoWidget->setWindowOpacity(0.1);

    userinfoWidget->show();


    solo  =   new QPushButton(this);
    pk     =   new QPushButton(this);
    avatar=  new QPushButton(this);
    solo ->  setGeometry(3*window.winWidth/10,2*window.winHeight/5,2*window.winWidth/5,window.winHeight/10);
    pk    ->  setGeometry(3*window.winWidth/10,6*window.winHeight/10,4*window.winWidth/10,window.winHeight/10);
    avatar-> setGeometry(1*window.winWidth/10,1*window.winHeight/10,window.winWidth/10,window.winWidth/10);
    pk    ->   setText("PK");
    solo ->   setText("SOLO");
    avatar-> setText("登    陆");

    avatar    ->  setStyleSheet("QPushButton{background-color: white;                                     \
                            border-style: solid;                                                                                             \
                            border-width:1px;    font-size:30px;                                                                                          \
                            border-radius:"+QString::number(window.winWidth/20)+
                            ";                                                                                                                      \
                            border-color: red;      border-image: url(:/images/fyh.jpg);           }            \
                            QPushButton:hover{border-image: url(:/images/zyc.jpg); font-size:40px \
                                                                      }                     \
                                                     ");
    pk ->  setStyleSheet("QPushButton{border-image: url(:/images/fyh.jpg);}"
                            "QPushButton:hover{border-image: url(:/images/zyc.jpg);}");
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
    connect(pk,SIGNAL(clicked()),this,SLOT(pkClicked()));
    pk    ->  show();
    solo ->  show();
    avatar->show();





}

MainWindow::~MainWindow()
{
}


void MainWindow::avatarClicked(){
  userinfoWidget->annimation();
//    delete  animation;


}

void MainWindow::soloClicked(){
    return;
}

void MainWindow::pkClicked(){
    exit(0);
    return;
}
