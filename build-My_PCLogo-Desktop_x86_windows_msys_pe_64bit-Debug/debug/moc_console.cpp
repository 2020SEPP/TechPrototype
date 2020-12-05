/****************************************************************************
** Meta object code from reading C++ file 'console.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../My_PCLogo/console.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'console.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Console_t {
    QByteArrayData data[11];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Console_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Console_t qt_meta_stringdata_Console = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Console"
QT_MOC_LITERAL(1, 8, 7), // "newLine"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 13), // "newLineWriten"
QT_MOC_LITERAL(4, 31, 8), // "drawLine"
QT_MOC_LITERAL(5, 40, 13), // "turnDirection"
QT_MOC_LITERAL(6, 54, 9), // "penDownUp"
QT_MOC_LITERAL(7, 64, 5), // "setXT"
QT_MOC_LITERAL(8, 70, 5), // "setPC"
QT_MOC_LITERAL(9, 76, 5), // "setBG"
QT_MOC_LITERAL(10, 82, 9) // "stampoval"

    },
    "Console\0newLine\0\0newLineWriten\0drawLine\0"
    "turnDirection\0penDownUp\0setXT\0setPC\0"
    "setBG\0stampoval"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Console[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    2,   65,    2, 0x06 /* Public */,
       5,    2,   70,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,
       7,    2,   78,    2, 0x06 /* Public */,
       8,    1,   83,    2, 0x06 /* Public */,
       9,    1,   86,    2, 0x06 /* Public */,
      10,    2,   89,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QReal, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::QReal, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,    2,    2,
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,    2,    2,

       0        // eod
};

void Console::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Console *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->newLineWriten((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->drawLine((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->turnDirection((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->penDownUp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setXT((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 6: _t->setPC((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 7: _t->setBG((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->stampoval((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Console::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::newLine)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Console::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::newLineWriten)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Console::*)(qreal , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::drawLine)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Console::*)(qreal , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::turnDirection)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Console::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::penDownUp)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Console::*)(qreal , qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::setXT)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Console::*)(uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::setPC)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Console::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::setBG)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Console::*)(qreal , qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::stampoval)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Console::staticMetaObject = { {
    QMetaObject::SuperData::link<QTextEdit::staticMetaObject>(),
    qt_meta_stringdata_Console.data,
    qt_meta_data_Console,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Console::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Console::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Console.stringdata0))
        return static_cast<void*>(this);
    return QTextEdit::qt_metacast(_clname);
}

int Console::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Console::newLine(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Console::newLineWriten(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Console::drawLine(qreal _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Console::turnDirection(qreal _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Console::penDownUp(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Console::setXT(qreal _t1, qreal _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Console::setPC(uint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Console::setBG(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Console::stampoval(qreal _t1, qreal _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
