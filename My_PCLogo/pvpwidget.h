#ifndef PVPWINDOW_H
#define PVPWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QKeyEvent>
#include "canvas.h"
#include "console.h"
#include "window.h"
#include "HttpRequest.h"

class PvpWidget : public QWidget {
    Q_OBJECT
  public:
    explicit PvpWidget(QWidget *parent);
    ~PvpWidget() override {}
    void init(int);
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
    bool visible;
    HttpRequest *http;

  protected:
    virtual void keyPressEvent(QKeyEvent *) override;

  signals:
    void ClosePvP(int);
  public slots:
    void drawLine(qreal, bool);
    void turnDirection(qreal, bool);
    void setXT(qreal, qreal);
    void setPC(uint);
    void setBG(QString);
    void stampoval(qreal, qreal);
    void InAnnimation();
    void exitClicked();
};

#endif // PVPWINDOW_H
