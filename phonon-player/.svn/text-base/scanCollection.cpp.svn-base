#include "scanCollection.h"
#include <QtDebug>

ScanCollection::ScanCollection(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    scanDirs = new QStringList();

    jumpDirs = new QStringList();
    jumpDirs->append(QString("/dev"));
    jumpDirs->append(QString("/proc"));
    jumpDirs->append(QString("/sys"));

    this->scanFolderTree->setColumnCount(1);
    this->scanFolderTree->setAnimated(true);

    QTreeWidgetItem *topLvlItems = new QTreeWidgetItem();
    topLvlItems->setText(0, "/");
    topLvlItems->setData(0, 5, QString("/"));
    loadFolderStructure(topLvlItems, false);

    connect(this->scanFolderTree, SIGNAL(itemExpanded(QTreeWidgetItem *)), this, SLOT(loadFolderStructure(QTreeWidgetItem *)));
    connect(this->scanFolderTree, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(changeFolderState(QTreeWidgetItem *,int)));
    connect(this->scanButton, SIGNAL(clicked()), this, SLOT(scanFolders()));
}

/**
 * Verifica se uma pasta foi marcada ou desmarcada para ser escaneada
 */
void ScanCollection::changeFolderState(QTreeWidgetItem *item, int /*column*/)
{
    if(item->checkState(0) == Qt::Checked) //selecionou um diretório
    {
        if(item->childCount() > 0 && item->child(0)->data(0,6).toInt() == 1) //já existem diretórios reais marcados abaixo do diretório pai
        {
            for(int i =0; i < item->childCount(); i++) //marcando todos os filhos
            {
                item->child(i)->setCheckState(0, Qt::Checked);
                item->child(i)->setDisabled(true);
            }
        }

       if(item->data(0,6).toInt() == 1 && !scanDirs->contains(item->data(0,5).toString()))
       {
            if(!item->parent() || item->parent()->checkState(0) == Qt::Unchecked)
            {
                scanDirs->append(item->data(0,5).toString()); //adiciona na lista de diretórios a serem escaneados
            }
       }
    }
    else if(item->checkState(0) == Qt::Unchecked) //desmarcou um diretório
    {
        if(item->childCount() > 0 && item->child(0)->data(0,6).toInt() == 1) //já existem diretórios reais marcados abaixo do diretório pai
        {
            for(int i =0; i < item->childCount(); i++) //desmarcando todos os filhos
            {
                item->child(i)->setCheckState(0, Qt::Unchecked);
                item->child(i)->setDisabled(false);
            }
        }

        if(scanDirs->contains(item->data(0, 5).toString())) //removendo da lista de diretórios a escanear, se já existia na lista
        {
            scanDirs->removeAt(scanDirs->indexOf(item->data(0, 5).toString()));
        }
    }
}

/**
 * Carregar a estrutura de uma pasta(os seus subdiretórios)
 */
void ScanCollection::loadFolderStructure(QTreeWidgetItem *item, bool removeFirst)
{
    if(!removeFirst || item->child(0)->data(0,6).toInt() == 0)
    {
        QDir *dit = new QDir(item->data(0, 5).toString());
        QString path;

        QStringList dirNames = dit->entryList(QDir::Dirs | QDir::Readable | QDir::NoDotAndDotDot, QDir::Name);
        QList<QTreeWidgetItem *> items;

        QDir *subDirs = new QDir("/");

        if(removeFirst) //remover o primeiro item(Loading...) dentro de um nível da árvore
        {
            item->removeChild(item->child(0));
        }

        for(int i = 0; i < dirNames.size(); i++)
        {
            path = dit->path();
            if(path == "/") path = "";

            QTreeWidgetItem *dirItem = new QTreeWidgetItem();

            if(removeFirst)
                dirItem = new QTreeWidgetItem(item);

            dirItem->setText(0, dirNames.at(i));

            dirItem->setData(0, 5, path+"/"+dirNames.at(i)+"/");
            dirItem->setData(0, 6, 1); //item é um diretório
            dirItem->setFlags(dirItem->flags() | Qt::ItemIsUserCheckable);

            if(item->checkState(0) == Qt::Checked) //pai marcado
            {
                dirItem->setDisabled(true);
                dirItem->setCheckState(0, Qt::Checked);
            }
            else
                dirItem->setCheckState(0, Qt::Unchecked);

            dirItem->setIcon(0, style()->standardIcon(QStyle::SP_DirIcon));

            //não considerar alguns diretórios
            if(jumpDirs->contains(path+"/"+dirNames.at(i)))
            {
                dirItem->setDisabled(true);
            }
            else
            {
                subDirs = new QDir(dirItem->data(0, 5).toString());
                QStringList subDirNames = subDirs->entryList(QDir::Dirs | QDir::Readable | QDir::NoDotAndDotDot, QDir::Name);

                if(subDirNames.size() > 0) //existem subdiretórios
                {
                    QTreeWidgetItem *childItem = new QTreeWidgetItem(dirItem);
                    childItem->setText(0, tr("Loading..."));
                    childItem->setData(0, 5, path+"/"+"Loading..."+"/");
                    childItem->setData(0, 6, 0); //item não é um diretório
                    childItem->setFlags(childItem->flags() | Qt::ItemIsUserCheckable);
                    childItem->setCheckState(0, Qt::Unchecked);
                }
            }

            if(!removeFirst)
                items.append(dirItem);
        }

        if(!removeFirst)
        {
            this->scanFolderTree->insertTopLevelItems(0, items);
        }
    }
}

/**
 * Chamado quando o botão de escanear for clicado
 */
void ScanCollection::scanFolders()
{
    if(scanDirs->size() > 0) //lista de diretórios contém algum diretório
    {
        emit startScan(scanDirs, jumpDirs);
    }
    else //lista de diretórios a escanear vazia
    {
        QMessageBox::warning(this, tr("Warning"),
                                    tr("You have not especified a folder to scan!\n"
                                       "Please, choose a folder and try again."));
    }
}
