#include "loginwidget.h"

LoginWidget::LoginWidget()
{

}

LoginWidget::LoginWidget(int width,int height,QWidget *p){

    this->width=width;
    this->height=height;

    this->setFixedSize(width,height);
    this->setParent(p);
}
