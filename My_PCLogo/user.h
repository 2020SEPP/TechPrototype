#ifndef USER_H
#define USER_H

#include <QString>

class User
{
private:
    int id;
    QString name;
    QString phone;
    QString password;

private:
    User(){}
    User(int i, QString n, QString ph, QString pw) : id(i), name(n), phone(ph), password(pw){}
    ~User(){}

public:
    int getId() { return id; }
    QString getName() { return name; }
    QString getPhone() { return phone; }
    QString getPassword() { return password; }

    void setId(int i) { id = i; }
    void setName(QString n) { name = n; }
    void setPhone(QString ph) { phone = ph; }
    void setPassword(QString pw) { password = pw; }


};



#endif // USER_H
