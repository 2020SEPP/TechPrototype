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
    Window_Pixels_Init();
    this->setWindowTitle("My PC Logo");
//    this->setFixedSize(WIN_W, WIN_H);
    this->resize(WIN_W, WIN_H);
    this->setMinimumSize(800, 600);

    home = new HomePage(this, WIN_W, WIN_H);
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

    connect(home, SIGNAL(CodeEditor(void)), this, SLOT(CodeEditor()));
    connect(home, SIGNAL(CommandLine(void)), this, SLOT(CommandLine()));
    connect(home, SIGNAL(PVPMode(void)), this, SLOT(PVP()));
}

MainWindow::~MainWindow()
{
}

// SLOTS
void MainWindow::CodeEditor(){
    editor = new CodEditor(this, WIN_W, WIN_H);
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
