/****************************************************************************
** Meta object code from reading C++ file 'findandreplacemodal.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "findandreplacemodal.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'findandreplacemodal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FindAndReplaceModal[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_FindAndReplaceModal[] = {
    "FindAndReplaceModal\0\0ok()\0"
};

void FindAndReplaceModal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FindAndReplaceModal *_t = static_cast<FindAndReplaceModal *>(_o);
        switch (_id) {
        case 0: _t->ok(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData FindAndReplaceModal::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FindAndReplaceModal::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FindAndReplaceModal,
      qt_meta_data_FindAndReplaceModal, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FindAndReplaceModal::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FindAndReplaceModal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FindAndReplaceModal::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FindAndReplaceModal))
        return static_cast<void*>(const_cast< FindAndReplaceModal*>(this));
    return QDialog::qt_metacast(_clname);
}

int FindAndReplaceModal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void FindAndReplaceModal::ok()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
