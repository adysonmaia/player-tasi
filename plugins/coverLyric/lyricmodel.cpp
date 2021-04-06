#include "lyricmodel.hpp"

LyricModel::LyricModel(QObject *parent) : QObject(parent)
{
    this->accessKey = "phononp";
}

void LyricModel::searchLyric(QString artist, QString title)
{
    QString urlString;
    urlString = "http://api.leoslyrics.com/api_search.php?auth="+this->accessKey+"&artist="+artist+"&songtitle="+title;

    this->network = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(urlString));

    this->network->get(request);

    connect(this->network, SIGNAL(finished(QNetworkReply*)),
            this         , SLOT(finishedSearch(QNetworkReply*)));

    qDebug() << urlString;
}

void LyricModel::finishedSearch(QNetworkReply *reply)
{
    //qDebug() << "finishedSearch";
    QString xml = reply->readAll();

    //qDebug() << xml;

    QString errorStr;
    int errorLine;
    int errorColumn;
    QDomDocument doc;

    if (!doc.setContent(xml,true,&errorStr,&errorLine,&errorColumn) )
    {
        //qDebug() << errorStr;
        emit lyricNotFound();
        return;
    }

    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();
    if (node.toElement().tagName() == "response")
    {
        QDomNode childNode = node.firstChild();
        QString  response  = childNode.toText().data();
        if (response != "SUCCESS")
        {
            //qDebug() << "a";
            emit lyricNotFound();
            return;
        }
    }

    node = node.nextSibling();
    if (node.toElement().tagName() != "searchResults")
    {
        //qDebug() << "b";
        emit lyricNotFound();
        return;
    }

    node = node.firstChild();
    this->listHid.clear();

    bool find = false;

    while (!node.isNull() )
    {
        if ( node.toElement().tagName() == "result" )
        {
            QString hid = node.toElement().attribute("hid");
            this->listHid.append(hid);
            find = true;
        }
        node = node.nextSibling();
    }

    if (!find || this->listHid.isEmpty() ) {
        //qDebug() << "c";
        emit lyricNotFound();
        return;
    }

    this->createRequestGetLyric();
}

void LyricModel::createRequestGetLyric()
{
    if (this->listHid.isEmpty() )
    {
        //qDebug() << "createRequestGetLyric :: Vazio";
        emit lyricNotFound();
        return;
    }
    QString hid = this->listHid.at(0);
    this->listHid.removeFirst();

    QString urlString;
    urlString = "http://api.leoslyrics.com/api_lyrics.php?auth="+this->accessKey+"&hid="+hid;
    qDebug() << urlString;

    this->network = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(urlString));

    this->network->get(request);

    connect(this->network, SIGNAL(finished(QNetworkReply*)),
            this         , SLOT(finishedLyric(QNetworkReply*)));
}

void LyricModel::finishedLyric(QNetworkReply *reply)
{
    //qDebug() << "finishedLyric";
    QString xml = reply->readAll();

    //qDebug() << xml;

    QString errorStr;
    int errorLine;
    int errorColumn;
    QDomDocument doc;

    if (!doc.setContent(xml,true,&errorStr,&errorLine,&errorColumn) )
    {
        //qDebug() << errorStr;
        emit lyricNotFound();
        return;
    }

    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();

    if (node.toElement().tagName() == "response")
    {
        QDomNode childNode = node.firstChild();
        QString  response  = childNode.toText().data();
        if (response != "SUCCESS")
        {
            //qDebug() << "finishedLyric :: pegando prox";
            this->createRequestGetLyric();
            return;
        }
    }

    node = node.nextSibling();
    if (node.toElement().tagName() != "lyric")
    {
        emit lyricNotFound();
        return;
    }

    node = node.firstChild();
    while (node.toElement().tagName() != "text" )
    {
        node = node.nextSibling();
    }

    QString lyric;
    QDomNode childNode = node.firstChild();
    lyric = childNode.toText().data();

    emit lyricFound(lyric);
}
