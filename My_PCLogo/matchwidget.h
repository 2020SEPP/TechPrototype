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
#include <QTimer>
#include <QPixmap>
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
    bool waiting; // create waiting
    QPushButton *certainRoom;
    QPushButton *randomRoom;
    QPushButton *quitRoom;
    QPushButton *cnfm;
    QPushButton *back;
    QPushButton *vs;
    QPushButton *battle;
    QPushButton *cooper;
    QPushButton *coming;
    QPushButton *back_1;
    QLabel *room;
    QLabel *title;
    LineEdit *roominput;
    btnStat stat;
    int currroom;
    HttpRequest http;
    int type; // 0: BATTLE 1: COOPER
    QPixmap one, two;

  private:
    void btnDisplay(int);
    QTimer *timer;
  private slots:
    void listen();
    void battleClicked();
    void cooperClicked();
    void back_1Clicked();
    void createClicked();
    void certainClicked();
    void randomClicked();
    void quitClicked();
    void cnfmClicked();
    void backClicked();

  public:
    MatchDialog();
    MatchDialog(int widght, int height, QWidget *p = nullptr);
    ~MatchDialog() override;
    void init();

  signals:
    void EnterRoom(int, int, bool);
    void DialogResponse(User *);

  protected:
    virtual void paintEvent(QPaintEvent *) override;
};


#endif // MATCHWIDGET_H
