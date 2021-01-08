#ifndef PVPWINDOW_H
#define PVPWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QDialog>
#include "canvas.h"
#include "console.h"
#include "window.h"
#include "HttpRequest.h"
#include "errorwidget.h"

class PvpWidget : public QWidget {
    Q_OBJECT
  private:
    enum roomtype {
        BATTLE = 0,
        COOPER,
        INIT
    };
  public:
    friend class uniT;
    explicit PvpWidget(QWidget *parent);
    ~PvpWidget() override {}
    void init(int, int, bool);
  private:
    Canvas *canvas;
    Canvas *enermy;
    Console *console;
    Window window;
    QPushButton *exit;
    QPushButton *help;
    int height;
    int width;
    int room;
    int type;
    int cycle;
    bool visible;
    bool owner;
    QTimer *timer;
    HttpRequest http;
    ErrorDialog *error;

  protected:
    virtual void keyPressEvent(QKeyEvent *) override;

  signals:
    void ClosePvP(int);
  public slots:
    void listen();
    void drawLine(qreal, bool);
    void turnDirection(qreal, bool);
    void setXT(qreal, qreal);
    void setPC(uint);
    void setBG(QString);
    void stampoval(qreal, qreal);
    void InAnnimation();
    void exitClicked();
    void errorhandler1();
    void errorhandler2();
    void sendCommand(QString);
};

#endif // PVPWINDOW_H
