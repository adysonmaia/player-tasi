#include "collectionTree.h"
#include <QtDebug>

CollectionTree::CollectionTree(QWidget *parent)
  :QTreeWidget(parent)
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    this->setSelectionMode(QAbstractItemView::ExtendedSelection);
    this->setAcceptDrops(false);
    this->setDropIndicatorShown(true);
    this->setDragEnabled(true);

    index = 0;
    setIconSize(QSize(36, 36));

    metaDataResolver = new Phonon::MediaObject(this);

    connect(metaDataResolver, SIGNAL(stateChanged(Phonon::State,Phonon::State)), this, SLOT(metaStateChanged(Phonon::State,Phonon::State)));
}

void CollectionTree::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void CollectionTree::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
}

QMimeData *CollectionTree::mimeData(const QList<QTreeWidgetItem *> items) const
{
        QList<QUrl> urls;

        for (int i=0;i<items.size();i++)
        {
            QUrl url;
            url.setUrl(items.at(i)->data(0,36).toString());
            urls << url;
        }

        QMimeData *md = new QMimeData;

        md->setUrls(urls);

        return md;
}

/*bool CollectionTree::dropMimeData(QTreeWidgetItem *parent, int index, const
                                             QMimeData *data, Qt::DropAction action)
{
      QStringList strl;

      if(data->hasUrls())
      {
           QList<QUrl> files = data->urls();

           foreach(QUrl file, files) {
              QString str;
              str = file.toLocalFile();

              strl << str;

              QTreeWidgetItem *childItem = new QTreeWidgetItem(this->itemAt(0,0));
              childItem->setText(0, str);

              this->insertTopLevelItem(index, childItem);
           }

           emit dropAccepted(strl);
      }
      else return false;

      return true;
}*/

void CollectionTree::resetCollectionList()
{
    collectionList.clear();
}

void CollectionTree::setMusic(const QString &path)
{
    Phonon::MediaSource source(path);
    collectionList.append(path);
}

void CollectionTree::loadMusicIntoWidget()
{
    this->clear();

    for(int i =0; i < collectionList.size(); i++)
    {
        metaDataResolver->setCurrentSource(collectionList.at(i));
    }
}

QTreeWidgetItem * CollectionTree::find_by_album(const QString &album)
{
    //procurando pelo álbum
    QList<QTreeWidgetItem *> items = findItems(album, Qt::MatchExactly | Qt::MatchFixedString);

    if(items.size() <= 0) //não encontrou nenhum item
    {
        QTreeWidgetItem *albumItem = new QTreeWidgetItem();

        albumItem->setIcon(0, QIcon(":/images/36/empty_cover.png"));
        albumItem->setSizeHint(0, QSize(0, 38));
        albumItem->setText(0, album);
        albumItem->setData(0, 35, 0);

        addTopLevelItem(albumItem); //adiciona novo item na coleção

        return albumItem;
    }

    return items.at(0);
}

bool CollectionTree::trackExists(const QString &album, const QString &title)
{
    //procurando pelo álbum
    QList<QTreeWidgetItem *> items = findItems(album, Qt::MatchExactly | Qt::MatchFixedString);

    if(items.size() > 0) //encontrou album
    {
       if(items.at(0)->childCount() <= 0) return false;

       for(int i = 0; i < items.at(0)->childCount(); i++)
       {
            if(items.at(0)->child(i)->data(0,35).toInt() == 1) //é uma faixa
            {
                if(items.at(0)->child(i)->text(0) == title)
                    return true;
            }
       }
    }

    return false;
}

/**
 * Adiciona uma música a coleção, juntamente com os seus metadados
 * 35 - IsTrack (0 - False, 1 - True)
 * 36 - Path
 */
void CollectionTree::metaStateChanged(Phonon::State /*newState*/, Phonon::State /* oldState */)
{
    //Obtendo meta dados da música
    QMap<QString, QString> metaData = metaDataResolver->metaData();

    QString title = metaData.value("TITLE");
    if (title == "")
    {
        title = metaDataResolver->currentSource().fileName();
        title = title.right(title.length() - title.lastIndexOf('/') - 1);
    }

    QTime itemDisplayTime(0, (metaDataResolver->totalTime() / 60000) % 60, (metaDataResolver->totalTime() / 1000) % 60);

    QString artist = metaData.value("ARTIST");
    QString album = metaData.value("ALBUM");
    if(album == "")
    {
        album = QString("UNKNOW ALBUM");
    }

    if(index < collectionList.size())
    {
        if(!trackExists(album, title))
        {
            //encontrando album ao qual a faixa pertence
            QTreeWidgetItem *albumItem = find_by_album(album);

            QTreeWidgetItem *track = new QTreeWidgetItem(albumItem);
            track->setText(0, title);
            track->setData(0, 35, 1);

             //qDebug() << "FileName: " << collectionList.at(index).fileName() << " Title: " << title << " Album: " << album;
             track->setData(0, 36, collectionList.at(index).fileName());
             index++;

             //if(index > 500) exit(1);
        }
    }
}



