#include "signinwidget.h"

#include <QBrush>
#include <QPalette>
#include <QtCore>

QList<User *> getFriend(int uid)
{
    HttpRequest http;
    QString url = ADDR + "/user/getFriend?uid=" + QString::number(uid);
    QJsonArray res = http.get_array(url);

    QList<User *> users;

    for (int i = 0; i < res.size(); ++i)
    {
        QJsonObject object = res.at(i).toObject();
        User *user = new User(object);
        users.append(user);
    }

    return users;
}

LoginDialog::LoginDialog()
{
}

LoginDialog::LoginDialog(int width, int height, QWidget *p)
{
    p->setVisible(0);
    this->setStyleSheet("QDialog{border-image:url(:/images/image/login2.png)}");
    this->setParent(p);
    this->setFocus();
    this->width=width;
    this->height=height;
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    Region *Re = new Region(width,height,width/25);
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
    signup= new QPushButton(this);

    usrlabel->setFont(font);
    pwdlabel->setFont(font);
    pholabel->setFont(font);
    login->setGeometry(width/10,6*height/10,width/5,height/10);
    quit->setGeometry(4*width/10,6*height/10,width/5,height/10);
    signup->setGeometry(7*width/10,6*height/10,width/5,height/10);
    usrlabel->setAttribute(Qt::WA_TranslucentBackground, true);//透明
    usrlabel->setAlignment(Qt::AlignCenter|Qt::AlignCenter);
    pwdlabel->setAttribute(Qt::WA_TranslucentBackground,true);
    pwdlabel->setAlignment(Qt::AlignCenter|Qt::AlignCenter);
    pholabel->setAttribute(Qt::WA_TranslucentBackground, true);
    pholabel->setAlignment(Qt::AlignCenter|Qt::AlignCenter);
    usrlabel->setGeometry(1*width/15,height/5,width/5,height/10);
    pwdlabel->setGeometry(1*width/15,2*height/5,width/5,height/10);
    pholabel->setGeometry(1*width/15,3*height/5,width/5,height/10);
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
    phoneinput=new LineEdit(this);


    usrinput->setGeometry(width/4+50,height*13/60,width/2,height/15);
    usrinput->setFont(font);
    usrinput->setMaxLength(16);


    pwdinput->setGeometry(width/4+50,height*25/60,width/2,height/15);
    pwdinput->setFont(font);
    pwdinput->setMaxLength(16);
    pwdinput->setEchoMode(QLineEdit::Password);

    phoneinput->setGeometry(width/4+50,height*37/60,width/2,height/15);
    phoneinput->setFont(font);
    phoneinput->setMaxLength(16);

    login->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    quit->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    signup->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    login->setFont(font);
    quit->setFont(font);
    signup->setFont(font);

    connect(login,SIGNAL(clicked()),this,SLOT(loginClicked()));
    connect(quit,SIGNAL(clicked()),this,SLOT(quitClicked()));
    connect(signup,SIGNAL(clicked()),this,SLOT(signupClicked()));

    pholabel->hide();
    phoneinput->hide();
}

void LoginDialog::loginClicked()
{
//    QString usr = usrinput->text();
//    QString pwd = pwdinput->text();
    QString usr = "laffery";
    QString pwd = "111111";
    QString pho = phoneinput->text();
    QString res;
    User user(usr, pwd);
    QString url = ADDR + "/user/";

    if(SignUpMode){
        url += "register?phone="+pho+"&password="+pwd+"&name="+usr;
        res = http.get(url);
        qDebug() << url;
        if(res=="1"){
            this->hide();
            emit LoginResponse(true);
        }
    }
    else{

        url += "loginByName?name="+usr+"&password="+pwd;
        qDebug() << url;
        QJsonObject res = http.get_json(url);

        // TODO: Token: how to?
//        if (object.contains("token"))
//        {
//            QString token = object.value("token").toString();
//        }

        User *user = new User(res);

        QList<QString> list;
        list.append("name");
        list.append("phone");
        list.append("avatar");
        list.append("id");
        list.append("friends");
        qDebug() << user->toJsonObject(list);
    }
//    qDebug() << res<<"res";
    emit LoginResponse(true);

}

void LoginDialog::quitClicked(){
    this->hide();
}

LoginDialog::~LoginDialog(){

}

void LoginDialog::signupClicked(){
    this->SignUpMode=!this->SignUpMode;
    if(this->SignUpMode){
        this->setStyleSheet("QDialog{border-image:url(:/images/image/login11.png)}");
        login->setGeometry(width/10,8*height/10,width/5,height/10);
        quit->setGeometry(4*width/10,8*height/10,width/5,height/10);
        signup->setGeometry(7*width/10,8*height/10,width/5,height/10);
        signup->setText("取消");
        pholabel->show();
        phoneinput->show();
    }
    else{
        this->setStyleSheet("QDialog{border-image:url(:/images/image/login2.png)}");
        pholabel->hide();
        phoneinput->hide();
        signup->setText("注册");
        login->setGeometry(width/10,6*height/10,width/5,height/10);
        quit->setGeometry(4*width/10,6*height/10,width/5,height/10);
        signup->setGeometry(7*width/10,6*height/10,width/5,height/10);
    }
}
