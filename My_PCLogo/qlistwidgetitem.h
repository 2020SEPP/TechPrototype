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
  public slots:
    void addClicked();
};

#endif // QLISTWIDGETITEM_H
