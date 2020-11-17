#ifndef QLISTWIDGETITEM_H
#define QLISTWIDGETITEM_H

#include <QObject>
#include <QListWidgetItem>
#include "user.h"
class ListWidgetItem:public QWidget
{
public:
    ListWidgetItem(QWidget *p);
    ListWidgetItem(User *u,QWidget *p);
};

#endif // QLISTWIDGETITEM_H
