/****************************************************************************
** Meta object code from reading C++ file 'coverlyric.hpp'
**
** Created: Mon Nov 23 21:43:55 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "coverlyric.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coverlyric.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CoverLyric[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      35,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   11,   11,   11, 0x08,
      77,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CoverLyric[] = {
    "CoverLyric\0\0getCover(MediaObject*)\0"
    "getLyric(MediaObject*)\0mountCover(QImage)\0"
    "mountLyric(QString)\0"
};

const QMetaObject CoverLyric::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CoverLyric,
      qt_meta_data_CoverLyric, 0 }
};

const QMetaObject *CoverLyric::metaObject() const
{
    return &staticMetaObject;
}

void *CoverLyric::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CoverLyric))
        return static_cast<void*>(const_cast< CoverLyric*>(this));
    if (!strcmp(_clname, "ContextInterface"))
        return static_cast< ContextInterface*>(const_cast< CoverLyric*>(this));
    if (!strcmp(_clname, "ContextInterface/1.0"))
        return static_cast< ContextInterface*>(const_cast< CoverLyric*>(this));
    return QObject::qt_metacast(_clname);
}

int CoverLyric::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: getCover((*reinterpret_cast< MediaObject*(*)>(_a[1]))); break;
        case 1: getLyric((*reinterpret_cast< MediaObject*(*)>(_a[1]))); break;
        case 2: mountCover((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: mountLyric((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CoverLyric::getCover(MediaObject * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CoverLyric::getLyric(MediaObject * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
