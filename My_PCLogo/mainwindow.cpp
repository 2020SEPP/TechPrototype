#include "mainwindow.h"
#include <QtGlobal>
#include <QPropertyAnimation>
#include <QDebug>

#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    WIN_W = window.getW();
    WIN_H = window.getH();
    this->setWindowTitle("My PC Logo");
    this->setFixedSize(WIN_W, WIN_H);
    this->resize(WIN_W, WIN_H);
    home = new HomePage(this);
    home->setGeometry(0, 0, WIN_W, WIN_H);
    home->show();
    QPixmap pixmap = QPixmap(":/images/image/bk.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
    this->setWindowState(Qt::WindowFullScreen);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setFocus();
    cmdfile = new CmdFileWidget(this);
    cmdfile->hide();
    single = new SingleWidget(this);
    single->hide();
    pvp = new PvpWidget(this);
    pvp->hide();
    connect(home, SIGNAL(CommandFile(void)), this, SLOT(CommandFile()));
    connect(home, SIGNAL(CommandLine(void)), this, SLOT(CommandLine()));
    connect(home, SIGNAL(PVPMode(void)), this, SLOT(PVP()));
    connect(cmdfile, SIGNAL(CloseCmdFile(int)), this, SLOT(SwitchWidget(int)));
    connect(single, SIGNAL(CloseSingle(int)), this, SLOT(SwitchWidget(int)));
    connect(pvp, SIGNAL(ClosePvP(int)), this, SLOT(SwitchWidget(int)));
}

// SLOTS
void MainWindow::CommandFile() {
    setCentralWidget(cmdfile);
    cmdfile->show();
}

void MainWindow::CommandLine() {
    single->show();
    single->InAnnimation();
}

void MainWindow::PVP() {
    pvp->show();
    pvp->InAnnimation();
}

void MainWindow::SwitchWidget(int xXCode) {
    switch (xXCode) {
    case 1:
        single->InAnnimation();
        single->hide();
        break;
    case 2:
        cmdfile->hide();
        break;
    case 3:
        pvp->hide();
        break;
    default:
        break;
    }
    home->show();
}
