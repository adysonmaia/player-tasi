/**
* @file phononp.cpp
* @author Caio Fellipe
*/
#include "phononp.hpp"
#include <cmath>
#include <cstdlib>


/**Construtor da Classe Phononp
*/
Phononp::Phononp(QWidget *parent) : QMainWindow(parent)
{
   QCoreApplication::setApplicationName(QString("phononp"));
   QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
   QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
   this->setAcceptDrops(false);

   this->pluginLoadError = false;

   this->moo = new Phonon::MediaObject(this);
   this->device = new Phonon::AudioOutput(Phonon::MusicCategory, this);
   metaInformationResolver = new Phonon::MediaObject(this);
   moo->setTickInterval(1000);

   connect(moo, SIGNAL(tick(qint64)), this, SLOT(tick(qint64)));
   connect(moo, SIGNAL(stateChanged(Phonon::State, Phonon::State)),
            this, SLOT(stateChanged(Phonon::State, Phonon::State)));
   connect(metaInformationResolver, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
            this, SLOT(metaStateChanged(Phonon::State, Phonon::State)));

   //informar música atual para os plugins
   connect(moo, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
            this, SLOT(informContext(Phonon::State, Phonon::State)));

   connect(moo, SIGNAL(currentSourceChanged(const Phonon::MediaSource &)),
            this, SLOT(sourceChanged(const Phonon::MediaSource &)));
   connect(moo, SIGNAL(finished()), this, SLOT(musicEnded()));

   createPath(this->moo, this->device);

   setupActions();
   setupMenus();

   setupUi();
   readSettings(); //carregando configurações
   createContextMenu();
   createStatusBar();

   timeLcd->display("00:00");
   seq = 0;
   initialState = true;
}

/**
 * Ao fechar o programa
 */
void Phononp::closeEvent(QCloseEvent *event)
{
       writeSettings(); //gravando configurações

       event->accept();
}

bool Phononp::loadPlugin(const QString &path)
{
    QPluginLoader pluginLoader(path);
    QObject *plugin = pluginLoader.instance();
    if(plugin)
    {
         ContextInterface *contextInterface = qobject_cast<ContextInterface *>(plugin);
         if(contextInterface)
         {
              installedPlugins.append(contextInterface);

              QScrollArea *contextArea = new QScrollArea(contextAreaTabs);

              contextInterface->setScrollArea(contextArea);
              contextAreaTabs->addTab(contextArea, contextInterface->pluginName());

              return true;
         }
    }

    return false;
}

/**
 * Informando a música atual para todos os plugins instalados
 */
void Phononp::informContext(Phonon::State newState, Phonon::State /* oldState */)
{
    if(newState == Phonon::PlayingState)
    {
        for(int i = 0; i < installedPlugins.size(); i++)
        {
            installedPlugins.at(i)->stateChanged(this->moo);
        }
    }
}

void Phononp::about()
{
    QMessageBox::information(this, tr("About Phonon Player"),
        tr("Phono Player. Play audio files in a simplified way"));
}

/**
 * Abre o widget que permite a configuração do player
 */
void Phononp::openPluginsManagerWidget()
{
    pluginManager = new PluginManager(installedPlugins, this);

    connect(pluginManager, SIGNAL(newPluginInstalled(const QString &)), this, SLOT(addPlugin(const QString &)));
    connect(pluginManager, SIGNAL(pluginUninstalled(const int &)), this, SLOT(removePlugin(const int &)));

    pluginManager->show();
}

/**
 * Chamado quando um novo plugin for instalado
 */
void Phononp::addPlugin(const QString &path)
{
    //carregando plugin na área de contexto
    if(loadPlugin(path))
    {
        //adicionando na lista de plugins instalados
        installedPluginsPaths.append(path);
    }
}

/**
 * Chamado quando um plugin for desinstalado
 */
void Phononp::removePlugin(const int &index)
{
    installedPlugins.removeAt(index);
    installedPluginsPaths.removeAt(index);

    contextAreaTabs->removeTab(index);
}

/**
 * Abre o widget que permite a configuração do player
 */
void Phononp::openConfigurationWidget()
{
    scanCollectionWidget = new ScanCollection(this);

    connect(scanCollectionWidget, SIGNAL(startScan(QStringList*,QStringList*)), this, SLOT(startScan(QStringList*,QStringList*)));

    scanCollectionWidget->exec();
}

/**
 * Chamado quando a thread de escaneamento iniciar
 */
void Phononp::startScan(QStringList *scanDirs,QStringList *jumpDirs)
{
    scanAlgorithm.setScanDirs(scanDirs);
    scanAlgorithm.setJumpDirs(jumpDirs);
    scanAlgorithm.setAbort(false);

    //quando achar uma música
    connect(&scanAlgorithm, SIGNAL(musicFound(const QString &)), this, SLOT(musicFound(const QString &)));
    //antes de começar a escanear, configura a progress bar
    connect(&scanAlgorithm, SIGNAL(totalFiles(int)), pbar, SLOT(setMaximum(int)));
    //terminou de escanear
    connect(&scanAlgorithm, SIGNAL(finished()), this, SLOT(scanFinished()));

    messageLabel->setText(tr("Scanning Folders..."));
    stopActionButton->setVisible(true);
    pbar->setVisible(true);
    pbar->reset();

    collectionTable->resetCollectionList(); //reiniciando a lista da coleção
    scanAlgorithm.start(QThread::LowPriority); //rodando a thread que irá escanear os diretórios
}

/**
 * Chamado quando a thread de escaneamento terminar
 */
void Phononp::scanFinished()
{
    pbar->setValue(pbar->maximum());
    pbar->setVisible(false);
    pbar->reset();
    stopActionButton->setVisible(false);

    collectionTable->loadMusicIntoWidget();

    messageLabel->setText(tr("Finished!"));
}

/**
 * Chamado quando clicado no botão para cancelar o Escaneamento
 */
void Phononp::abortScan()
{
    scanAlgorithm.setAbort(true);

    pbar->reset();
    pbar->setVisible(false);

    stopActionButton->setVisible(false);

    messageLabel->setText(tr("Aborted!"));
}

/**
 * Chamado quando a Thread de escaneamento encontra alguma música nos diretórios especificados
 */
void Phononp::musicFound(const QString &path)
{
    pbar->setValue(pbar->value()+1);

    collectionTable->setMusic(path);
}

void Phononp::stateChanged(Phonon::State newState, Phonon::State /* oldState */)
{
    switch (newState) {
        case Phonon::ErrorState:
            if (moo->errorType() == Phonon::FatalError) {
                QMessageBox::warning(this, tr("Fatal Error"),
                moo->errorString());
            } else {
                QMessageBox::warning(this, tr("Error"),
                moo->errorString());
            }
            break;
        case Phonon::PlayingState:
                playAction->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
                playAction->setText(tr("Pause"));
                playAction->setEnabled(true);
                stopAction->setEnabled(true);
                break;
        case Phonon::StoppedState:
                stopAction->setEnabled(false);
                playAction->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
                playAction->setText(tr("Play"));
                playAction->setEnabled(true);
                timeLcd->display("00:00");
                break;
        case Phonon::PausedState:
                playAction->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
                playAction->setText(tr("Play"));
                playAction->setEnabled(true);
                stopAction->setEnabled(true);
                break;
        case Phonon::BufferingState:
                break;
        default:
            ;
    }
}

void Phononp::tick(qint64 time)
{
    QTime displayTime(0, (time / 60000) % 60, (time / 1000) % 60);

    timeLcd->display(displayTime.toString("mm:ss"));
}

void Phononp::addFiles()
{
    QStringList files = QFileDialog::getOpenFileNames(this, tr("Choose audio files"),
        QDesktopServices::storageLocation(QDesktopServices::MusicLocation));

    loadIntoPlaylist(files, -1);
}

void Phononp::loadIntoPlaylist(QStringList &files, int dposition)
{
    if (files.isEmpty())
        return;

    //bool repetido = false;
    foreach (QString string, files) {
            Phonon::MediaSource source(string);
            /*repetido = false;

            foreach(Phonon::MediaSource ms, sources)
            {
                if(ms.fileName() == string)
                {
                    repetido = true;
                    break;
                }
            }*/

            /*if(!repetido)
            {*/
                if(dposition <= 0)
                {
                    sources.append(source);
                }
                else
                {
                    sources.insert(dposition, source);
                }
            //}
    }

    seq = 0;
    playlistTable->clear();

    for(int i = 0; i < sources.size(); i++)
    {
        metaInformationResolver->setCurrentSource(sources.at(i));
    }
}

/**
 * Chamado quando uma ação de drag é iniciada na lista de músicas, então remove-se os itens de música selecionados para poder inseri-los em outra posição
 */
void Phononp::moveMusicItem()
{
    //removeFromPlaylist();
}

void Phononp::removeFromPlaylist()
{
    if(sources.isEmpty())
        return;

    QList<QListWidgetItem *> selitens = playlistTable->selectedItems();

    for(int i = 0; i < selitens.size(); ++i)
    {
        sources.removeAt(playlistTable->row(selitens.at(i)));
        delete playlistTable->takeItem(playlistTable->row(selitens.at(i)));
    }

    if(sources.isEmpty())
    {
        moo->clear();
        moo->clearQueue();
    }
}

void Phononp::addToCollection()
{
    QStringList files = QFileDialog::getOpenFileNames(this, tr("Choose audio files"),
        QDesktopServices::storageLocation(QDesktopServices::MusicLocation));

    loadIntoCollection(files);
}

void Phononp::loadIntoCollection(QStringList &files)
{
    if (files.isEmpty())
        return;

    foreach (QString string, files) {
            Phonon::MediaSource source(string);
            collection.append(source);

            QTreeWidgetItem *childItem = new QTreeWidgetItem(collectionTable->itemAt(0,0));
            childItem->setText(0, string);
    }

    collectionTable->expandAll();
}

void Phononp::dropIntoCollection(QStringList &files)
{
    if (files.isEmpty())
        return;

    foreach (QString string, files) {
            Phonon::MediaSource source(string);
            collection.append(source);
    }

    collectionTable->expandAll();
}


void Phononp::tableClicked(QListWidgetItem *item)
{
    moo->stop();
    moo->clearQueue();

    moo->setCurrentSource(sources[playlistTable->row(item)]);

    moo->play();
}

void Phononp::addToPlaylist(QTreeWidgetItem *item, int /*column*/)
{
    Phonon::MediaSource source(item->data(0,36).toString());
    sources.append(source);

    metaInformationResolver->setCurrentSource(sources.last());
}

void Phononp::sourceChanged(const Phonon::MediaSource &source)
{
    playlistTable->clearSelection();
    playlistTable->setCurrentItem(playlistTable->item(sources.indexOf(source)));
    timeLcd->display("00:00");
}

/**
 * Insere um novo item na lista de músicas
 */
void Phononp::metaStateChanged(Phonon::State newState, Phonon::State /* oldState */)
{
    if (newState == Phonon::ErrorState) {
        QMessageBox::warning(this, tr("Erro ao abrir arquivos"),
            metaInformationResolver->errorString());
        while (!sources.isEmpty() && !(sources.takeLast() == metaInformationResolver->currentSource()))
            ;
        return;
    }

    if (newState != Phonon::StoppedState && newState != Phonon::PausedState)
        return;

    if (metaInformationResolver->currentSource().type() == Phonon::MediaSource::Invalid)
            return;

    QMap<QString, QString> metaData = metaInformationResolver->metaData();

    QString title = metaData.value("TITLE");
    if (title == "")
    {
        title = metaInformationResolver->currentSource().fileName();
        title = title.right(title.length() - title.lastIndexOf('/') - 1);
    }

    QTime itemDisplayTime(0, (metaInformationResolver->totalTime() / 60000) % 60, (metaInformationResolver->totalTime() / 1000) % 60);

    QString artist = metaData.value("ARTIST");
    QString album = metaData.value("ALBUM");

    seq += 1;
    QString trackText = QString::number(seq)+". "+title.toUtf8();
    if(artist != "")
        trackText = trackText+" - "+artist.toUtf8();
    if(album != "")
        trackText = trackText+" - "+album.toUtf8();

    //visualização dos itens
    QListWidgetItem *trackitem = new QListWidgetItem();
    trackitem->setData(Qt::UserRole, sources.at(seq-1).fileName());
    //qDebug() << "\n" << trackText << " => " << sources.at(seq-1).fileName();
    trackitem->setData(Qt::DisplayRole,trackText);
    playlistTable->insertItem(playlistTable->count(), trackitem);

    if(initialState)
    {
        initialState = false;
        moo->setCurrentSource(metaInformationResolver->currentSource());
    }

    Phonon::MediaSource source = metaInformationResolver->currentSource();
    int index = sources.indexOf(metaInformationResolver->currentSource()) + 1;
    if (sources.size() > index) {
        metaInformationResolver->setCurrentSource(sources.at(index));
    }
}

/**
 * Chamado quando uma música tiver terminado de executar
 */
void Phononp::musicEnded()
{
    this->next();
}

/**
 * Vai para a música anterior
 */
void Phononp::previous()
{
    int index = sources.indexOf(moo->currentSource()) - 1;
    if(index >= 0)
    {
        moo->stop();
        moo->clearQueue();
        moo->setCurrentSource(sources.at(index));
        moo->play();
    }
}

/**
 * Vai para a próxima música
 */
void Phononp::next()
{
    int index = sources.indexOf(moo->currentSource()) + 1;

    if(index < sources.size())
    {
        moo->stop();
        moo->clearQueue();
        moo->setCurrentSource(sources.at(index));
        moo->play();
    }
}

/**
 * Pausa ou toca uma determinada música
 */
void Phononp::playpause()
{
    if(moo->state() == Phonon::PausedState || moo->state() == Phonon::StoppedState)
    {
        moo->play();
    }
    else if(moo->state() == Phonon::PlayingState)
    {
        moo->pause();
    }
}

/**
 * Aplica uma ordem aleatória na lista de músicas
 */
void Phononp::randomize()
{
    int num1,num2;
    qsrand(time(NULL));

    randomAction->setEnabled(false);

    for(int i = 0; i < sources.size(); i++)
    {
        num1 = i;
        num2 = qrand() % sources.size();

        //qDebug() << "\nNum1: " << num1 << " | Num2: " << num2 << " | Size: " << sources.size();
        sources.swap(num1,num2);

    }

    playlistTable->clear();
    seq = 0;
    int index;
    index = sources.indexOf(moo->currentSource(), 0);

    for(int i = 0; i < sources.size(); i++)
    {
        metaInformationResolver->setCurrentSource(sources.at(i));
    }

    if(moo->state() == Phonon::StoppedState)
    {
        moo->setCurrentSource(sources.at(0));
    }

    playlistTable->clearSelection();
    playlistTable->setCurrentItem(playlistTable->item(index));

    randomAction->setEnabled(true);
}

/**
 * Configura as ações da interface
 */
void Phononp::setupActions()
{
    playAction = new QAction(style()->standardIcon(QStyle::SP_MediaPlay), tr("Play"), this);
    playAction->setShortcut(tr("Crl+P"));
    playAction->setDisabled(true);
    stopAction = new QAction(style()->standardIcon(QStyle::SP_MediaStop), tr("Stop"), this);
    stopAction->setShortcut(tr("Ctrl+S"));
    stopAction->setDisabled(true);
    nextAction = new QAction(style()->standardIcon(QStyle::SP_MediaSkipForward), tr("Next"), this);
    nextAction->setShortcut(tr("Ctrl+N"));
    previousAction = new QAction(style()->standardIcon(QStyle::SP_MediaSkipBackward), tr("Previous"), this);
    previousAction->setShortcut(tr("Ctrl+R"));
    addFilesAction = new QAction(tr("Add Files to &Playlist"), this);
    addFilesAction->setShortcut(tr("Ctrl+F"));
    addToCollectionAction = new QAction(tr("Add Files to &Collection"), this);
    addToCollectionAction->setShortcut(tr("Ctrl+C"));
    rmPlaylistAction = new QAction(tr("&Remove from playlist"), this);
    rmPlaylistAction->setShortcut(tr("Delete"));
    randomAction = new QAction(tr("Ran&dom"), this);
    randomAction->setShortcut(tr("Ctrl+D"));
    configureAction = new QAction(tr("&Configure Player"), this);
    configureAction->setShortcut(tr("Ctrl+Shift+C"));
    pluginManagerAction = new QAction(tr("&Plugins Manager"), this);
    pluginManagerAction->setShortcut(tr("Ctrl+Shift+P"));

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+X"));
    aboutAction = new QAction(tr("A&bout"), this);
    aboutAction->setShortcut(tr("Ctrl+B"));
    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setShortcut(tr("Ctrl+Q"));

    connect(playAction, SIGNAL(triggered()), this, SLOT(playpause()));
    connect(stopAction, SIGNAL(triggered()), moo, SLOT(stop()));
    connect(previousAction, SIGNAL(triggered()), this, SLOT(previous()));
    connect(nextAction, SIGNAL(triggered()), this, SLOT(next()));
    connect(randomAction, SIGNAL(triggered()), this, SLOT(randomize()));

    connect(addFilesAction, SIGNAL(triggered()), this, SLOT(addFiles()));
    connect(addToCollectionAction, SIGNAL(triggered()), this, SLOT(addToCollection()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(configureAction, SIGNAL(triggered()), this, SLOT(openConfigurationWidget()));
    connect(pluginManagerAction, SIGNAL(triggered()), this, SLOT(openPluginsManagerWidget()));
    connect(rmPlaylistAction, SIGNAL(triggered()), this, SLOT(removeFromPlaylist()));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

/**
 * Configura os menus da interface
 */
void Phononp::setupMenus()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(addToCollectionAction);
    fileMenu->addAction(addFilesAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    QMenu *toolsMenu = menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(pluginManagerAction);

    QMenu *configMenu = menuBar()->addMenu(tr("&Configure"));
    configMenu->addAction(configureAction);

    QMenu *aboutMenu = menuBar()->addMenu(tr("&Help"));
    aboutMenu->addAction(aboutAction);
    aboutMenu->addAction(aboutQtAction);
}

/**
 * Cria um menu de contexto
 */
void Phononp::createContextMenu()
{
   playlistTable->addAction(rmPlaylistAction);
   playlistTable->addAction(randomAction);
   playlistTable->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void Phononp::createStatusBar()
{
    messageLabel = new QLabel("");
    messageLabel->setAlignment(Qt::AlignHCenter);
    messageLabel->setMinimumSize(messageLabel->sizeHint());
    messageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    QSpacerItem *horizontalSpacer = new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Fixed);

    stopActionButton = new QPushButton(style()->standardIcon(QStyle::SP_DialogCancelButton), tr(""));
    stopActionButton->setMaximumSize(QSize(30,30));
    stopActionButton->setVisible(false);

    connect(stopActionButton, SIGNAL(clicked()), this, SLOT(abortScan()));

    pbar = new QProgressBar();
    pbar->setOrientation(Qt::Horizontal);
    pbar->setMinimumSize(QSize(150,0));
    pbar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    pbar->setMinimum(0);
    pbar->setMaximum(100);
    pbar->setValue(0);
    pbar->setVisible(false);

    QHBoxLayout *statusBarLayout = new QHBoxLayout();
    statusBarLayout->addWidget(messageLabel, 1, Qt::AlignLeft);
    statusBarLayout->addSpacerItem(horizontalSpacer);

    QWidget *statusBarWidget = new QWidget();
    statusBarWidget->setLayout(statusBarLayout);

    statusBar()->addWidget(statusBarWidget, 1);
    statusBar()->addWidget(stopActionButton);
    statusBar()->addWidget(pbar);
}

/**
 * Configura a interface inteira
 */
void Phononp::setupUi()
{
    QToolBar *bar = new QToolBar;

    bar->addAction(previousAction);
    bar->addAction(playAction);
    bar->addAction(stopAction);
    bar->addAction(nextAction);
    
    seekSlider = new Phonon::SeekSlider(this);
    seekSlider->setMediaObject(moo);

    volumeSlider = new Phonon::VolumeSlider(this);
    volumeSlider->setAudioOutput(device);

    volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    QLabel *volumeLabel = new QLabel;
    volumeLabel->setPixmap(QPixmap("images/volume.png"));

    QPalette palette;
    palette.setBrush(QPalette::Light, Qt::darkGray);

    timeLcd = new QLCDNumber;
    timeLcd->setPalette(palette);

    collectionTable = new CollectionTree(this);
    collectionTable->setColumnCount(1);
    collectionTable->setHeaderHidden(true);
    collectionTable->setAnimated(true);
    collectionTable->setMinimumSize(QSize(CollectionW, CollectionH));

    connect(collectionTable, SIGNAL(itemDoubleClicked (QTreeWidgetItem *, int)),
            this, SLOT(addToPlaylist(QTreeWidgetItem *, int)));
    connect(collectionTable, SIGNAL(dropAccepted(QStringList &)),
            this, SLOT(dropIntoCollection(QStringList &)));

    QStringList headers;
    headers << tr("Title") << tr("Artist") << tr("Album") << tr("Year");

    playlistTable = new PlaylistTable();
    playlistTable->setSelectionMode(QAbstractItemView::ExtendedSelection);
    playlistTable->setResizeMode(QListView::Adjust);
    playlistTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    playlistTable->setMinimumSize(QSize(PlaylistW, PlaylistH));

    connect(playlistTable, SIGNAL(itemDoubleClicked (QListWidgetItem *)),
            this, SLOT(tableClicked(QListWidgetItem *)));
    connect(playlistTable, SIGNAL(dropAccepted(QStringList &, int )),
            this, SLOT(loadIntoPlaylist(QStringList &, int)));
    connect(playlistTable, SIGNAL(dragInProgress()),
            this, SLOT(moveMusicItem()));

    //Área de contexto dos plugins
    contextAreaTabs = new QTabWidget();
    contextAreaTabs->setMinimumSize(QSize(ContextW, ContextH));

    QHBoxLayout *seekerLayout = new QHBoxLayout;
    seekerLayout->addWidget(seekSlider);
    seekerLayout->addWidget(timeLcd);

    QHBoxLayout *playbackLayout = new QHBoxLayout;
    playbackLayout->addWidget(bar);
    playbackLayout->addStretch();
    playbackLayout->addWidget(volumeLabel);
    playbackLayout->addWidget(volumeSlider);

    QList<int> tablesSizes;
    tablesSizes << 400 << 400 << 400;

    QSplitter *tablesSplitter = new QSplitter;
    tablesSplitter->addWidget(collectionTable);
    tablesSplitter->addWidget(contextAreaTabs);
    tablesSplitter->addWidget(playlistTable);
    tablesSplitter->setSizes(tablesSizes);

    QVBoxLayout *controlBarLayout = new QVBoxLayout;
    controlBarLayout->addLayout(seekerLayout);
    controlBarLayout->addLayout(playbackLayout);

    QWidget *controlWidget = new QWidget;
    controlWidget->setLayout(controlBarLayout);

    controlWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    QVBoxLayout *containerLayout = new QVBoxLayout;
    containerLayout->addWidget(tablesSplitter);
    containerLayout->addWidget(controlWidget);

    QWidget *mainWidget = new QWidget;
    mainWidget->setLayout(containerLayout);

    setCentralWidget(mainWidget);
    setWindowTitle("Phonon Player");
}

/**
 * Salvando configurações
 */
void Phononp::writeSettings()
{
    QSettings settings("Phononp Settings", "Phononp");
    settings.setValue("geometry", geometry());
    settings.setValue("plugins", installedPluginsPaths);
}

/**
 * Carregando configurações
 */
void Phononp::readSettings()
{
    QSettings settings("Phononp Settings", "Phononp");

    QRect rect = settings.value("geometry", QRect(200, 200, 900, 400)).toRect();
    move(rect.topLeft());
    resize(rect.size());

    //carregando plugins instalados
    installedPluginsPaths = settings.value("plugins").toStringList();

    for(int i = 0; i < installedPluginsPaths.size(); i++)
    {
        loadPlugin(installedPluginsPaths.at(i));
    }
}

