#ifndef REGION_H
#define REGION_H

#include <QRegion>
#include <QPainterPath>
#include <QWidget>

class Region:public QRegion
{
private:
    QPainterPath path;
    QRectF *rect;
    QPolygon po;
public:
    Region(int width,int height,int radius);
    ~Region() {}
    void mask(QWidget *p);
};

#endif // REGION_H
