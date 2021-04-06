#include <QtGui>
#include <QMetaType>
#include "phononp.hpp"


//Q_DECLARE_METATYPE(Phonon::MediaObject);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Phononp phonon;
    phonon.show();
    return a.exec();
}
