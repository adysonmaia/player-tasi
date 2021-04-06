#ifndef CONTEXTINTERFACE_H
#define CONTEXTINTERFACE_H

#include <phonon/mediaobject.h>
#include <QtGui>

/**
 * Interface para implementação pelos plugins
 * @author Caio Fellipe
 * @version 1.0
 */
class ContextInterface
 {
 public:
     ~ContextInterface() {}
     
     //nome do plugin
     virtual const QString pluginName()  = 0;
     //descrição do plugin
     virtual const QString pluginDescription()  = 0;
     //versão do plugin
     virtual const QString pluginVersion() = 0;
     //envia o novo objeto de media toda vez que uma nova música for tocada
     virtual void  stateChanged(Phonon::MediaObject *moo) = 0;
     //passa a referência do widget da área de contexto dos plugins, cabe ao desenvolvedor do plugin mostrá-lo na hora que lhe convier
     //para exibir o widget do plugin na área de contexto use sa->setWidget(SeuWidgetPlugin)
     virtual void  setScrollArea(QScrollArea *sa) = 0;
 };

 Q_DECLARE_INTERFACE(ContextInterface,
                     "ContextInterface/1.0");

#endif // CONTEXTINTERFACE_H
