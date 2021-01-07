#ifndef QLISTWIDGETITEM_H
#define QLISTWIDGETITEM_H

#include <QObject>
#include <QListWidgetItem>
#include "user.h"

class ListWidgetItem: public QWidget {
    Q_OBJECT
  private:
    User user;
  public:
    ListWidgetItem(QWidget *p);
    ListWidgetItem(User *u, QWidget *p);
    ListWidgetItem(User *u, int flag, QWidget *p);
    void setFriend(bool);
  public slots:
    void addClicked();
    void acceptClicked();
    void rejectClicked();
};

#endif // QLISTWIDGETITEM_H
