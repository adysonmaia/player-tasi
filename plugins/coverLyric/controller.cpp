#include "controller.hpp"

Controller::Controller(QObject *parent) : QObject(parent)
{
    modelCover = new CoverModel(this);
    connect(this, SIGNAL(searchCover(QString, QString)), modelCover, SLOT(searchCover(QString, QString)) );
    connect(modelCover, SIGNAL(coverNotFound()), this, SLOT(coverNotFound()) );
    connect(modelCover, SIGNAL(coverFound(QImage)), this, SLOT(coverFound(QImage)) );

    modelLyric = new LyricModel(this);
    connect(this, SIGNAL(searchLyric(QString,QString)), modelLyric, SLOT(searchLyric(QString,QString)) );
    connect(modelLyric, SIGNAL(lyricNotFound()), this, SLOT(lyricNotFound()) );
    connect(modelLyric, SIGNAL(lyricFound(QString)), this, SLOT(lyricFound(QString)) );
}

void Controller::getCover(MediaObject *moo)
{
    QMap<QString, QString> metaData = moo->metaData();
    QString title  = metaData.value("TITLE");
    QString artist = metaData.value("ARTIST");
    QString album  = metaData.value("ALBUM");
    qDebug() << "Pegar capa " << title << " - " << artist << " - " << album ;

    emit searchCover(artist, album);
}

void Controller::coverNotFound()
{
    //qDebug() << "Nao achou cover";
    QImage image(174,174, QImage::Format_RGB32);
    image.fill(0);
    emit returnCover(image);
}

void Controller::coverFound(QImage image)
{
    //qDebug() << "Achou cover";
    emit returnCover(image);
}

void Controller::getLyric(MediaObject *moo)
{
    QMap<QString, QString> metaData = moo->metaData();
    QString title  = metaData.value("TITLE");
    QString artist = metaData.value("ARTIST");
    QString album  = metaData.value("ALBUM");
    //qDebug() << title << " - " << artist << " - " << album ;

    emit searchLyric(artist, title);
}

void Controller::lyricNotFound()
{
    //qDebug() << "Nao achou lyric";
    QString lyric = "Lyric not found";
    emit returnLyric(lyric);
}

void Controller::lyricFound(QString lyric)
{
    //qDebug() << "Achou lyric";
    emit returnLyric(lyric);
}
