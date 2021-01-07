#ifndef ERRORWIDGET_H
#define ERRORWIDGET_H

#include "window.h"
#include "region.h"

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QPushButton>

class ErrorDialog : public QDialog {
    Q_OBJECT

  private:
    friend class uniT;
    int width;
    int height;
    Window window;

    QLabel *title;
    QLabel *cntnt;
    QPushButton *cnfm;
    QPushButton *quit;

  private slots:
    void quitClicked();
    void cnfmClicked();

  signals:
    void quited();
    void cnfmed();

  public:
    ErrorDialog();
    ErrorDialog(int widght, int height, QWidget *p = nullptr);
    ~ErrorDialog();

  signals:
};

#endif // ERRORWIDGET_H
