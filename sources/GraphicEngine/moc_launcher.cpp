/****************************************************************************
** Meta object code from reading C++ file 'launcher.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../includes/GraphicEngine/launcher.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'launcher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Launcher[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      28,    9,    9,    9, 0x08,
      48,    9,    9,    9, 0x08,
      68,    9,    9,    9, 0x08,
      91,    9,    9,    9, 0x08,
     109,    9,    9,    9, 0x08,
     127,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Launcher[] = {
    "Launcher\0\0on_Load_clicked()\0"
    "on_Option_clicked()\0on_Back_2_clicked()\0"
    "on_StartGame_clicked()\0on_Back_clicked()\0"
    "on_Exit_clicked()\0on_Play_clicked()\0"
};

void Launcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Launcher *_t = static_cast<Launcher *>(_o);
        switch (_id) {
        case 0: _t->on_Load_clicked(); break;
        case 1: _t->on_Option_clicked(); break;
        case 2: _t->on_Back_2_clicked(); break;
        case 3: _t->on_StartGame_clicked(); break;
        case 4: _t->on_Back_clicked(); break;
        case 5: _t->on_Exit_clicked(); break;
        case 6: _t->on_Play_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Launcher::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Launcher::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Launcher,
      qt_meta_data_Launcher, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Launcher::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Launcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Launcher::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Launcher))
        return static_cast<void*>(const_cast< Launcher*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Launcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
