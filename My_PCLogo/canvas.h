#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QIcon>
#include <QPainter>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>

typedef struct circle {
    QPointF center;
    qreal rx;
    qreal ry;
} circle_t;

class Canvas : public QWidget {
    Q_OBJECT
  public:
      friend class uniT;
    explicit Canvas(QWidget *, int, int, int, int);
    ~Canvas() override {
        LINES.clear();
        CIRCLES.clear();
    }

  private:
    int CANVAS_XPOS = 0, CANVAS_YPOS = 0;
    int CANVAS_WIDTH, CANVAS_HEIGHT;

    QPixmap pixmap;
    QLabel *turtle;
    int TURTLE_SIZE = 80;

    QPointF *CURR_POS;
    qreal CURR_ANGLE;

    bool PEN_IS_DOWN;
    QPen pen;

    QVector<QLineF> LINES;
    QVector<circle_t> CIRCLES;

  public:
    void addAngle(qreal);

  signals:
    void setBG(QString);
    void write(QString);

  public slots:
    void parse_line(QString);
    void drawLine(qreal, bool);
    void turnDirection(qreal, bool);
    void reset();
    void penDown();
    void penUp();
    void setXT(qreal, qreal);
    void setPC(uint);
    void stampoval(qreal, qreal);

  protected:
    virtual void paintEvent(QPaintEvent *ev) override;
};

#endif // CANVAS_H
