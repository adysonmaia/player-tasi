/****************************************************************************
** Meta object code from reading C++ file 'scanAlgorithm.h'
**
** Created: Sun Nov 22 16:05:49 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "scanAlgorithm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scanAlgorithm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ScanAlgorithm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      35,   14,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ScanAlgorithm[] = {
    "ScanAlgorithm\0\0musicFound(QString)\0"
    "totalFiles(int)\0"
};

const QMetaObject ScanAlgorithm::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ScanAlgorithm,
      qt_meta_data_ScanAlgorithm, 0 }
};

const QMetaObject *ScanAlgorithm::metaObject() const
{
    return &staticMetaObject;
}

void *ScanAlgorithm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScanAlgorithm))
        return static_cast<void*>(const_cast< ScanAlgorithm*>(this));
    return QThread::qt_metacast(_clname);
}

int ScanAlgorithm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: musicFound((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: totalFiles((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ScanAlgorithm::musicFound(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ScanAlgorithm::totalFiles(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
