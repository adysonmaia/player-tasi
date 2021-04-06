#ifndef LYRICMODEL_HPP
#define LYRICMODEL_HPP

#include <QObject>
#include <QString>
#include <QStringList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QtXml>

class LyricModel : public QObject
{
    Q_OBJECT
public:
    LyricModel(QObject *parent = 0);
public slots:
    void searchLyric(QString artist, QString title);
signals:
    void lyricFound(QString lyric);
    void lyricNotFound();
private slots:
    void finishedSearch(QNetworkReply *);
    void finishedLyric(QNetworkReply *);
private:
    void createRequestGetLyric();
private:
    QNetworkAccessManager *network;
    QString accessKey;
    QStringList listHid;
};

#endif // LYRICMODEL_HPP
