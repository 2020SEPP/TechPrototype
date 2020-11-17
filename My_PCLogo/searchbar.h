#ifndef SEARCHBAR_H
#define SEARCHBAR_H

#include <QObject>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
class Searchbar :public QLineEdit
{
public:
    Searchbar(QWidget *p,int w,int h);
};

#endif // SEARCHBAR_H
