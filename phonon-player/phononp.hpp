/**
 * @file phonop.hpp
 * @author Caio Fellipe
 */
#ifndef PHONONP_HPP
#define PHONONP_HPP

#include <QtGui>
#include <QMetaType>
#include <phonon/audiooutput.h>
#include <phonon/seekslider.h>
#include <phonon/mediaobject.h>
#include <phonon/volumeslider.h>
#include <phonon/backendcapabilities.h>
#include <QList>
#include "collectionTree.h"
#include "playlistTable.h"
#include "ContextInterface.h"
#include "scanCollection.h"
#include "scanAlgorithm.h"
#include "pluginManager.h"
using namespace Phonon;

QT_BEGIN_NAMESPACE
class QAction;
class QTableWidget;
class QLCDNumber;
QT_END_NAMESPACE

//dimensões preferidas
enum WidgetsMinWidth { CollectionW = 300, ContextW = 300, PlaylistW = 300 };
enum WidgetsMinHeigth { CollectionH = 400, ContextH = 400, PlaylistH = 400 };

class Phononp : public QMainWindow
{
  Q_OBJECT

   public:
      Phononp(QWidget *parent = 0);

      QSize sizeHint() const {
        return QSize(600, 300);
      }

   private slots:
      void addFiles();
      void addToCollection();
      void removeFromPlaylist();
      void about();
      void openConfigurationWidget();
      void openPluginsManagerWidget();
      void loadIntoCollection(QStringList &files);
      void dropIntoCollection(QStringList &files);
      void loadIntoPlaylist(QStringList &files, int dposition);
      void moveMusicItem();
      void informContext(Phonon::State newState, Phonon::State oldState);

      void startScan(QStringList *scanDirs,QStringList *jumpDirs);
      void scanFinished();
      void abortScan();
      void musicFound(const QString &path);

      void stateChanged(Phonon::State newState, Phonon::State oldState);
      void tick(qint64 time);
      void sourceChanged(const Phonon::MediaSource &source);
      void metaStateChanged(Phonon::State newState, Phonon::State oldState);
      void tableClicked(QListWidgetItem *item);
      void addToPlaylist(QTreeWidgetItem *item, int column);
      void playpause();
      void next();
      void previous();
      void randomize();

      void addPlugin(const QString &path);
      void removePlugin(const int &index);
      void musicEnded();

   protected:
      void closeEvent(QCloseEvent *event);

   private:
      void setupUi();
      void setupActions();
      void setupMenus();
      void createContextMenu();
      void createStatusBar();
      bool loadPlugin(const QString &path);

      void writeSettings();
      void readSettings();

      Phonon::MediaObject *moo;
      Phonon::AudioOutput *device;
      Phonon::SeekSlider *seekSlider;
      Phonon::MediaObject *metaInformationResolver;
      Phonon::VolumeSlider *volumeSlider;
      QList<Phonon::MediaSource> sources;
      QList<Phonon::MediaSource> collection;

      QAction *playAction;
      QAction *pauseAction;
      QAction *stopAction;
      QAction *nextAction;
      QAction *previousAction;
      QAction *addFilesAction;
      QAction *addToCollectionAction;
      QAction *exitAction;
      QAction *pluginManagerAction;
      QAction *configureAction;
      QAction *rmPlaylistAction;
      QAction *randomAction;
      QAction *aboutAction;
      QAction *aboutQtAction;
      QLCDNumber *timeLcd;
      CollectionTree *collectionTable;
      PlaylistTable *playlistTable;
      QTabWidget *contextAreaTabs;

      QLabel *messageLabel;
      QPushButton *stopActionButton;
      QProgressBar *pbar;

      ScanCollection *scanCollectionWidget;
      PluginManager *pluginManager;

      ScanAlgorithm scanAlgorithm;

      QStringList installedPluginsPaths;
      QList<ContextInterface *> installedPlugins;

      int seq;
      bool initialState;
      bool pluginLoadError;
};



#endif
