#ifndef SEARCHBAR_H
#define SEARCHBAR_H

#include <QObject>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>

class Searchbar : public QLineEdit {
    Q_OBJECT
  private:
    bool searching = false;
    QPushButton *searchBtn;
    QPushButton *cancelBtn;
  public:
    Searchbar(QWidget *p, int w, int h);

  public  slots:
    void buttonclicked();
    void cancelclicked();

  signals:
    void Search(QString s);

  protected:
    virtual void keyPressEvent(QKeyEvent *) override;
};

#endif // SEARCHBAR_H
