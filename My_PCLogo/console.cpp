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
}

void Console::write(QString str)
{
    this->insertPlainText(str);
}

void Console::keyPressEvent(QKeyEvent *ev)
{
    if (ev->key() == Qt::Key_Return) {
        QTextCursor cursor = this->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.select(QTextCursor::LineUnderCursor);

        QString CMD_LINE = cursor.selectedText().toLower().trimmed();
        if (CMD_LINE == "")
            return;
        else
            emit newLine(CMD_LINE);
    }

    QTextEdit::keyPressEvent(ev);
}
