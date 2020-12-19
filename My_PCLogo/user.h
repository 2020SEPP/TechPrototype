#ifndef USER_H
#define USER_H

#include <QString>
#include <QPixmap>

#include <QJsonObject>
#include <QJsonArray>
#include <HttpRequest.h>

class User {
  private:
      friend class uniT;
    int id;
    QString name;
    QString phone;
    QString password;
    QString avatar;
    QPixmap *image;
    QList<int> friends;

  public:
    User() {}
    User(QJsonObject object) {
        if (object.contains("name")) {
            name = object.value("name").toString();
        }
        if (object.contains("phone")) {
            phone = object.value("phone").toString();
        }
        if (object.contains("uid")) {
            id = object.value("uid").toInt();
        }
        if (object.contains("avatar")) {
            avatar = object.value("avatar").toString();
        }
        if (object.contains("friends")) {
            friends = JsonValue2ListInt(object.value("friends"));
        }
    }
    User(QString ph, QString pw) : phone(ph), password(pw) {}
    User(int i, QString n, QString ph, QString pw, QString ava)
        : id(i), name(n), phone(ph), password(pw), avatar(ava) {
        image = new QPixmap();
        image->loadFromData(QByteArray::fromBase64(ava.toLocal8Bit()));
    }
    ~User() {}

  public:
    int getId() {
        return id;
    }
    QString getName() {
        return name;
    }
    QString getPhone() {
        return phone;
    }
    QString getPassword() {
        return password;
    }
    QString getavatar() {
        return  avatar;
    }
    QList<int> getFriends() {
        return friends;
    }
    QPixmap* getPix() {
        return image;
    }

    void setId(int i) {
        id = i;
    }
    void setName(QString n) {
        name = n;
    }
    void setPhone(QString ph) {
        phone = ph;
    }
    void setPassword(QString pw) {
        password = pw;
    }
    void setAvatar(QString av) {
        avatar = av;
    }
    void setFriends(QList<int> f) {
        friends.clear();
        for (int i = 0; i < f.size(); ++i)
            friends.append(f.at(i));
    }
    bool hasImage() {
        return !( this->image == nullptr);
    }

    QString toJsonObeject(bool withId) {
        QString Json = "{";
        if (withId) {
            Json += "\"id\": " + QString::number(id) + ", ";
        }
        Json += "\"phone\": \"" + phone + "\", \
                 \"password\": \"" + password + "\"}";
        return Json;
    }

    QJsonObject toJsonObject(QList<QString> items) {
        QJsonObject object;
        if (items.contains("id"))
            object.insert("uid", id);
        if (items.contains("name"))
            object.insert("name", name);
        if (items.contains("avatar"))
            object.insert("avatar", avatar);
        if (items.contains("phone"))
            object.insert("phone", phone);
        if (items.contains("password"))
            object.insert("password", password);
        if (items.contains("friends")) {
            QJsonArray array;
            for (int i = 0; i < friends.size(); ++i) {
                array.append(friends.at(i));
            }
            object.insert("friends", QJsonValue(array));
        }
        return object;
    }
};

#endif // USER_H
