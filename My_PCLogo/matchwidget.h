#ifndef MATCHWIDGET_H
#define MATCHWIDGET_H

#include "window.h"
#include "region.h"
#include "HttpRequest.h"
#include "user.h"
#include "LineEdit.h"
#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include "token.h"

class MatchDialog : public QDialog {
    Q_OBJECT

    enum btnStat {
        MODE = 0,
        CREATE,
        CERTAIN,
        RANDOM,
        MATCH,
        CONFIRM,
        CANCEL
    };

  private:
    int width;
    int height;
    Window window;

    QPushButton *createRoom;
    QPushButton *certainRoom;
    QPushButton *randomRoom;
    QPushButton *quitRoom;
    QPushButton *cnfm;
    QPushButton *back;
    QPushButton *btn;
    QLabel *room;
    QLabel *title;
    LineEdit *roominput;
    btnStat stat;
    int currroom;
    HttpRequest http;

  private:
    void btnDisplay(bool);

  private slots:
    void createClicked();
    void certainClicked();
    void randomClicked();
    void quitClicked();
    void cnfmClicked();
    void backClicked();
    void btnClicked();

  public:
    MatchDialog();
    MatchDialog(int widght, int height, QWidget *p = nullptr);
    ~MatchDialog() override;

  signals:
    void EnterRoom(int);
    void DialogResponse(User *);

  protected:
    virtual void paintEvent(QPaintEvent *) override;
};


#endif // MATCHWIDGET_H
