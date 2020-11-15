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

    QMenuBar *menu_bar = new QMenuBar(this);             //创建一个菜单栏
    this->setMenuBar(menu_bar);                                          //添加工具栏到MainWindow
    QStatusBar *status_bar = new QStatusBar(this);            //创建一个状态栏
    this->setStatusBar(status_bar);                                        //设置为MainWindow的状态栏

    //创建菜单
    QMenu *file_menu = new QMenu("文件(&F)",menu_bar);
    QMenu *edit_menu = new QMenu("编辑(&E)",menu_bar);
    QMenu *help_menu = new QMenu("帮助(&H)",menu_bar);

    //创建动作
    QAction *new_action = new QAction("新建(&N)");
    QAction *open_action = new QAction("打开(&O)");
    QAction *save_action = new QAction("保存(&S)");

    //添加状态栏提示
    new_action->setStatusTip("新建一个文件或项目");
    open_action->setStatusTip("打开一个文件或项目");
    save_action->setStatusTip("保存");

    //添加动作到新建菜单，QAction就会自动变成子菜单
    file_menu->addAction(new_action);
    file_menu->addAction(open_action);
    file_menu->addSeparator();                      //添加菜单分隔符
    file_menu->addAction(save_action);

    //给编辑菜单添加子菜单
    edit_menu->addAction("剪切(&T)");
    //给帮助菜单添加子菜单
    help_menu->addAction("关于(&A)");

    //把菜单添加到菜单栏
    menu_bar->addMenu(file_menu);
    menu_bar->addMenu(edit_menu);
    menu_bar->addMenu(help_menu);

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

