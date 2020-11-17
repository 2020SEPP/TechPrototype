#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QObject>
#include <QJsonArray>
#include <QList>

#include "Network.h"

QList<int> JsonValue2ListInt(QJsonValue value);

class HttpRequest : public QObject
{
    Q_OBJECT

public:
    HttpRequest();

    QString get(QString url);
    QJsonObject get_json(QString url);
    QString getRequest(QString url);
    QString post_str(QString url,  QString jsondata);
    QJsonObject post_json(QString url, QString jsondata);
    QString postHeadRequest(QString url, QString jsondata);
};

#endif // HTTPREQUEST_H
