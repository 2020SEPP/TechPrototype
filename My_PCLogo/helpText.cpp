#include "helpText.h"
#include <QRegExpValidator>
#include "region.h"

HelpText::HelpText(int wid, int hei, QWidget *p)
{
    this->setStyleSheet("QDialog{border-image:url(:/images/image/login2.png)}");
    this->setFocus();
    this->setParent(p);
    this->text = new QTextEdit(this);
    this->close = new QPushButton(this);
    this->width = wid;
    this->height = hei;
    this->setWindowModality(Qt::ApplicationModal);
    this->setGeometry(width / 2, 100, width, height);
    //取消边框
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    //圆角遮罩
    Region *Re = new Region(width, height, width / 25);
    Re->mask(this);
    close->setGeometry(width * 9 / 10, height / 20, width / 15, height / 11);
    close->setStyleSheet("QPushButton{border-image:url(:/images/image/error.png)}");
    text->append("1.	 引言");
    text->append("\t编写目的");
    text->append("\t编写文档的目的是充分叙述本软件的所实现的功能以及运行环境，以便使使用者了解本软件的使用范围和使用方法。");
    text->append("2.	软件概述\n"
                 "a)	软件用途\n"
                 "My PCLogo 小海龟绘图软件，它满足用户以命令行或者命令文件形式控制小海龟多种形式在线绘图并支持用户添加好友互动与对战。\n"
                 "b)	软件运行\n"
                 "软件运行在PC及其兼容机上，使用windows系统。下载客户端后点击图标就可以出现首页主菜单，进行相应的操作。\n"
                 "c)	系统配置\n"
                 "用户系统版本应为Win10 1904及以上");
    text->append("4.	注册使用方法\n"
                 "a)	注册登录方法\n"
                " 进入首页点击相应按钮，输入电话号码进行登录注册操作，注册成功后下次直接登录。\n"
                 "b)	基于命令行编程绘图的基本命令\n"
                 "小海龟的前后、转向：		FD, BK, RT, LT  n，\n"
                         "    清屏复位：			LT\n"
                            " 提笔: 				PU，落笔：PD\n"
                           "  坐标定位:				SETXT[x y]\n"
                           "  设置笔的颜色：			SETPC n, n为颜色号\n"
                            " 设置背景的颜色：		SETBG n, n为颜色号\n"
                          "   画圆：				STAMPOVAL x y, x 表示横向半径，y表示纵向半径\n"
                            " 重复命令：		Repeat n [ ], 即[]内的命令重复n次\n"
                 "命令的编辑窗口的功能"
                           "  移到行首：			Home, 移到行尾：End\n"
                            " 命令的编辑功能：		\n"
                 "copy (Ctrl + C), Cut(Ctrl+X), Paste(Ctrl+V) 等\n"
                " c)	基于命令文件编程绘图的基本命令\n"
                 "一个命令文件中包括多条命令\n"
                           "  支持命令文件的新建、编辑、保存、打开和运行\n"
                 "命令文件的编辑功能包括copy, cut, paste, undo, redo等\n"
                 "d)	网上双人单海归协同作图"
                 "略");
    text->setGeometry(width / 8, height / 8, width * 3 / 4, height * 3 / 4);
    text->setStyleSheet("QTextEdit{"
                        "border-image:url(:images/image/space.png);"
                        "}");
//    text->verticalScrollBar()->hide();
    text->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    text->setReadOnly(true);
    text->show();
    close->show();
    connect(close, SIGNAL(clicked()), this, SLOT(help_close()));
}

HelpText::~HelpText()
{

}

void HelpText::help_close()
{
    this->hide();
}
