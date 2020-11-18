#include "canvas.h"
#include <QApplication>
#include <QStyleOption>
#include <QDebug>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    CANVAS_WIDTH = (parent->width() * 3) / 4;
    CANVAS_HEIGHT = (parent->height() * 3) / 4;
    CURR_POS = new QPointF(parent->width() / 2, CANVAS_HEIGHT / 2);
    CURR_ANGLE = 90;
    PEN_IS_DOWN = true;


}

Canvas::Canvas(QWidget *parent, int xPos, int yPos, int xScale, int yScale)
    : QWidget(parent)
{
    CANVAS_XPOS = xPos;
    CANVAS_YPOS = yPos;
    CANVAS_WIDTH = xScale;
    CANVAS_HEIGHT = yScale;
    CURR_POS = new QPointF(CANVAS_XPOS + CANVAS_WIDTH/2, CANVAS_YPOS + CANVAS_HEIGHT / 2);
    CURR_ANGLE = 90;
    PEN_IS_DOWN = true;
}

// public
void
Canvas::addAngle(qreal delta)
{
    CURR_ANGLE += delta;

    if (CURR_ANGLE >= 360)
        CURR_ANGLE -= 360;
    else if (CURR_ANGLE < 0)
        CURR_ANGLE += 360;
}

void
Canvas::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    p.setPen(pen);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    for (QLineF line : LINES)
    {
        p.drawLine(line);
    }

    for (circle_t cl : CIRCLES)
    {
        p.drawEllipse(cl.center, cl.rx, cl.ry);
    }

    const QPointF curr(CURR_POS->rx(), CURR_POS->ry());
    p.drawPoint(curr);
}

// UTILS

QString get_qreal_str(QString str)
{
    int index = 0;
    while (index < str.length())
    {
        QChar ch = str.at(index);
        if ((ch >= '0' && ch <= '9') || ch == '.')
        {
            index++;
        }

        else if (ch == ' ' || ch == ']')
        {
            break;
        }

        else
        {
            return "";
        }
    }

    return str.left(index);
}

// SLOT
void
Canvas::parse_line(QString line)
{
    line = line.trimmed();
    if (line == "")
        return;


    int line_index = 0;
    QString inst;

    while (line_index < line.length() && line.at(line_index) != ' ')
        line_index++;

    inst = line.left(line_index);

    if (INSTRUCTIONS.indexOf(inst) != -1)
    {
        bool zro_arg_flag = false;
        bool one_arg_flag = false;
        bool two_arg_flag = false;

        if (inst == "cs" || inst == "pu" || inst == "pd")
        {
            zro_arg_flag = true;
            if (inst == "cs")
                reset();
            else if (inst == "pu")
                penUp();
            else if (inst == "pd")
                penDown();
        }

        line = line.right(line.length() - line_index).trimmed();

        if (zro_arg_flag)
        {
            parse_line(line);
            return;
        }

        QString arg0 = get_qreal_str(line);

        if (arg0 == "")
        {
argument_type_err:
            qDebug() << "ERROR!" << inst << "expect a real number as argument";
            return;
        }

        line_index = arg0.length();


        if (inst == "fd" || inst == "bk" || inst == "rt" || inst == "lt" ||
                 inst == "setpc" || inst == "setbg")
        {
            one_arg_flag = true;

            if (inst == "fd")
                drawLine(arg0.toDouble(nullptr), true);
            else if (inst == "bk")
                drawLine(arg0.toDouble(nullptr), false);
            else if (inst == "rt")
                turnDirection(arg0.toDouble(nullptr), true);
            else if (inst == "lt")
                turnDirection(arg0.toDouble(nullptr), false);
            else if (inst == "setpc")
                setPC(arg0.toUInt(nullptr, 10));
            else if (inst == "setbg")
                emit setBG(arg0);
        }

        line = line.right(line.length() - line_index).trimmed();

        if (one_arg_flag)
        {
            parse_line(line);
            return;
        }


        if (inst == "setxy" || inst == "stampoval")
        {
            two_arg_flag = true;
            QString arg1 = get_qreal_str(line);

            if (arg1 == "")
                goto argument_type_err;

            if (inst == "setxy")
                setXT(arg0.toDouble(nullptr), arg1.toDouble(nullptr));
            else if (inst == "stampoval")
                stampoval(arg0.toDouble(nullptr), arg1.toDouble(nullptr));

            line = line.right(line.length() - line_index).trimmed();
        }

        else if (inst == "repeat")
        {
            two_arg_flag = true;
            if (line.at(0) != '[')
            {
                qDebug() << "ERROR! repeat: expect '['\n";
                return;
            }

            int lbracket_index, rbracket_index;
            if ((lbracket_index = line.indexOf('[')) == -1)
                return;

            int lbracket_count = 1;
            int length = line.length();
            int index = lbracket_index;

            while (lbracket_count && index < length)
            {
                index++;
                if (!lbracket_count)
                    break;
                if (line.at(index) == '[')
                    lbracket_count++;
                else if (line.at(index) == ']')
                    lbracket_count--;
            }

            if (lbracket_count)
            {
                qDebug() << "ERROR! repeat: expect ']'\n";
                return;
            }

            else {
                rbracket_index = index;
            }

            for (int i = 0; i < arg0.toInt(); ++i)
            {
                qDebug() << lbracket_index << ' ' << line.at(lbracket_index);
                qDebug() << rbracket_index << ' ' << line.at(rbracket_index);
                parse_line(line.mid(lbracket_index + 1, rbracket_index - 1));
            }

            line = line.right(line.length() - rbracket_index - 1).trimmed();
        }

        if (two_arg_flag)
        {
            parse_line(line);
            return;
        }
    }

    qDebug() << "ERROR! unknown command " << line;
    return;
}

void
Canvas::drawLine(qreal rlen, bool flag)
{
    if (flag)
        qDebug() << "fd: " << rlen;
    else
        qDebug() << "bk: " << rlen;

    const QPointF aP1(CURR_POS->rx(), CURR_POS->ry());

    QLineF line;
    line.setP1(aP1);
    if (flag == false)
        addAngle(180);

    line.setAngle(CURR_ANGLE);
    line.setLength(rlen);

    if (PEN_IS_DOWN)
        LINES.append(line);

    CURR_POS->setX(line.pointAt(1).x());
    CURR_POS->setY(line.pointAt(1).y());

    if (flag == false)
        addAngle(180);
    update();
}

void
Canvas::turnDirection(qreal delta, bool flag)
{
    if (flag)
        qDebug() << "set direction: " << delta << " right\n";
    else
        qDebug() << "set direction: " << delta << " left\n";

    if (flag)
        addAngle(delta * (-1));
    else
        addAngle(delta);
}

void
Canvas::reset()
{
    qDebug() << "reset";

    LINES.clear();
    CIRCLES.clear();

    CURR_POS->setX(CANVAS_XPOS + CANVAS_WIDTH/2);
    CURR_POS->setY(CANVAS_YPOS + CANVAS_HEIGHT/2);
    CURR_ANGLE = 90;

    update();
}

void
Canvas::penDown()
{
    qDebug() << "pen down";
    PEN_IS_DOWN = true;
}

void
Canvas::penUp()
{
    qDebug() << "pen up";

    PEN_IS_DOWN = false;
}

void
Canvas::setXT(qreal rx, qreal ry)
{
    qDebug() << "setxy: " << rx << ' ' << ry;

    CURR_POS->setX(rx);
    CURR_POS->setY(ry);
}

void
Canvas::setPC(uint color)
{
    qDebug() << "setpencolor: " << color;

    pen.setColor(color);
    update();
}


void
Canvas::stampoval(qreal rx, qreal ry)
{
    qDebug() << "stampoval: " << rx << ' ' << ry;
    const QPointF center(CURR_POS->rx(), CURR_POS->ry());
    circle_t cl;
    cl.center = center;
    cl.rx = rx;
    cl.ry = ry;
    CIRCLES.append(cl);
    update();
}



