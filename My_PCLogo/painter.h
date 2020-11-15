#ifndef SINGLEWIDGET_H
#define SINGLEWIDGET_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include "canvas.h"
#include "console.h"
#include "window.h"


class SingleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SingleWidget(QWidget *parent);
    ~SingleWidget() {}
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
#endif // SINGLEWIDGET_H
