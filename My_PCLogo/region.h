#ifndef REGION_H
#define REGION_H
#include <QRegion>
#include <QPushButton>
/**
 *   次Region继承QRegion  用于setmask
 * */
class Region:public QRegion
{
public:
    Region(int width,int height,int radius,QWidget *p);
    void mask(QWidget *p,QPolygon po);
    void mask(QDialog *p,QPolygon po);
    void mask(QPushButton *p,QPolygon po);
};

#endif // REGION_H
