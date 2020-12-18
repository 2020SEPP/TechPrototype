#ifndef HELPTEXT_H
#define HELPTEXT_H
#include <QDialog>
#include <QPushButton>
#include <QTextEdit>

class HelpText : public QDialog
{
    Q_OBJECT

private:
    int width;
    int height;
    QPushButton *close;
    QTextEdit *text;
public:
    HelpText(int wid, int hei, QWidget *p);
    ~HelpText();
public slots:
    void help_close();
};

#endif // HELPTEXT_H
