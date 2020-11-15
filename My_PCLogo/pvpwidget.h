#ifndef PVPWINDOW_H
#define PVPWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include "canvas.h"
#include "console.h"
#include "window.h"


class PvpWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PvpWidget(QWidget *parent);
    ~PvpWidget() {}
private:
    Canvas *canvas;
    Console *console;
    Window window;
    int height;
    int width;
    bool visible;


signals:

public slots:
    void setCanvasBG(QString);
    void InAnnimation();
};

#endif // PVPWINDOW_H
