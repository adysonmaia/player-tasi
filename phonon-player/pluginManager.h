#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QtGui>
#include "ui_pluginManager.h"
#include "ContextInterface.h"

class PluginManager : public QDialog, public Ui::PluginManager
{
    Q_OBJECT

public:
    PluginManager(QList<ContextInterface *> installedPlugins, QWidget *parent = 0);
    ~PluginManager() { }

signals:
    void newPluginInstalled(const QString &path);
    void pluginUninstalled(const int &index);

private slots:
    void installPlugin();
    void uninstallPlugin();
    void searchInstalledPlugins(const QString &);

private:
    ContextInterface *contextInterface;
    bool isPluginInstalled(const QString &pluginName);


    QList<ContextInterface *> installedPlugins;

};

#endif // PLUGINMANAGER_H
