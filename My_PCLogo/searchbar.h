#ifndef SEARCHBAR_H
#define SEARCHBAR_H

#include <QObject>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
class Searchbar :public QLineEdit
{
    Q_OBJECT
public:
    Searchbar(QWidget *p,int w,int h);

  public  slots:
      void buttonclicked();

signals:
    void Search(QString s);
};

#endif // SEARCHBAR_H
