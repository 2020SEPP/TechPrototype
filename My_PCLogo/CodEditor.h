#ifndef CODEDITOR_H
#define CODEDITOR_H

#include <QWidget>
#include <QMainWindow>

class CodEditor : public QMainWindow
{
    Q_OBJECT
public:
    int WIN_W;
    int WIN_H;
public:
    CodEditor(QWidget *parent, int, int);
    virtual ~CodEditor(){}
};

#endif // CODEDITOR_H
