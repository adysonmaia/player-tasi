/****************************************************************************
** Meta object code from reading C++ file 'lyricmodel.hpp'
**
** Created: Mon Nov 23 21:16:27 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "lyricmodel.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lyricmodel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LyricModel[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x05,
      38,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      67,   54,   11,   11, 0x0a,
      96,   11,   11,   11, 0x08,
     127,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LyricModel[] = {
    "LyricModel\0\0lyric\0lyricFound(QString)\0"
    "lyricNotFound()\0artist,title\0"
    "searchLyric(QString,QString)\0"
    "finishedSearch(QNetworkReply*)\0"
    "finishedLyric(QNetworkReply*)\0"
};

const QMetaObject LyricModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LyricModel,
      qt_meta_data_LyricModel, 0 }
};

const QMetaObject *LyricModel::metaObject() const
{
    return &staticMetaObject;
}

void *LyricModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LyricModel))
        return static_cast<void*>(const_cast< LyricModel*>(this));
    return QObject::qt_metacast(_clname);
}

int LyricModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: lyricFound((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: lyricNotFound(); break;
        case 2: searchLyric((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: finishedSearch((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: finishedLyric((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void LyricModel::lyricFound(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LyricModel::lyricNotFound()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
