#ifndef CMDFILEWIDGET_H
#define CMDFILEWIDGET_H

#include <QWidget>
#include <QPushButton>

#include "window.h"
#include "CodEditor.h"
#include "canvas.h"

class CmdFileWidget : public QWidget
{
    Q_OBJECT
private:
    int WIN_W;
    int WIN_H;
    Window window;

public:
    bool step;
    QString Curr_file;
    QPushButton *import;
    QPushButton *run;
    Canvas *canvas;
    CodEditor *editor;

public:
    CmdFileWidget(QWidget *);
    ~CmdFileWidget() {}

signals:
    void CloseCmdFile(int);

private slots:
    void Import();
    void Run();
};

#endif // CMDFILEWIDGET_H
