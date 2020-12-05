#include "console.h"
#include <QApplication>
#include <QStyleOption>
#include <QTextLine>
#include <QTextCursor>
#include <QDebug>
#include <QTextStream>
#include <QTextStreamFunction>
#include <QTextStreamManipulator>

Console::Console(QWidget *parent) : QTextEdit(parent) {
    this->setFocusPolicy(Qt::StrongFocus);
    storage = "";
    this->setStyleSheet("QTextEdit {border-image: url(:/images/image/paint2.png);"
                        "background:rgba(255,255,255,0.5);"
                        ""
                        "}");
    connect(this, SIGNAL(enter()), this, SLOT(wrap()));
}

void Console::write(QString str) {
    this->insertPlainText(str);
}

void Console::wrap() {
    write("\n>> ");
}

void Console::keyPressEvent(QKeyEvent *ev) {
    if (ev->key() == Qt::Key_Return) {
        QTextCursor cursor = this->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.select(QTextCursor::LineUnderCursor);
        QString CMD_LINE = cursor.selectedText().toLower();
        CMD_LINE = CMD_LINE.right(CMD_LINE.length() - 3).trimmed();
        if (CMD_LINE != "")
            emit newLine(CMD_LINE);
        emit enter();
        return;
    }
    if (ev->key() == Qt::Key_Backspace) {
        QTextCursor cursor = this->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.select(QTextCursor::LineUnderCursor);
        QString CMD_LINE = cursor.selectedText().toLower();
        if (CMD_LINE == ">> ")
            return;
    }
    QTextEdit::keyPressEvent(ev);
}
