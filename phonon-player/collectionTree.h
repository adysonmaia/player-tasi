#ifndef COLLECTIONTREE_H
#define COLLECTIONTREE_H

#include <QtGui>
#include <phonon/mediaobject.h>

class CollectionTree : public QTreeWidget
{
  Q_OBJECT
    public:
        CollectionTree(QWidget *parent = 0);

        /*bool dropMimeData(QTreeWidgetItem *parent, int index, const
               QMimeData *data, Qt::DropAction action);*/
        QMimeData *mimeData(const QList<QTreeWidgetItem *> items) const;

        void setMusic(const QString &path);
        void addMusic(const QString &path);
        void loadMusicIntoWidget();
        void resetCollectionList();
        bool trackExists(const QString &album, const QString &title);

    protected:
        void dragEnterEvent(QDragEnterEvent *event);
        void dragMoveEvent(QDragMoveEvent *event);
    signals:
        void dropAccepted(QStringList &files);
    private slots:
        void metaStateChanged(Phonon::State newState, Phonon::State /* oldState */);

    private:
        QTreeWidgetItem *find_by_album(const QString &album);


        QList<Phonon::MediaSource> collectionList;

        Phonon::MediaObject *metaDataResolver;

        int index;

};


#endif // COLLECTIONTREE_H
