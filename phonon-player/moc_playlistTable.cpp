/****************************************************************************
** Meta object code from reading C++ file 'playlistTable.h'
**
** Created: Sun Nov 22 16:05:43 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "playlistTable.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playlistTable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PlaylistTable[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      27,   15,   14,   14, 0x05,
      58,   14,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_PlaylistTable[] = {
    "PlaylistTable\0\0files,index\0"
    "dropAccepted(QStringList&,int)\0"
    "dragInProgress()\0"
};

const QMetaObject PlaylistTable::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_PlaylistTable,
      qt_meta_data_PlaylistTable, 0 }
};

const QMetaObject *PlaylistTable::metaObject() const
{
    return &staticMetaObject;
}

void *PlaylistTable::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PlaylistTable))
        return static_cast<void*>(const_cast< PlaylistTable*>(this));
    return QListWidget::qt_metacast(_clname);
}

int PlaylistTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: dropAccepted((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: dragInProgress(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void PlaylistTable::dropAccepted(QStringList & _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlaylistTable::dragInProgress()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
