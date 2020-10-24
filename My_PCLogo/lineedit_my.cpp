#include "lineedit_my.h"
#include <stdbool.h>

LineEdit::LineEdit(QWidget* parent)
 : QLineEdit(parent)
{
  setReadOnly(true);
  this->setCursor(Qt::PointingHandCursor);
  this->setStyleSheet(
                          "QLineEdit{border-image:url(:/images/input.png);background:rgba(0,200,128,0);padding-left:30px;}"

                          );
  this->setAttribute(Qt::WA_MacShowFocusRect, 0);
  connect(this,SIGNAL(selectionChanged()),this,SLOT(SlotLineEditDeselect()));
}

void LineEdit::keyPressEvent(QKeyEvent* e)
{
  setReadOnly(false);
   QLineEdit::keyPressEvent(e);

  setReadOnly(true);
}

void LineEdit::focusInEvent(QFocusEvent *e){
    this->setStyleSheet(
                "QLineEdit{border-image:url(:/images/input.png);background:rgba(255,255,255,0.9);padding-left:30px;}"

                                                  );
    QLineEdit::focusInEvent(e);
}
void LineEdit::focusOutEvent(QFocusEvent *e){
    this->setStyleSheet(
                "QLineEdit{border-image:url(:/images/input.png);background:rgba(0,200,128,0);padding-left:30px;}"
                        );
    QLineEdit::focusOutEvent(e);
}

void LineEdit::SlotLineEditDeselect(){
    this->deselect();
}
