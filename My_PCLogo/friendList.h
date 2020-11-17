#ifndef FRIENDLIST_H
#define FRIENDLIST_H

#include <QObject>
#include <QWidget>
#include <QListWidget>
#include "searchbar.h"
#include "user.h"
class FriendList:public QWidget
{
    Q_OBJECT
private:
    int WIN_W;
    int WIN_H;
    int p_H;
    bool visible;
    QListWidget *friends;
    Searchbar *sb;
public:
    FriendList(QWidget *p,int w,int h);
    void annimation();
    void setFriends(QList<User> FL);
};

#endif // FRIENDLIST_H
