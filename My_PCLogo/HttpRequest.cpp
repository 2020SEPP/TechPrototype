#include "HttpRequest.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QTextCodec>
#include <QTimer>

#include <QJsonObject>
#include <QJsonDocument>

HttpRequest::HttpRequest()
{
}

QString HttpRequest::get(QString url)
{
    QNetworkRequest request;
    QNetworkAccessManager *naManager = new QNetworkAccessManager();
    QUrl strUrl = url;
    request.setUrl(strUrl);
    request.setRawHeader("Content-Type", "charset='utf-8'");
    request.setRawHeader("Content-Type", "application/json");

    QNetworkReply* reply = naManager->get(request);

    QEventLoop eventLoop;
    connect(naManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();
    QTextCodec* codec = QTextCodec::codecForName("utf8");
    QString strReply = codec->toUnicode(reply->readAll());
    reply->deleteLater();
    delete naManager;
    return strReply;
}

QJsonObject HttpRequest::get_json(QString url)
{
    QNetworkRequest request;
    QNetworkAccessManager *naManager = new QNetworkAccessManager();
    QUrl strUrl = url;
    request.setUrl(strUrl);
    request.setRawHeader("Content-Type", "charset='utf-8'");
    request.setRawHeader("Content-Type", "application/json");

    QNetworkReply* reply = naManager->get(request);

    QEventLoop eventLoop;
    connect(naManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    QJsonObject object = QJsonDocument::fromJson(reply->readAll()).object();

    reply->deleteLater();
    delete naManager;
    return object;
}

QJsonArray HttpRequest::get_array(QString url)
{
    QNetworkRequest request;
    QNetworkAccessManager *naManager = new QNetworkAccessManager();
    QUrl strUrl = url;
    request.setUrl(strUrl);
    request.setRawHeader("Content-Type", "charset='utf-8'");
    request.setRawHeader("Content-Type", "application/json");

    QNetworkReply* reply = naManager->get(request);

    QEventLoop eventLoop;
    connect(naManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    QJsonArray array = QJsonDocument::fromJson(reply->readAll()).array();

    reply->deleteLater();
    delete naManager;
    return array;
}

QString HttpRequest::getRequest(QString url)
{
    QTimer timer;
    timer.setSingleShot(true);

    QNetworkRequest request;

    QUrl strUrl = url;
    request.setUrl(strUrl);
    qDebug() << "post address:" << request.url().toEncoded();
    request.setRawHeader("Content-Type", "charset='utf-8'");
    request.setRawHeader("Content-Type", "application/json");


    //异步传输
    QNetworkAccessManager *naManager=new QNetworkAccessManager();
    QNetworkReply* reply = naManager->get(request);

    QEventLoop eventLoop;
    connect(&timer, SIGNAL(timeout()), &eventLoop, SLOT(quit()));
    connect(naManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    timer.start(2000);//设置超时时间

	eventLoop.exec();
	QString strReply;
	if(timer.isActive()) //正常接收
	{
		timer.stop();
		QTextCodec* codec = QTextCodec::codecForName("utf8");
		//获取响应的内容
		strReply = codec->toUnicode(reply->readAll());
		qDebug()<<"strReply: "<<strReply;
		reply->deleteLater();
	} else //超时处理
	{
		disconnect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
		reply->abort();
		reply->close();
		reply->deleteLater();
	}
	qDebug()<<"code:"<<reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).value<int>();
	delete naManager;
	return strReply;
}

QString HttpRequest::post_str(QString url, QString jsondata)
{
    QByteArray array = jsondata.toLatin1();
    QNetworkRequest request;
    QNetworkAccessManager *naManager=new QNetworkAccessManager();
    QUrl strUrl = url;
    request.setUrl(strUrl);
    request.setRawHeader("Content-Type", "charset='utf-8'");
    request.setRawHeader("Content-Type", "application/json");

    QNetworkReply* reply = naManager->post(request, array);
    QEventLoop eventLoop;
    connect(naManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();
    QTextCodec* codec = QTextCodec::codecForName("utf8");
    QString strReply = codec->toUnicode(reply->readAll());

    reply->deleteLater();
    delete naManager;
    return strReply;
}

QJsonObject HttpRequest::post_json(QString url, QString jsondata)
{
    QByteArray array = jsondata.toLatin1();
    QNetworkRequest request;
    QNetworkAccessManager *naManager=new QNetworkAccessManager();
    QUrl strUrl = url;
    request.setUrl(strUrl);
    request.setRawHeader("Content-Type", "charset='utf-8'");
    request.setRawHeader("Content-Type", "application/json");

    QNetworkReply* reply = naManager->post(request, array);
    QEventLoop eventLoop;
    connect(naManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    QJsonObject object = QJsonDocument::fromJson(reply->readAll()).object();

    reply->deleteLater();
    delete naManager;
    return object;
}

QString HttpRequest::postHeadRequest(QString url, QString jsondata)
{
	QByteArray mac = jsondata.toUtf8();

	QByteArray postArray;
	postArray.append("mac="+ mac);
	qDebug() << "postArray" << postArray;

	QNetworkAccessManager *naManager = new QNetworkAccessManager();
	QNetworkRequest request;
	QUrl strUrl = url;
	request.setUrl(strUrl);
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	request.setHeader(QNetworkRequest::ContentLengthHeader, postArray.length());

	//设置表头token信息
	request.setRawHeader("Content-Type", "charset='utf-8'");
	request.setRawHeader("Content-Type", "application/json");

	QNetworkReply* reply = naManager->post(request, postArray);
	QEventLoop eventLoop;
	connect(naManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	eventLoop.exec();
	QTextCodec* codec = QTextCodec::codecForName("utf8");
	QString strReply = codec->toUnicode(reply->readAll());
//	qDebug() << "post address:" << request.url().toEncoded();
//	qDebug() << strReply;
	reply->deleteLater();
	delete naManager;
	return strReply;
}

QList<int> JsonValue2ListInt(QJsonValue value)
{
    QList<int> list;

    if (value.isArray())
    {
        QJsonArray array = value.toArray();
        for(int i = 0; i < array.size(); ++i)
        {
            list.append(array.at(i).toInt());
        }
    }

    return list;
}
