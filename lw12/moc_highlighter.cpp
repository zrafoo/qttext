/****************************************************************************
** Meta object code from reading C++ file 'highlighter.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "highlighter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'highlighter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Highlighter[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      19,   12,   12,   12, 0x0a,
      29,   12,   12,   12, 0x0a,
      39,   12,   12,   12, 0x0a,
      47,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Highlighter[] = {
    "Highlighter\0\0c89()\0cpp9803()\0cpp1114()\0"
    "cpp17()\0cpp20()\0"
};

void Highlighter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Highlighter *_t = static_cast<Highlighter *>(_o);
        switch (_id) {
        case 0: _t->c89(); break;
        case 1: _t->cpp9803(); break;
        case 2: _t->cpp1114(); break;
        case 3: _t->cpp17(); break;
        case 4: _t->cpp20(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Highlighter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Highlighter::staticMetaObject = {
    { &QSyntaxHighlighter::staticMetaObject, qt_meta_stringdata_Highlighter,
      qt_meta_data_Highlighter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Highlighter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Highlighter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Highlighter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Highlighter))
        return static_cast<void*>(const_cast< Highlighter*>(this));
    return QSyntaxHighlighter::qt_metacast(_clname);
}

int Highlighter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSyntaxHighlighter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
