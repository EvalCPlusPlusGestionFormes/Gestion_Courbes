/****************************************************************************
** Meta object code from reading C++ file 'fdessiner.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dlldessiner/fdessiner.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fdessiner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FDessiner_t {
    QByteArrayData data[8];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FDessiner_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FDessiner_t qt_meta_stringdata_FDessiner = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FDessiner"
QT_MOC_LITERAL(1, 10, 22), // "CBGererAffichageNormal"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 21), // "CBGererAffichageCadre"
QT_MOC_LITERAL(4, 56, 17), // "CBGererEffacement"
QT_MOC_LITERAL(5, 74, 15), // "CBVSliderChange"
QT_MOC_LITERAL(6, 90, 1), // "v"
QT_MOC_LITERAL(7, 92, 15) // "CBHSliderChange"

    },
    "FDessiner\0CBGererAffichageNormal\0\0"
    "CBGererAffichageCadre\0CBGererEffacement\0"
    "CBVSliderChange\0v\0CBHSliderChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FDessiner[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void FDessiner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FDessiner *_t = static_cast<FDessiner *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CBGererAffichageNormal(); break;
        case 1: _t->CBGererAffichageCadre(); break;
        case 2: _t->CBGererEffacement(); break;
        case 3: _t->CBVSliderChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->CBHSliderChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FDessiner::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FDessiner.data,
      qt_meta_data_FDessiner,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FDessiner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FDessiner::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FDessiner.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FDessiner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
