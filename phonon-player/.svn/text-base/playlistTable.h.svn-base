#ifndef PLAYLISTTABLE_H
#define PLAYLISTTABLE_H

#include <QtGui>

class PlaylistTable : public QListWidget
{
  Q_OBJECT
    public:
        PlaylistTable(QWidget *parent = 0);

        bool dropMimeData (int index, const QMimeData * data, Qt::DropAction action);
        QMimeData *mimeData(const QList<QListWidgetItem *> items) const;
    protected:
        void dragEnterEvent(QDragEnterEvent *event);
        void dragMoveEvent(QDragMoveEvent *e) { e->accept(); }
    signals:
        void dropAccepted(QStringList &files, int index);
        void dragInProgress();

};

#endif // PLAYLISTTABLE_H
