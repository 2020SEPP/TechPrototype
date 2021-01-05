#ifndef MATCHWIDGET_H
#define MATCHWIDGET_H

#include "window.h"
#include "region.h"
#include "HttpRequest.h"
#include "user.h"

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include "token.h"

class MatchDialog : public QDialog {
    Q_OBJECT

    enum btnStat {
        MATCH = 0,
        CONFIRM,
        CANCEL
    };

  private:
    friend class uniT;
    int width;
    int height;
    bool SignUpMode = false;
    Window window;

    QLabel *usrlabel;
    QLabel *pwdlabel;
    QPushButton *btn;
    btnStat stat;

    HttpRequest http;

  private slots:
    void btnClicked();

  public:
    MatchDialog();
    MatchDialog(int widght, int height, QWidget *p = nullptr);
    ~MatchDialog();

  signals:
    void DialogResponse(User *);
};


#endif // MATCHWIDGET_H
