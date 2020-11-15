#include "console.h"
#include <QApplication>
#include <QStyleOption>
#include <QTextLine>
#include <QTextCursor>
#include <QDebug>
#include <QTextStream>
#include <QTextStreamFunction>
#include <QTextStreamManipulator>

Console::Console(QWidget *parent) : QTextEdit(parent)
{
    this->setFocusPolicy(Qt::StrongFocus);
    storage = "";
//    this->insertPlainText("Please type your code.\n");
}

void
Console::write(QString str)
{
    this->insertPlainText(str);
}

void
Console::keyPressEvent(QKeyEvent *ev)
{
    if (ev->key() == Qt::Key_Escape)
    {
        qApp->exit(0);
        return;
    }

    else if (ev->key() == Qt::Key_Return) {
        QTextCursor cursor = this->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.select(QTextCursor::LineUnderCursor);

        QString CMD_LINE = cursor.selectedText().toLower().trimmed();
        if (CMD_LINE == "")
            return;
        else
            emit newLine(CMD_LINE);
//        QStringList args = CMD_LINE.split(QRegExp(",|\\s+"), QString::SkipEmptyParts);

        /*if (args.count() == 0)
            return;
        else
            emit newLine(CMD_LINE);*/

//        int i = 0;
//        while (i < args.count())
//        {
//            qDebug() << args.at(i) << Qt::endl;
//            i++;
//        }
//        qDebug() << CMD_LINE << Qt::endl;

//        if (args.count())
//            emit newLineWriten(args);

//        QString INST = args.at(0);
//        if (INST == "fd")
//            emit drawLine(args.at(1).toDouble(nullptr), true);
//        else if (INST == "bk")
//            emit drawLine(args.at(1).toDouble(nullptr), false);
//        else if (INST == "rt")
//            emit turnDirection(args.at(1).toDouble(nullptr), true);
//        else if (INST == "lt")
//            emit turnDirection(args.at(1).toDouble(nullptr), false);

//        else if (INST == "pd")
//            emit penDownUp(true);
//        else if (INST == "pu")
//            emit penDownUp(false);

//        else if (INST == "setxt")
//            emit setXT(args.at(1).toDouble(nullptr), args.at(2).toDouble(nullptr));

//        else if (INST == "setpc")
//            emit setPC(args.at(1).toUInt(nullptr, 10));
//        else if (INST == "setbg")
//            emit setBG(args.at(1));
//        else if (INST == "stampoval")
//            emit stampoval(args.at(1).toDouble(nullptr), args.at(2).toDouble(nullptr));
    }

    QTextEdit::keyPressEvent(ev);
}
