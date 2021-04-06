#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <QObject>
#include <QImage>
#include <QString>
#include <QMap>
#include <phonon/mediaobject.h>
#include "covermodel.hpp"
#include "lyricmodel.hpp"

using namespace Phonon;

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(QObject *parent = 0);
public slots:
    void getCover(MediaObject *moo);
    void getLyric(MediaObject *moo);
private slots:
    void coverNotFound();
    void coverFound(QImage image);

    void lyricNotFound();
    void lyricFound(QString lyric);
signals:
    void returnCover(QImage image);
    void returnLyric(QString lyric);

    void searchCover(QString, QString);
    void searchLyric(QString, QString);
private:
    CoverModel *modelCover;
    LyricModel *modelLyric;
};

#endif // CONTROLLER_HPP
