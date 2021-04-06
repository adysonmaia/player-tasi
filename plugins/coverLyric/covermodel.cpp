#include "covermodel.hpp"

CoverModel::CoverModel(QObject *parent) : QObject(parent)
{
    this->lastFmKey = "416ed346c0e94e30a5f0cb8f94eded80";
}

void CoverModel::searchCover(QString artist, QString album)
{
    QString urlString;
    urlString = "http://ws.audioscrobbler.com/2.0/?method=album.getinfo&api_key="+this->lastFmKey+"&artist="+artist+"&album="+album;

    this->network = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(urlString));

    QNetworkReply *reply = this->network->get(request);

    connect(this->network, SIGNAL(finished(QNetworkReply*)),
            this         , SLOT(finishedSearch(QNetworkReply*)));

    qDebug() << urlString;
}

void CoverModel::finishedSearch(QNetworkReply *reply) {
    //qDebug() << "httpDoneSearch";
    QString xml = reply->readAll();

    //qDebug() << xml;

    QString errorStr;
    int errorLine;
    int errorColumn;
    QDomDocument doc;

    if (!doc.setContent(xml,true,&errorStr,&errorLine,&errorColumn) )
    {
        //qDebug() << errorStr;
        emit coverNotFound();
        return;
    }

    QDomElement root = doc.documentElement();
    QString status = root.attribute("status");
    if (status == "failed")
    {
        //qDebug() << "a";
        emit coverNotFound();
        return;
    }

    QDomNode node = root.firstChild().firstChild();
    bool find = false;
    QString urlImage = "";

    while (!find && !node.isNull() )
    {
        if ( node.toElement().tagName() == "image" )
        {
            if (node.toElement().attribute("size") == "large")
            {
                QDomNode childNode = node.firstChild();
                urlImage = childNode.toText().data();
                find = true;
            }
        }
        node = node.nextSibling();
    }

    if (!find) {
        //qDebug() << "b";
        emit coverNotFound();
        return;
    }

    //qDebug() << urlImage;

    int indexDot = urlImage.lastIndexOf(".");
    if (indexDot < 0)
    {
        //qDebug() << "c";
        emit coverNotFound();
        return;
    }
    this->formatImage = urlImage.right(urlImage.length() - indexDot);
    if (urlImage.length() == 0 ) {
        //qDebug() << "d";
        emit coverNotFound();
        return;
    }

    this->network = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl(urlImage));

    this->network->get(request);

    connect(this->network, SIGNAL(finished(QNetworkReply*)),
            this         , SLOT(finishedImage(QNetworkReply*)));

}

void CoverModel::finishedImage(QNetworkReply *reply)
{
    //qDebug() << "finishedImage";
    QImage image;
    image.load(reply, this->formatImage.toAscii());
    emit coverFound(image);
}
