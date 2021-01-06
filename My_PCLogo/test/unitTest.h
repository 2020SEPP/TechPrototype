#ifndef UNITTEST_H
#define UNITTEST_H
#include <QtTest>
#include <QObject>
#include "user.h"
#include "loginwidget.h"
#include "mainwindow.h"
#include "homepage.h"
#include "userinfo.h"
#include "user.h"
#include "friendList.h"
#include "singlewidget.h"
#include "console.h"
#include "canvas.h"
class uniT:public QObject{
    Q_OBJECT
private slots:

    /**
     * @brief _mainWindow
     * 窗口切换、键盘响应
     */
    void _mainWindow();


    /**
     * @brief 用户信息类
     */
    void _User();
    void _User_data();

    /**
     * @brief _signinwidget_basic
     *
     * 登陆注册
     * basic:            基本测试，查重、验证等
     * ui:                  界面测试、点击事件等等
     * advance：    完整功能
     */
    void _signinwidget_basic();
    void _signinwidget_basic_data();
    void _signinwidget_ui();
    void _signinwidget_ui_data();
    void _signinwidget_advance();
    void _signinwidget_advance_data();

    /**
     * @brief _homepage
     * 主页测试：登陆检查、登陆跳转、按钮点击和基本函数
     */
    void _homepage();

    /**
     * @brief _usrinfo
     * 用户信息页：动画、点击、函数功能
     */
    void _usrinfo();

    /**
     * @brief _friendlist
     * 好友列表：搜索、设置item等等
     */
    void _friendlist();

    /**
     * @brief _singleWidget
     */
    void _singleWidget();

    /**
     * @brief _console
     * 函数功能、命令输入
     */
    void _console_basic();
    void _console_basic_data();
    void _console_complex();

    /**
     * @brief _canvas
     * 画布测试：转角等
     */
    void _canvas();


    /**
     * @brief _singleWidget_complex
     * 画笔动作、指令分析测试
     */
    void _singleWidget_complex();
    void _singleWidget_complex_data();



private:

};

#endif // UNITTEST_H
