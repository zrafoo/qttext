/****************************************************************************
** Meta object code from reading C++ file 'editarea.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "editarea.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EditArea[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,    9,    9,    9, 0x0a,
      62,    9,    9,    9, 0x08,
      93,    9,    9,    9, 0x08,
     118,  116,    9,    9, 0x08,
     150,    9,    9,    9, 0x08,
     170,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EditArea[] = {
    "EditArea\0\0context(QContextMenuEvent*)\0"
    "toggleLineVisible(bool)\0"
    "updateLineNumberAreaWidth(int)\0"
    "highlightCurrentLine()\0,\0"
    "updateLineNumberArea(QRect,int)\0"
    "toggleNumbers(bool)\0test()\0"
};

void EditArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EditArea *_t = static_cast<EditArea *>(_o);
        switch (_id) {
        case 0: _t->context((*reinterpret_cast< QContextMenuEvent*(*)>(_a[1]))); break;
        case 1: _t->toggleLineVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->updateLineNumberAreaWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->highlightCurrentLine(); break;
        case 4: _t->updateLineNumberArea((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->toggleNumbers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->test(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EditArea::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditArea::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_EditArea,
      qt_meta_data_EditArea, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditArea::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditArea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditArea))
        return static_cast<void*>(const_cast< EditArea*>(this));
    return QPlainTextEdit::qt_metacast(_clname);
}

int EditArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void EditArea::context(QContextMenuEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
