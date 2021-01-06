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
      friend class uniT;
    explicit PvpWidget(QWidget *parent);
    ~PvpWidget() override {}
  private:
    Canvas *canvas;
    Canvas *enermy;
    Console *console;
    Window window;
    QPushButton *exit;
    QPushButton *help;
    int height;
    int width;
    bool visible;

  protected:
    virtual void keyPressEvent(QKeyEvent *) override;

  signals:
    void ClosePvP(int);

  public slots:
    void setCanvasBG(QString);
    void InAnnimation();
    void exitClicked();
};

#endif // PVPWINDOW_H
