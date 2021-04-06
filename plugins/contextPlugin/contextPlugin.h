#ifndef CONTEXTPLUGIN_H
#define CONTEXTPLUGIN_H

#include <QtGui>
#include "ContextInterface.h"

class ContextPlugin : public QObject, ContextInterface
 {
     Q_OBJECT
     Q_INTERFACES(ContextInterface)

 public:
     ContextPlugin(QWidget *parent = 0);

     QString echo();
     QWidget* createWidget(QWidget * parent);
     inline const QString pluginName() {return tr("CurrentContext");}
     inline const QString pluginDescription() {return tr("Show some information about the current playing music");}
     inline const QString pluginVersion() {return tr("1.0");}
     void stateChanged(Phonon::MediaObject *moo);
     void setScrollArea(QScrollArea *sa);

 private:
     Phonon::MediaObject *mtResolver;
     QScrollArea *sa;

     //bool mediaObjectPassed; //indica se o objeto de media já foi passado para este plugin
 };

#endif // CONTEXTPLUGIN_H
