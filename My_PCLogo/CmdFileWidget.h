#ifndef CMDFILEWIDGET_H
#define CMDFILEWIDGET_H

#include <QWidget>
#include <QPushButton>

#include "window.h"
#include "CodEditor.h"
#include "canvas.h"

class CmdFileWidget : public QWidget {
    Q_OBJECT
  private:
    int WIN_W;
    int WIN_H;
    Window window;

  public:
    bool step;
    int point = -1;
    QList<int> points;

    QString Curr_file;
    QPushButton *import;
    QPushButton *save;
    QPushButton *run;
    QPushButton *debug;
    QPushButton *exit;
    Canvas *canvas;
    CodEditor *editor;

  public:
    CmdFileWidget(QWidget *);
    ~CmdFileWidget() {}

  signals:
    void CloseCmdFile(int);

  private slots:
    void Import();
    void Save();
    void Run();
    void Debug();
    void Exit();
    void MarkChanged();

  private:
    bool saveAs();
    bool saveFile(QString filename);
};

#endif // CMDFILEWIDGET_H
