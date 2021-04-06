#include "contextPlugin.h"

ContextPlugin::ContextPlugin(QWidget *parent)
{
    //mediaObjectPassed = false;
}

QString ContextPlugin::echo()
{

        QMap<QString, QString> metaData = mtResolver->metaData();

        QString title = metaData.value("TITLE");
        if (title == "")
            title = mtResolver->currentSource().fileName();

        QTime itemDisplayTime(0, (mtResolver->totalTime() / 60000) % 60, (mtResolver->totalTime() / 1000) % 60);

        QString artist = metaData.value("ARTIST");
        QString album = metaData.value("ALBUM");

        QString trackText = "<h3>Title: "+title.toUtf8()+"</h3><br /><h3>Artist: "+artist.toUtf8()+"</h3><br /><h3>Album: "+album.toUtf8()+"</h3>";

        return trackText;

    return tr("<h3>No Music Playing!</h3>");
}

QWidget* ContextPlugin::createWidget(QWidget * parent)
{
    QTextEdit *te = new QTextEdit(parent);
    te->setReadOnly(true);
    te->setHtml(echo());

    return te;
}

void ContextPlugin::stateChanged(Phonon::MediaObject *moo)
{
    this->mtResolver = moo;

    this->sa->setWidget(createWidget(sa));
    this->sa->setWidgetResizable(true);

    //mediaObjectPassed = true;

    //emit widgetReady(createWidget(0));
}

void ContextPlugin::setScrollArea(QScrollArea *sa)
{
    this->sa = sa;
}

Q_EXPORT_PLUGIN2(contextplugin, ContextPlugin);


