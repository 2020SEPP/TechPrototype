#ifndef CODEDITOR_H
#define CODEDITOR_H

#include "window.h"

#include <QWidget>
#include <QMainWindow>

class CodEditor : public QWidget
{
    Q_OBJECT
private:
    Window window;
public:
    int WIN_W;
    int WIN_H;
public:
    CodEditor(QWidget *parent = nullptr);
    virtual ~CodEditor() override {}

protected:
    virtual void keyPressEvent(QKeyEvent *) override;

signals:
    void CloseEditor(int);
};

#endif // CODEDITOR_H
