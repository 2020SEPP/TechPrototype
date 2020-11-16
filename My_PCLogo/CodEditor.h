#ifndef CODEDITOR_H
#define CODEDITOR_H

#include "window.h"

#include <QWidget>
#include <QMainWindow>

#include "Qsci/qsciscintilla.h"
#include "Qsci/qsciapis.h"
#include "LogoLexer.h"
#include "Qsci/qscilexerpython.h"

class CodEditor : public QWidget
{
    Q_OBJECT
private:
    Window window;
    QsciScintilla *editor;
public:
    int WIN_W;
    int WIN_H;
public:
    CodEditor(QWidget *parent = nullptr);
    virtual ~CodEditor() override {}

public:
    QString getAllContent();
    void setContent(QString);

signals:
    void CloseEditor(int);
};

#endif // CODEDITOR_H
