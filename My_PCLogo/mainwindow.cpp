#include "mainwindow.h"
#include <QtGlobal>
#include <QPropertyAnimation>
#include <QDebug>

#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    WIN_W = window.getW();
    WIN_H = window.getH();

    this->setWindowTitle("My PC Logo");
//    this->setFixedSize(width, height);
    this->resize(WIN_W, WIN_H);
    this->setMinimumSize(800, 600);

    home = new HomePage(this);
    home->setGeometry(0, 0, WIN_W, WIN_H);
    this->setCentralWidget(home);
    home->show();

    QPixmap pixmap = QPixmap(":/images/bk.png").scaled(this->size());

    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));

    this->setPalette(palette);
//    this->setWindowState(Qt::WindowFullScreen);
//    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
//    this->setFocus();

    editor = new CodEditor(this);
    editor->hide();
    single = new SingleWidget(this);
    single->hide();
    pvp = new PvpWidget(this);
    pvp->hide();

    connect(home, SIGNAL(CodeEditor(void)), this, SLOT(CodeEditor()));
    connect(home, SIGNAL(CommandLine(void)), this, SLOT(CommandLine()));
    connect(home, SIGNAL(PVPMode(void)), this, SLOT(PVP()));

    connect(editor, SIGNAL(CloseEditor(int)), this, SLOT(SwitchWidget(int)));
    connect(single, SIGNAL(CloseSingle(int)), this, SLOT(SwitchWidget(int)));
    connect(pvp, SIGNAL(ClosePvP(int)), this, SLOT(SwitchWidget(int)));
}

// SLOTS
void MainWindow::CodeEditor(){
    editor = new CodEditor(this);
    setCentralWidget(editor);
    editor->show();
    return ;
}

void MainWindow::CommandLine()
{
    single = new SingleWidget(this);
    single->show();
    single->InAnnimation();
}

void MainWindow::PVP()
{
    pvp = new PvpWidget(this);
    pvp->show();
    pvp->InAnnimation();
}

void MainWindow::SwitchWidget(int xXCode)
{
    qDebug() << xXCode;
    switch (xXCode) {
    case 1:
        single->hide();
        break;
    case 2:
        editor->hide();
        break;
    case 3:
        pvp->hide();
        break;
    default:
        break;
    }

    home->show();
}
