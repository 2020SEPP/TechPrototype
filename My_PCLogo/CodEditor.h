#ifndef CODEDITOR_H
#define CODEDITOR_H

#include "window.h"

#include <QWidget>
#include <QList>
#include <QMainWindow>

#include "Qsci/qsciscintilla.h"
#include "Qsci/qsciapis.h"
#include "qscilexerLogo.h"
#include "Qsci/qscilexerpython.h"

class CodEditor : public QWidget {
    Q_OBJECT
  private:
    Window window;
    QsciScintilla *editor;
    QList<int> points;

  public:
    int WIN_W;
    int WIN_H;

  public:
    CodEditor(QWidget *parent = nullptr);
    virtual ~CodEditor() override {}

  public:
    QString getAllContent();
    void setContent(QString);
    QList<int> getPoints();

  private slots:
    void addMarker(int, int, Qt::KeyboardModifiers);

  signals:
    void CloseEditor(int);
    void Mark();
};

#endif // CODEDITOR_H
