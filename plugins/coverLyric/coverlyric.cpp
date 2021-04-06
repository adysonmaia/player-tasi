#include "coverlyric.hpp"


CoverLyric::CoverLyric(QWidget *parent) : QObject(parent)
{
    controller = new Controller();
    //threadController = new QThread();
    //controller->moveToThread(threadController);

    connect(this, SIGNAL(getCover(MediaObject*)), controller, SLOT(getCover(MediaObject*)) );
    connect(controller, SIGNAL(returnCover(QImage) ), this, SLOT(mountCover(QImage)) );

    connect(this, SIGNAL(getLyric(MediaObject*)), controller, SLOT(getLyric(MediaObject*)) );
    connect(controller, SIGNAL(returnLyric(QString) ), this, SLOT(mountLyric(QString)) );

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}

void CoverLyric::setScrollArea(QScrollArea *sa)
{
    this->sa = sa;
}

void CoverLyric::stateChanged(Phonon::MediaObject *moo)
{
    this->mtResolver = moo;
    emit getCover(this->mtResolver);
    emit getLyric(this->mtResolver);
}

void CoverLyric::mountCover(QImage cover)
{
   this->imageCover = cover;
   this->mountView();
}

void CoverLyric::mountLyric(QString lyric)
{
    this->stringLyric = lyric;
    this->mountView();
}

void CoverLyric::mountView()
{
    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *window = new QWidget();

    int coverMinHeight = this->imageCover.height();

    QGraphicsView *gv = new QGraphicsView();
    QGraphicsScene *gs = new QGraphicsScene();
    QGraphicsPixmapItem *gpi = new QGraphicsPixmapItem(QPixmap::fromImage(this->imageCover) );

    gs->addItem(gpi);
    gv->setScene(gs);
    gv->setMinimumHeight(coverMinHeight+20);

    QTextEdit *te = new QTextEdit();
    te->setReadOnly(true);
    te->setText(this->stringLyric);

    layout->addWidget(gv);
    layout->addWidget(te);
    window->setLayout(layout);

    this->sa->setWidget(window);
    this->sa->setWidgetResizable(true);
}

Q_EXPORT_PLUGIN2(coverLyric, CoverLyric);
