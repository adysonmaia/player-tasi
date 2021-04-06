/****************************************************************************
** Meta object code from reading C++ file 'controller.hpp'
**
** Created: Mon Nov 23 21:16:25 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "controller.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Controller[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x05,
      44,   38,   11,   11, 0x05,
      67,   65,   11,   11, 0x05,
      96,   65,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     129,  125,   11,   11, 0x0a,
     152,  125,   11,   11, 0x0a,
     175,   11,   11,   11, 0x08,
     191,   12,   11,   11, 0x08,
     210,   11,   11,   11, 0x08,
     226,   38,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Controller[] = {
    "Controller\0\0image\0returnCover(QImage)\0"
    "lyric\0returnLyric(QString)\0,\0"
    "searchCover(QString,QString)\0"
    "searchLyric(QString,QString)\0moo\0"
    "getCover(MediaObject*)\0getLyric(MediaObject*)\0"
    "coverNotFound()\0coverFound(QImage)\0"
    "lyricNotFound()\0lyricFound(QString)\0"
};

const QMetaObject Controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Controller,
      qt_meta_data_Controller, 0 }
};

const QMetaObject *Controller::metaObject() const
{
    return &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Controller))
        return static_cast<void*>(const_cast< Controller*>(this));
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: returnCover((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: returnLyric((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: searchCover((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: searchLyric((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: getCover((*reinterpret_cast< MediaObject*(*)>(_a[1]))); break;
        case 5: getLyric((*reinterpret_cast< MediaObject*(*)>(_a[1]))); break;
        case 6: coverNotFound(); break;
        case 7: coverFound((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 8: lyricNotFound(); break;
        case 9: lyricFound((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Controller::returnCover(QImage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Controller::returnLyric(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Controller::searchCover(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Controller::searchLyric(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
