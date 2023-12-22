/****************************************************************************
** Meta object code from reading C++ file 'textedit.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "textedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Textedit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      25,    9,   20,    9, 0x08,
      36,    9,   20,    9, 0x08,
      49,    9,    9,    9, 0x08,
      60,    9,   20,    9, 0x08,
      72,    9,    9,    9, 0x08,
      83,    9,    9,    9, 0x08,
      94,    9,    9,    9, 0x08,
     115,    9,    9,    9, 0x08,
     130,  128,    9,    9, 0x08,
     155,    9,    9,    9, 0x08,
     174,    9,    9,    9, 0x08,
     197,    9,    9,    9, 0x08,
     214,    9,    9,    9, 0x08,
     232,    9,    9,    9, 0x08,
     252,  128,    9,    9, 0x08,
     274,    9,    9,    9, 0x08,
     287,    9,    9,    9, 0x08,
     303,    9,    9,    9, 0x08,
     317,    9,    9,    9, 0x08,
     331,    9,    9,    9, 0x08,
     344,    9,    9,    9, 0x08,
     357,    9,    9,    9, 0x08,
     385,    9,    9,    9, 0x08,
     398,  128,    9,    9, 0x08,
     418,    9,    9,    9, 0x08,
     431,    9,    9,    9, 0x08,
     454,  128,    9,    9, 0x08,
     482,    9,    9,    9, 0x08,
     496,    9,    9,    9, 0x08,
     508,    9,    9,    9, 0x08,
     519,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Textedit[] = {
    "Textedit\0\0fileNew()\0bool\0fileSave()\0"
    "fileSaveAs()\0fileOpen()\0maybeSave()\0"
    "tryClose()\0findText()\0findAndReplaceText()\0"
    "ChangeFonT()\0f\0toggleLineWrapMode(bool)\0"
    "changeBackground()\0changeLineBackground()\0"
    "cursorPosLabel()\0lastSavedUpdate()\0"
    "lastChangedUpdate()\0toggleStatusBar(bool)\0"
    "updateSize()\0updateStrings()\0updateChars()\0"
    "updateWords()\0selectWord()\0selectLine()\0"
    "context(QContextMenuEvent*)\0deleteText()\0"
    "toggleToolBar(bool)\0findAccept()\0"
    "findAndReplaceAccept()\0"
    "toggleSyntaxHighlight(bool)\0changeStyle()\0"
    "loadStyle()\0setStyle()\0about()\0"
};

void Textedit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Textedit *_t = static_cast<Textedit *>(_o);
        switch (_id) {
        case 0: _t->fileNew(); break;
        case 1: { bool _r = _t->fileSave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->fileSaveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->fileOpen(); break;
        case 4: { bool _r = _t->maybeSave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->tryClose(); break;
        case 6: _t->findText(); break;
        case 7: _t->findAndReplaceText(); break;
        case 8: _t->ChangeFonT(); break;
        case 9: _t->toggleLineWrapMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->changeBackground(); break;
        case 11: _t->changeLineBackground(); break;
        case 12: _t->cursorPosLabel(); break;
        case 13: _t->lastSavedUpdate(); break;
        case 14: _t->lastChangedUpdate(); break;
        case 15: _t->toggleStatusBar((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->updateSize(); break;
        case 17: _t->updateStrings(); break;
        case 18: _t->updateChars(); break;
        case 19: _t->updateWords(); break;
        case 20: _t->selectWord(); break;
        case 21: _t->selectLine(); break;
        case 22: _t->context((*reinterpret_cast< QContextMenuEvent*(*)>(_a[1]))); break;
        case 23: _t->deleteText(); break;
        case 24: _t->toggleToolBar((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->findAccept(); break;
        case 26: _t->findAndReplaceAccept(); break;
        case 27: _t->toggleSyntaxHighlight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->changeStyle(); break;
        case 29: _t->loadStyle(); break;
        case 30: _t->setStyle(); break;
        case 31: _t->about(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Textedit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Textedit::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Textedit,
      qt_meta_data_Textedit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Textedit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Textedit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Textedit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Textedit))
        return static_cast<void*>(const_cast< Textedit*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Textedit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
