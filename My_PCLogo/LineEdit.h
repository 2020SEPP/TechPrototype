#ifndef LINEEDIT_MY_H
#define LINEEDIT_MY_H

#include <QLineEdit>

class LineEdit: public QLineEdit {
    Q_OBJECT
  public:
    LineEdit(QWidget* parent);
    void keyPressEvent(QKeyEvent* e);
    void focusInEvent(QFocusEvent *e);
    void focusOutEvent(QFocusEvent *e);
  public slots:
    void SlotLineEditDeselect();

};

#endif // LINEEDIT_MY_H
