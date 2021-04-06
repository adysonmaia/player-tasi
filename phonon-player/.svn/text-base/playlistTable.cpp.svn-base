#include "playlistTable.h"

PlaylistTable::PlaylistTable(QWidget *parent)
  :QListWidget(parent)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    this->setAcceptDrops(true);
    this->setDropIndicatorShown(true);
    this->setDragEnabled(true);

    this->resizeContents(200,40);
}

void PlaylistTable::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();

    emit dragInProgress();
}

QMimeData *PlaylistTable::mimeData(const QList<QListWidgetItem *> items) const
{
        QList<QUrl> urls;

        for (int i=0;i<items.size();i++)
        {
            QUrl url;
            url.setUrl(items.at(i)->data(Qt::UserRole).toString());
            urls << url;
        }

        QMimeData *md = new QMimeData;

        md->setUrls(urls);

        return md;
}

bool PlaylistTable::dropMimeData (int index, const QMimeData * data, Qt::DropAction /*action*/)
{
      QStringList strl;

      if(data->hasUrls())
      {
           QList<QUrl> files = data->urls();

           foreach(QUrl file, files) {
              QString str;
              str = file.toLocalFile();

              strl << str;
           }

           emit dropAccepted(strl, index);
      }
      else return false;

      return true;
}

