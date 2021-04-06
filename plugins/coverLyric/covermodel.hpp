#ifndef COVERMODEL_HPP
#define COVERMODEL_HPP

#include <QObject>
#include <QImage>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QtXml>

class CoverModel : public QObject
{
    Q_OBJECT
public:
    CoverModel(QObject *parent = 0);
public slots:
    void searchCover(QString artist, QString album);
signals:
    void coverFound(QImage album);
    void coverNotFound();
private slots:
    void finishedSearch(QNetworkReply *);
    void finishedImage(QNetworkReply *);
private:
    QNetworkAccessManager *network;
    QString lastFmKey;
    QString formatImage;
};

#endif // COVERMODEL_HPP
