#ifndef PVPWINDOW_H
#define PVPWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QKeyEvent>

#include "canvas.h"
#include "console.h"
#include "window.h"

class PvpWidget : public QWidget {
    Q_OBJECT
  public:
    explicit PvpWidget(QWidget *parent);
    ~PvpWidget() override {}
  private:
    Canvas *canvas;
    Console *console;
    Window window;
    int WIN_H;
    int WIN_W;
    bool visible;

  signals:
    void ClosePvP(int);

  public slots:
    void setCanvasBG(QString);
    void InAnnimation();

  protected:
    virtual void keyPressEvent(QKeyEvent *) override;
};

#endif // PVPWINDOW_H
