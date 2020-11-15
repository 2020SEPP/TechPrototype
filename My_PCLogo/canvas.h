#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

/*
    | 小海龟的前后、转向 | FD, BK, RT, LT  n |
    | 清屏复位 | LT |
    | 提笔、落笔 | PU, PD |
    | 坐标定位 | SETXT[x y]|
    | 设置笔的颜色 | SETPC n (n为颜色号) |
    | 设置背景的颜色 | SETBG n, n为颜色号 |
    | 画圆 | STAMPOVAL x y (x 表示横向半径，y表示纵向半径) |
    | 重复命令 | Repeat n [ ], 即[]内的命令重复n次 |
    | 移到行首、移到行尾 | Home, End |
    | 命令的编辑功能 | copy (Ctrl + C), Cut(Ctrl+X), Paste(Ctrl+V) 等 |
 */

const QStringList INSTRUCTIONS = {
    "fd", "bk", "rt", "lt",
    "cs", "pu", "pd",
    "setxy", "setpc", "setbg",
    "stampoval", "repeat"
};

typedef struct circle
{
    QPointF center;
    qreal rx;
    qreal ry;
} circle_t;

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas() override { LINES.clear(); }

private:
    int CANVAS_WIDTH, CANVAS_HEIGHT;
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
