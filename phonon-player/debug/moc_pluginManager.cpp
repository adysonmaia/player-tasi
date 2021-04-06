/****************************************************************************
** Meta object code from reading C++ file 'pluginManager.h'
**
** Created: Sat Nov 21 15:23:34 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pluginManager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pluginManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PluginManager[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      20,   15,   14,   14, 0x05,
      54,   48,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      77,   14,   14,   14, 0x08,
      93,   14,   14,   14, 0x08,
     111,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PluginManager[] = {
    "PluginManager\0\0path\0newPluginInstalled(QString)\0"
    "index\0pluginUninstalled(int)\0"
    "installPlugin()\0uninstallPlugin()\0"
    "searchInstalledPlugins(QString)\0"
};

const QMetaObject PluginManager::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PluginManager,
      qt_meta_data_PluginManager, 0 }
};

const QMetaObject *PluginManager::metaObject() const
{
    return &staticMetaObject;
}

void *PluginManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PluginManager))
        return static_cast<void*>(const_cast< PluginManager*>(this));
    if (!strcmp(_clname, "Ui::PluginManager"))
        return static_cast< Ui::PluginManager*>(const_cast< PluginManager*>(this));
    return QDialog::qt_metacast(_clname);
}

int PluginManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newPluginInstalled((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: pluginUninstalled((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: installPlugin(); break;
        case 3: uninstallPlugin(); break;
        case 4: searchInstalledPlugins((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void PluginManager::newPluginInstalled(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PluginManager::pluginUninstalled(const int & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
