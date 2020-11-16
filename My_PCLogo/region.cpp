#include "region.h"

Region::Region(int width, int height,int radius)
{
    rect = new QRectF(0,0,width,height);  //两点确定矩形范围，一般为控件大小，这样可以切割四个圆角，也可以调整大小，调整圆角个数
//    path.addRoundedRect(*rect, radius, radius);   //后面两个参数的范围0-99，值越大越园
    path.addRoundRect(*rect, radius, radius);
    po= path.toFillPolygon().toPolygon();//获得这个路径上的所有的点
    //根据这些点构造这个区域
//    p->setMask(polygon);
}

void Region::mask(QWidget *p){
    p->setMask(po);
}
