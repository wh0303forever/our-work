/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Server_t {
    QByteArrayData data[17];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Server_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Server_t qt_meta_stringdata_Server = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Server"
QT_MOC_LITERAL(1, 7, 13), // "HandleMessage"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "classfyMessage"
QT_MOC_LITERAL(4, 37, 8), // "ShowLink"
QT_MOC_LITERAL(5, 46, 11), // "ShowRequire"
QT_MOC_LITERAL(6, 58, 14), // "HandleRegister"
QT_MOC_LITERAL(7, 73, 11), // "HandleLogin"
QT_MOC_LITERAL(8, 85, 14), // "stringTopixmap"
QT_MOC_LITERAL(9, 100, 20), // "handleupdatepassword"
QT_MOC_LITERAL(10, 121, 15), // "handleupdatesex"
QT_MOC_LITERAL(11, 137, 25), // "handlepersonalinformation"
QT_MOC_LITERAL(12, 163, 13), // "handdlebrowse"
QT_MOC_LITERAL(13, 177, 16), // "handleparticular"
QT_MOC_LITERAL(14, 194, 12), // "handleRelase"
QT_MOC_LITERAL(15, 207, 10), // "SendToHost"
QT_MOC_LITERAL(16, 218, 11) // "handlexinxi"

    },
    "Server\0HandleMessage\0\0classfyMessage\0"
    "ShowLink\0ShowRequire\0HandleRegister\0"
    "HandleLogin\0stringTopixmap\0"
    "handleupdatepassword\0handleupdatesex\0"
    "handlepersonalinformation\0handdlebrowse\0"
    "handleparticular\0handleRelase\0SendToHost\0"
    "handlexinxi"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Server[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    1,   92,    2, 0x08 /* Private */,
       6,    1,   95,    2, 0x08 /* Private */,
       7,    1,   98,    2, 0x08 /* Private */,
       8,    1,  101,    2, 0x08 /* Private */,
       9,    1,  104,    2, 0x08 /* Private */,
      10,    1,  107,    2, 0x08 /* Private */,
      11,    1,  110,    2, 0x08 /* Private */,
      12,    1,  113,    2, 0x08 /* Private */,
      13,    1,  116,    2, 0x08 /* Private */,
      14,    1,  119,    2, 0x08 /* Private */,
      15,    1,  122,    2, 0x08 /* Private */,
      16,    1,  125,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::QPixmap, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList,    2,

       0        // eod
};

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Server *_t = static_cast<Server *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->HandleMessage(); break;
        case 1: _t->classfyMessage(); break;
        case 2: _t->ShowLink(); break;
        case 3: _t->ShowRequire((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->HandleRegister((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 5: _t->HandleLogin((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 6: { QPixmap _r = _t->stringTopixmap((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->handleupdatepassword((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 8: _t->handleupdatesex((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 9: _t->handlepersonalinformation((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 10: _t->handdlebrowse((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 11: _t->handleparticular((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 12: _t->handleRelase((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 13: _t->SendToHost((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->handlexinxi((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Server::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Server.data,
      qt_meta_data_Server,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Server.stringdata0))
        return static_cast<void*>(const_cast< Server*>(this));
    return QWidget::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
