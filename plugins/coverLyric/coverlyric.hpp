#ifndef COVERLYRIC_HPP
#define COVERLYRIC_HPP

#include <QtGui>
#include <QThread>
#include <phonon/mediaobject.h>
#include "ContextInterface.h"
#include "controller.hpp"

using namespace Phonon;

class CoverLyric : public QObject, ContextInterface
{
    Q_OBJECT
    Q_INTERFACES(ContextInterface)
public:
    CoverLyric(QWidget *parent = 0);

    inline const QString pluginName() {return tr("CoverLyric");}
    inline const QString pluginDescription() {return tr("Shows the cover and the lyrics about the current playing music");}
    inline const QString pluginVersion() {return tr("1.0");}

    void stateChanged(Phonon::MediaObject *moo);
    void setScrollArea(QScrollArea *sa);

signals:
    void getCover(MediaObject*);
    void getLyric(MediaObject*);
private slots:
    void mountCover(QImage);
    void mountLyric(QString);
private:
    void mountView();
private:
     Phonon::MediaObject *mtResolver;

     Controller *controller;
     QThread *threadController;
     QScrollArea *sa;

     QImage imageCover;
     QString stringLyric;
};

#endif // COVERLYRIC_HPP
