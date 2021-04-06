#include "scanAlgorithm.h"

#include <QtGui>
#include <QtDebug>

ScanAlgorithm::ScanAlgorithm(QObject *parent)
   :QThread(parent)
{
    abort = false;

    /*Extensões suportadas*/
    acceptedExt = new QStringList();
    acceptedExt->append(QString("mp3"));
    acceptedExt->append(QString("ogg"));
    acceptedExt->append(QString("aac"));
    acceptedExt->append(QString("wma"));
    acceptedExt->append(QString("ac3"));
    acceptedExt->append(QString("mpc"));
    acceptedExt->append(QString("acd"));
    acceptedExt->append(QString("cda"));
    acceptedExt->append(QString("mid"));
    acceptedExt->append(QString("midi"));
    acceptedExt->append(QString("mpa"));
}

ScanAlgorithm::~ScanAlgorithm()
{
    mutex.lock();
        abort = true;
    mutex.unlock();
}

void ScanAlgorithm::setScanDirs(QStringList *scanDirs)
{
    QMutexLocker locker(&mutex);

    this->scanDirs = scanDirs;
}

void ScanAlgorithm::setJumpDirs(QStringList *jumpDirs)
{
    QMutexLocker locker(&mutex);

    this->jumpDirs = jumpDirs;
}

QStringList* ScanAlgorithm::getScanDirs()
{
    QMutexLocker locker(&mutex);

    return scanDirs;
}

QStringList* ScanAlgorithm::getJumpDirs()
{
    QMutexLocker locker(&mutex);

    return jumpDirs;
}

void ScanAlgorithm::setAbort(bool value)
{
    QMutexLocker locker(&mutex);

    this->abort = value;
}

void ScanAlgorithm::run()
{
    mutex.lock();
        QStringList *scanDirs = this->scanDirs;
    mutex.unlock();

    int filesCount = 0;


    /**
     * Contabilizando o total de arquivos
     */
    for(int i = 0; i < scanDirs->size(); i++) //percorrendo a lista de diretórios a serem escaneados
    {
        QDirIterator fit(scanDirs->at(i),
                        QDir::NoDotAndDotDot | QDir::Readable | QDir::Files,
                        QDirIterator::Subdirectories | QDirIterator::FollowSymlinks);

        while (fit.hasNext()) //iterando recursivamente pelos subdiretórios do diretório escolhido
        {
            if(abort)
            {
                return;
            }

            QString filePath = fit.next();
            QFile file(filePath);
            QFileInfo fileInfo(file);

            //algum arquivo de áudio encontrado
            if(acceptedExt->contains(fileInfo.completeSuffix(), Qt::CaseInsensitive))
            {
                filesCount++;
            }
        }
    }

    emit totalFiles(filesCount);
    
    /**
     * Escaneando os diretórios escolhidos
     */
    for(int i = 0; i < scanDirs->size(); i++) //percorrendo a lista de diretórios a serem escaneados
    {
        QDirIterator fit(scanDirs->at(i),
                        QDir::NoDotAndDotDot | QDir::Readable | QDir::Files,
                        QDirIterator::Subdirectories | QDirIterator::FollowSymlinks);

        while (fit.hasNext()) //iterando recursivamente pelos subdiretórios do diretório escolhido
        {
          /*verificando se a busca foi cancelada*/
          if(abort)
          {
             return;
          }

          QString filePath = fit.next();
          QFile file(filePath);
          QFileInfo fileInfo(file);

          //algum arquivo de áudio encontrado
          if(acceptedExt->contains(fileInfo.completeSuffix(), Qt::CaseInsensitive))
          {
             emit musicFound(filePath);
          }
       }
    }
}


