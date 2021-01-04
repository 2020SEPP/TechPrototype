#ifndef CONSOLE_H
#define CONSOLE_H

#include <QWidget>
#include <QTextEdit>
#include <QPainter>
#include <QKeyEvent>

class Console : public QTextEdit {
    Q_OBJECT
  public:
    explicit Console(QWidget *parent = nullptr);
    ~Console() override {}
    void clear();
    void write(QString);
    void writetoStorage(QString);
    void parse_line(QString);

  private:
    QString storage;
  protected:
    virtual void keyPressEvent(QKeyEvent *) override;

  public slots:
    void wrap();

  signals:
    void enter();
    void newLine(QString);
    void reset();
    void drawLine(qreal, bool);
    void turnDirection(qreal, bool);
    void penDown();
    void penUp();
    void setXT(qreal, qreal);
    void setPC(uint);
    void setBG(QString);
    void stampoval(qreal, qreal);

};

#endif // CONSOLE_H
