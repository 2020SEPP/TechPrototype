#include "token.h"

QString token = "";
int ID = -1;
QString NAME = "";

QString getAvatarByName(QString name) {
    if (name == "")
        return "#.png";
    QChar first = name.toUpper().at(0);
    if (first.isLetter())
        return name.left(1).toUpper() + ".png";
    else
        return "#.png";
}
