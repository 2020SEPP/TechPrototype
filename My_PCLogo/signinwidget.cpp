#include "signinwidget.h"

#include <QBrush>
#include <QPalette>
#include <QtCore>
#include <QRegExpValidator>
#include "token.h"
QList<User *> getFriend(int uid) {
    HttpRequest http;
    QString url = ADDR + "/user/getFriend?uid=" + QString::number(uid);
    QJsonArray res = http.get_array(url);
    QList<User *> users;
    for (int i = 0; i < res.size(); ++i) {
        QJsonObject object = res.at(i).toObject();
        User *user = new User(object);
        users.append(user);
    }
    return users;
}

LoginDialog::LoginDialog() {
}

LoginDialog::LoginDialog(int width, int height, QWidget *p) {
    p->setVisible(0);
    this->setStyleSheet("QDialog{border-image:url(:/images/image/login2.png)}");
    this->setParent(p);
    this->setFocus();
    this->width = width;
    this->height = height;
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    Region *Re = new Region(width, height, width / 25);
    Re->mask(this);
    this->raise();
    QFont font;
    font.setWeight(30);
    font.setPixelSize(30);
    usrlabel = new QLabel(this);
    pwdlabel = new QLabel(this);
    pholabel = new QLabel(this);
    login    = new QPushButton(this);
    quit     = new QPushButton(this);
    signup = new QPushButton(this);
    Edit = new QLabel(this);
    usrlabel->setFont(font);
    pwdlabel->setFont(font);
    pholabel->setFont(font);
    login->setGeometry(width / 10, 6 * height / 10, width / 5, height / 10);
    quit->setGeometry(4 * width / 10, 6 * height / 10, width / 5, height / 10);
    signup->setGeometry(7 * width / 10, 6 * height / 10, width / 5, height / 10);
    usrlabel->setAttribute(Qt::WA_TranslucentBackground, true);//透明
    usrlabel->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    pwdlabel->setAttribute(Qt::WA_TranslucentBackground, true);
    pwdlabel->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    pholabel->setAttribute(Qt::WA_TranslucentBackground, true);
    pholabel->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    usrlabel->setGeometry(1 * width / 15, height / 5, width / 5, height / 10);
    pwdlabel->setGeometry(1 * width / 15, 2 * height / 5, width / 5, height / 10);
    pholabel->setGeometry(1 * width / 15, 3 * height / 5, width / 5, height / 10);
    Edit->setGeometry(width / 10, height * 5 / 10 + 20, width / 10 * 8, height / 20);
    Edit->show();
    Edit->setStyleSheet("QLabel{color:rgb(200,0,0);"
                        "font-size:20px"
                        "}");
    Edit->setAlignment(Qt::AlignCenter);
    usrlabel->setText("用户名:");
    pwdlabel->setText("密  码:");
    pholabel->setText("电话号码");
    login->setText("登陆");
    quit->setText("返回");
    signup->setText("注册");
    login->setStyleSheet("QPushButton{border-image: url(:/images/image/button.png);border-radius:20px;}");
    quit->setStyleSheet("QPushButton{border-image: url(:/images/image/button.png);border-radius:20px;}");
    signup->setStyleSheet("QPushButton{border-image: url(:/images/image/button.png);border-radius:20px;}");
    usrinput = new LineEdit(this);
    pwdinput = new LineEdit(this);
    phoneinput = new LineEdit(this);
    QRegExp rx("^1[0-9]{10}$");
    QRegExpValidator *validator = new QRegExpValidator(rx, this);
    phoneinput->setValidator(validator);
    usrinput->setGeometry(width / 4 + 50, height * 13 / 60, width / 2, height / 15);
    usrinput->setFont(font);
    usrinput->setMaxLength(16);
    pwdinput->setGeometry(width / 4 + 50, height * 25 / 60, width / 2, height / 15);
    pwdinput->setFont(font);
    pwdinput->setMaxLength(16);
    pwdinput->setEchoMode(QLineEdit::Password);
    phoneinput->setGeometry(width / 4 + 50, height * 37 / 60, width / 2, height / 15);
    phoneinput->setFont(font);
    phoneinput->setMaxLength(16);
    login->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    quit->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    signup->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    login->setFont(font);
    quit->setFont(font);
    signup->setFont(font);
    connect(login, SIGNAL(clicked()), this, SLOT(loginClicked()));
    connect(quit, SIGNAL(clicked()), this, SLOT(quitClicked()));
    connect(signup, SIGNAL(clicked()), this, SLOT(signupClicked()));
    pholabel->hide();
    phoneinput->hide();
}

void LoginDialog::loginClicked() {
    QString usr = usrinput->text();
    if(usr == "") {
        Edit->setText("请输入用户名");
        return;
    }
    QString pwd = pwdinput->text();
    if(pwd == "") {
        Edit->setText("请输入密码");
        return;
    }
    QString pho = phoneinput->text();
    QString res;
    QString url = ADDR + "/user/";
    if(SignUpMode) {
        if(pho == "") {
            Edit->setText("请输入电话号码");
            return;
        }
        if(pho.length() != 11) {
            Edit->setText("电话号码格式不可用");
            return;
        }
        url += "register?phone=" + pho + "&password=" + pwd + "&name=" + usr;
        res = http.get(url);
        if(res == "-1") {
            Edit->setText("用户名重复");
            return;
        } else if(res == "0") {
            Edit->setText("电话号码重复");
            return;
        }
//        if(res=="1"){
//            this->hide();
//            emit DialogResponse(user);
//        }
    }
    url = ADDR + "/user/" + "loginByName?name=" + usr + "&password=" + pwd;
    QJsonObject Res = http.get_json(url);
    // TODO: Token: how to?
    if (Res.contains("token")) {
        token = Res.value("token").toString();
    }
    User *user = new User(Res);
    if(user->getName() == "") {
        Edit->setText("用户名或密码错误");
        return;
    }
    QList<QString> list;
    list.append("name");
    list.append("phone");
    list.append("avatar");
    list.append("id");
    list.append("friends");
    this->hide();
    emit DialogResponse(user);
}

void LoginDialog::quitClicked() {
    this->hide();
}

LoginDialog::~LoginDialog() {
}

void LoginDialog::signupClicked() {
    this->SignUpMode = !this->SignUpMode;
    if(this->SignUpMode) {
        this->setStyleSheet("QDialog{border-image:url(:/images/image/login11.png)}");
        login->setGeometry(width / 10, 8 * height / 10, width / 5, height / 10);
        quit->setGeometry(4 * width / 10, 8 * height / 10, width / 5, height / 10);
        signup->setGeometry(7 * width / 10, 8 * height / 10, width / 5, height / 10);
        Edit->setGeometry(width / 10, height * 7 / 10 + 20, width / 10 * 8, height / 20);
        Edit->setText("");
        signup->setText("取消");
        pholabel->show();
        phoneinput->show();
    } else {
        Edit->setGeometry(width / 10, height * 5 / 10 + 20, width / 10 * 8, height / 20);
        Edit->setText("");
        this->setStyleSheet("QDialog{border-image:url(:/images/image/login2.png)}");
        pholabel->hide();
        phoneinput->hide();
        signup->setText("注册");
        login->setGeometry(width / 10, 6 * height / 10, width / 5, height / 10);
        quit->setGeometry(4 * width / 10, 6 * height / 10, width / 5, height / 10);
        signup->setGeometry(7 * width / 10, 6 * height / 10, width / 5, height / 10);
    }
}
