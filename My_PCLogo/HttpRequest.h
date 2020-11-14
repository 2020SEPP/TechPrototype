#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QObject>
#include "Network.h"

class HttpRequest : public QObject
{
    Q_OBJECT
public:
    HttpRequest();

    QString get(QString url);
    QString getRequest(QString url);
    QString post(QString url,  QString jsondata);
    QString postHeadRequest(QString url, QString jsondata);
};

#endif // HTTPREQUEST_H
