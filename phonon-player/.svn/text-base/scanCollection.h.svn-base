#ifndef SCANCOLLECTION_H
#define SCANCOLLECTION_H

#include <QtGui>
#include "ui_configureWidget.h"

class ScanCollection : public QDialog, public Ui::ConfigureWidget
{
    Q_OBJECT

public:
    ScanCollection(QWidget *parent = 0);
    ~ScanCollection() { }

private slots:
    void loadFolderStructure(QTreeWidgetItem *item, bool removeFirst = true);
    void changeFolderState(QTreeWidgetItem *item, int column);
    void scanFolders();

signals:
    void startScan(QStringList *scanDirs, QStringList *jumpDirs);

private:
    /**
     * Diretórios a serem escaneados
     */
    QStringList *scanDirs;
    /**
     * Diretórios a desconsiderar durante a busca
     */
    QStringList *jumpDirs;
};

#endif // SCANCOLLECTION_H
