/****************************************************************************
** Meta object code from reading C++ file 'phononp.hpp'
**
** Created: Tue Nov 24 00:29:05 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "phononp.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'phononp.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Phononp[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      20,    8,    8,    8, 0x08,
      38,    8,    8,    8, 0x08,
      59,    8,    8,    8, 0x08,
      67,    8,    8,    8, 0x08,
      93,    8,    8,    8, 0x08,
     126,  120,    8,    8, 0x08,
     159,  120,    8,    8, 0x08,
     208,  192,    8,    8, 0x08,
     243,    8,    8,    8, 0x08,
     277,  259,    8,    8, 0x08,
     338,  320,    8,    8, 0x08,
     375,    8,    8,    8, 0x08,
     390,    8,    8,    8, 0x08,
     407,  402,    8,    8, 0x08,
     427,  259,    8,    8, 0x08,
     474,  469,    8,    8, 0x08,
     494,  487,    8,    8, 0x08,
     529,  259,    8,    8, 0x08,
     580,  575,    8,    8, 0x08,
     623,  611,    8,    8, 0x08,
     659,    8,    8,    8, 0x08,
     671,    8,    8,    8, 0x08,
     678,    8,    8,    8, 0x08,
     689,    8,    8,    8, 0x08,
     701,  402,    8,    8, 0x08,
     726,  720,    8,    8, 0x08,
     744,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Phononp[] = {
    "Phononp\0\0addFiles()\0addToCollection()\0"
    "removeFromPlaylist()\0about()\0"
    "openConfigurationWidget()\0"
    "openPluginsManagerWidget()\0files\0"
    "loadIntoCollection(QStringList&)\0"
    "dropIntoCollection(QStringList&)\0"
    "files,dposition\0loadIntoPlaylist(QStringList&,int)\0"
    "moveMusicItem()\0newState,oldState\0"
    "informContext(Phonon::State,Phonon::State)\0"
    "scanDirs,jumpDirs\0"
    "startScan(QStringList*,QStringList*)\0"
    "scanFinished()\0abortScan()\0path\0"
    "musicFound(QString)\0"
    "stateChanged(Phonon::State,Phonon::State)\0"
    "time\0tick(qint64)\0source\0"
    "sourceChanged(Phonon::MediaSource)\0"
    "metaStateChanged(Phonon::State,Phonon::State)\0"
    "item\0tableClicked(QListWidgetItem*)\0"
    "item,column\0addToPlaylist(QTreeWidgetItem*,int)\0"
    "playpause()\0next()\0previous()\0randomize()\0"
    "addPlugin(QString)\0index\0removePlugin(int)\0"
    "musicEnded()\0"
};

const QMetaObject Phononp::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Phononp,
      qt_meta_data_Phononp, 0 }
};

const QMetaObject *Phononp::metaObject() const
{
    return &staticMetaObject;
}

void *Phononp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Phononp))
        return static_cast<void*>(const_cast< Phononp*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Phononp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addFiles(); break;
        case 1: addToCollection(); break;
        case 2: removeFromPlaylist(); break;
        case 3: about(); break;
        case 4: openConfigurationWidget(); break;
        case 5: openPluginsManagerWidget(); break;
        case 6: loadIntoCollection((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 7: dropIntoCollection((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 8: loadIntoPlaylist((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: moveMusicItem(); break;
        case 10: informContext((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 11: startScan((*reinterpret_cast< QStringList*(*)>(_a[1])),(*reinterpret_cast< QStringList*(*)>(_a[2]))); break;
        case 12: scanFinished(); break;
        case 13: abortScan(); break;
        case 14: musicFound((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: stateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 16: tick((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 17: sourceChanged((*reinterpret_cast< const Phonon::MediaSource(*)>(_a[1]))); break;
        case 18: metaStateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 19: tableClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 20: addToPlaylist((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 21: playpause(); break;
        case 22: next(); break;
        case 23: previous(); break;
        case 24: randomize(); break;
        case 25: addPlugin((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 26: removePlugin((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 27: musicEnded(); break;
        default: ;
        }
        _id -= 28;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
