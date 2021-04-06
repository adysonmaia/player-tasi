#ifndef SCANALGORITHM_H
#define SCANALGORITHM_H

#include <QMutex>
#include <QThread>
#include "collectionTree.h"

class ScanAlgorithm : public QThread
{
    Q_OBJECT

    public:
        ScanAlgorithm(QObject *parent = 0);
        ~ScanAlgorithm();

        /**
         * Sets
         */
        void setScanDirs(QStringList *scanDirs);
        void setJumpDirs(QStringList *jumpDirs);
        void setAbort(bool value);

        /**
         * Gets
         */
        QStringList* getScanDirs();
        QStringList* getJumpDirs();

    signals:
        void musicFound(const QString &);
        void totalFiles(int );

    protected:
        void run();

    private:
        QMutex mutex;

        bool abort;

        QStringList *scanDirs;
        QStringList *jumpDirs;
        CollectionTree *collectionTree;

        QStringList *acceptedExt;

};

#endif // SCANALGORITHM_H
