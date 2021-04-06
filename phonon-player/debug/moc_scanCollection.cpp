/****************************************************************************
** Meta object code from reading C++ file 'scanCollection.h'
**
** Created: Sat Nov 21 15:23:27 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scanCollection.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scanCollection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ScanCollection[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      34,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      88,   71,   15,   15, 0x08,
     136,  131,   15,   15, 0x28,
     186,  174,   15,   15, 0x08,
     226,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ScanCollection[] = {
    "ScanCollection\0\0scanDirs,jumpDirs\0"
    "startScan(QStringList*,QStringList*)\0"
    "item,removeFirst\0"
    "loadFolderStructure(QTreeWidgetItem*,bool)\0"
    "item\0loadFolderStructure(QTreeWidgetItem*)\0"
    "item,column\0changeFolderState(QTreeWidgetItem*,int)\0"
    "scanFolders()\0"
};

const QMetaObject ScanCollection::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ScanCollection,
      qt_meta_data_ScanCollection, 0 }
};

const QMetaObject *ScanCollection::metaObject() const
{
    return &staticMetaObject;
}

void *ScanCollection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScanCollection))
        return static_cast<void*>(const_cast< ScanCollection*>(this));
    if (!strcmp(_clname, "Ui::ConfigureWidget"))
        return static_cast< Ui::ConfigureWidget*>(const_cast< ScanCollection*>(this));
    return QDialog::qt_metacast(_clname);
}

int ScanCollection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startScan((*reinterpret_cast< QStringList*(*)>(_a[1])),(*reinterpret_cast< QStringList*(*)>(_a[2]))); break;
        case 1: loadFolderStructure((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: loadFolderStructure((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 3: changeFolderState((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: scanFolders(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ScanCollection::startScan(QStringList * _t1, QStringList * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
