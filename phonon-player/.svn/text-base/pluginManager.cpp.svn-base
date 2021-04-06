#include "pluginManager.h"
#include <QtDebug>

PluginManager::PluginManager(QList<ContextInterface *> installedPlugins, QWidget *parent)
        :QDialog(parent)
{
    setupUi(this);

    this->installedPlugins = installedPlugins;

    foreach(ContextInterface *plugin, installedPlugins)
    {
        installedPluginsList->addItem(plugin->pluginName()+" "+plugin->pluginVersion()+"\n"+plugin->pluginDescription());
    }

    this->installButton->setIcon(style()->standardIcon(QStyle::SP_DirIcon));
    this->uninstallButton->setIcon(style()->standardIcon(QStyle::SP_DialogCancelButton));

    connect(installButton, SIGNAL(clicked()), this, SLOT(installPlugin()));
    connect(uninstallButton, SIGNAL(clicked()), this, SLOT(uninstallPlugin()));
    connect(searchLine, SIGNAL(textChanged(const QString &)), this, SLOT(searchInstalledPlugins(const QString &)));
}


/**
 * Instala um plugin no player
 * Chamado quando o botão de instalar um plugin for clicado
 */
void PluginManager::installPlugin()
{
    //diálogo de escolha de arquivos
    QStringList files = QFileDialog::getOpenFileNames( this,
                                 tr("Select one or more plugins to install"),
                                 QDesktopServices::storageLocation(QDesktopServices::HomeLocation),
                                 tr("Player Plugins (*.so)"));

    //percorrendo os plugins escolhidos para instalar
    foreach (QString fileName, files) {
         QPluginLoader pluginLoader(fileName);
         QObject *plugin = pluginLoader.instance();
         if (plugin) {
             contextInterface = qobject_cast<ContextInterface *>(plugin);
             if (contextInterface)
             {
                 QString pluginName = contextInterface->pluginName();
                 //pesquisa se já não existe um plugin instalado com o mesmo nome
                 if(!isPluginInstalled(pluginName))
                 {
                     //adiciona plugin à lista de plugins instalados
                     installedPluginsList->addItem(pluginName+" "+contextInterface->pluginVersion()+"\n"+contextInterface->pluginDescription());
                     installedPlugins.append(contextInterface);
                     //emitindo sinal de plugin instalado
                     emit newPluginInstalled(fileName);

                     QMessageBox::warning(this, tr("Success"), tr("Plugin installed with success!"));
                 }
                 else
                 {
                     QMessageBox::warning(this, tr("Error"), tr("Plugin with the same name already installed!"));
                 }
             }
             else
             {
                 QMessageBox::warning(this, tr("Error"), tr("Error loading the plugin"));
             }
         }
         else
         {
             QMessageBox::warning(this, tr("Error"), tr("Error loading the plugin"));
         }
     }

}

/**
 * Desinstala um plugin que está instalado no player
 */
void PluginManager::uninstallPlugin()
{
     QListWidgetItem *selectedPlugin = installedPluginsList->selectedItems().at(0);
     int index = installedPluginsList->row(selectedPlugin);
     qDebug() << index;

     if(index >= 0 && index < installedPlugins.size())
     {
         QMessageBox msgBox;
         msgBox.setWindowTitle(tr("Uninstall Plugin"));
         msgBox.setInformativeText(tr("Do you really want to uninstall the plugin \"")+installedPlugins.at(index)->pluginName()+tr("\""));
         msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
         msgBox.setDefaultButton(QMessageBox::No);
         int ret = msgBox.exec();

         switch (ret) {
           case QMessageBox::Yes:
               //desinstalar plugin
               delete installedPluginsList->takeItem(index);

               //removendo da lista de plugins instalados
               installedPlugins.removeAt(index);

               //sinal que avisará o player sobre a desinstalação do plugin
               emit pluginUninstalled(index);

               break;
           case QMessageBox::No:
               // Não desinstalar

               break;
           default:
               // should never be reached
               break;
         }
     }
}

/**
 * Verifica se existe um plugin com um determinado nome instalado no player
 */
bool PluginManager::isPluginInstalled(const QString &pluginName)
{
    for(int i = 0; i < installedPlugins.size(); i++)
    {
        if(installedPlugins.at(i)->pluginName() == pluginName)
            return true;
    }

    return false;
}

/**
 * Executa uma busca na lista de plugins instalados, retornando apenas os plugins que satisfazem as condições da busca
 */
void PluginManager::searchInstalledPlugins(const QString &search)
{
    installedPluginsList->clear();

    if(search.isEmpty())
    {
        for(int i = 0; i < installedPlugins.size(); i++)
        {
            installedPluginsList->addItem(installedPlugins.at(i)->pluginName()+" "+installedPlugins.at(i)->pluginVersion()+"\n"+installedPlugins.at(i)->pluginDescription());
        }
    }
    else
    {
        for(int i = 0; i < installedPlugins.size(); i++)
        {
            if(installedPlugins.at(i)->pluginName().contains(search, Qt::CaseInsensitive))
            {
                installedPluginsList->addItem(installedPlugins.at(i)->pluginName()+" "+installedPlugins.at(i)->pluginVersion()+"\n"+installedPlugins.at(i)->pluginDescription());
            }
        }

        if(installedPluginsList->count() == 0)
        {
            installedPluginsList->addItem(tr("No plugin found!"));
        }
    }
}


