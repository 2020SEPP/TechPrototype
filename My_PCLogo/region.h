#ifndef REGION_H
#define REGION_H
#include <QRegion>
#include <QPushButton>
/**
 *   次Region继承QRegion  用于setmask
 * */
class Region:public QRegion
{
private:
    QPainterPath path;
    QRectF *rect;
    QPolygon po;
public:
    Region(int width,int height,int radius);
    void mask(QWidget *p);

};

#endif // REGION_H
