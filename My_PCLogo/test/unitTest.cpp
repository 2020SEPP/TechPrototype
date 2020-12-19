#include <test/unitTest.h>
#include <QtGui>
#include <QDebug>
using namespace  QTest;
void uniT::_User(){

//    user.setName("ddd");
//    QCOMPARE(user.getName(),"ddd");
//    QCOMPARE(user.name,"ddd");
}



void uniT::_User_data(){
//    addColumn<int>("id");
//    addColumn<QString>("name");
}


void uniT::_signinwidget_basic_data(){
    addColumn<int>("Index");   // 1 for  name 2 for pwd 3 for phone
    addColumn<QString>("input");
    addColumn<QString>("expect");

    newRow("short name  (15) abcdefghijklmno")<<1<<"abcdefghijklmno"<<"abcdefghijklmno";
    newRow("exact name  (16) abcdefghijklmnop")<<1<<"abcdefghijklmnop"<<"abcdefghijklmnop";
    newRow("long name   (17) abcdefghijklmnopq")<<1<<"abcdefghijklmnopq"<<"abcdefghijklmnop";
    newRow("short password  (15) abcdefghijklmno")<<2<<"abcdefghijklmno"<<"abcdefghijklmno";
    newRow("exact password  (16) abcdefghijklmnop")<<2<<"abcdefghijklmnop"<<"abcdefghijklmnop";
    newRow("long password   (17) abcdefghijklmnopq")<<2<<"abcdefghijklmnopq"<<"abcdefghijklmnop";
    newRow("short phone  (10) 1234567890")<<3<<"1234567890"<<"1234567890";
    newRow("exact phone  (11) 18796700152")<<3<<"18796700152"<<"18796700152";
    newRow("long phone   (12) 187967001523")<<3<<"187967001523"<<"18796700152";
    newRow("error phone 28796700152")<<3<<"28796700152"<<"152";
    newRow("error phone 28796700252")<<3<<"28796700252"<<"";

}



void uniT::_signinwidget_basic(){
    LoginDialog login(800,600);
    QFETCH(int,Index);
    QFETCH(QString,input);
    QFETCH(QString,expect);
    switch (Index) {
    case 1:
        keyClicks(login.usrinput,input);
        QCOMPARE(login.usrinput->text(),expect);
        break;
    case 2:
        keyClicks(login.pwdinput,input);
        QCOMPARE(login.pwdinput->text(),expect);
        break;
    case 3:
        keyClicks(login.phoneinput,input);
        QCOMPARE(login.phoneinput->text(),expect);
        break;
    }
}



void uniT::_signinwidget_ui_data(){
    addColumn<int>("Index"); //1 for signupbutton 2for name 3 for pwd 4 for phone
    addColumn<QTestEventList>("events");
    addColumn<QString>("expect");


    QTestEventList  clicksignup;
    clicksignup.addMouseClick(Qt::LeftButton);
    newRow("clickSignupButton")<<1<<clicksignup<<"取消";

    QTestEventList returntoLogin;
    returntoLogin.addMouseClick(Qt::LeftButton);
    returntoLogin.addMouseClick(Qt::LeftButton);
    newRow("return to login page")<<1<<returntoLogin<<"注册";

    QTestEventList editname;
    editname.addKeyClicks("popop");
    editname.addKeyClick(Qt::Key_Backspace);
    newRow("edit name")<<2<<editname<<"popo";

    QTestEventList editpwd;
    editpwd.addKeyClicks("123455");
    editpwd.addKeyClick(Qt::Key_Backspace);
    newRow("edit pwd")<<3<<editpwd<<"12345";

    QTestEventList editpho;
    editpho.addKeyClicks("18796700152");
    editpho.addKeyClick(Qt::Key_Backspace);
    newRow("edit pho")<<4<<editpho<<"1879670015";

}


void uniT::_signinwidget_ui(){
    LoginDialog login(800,600);
    QFETCH(int,Index);
    QFETCH(QTestEventList,events);
    QFETCH(QString,expect);
    switch (Index) {
    case 1:
        events.simulate(login.signup);
        QCOMPARE(login.signup->text(),expect);
         break;
    case 2:
        events.simulate(login.usrinput);
        QCOMPARE(login.usrinput->text(),expect);
        break;
    case 3:
        events.simulate(login.pwdinput);
        QCOMPARE(login.pwdinput->text(),expect);
        break;
    case 4:
        events.simulate(login.phoneinput);
        QCOMPARE(login.phoneinput->text(),expect);
        break;

    }
}


void uniT::_signinwidget_advance_data(){
    addColumn<bool>("op"); //   0  login    1 register
    addColumn<QString>("name");
    addColumn<QString>("password");
    addColumn<QString>("phone");
    addColumn<QString>("message");
    newRow("login without username ( has no password ) ")<<false<<""<<""<<""<<"请输入用户名";
    newRow("login without username ( has password ) ")<<false<<""<<"123456"<<""<<"请输入用户名";
    newRow("login without password" )<<false<<"the_junhan"<<""<<""<<"请输入密码";
    newRow("register without username ( has password or phone ) ")<<true<<""<<"123456"<<"18796700152"<<"请输入用户名";
    newRow("register without username ( has no password or phone ) ")<<true<<""<<""<<""<<"请输入用户名";
    newRow("register with error name ( exist name ) ")<<true<<"poker0"<<"123456"<<"18796700199"<<"用户名重复";
    newRow("register without password ( has phone ) ")<<true<<"the_junhan"<<""<<"18796700152"<<"请输入密码";
    newRow("register without password ( has no phone ) ")<<true<<"the_junhan"<<""<<""<<"请输入密码";
    newRow("register with no phone")<<true<<"the_junhan"<<"123456"<<""<<"请输入电话号码";
    newRow("register with error phone ( error length ) ")<<true<<"the_junhan"<<"123456"<<"1879670015"<<"电话号码格式不可用";
    newRow("register with error phone ( exist phone )")<<true<<"the_junhan"<<"123456"<<"18796700152"<<"电话号码重复";
}

void uniT::_signinwidget_advance(){
    LoginDialog login(800,600);
    QFETCH(bool,op);
    QFETCH(QString,name);
    QFETCH(QString,password);
    QFETCH(QString,phone);
    QFETCH(QString,message);

    if(!op){
        login.usrinput->setText(name);
        login.pwdinput->setText(password);
        mouseClick(login.login,Qt::LeftButton);
        QCOMPARE(login.Edit->text(),message);
    }else{
        mouseClick(login.signup,Qt::LeftButton);
        login.usrinput->setText(name);
        login.pwdinput->setText(password);
        login.phoneinput->setText(phone);
        mouseClick(login.login,Qt::LeftButton);
        QCOMPARE(login.Edit->text(),message);
    }

}


QTEST_MAIN(uniT);
//#include "unit.moc"
