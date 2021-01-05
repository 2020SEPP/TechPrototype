#include "console.h"
#include "instructions.h"
#include <QApplication>
#include <QStyleOption>
#include <QTextLine>
#include <QTextCursor>
#include <QDebug>
#include <QTextStream>
#include <QTextStreamFunction>
#include <QTextStreamManipulator>

typedef unsigned int uint;

// utils
QString
str2real(QString str) {
    int index = 0;
    while (index < str.length()) {
        QChar ch = str.at(index);
        if ((ch >= '0' && ch <= '9') || ch == '.')
            index++;
        else if (ch == ' ' || ch == ']')
            break;
        else
            return "";
    }
    return str.left(index);
}

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
            parse_line(CMD_LINE);
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

void
Console::parse_line(QString line) {
    line = line.trimmed();
    if (line == "")
        return;
    int line_index = 0;
    QString inst;
    while (line_index < line.length() && line.at(line_index) != ' ')
        line_index++;
    inst = line.left(line_index);
    if (INSTRUCTIONS.indexOf(inst) != -1) {
        bool zro_arg_flag = false;
        bool one_arg_flag = false;
        bool two_arg_flag = false;
        if (inst == "cs" || inst == "pu" || inst == "pd") {
            zro_arg_flag = true;
            if (inst == "cs")
                emit reset();
            else if (inst == "pu")
                emit penUp();
            else if (inst == "pd")
                emit penDown();
        }
        line = line.right(line.length() - line_index).trimmed();
        if (zro_arg_flag) {
            parse_line(line);
            return;
        }
        QString arg0 = str2real(line);
        if (arg0 == "") {
argument_type_err:
            write("\nERROR: '" + inst + "' expect a real number as argument");
            return;
        }
        line_index = arg0.length();
        if (inst == "fd" || inst == "bk" || inst == "rt" || inst == "lt" ||
                inst == "setpc" || inst == "setbg") {
            one_arg_flag = true;
            if (inst == "fd")
                emit drawLine(arg0.toDouble(nullptr), true);
            else if (inst == "bk")
                emit drawLine(arg0.toDouble(nullptr), false);
            else if (inst == "rt")
                emit turnDirection(arg0.toDouble(nullptr), true);
            else if (inst == "lt")
                emit turnDirection(arg0.toDouble(nullptr), false);
            else if (inst == "setpc")
                emit setPC(arg0.toUInt(nullptr, 10));
            else if (inst == "setbg")
                emit setBG(arg0);
        }
        line = line.right(line.length() - line_index).trimmed();
        if (one_arg_flag) {
            parse_line(line);
            return;
        }
        if (inst == "setxy" || inst == "stampoval") {
            two_arg_flag = true;
            QString arg1 = str2real(line);
            if (arg1 == "")
                goto argument_type_err;
            if (inst == "setxy")
                emit setXT(arg0.toDouble(nullptr), arg1.toDouble(nullptr));
            else if (inst == "stampoval")
                emit stampoval(arg0.toDouble(nullptr), arg1.toDouble(nullptr));
            line = line.right(line.length() - line_index).trimmed();
        } else if (inst == "repeat") {
            two_arg_flag = true;
            if (line.at(0) != '[') {
                write("\nERROR: 'repeat' expect '['");
                return;
            }
            int lbracket_index, rbracket_index;
            if ((lbracket_index = line.indexOf('[')) == -1)
                return;
            int lbracket_count = 1;
            int length = line.length();
            int index = lbracket_index;
            while (lbracket_count && index < length) {
                index++;
                if (!lbracket_count)
                    break;
                if (line.at(index) == '[')
                    lbracket_count++;
                else if (line.at(index) == ']')
                    lbracket_count--;
            }
            if (lbracket_count) {
                write("\nERROR: 'repeat' expect '['");
                return;
            } else {
                rbracket_index = index;
            }
            for (int i = 0; i < arg0.toInt(); ++i) {
                qDebug() << lbracket_index << ' ' << line.at(lbracket_index);
                qDebug() << rbracket_index << ' ' << line.at(rbracket_index);
                parse_line(line.mid(lbracket_index + 1, rbracket_index - 1));
            }
            line = line.right(line.length() - rbracket_index - 1).trimmed();
        }
        if (two_arg_flag) {
            parse_line(line);
            return;
        }
    }
    write("\nERROR: unknown command '" + line + "'");
    return;
}
