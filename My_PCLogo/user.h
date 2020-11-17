#ifndef USER_H
#define USER_H

#include <QString>
#include <QPixmap>

class User
{
private:
    int id;
    QString name;
    QString phone;
    QString password;
    QString avatar;
    QPixmap *image;

public:
    User(){}
    User(QString ph, QString pw) : phone(ph), password(pw){}
    User(int i, QString n, QString ph, QString pw,QString ava) : id(i), name(n), phone(ph), password(pw),avatar(ava){
        image=new QPixmap();
        image->loadFromData(QByteArray::fromBase64(ava.toLocal8Bit()));
    }
    ~User(){}

public:
    int getId() { return id; }
    QString getName() { return name; }
    QString getPhone() { return phone; }
    QString getPassword() { return password; }
    QString getavatar(){return  avatar;}

    void setId(int i) { id = i; }
    void setName(QString n) { name = n; }
    void setPhone(QString ph) { phone = ph; }
    void setPassword(QString pw) { password = pw; }
    bool hasImage(){return !( this->image==nullptr) ;}
    QPixmap* getPix(){return image;}

    QString toJsonObeject(bool withId) {
        QString Json = "{";
        if (withId) {
            Json += "\"id\": " + QString::number(id) + ", ";
        }

        Json += "\"phone\": \"" + phone + "\", \
                 \"password\": \"" + password + "\"}";
        return Json;
    }

};



#endif // USER_H
