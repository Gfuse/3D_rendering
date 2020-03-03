/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "randomButtonPressed"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 17), // "RGBsliderReleased"
QT_MOC_LITERAL(4, 50, 21), // "redSliderValueChanged"
QT_MOC_LITERAL(5, 72, 5), // "value"
QT_MOC_LITERAL(6, 78, 23), // "greenSliderValueChanged"
QT_MOC_LITERAL(7, 102, 22), // "blueSliderValueChanged"
QT_MOC_LITERAL(8, 125, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(9, 149, 19), // "comboboxItemChanged"
QT_MOC_LITERAL(10, 169, 12), // "play_pressed"
QT_MOC_LITERAL(11, 182, 12), // "stop_pressed"
QT_MOC_LITERAL(12, 195, 14), // "browse_pressed"
QT_MOC_LITERAL(13, 210, 12), // "dump_pressed"
QT_MOC_LITERAL(14, 223, 13), // "frame_pressed"
QT_MOC_LITERAL(15, 237, 16), // "dump2map_pressed"
QT_MOC_LITERAL(16, 254, 10), // "view_check"
QT_MOC_LITERAL(17, 265, 10), // "mode_radio"
QT_MOC_LITERAL(18, 276, 13), // "quality_radio"
QT_MOC_LITERAL(19, 290, 17), // "geobutton_pressed"
QT_MOC_LITERAL(20, 308, 27) // "on_progressbar_valueChanged"

    },
    "MainWindow\0randomButtonPressed\0\0"
    "RGBsliderReleased\0redSliderValueChanged\0"
    "value\0greenSliderValueChanged\0"
    "blueSliderValueChanged\0on_spinBox_valueChanged\0"
    "comboboxItemChanged\0play_pressed\0"
    "stop_pressed\0browse_pressed\0dump_pressed\0"
    "frame_pressed\0dump2map_pressed\0"
    "view_check\0mode_radio\0quality_radio\0"
    "geobutton_pressed\0on_progressbar_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    0,  105,    2, 0x0a /* Public */,
       4,    1,  106,    2, 0x0a /* Public */,
       6,    1,  109,    2, 0x0a /* Public */,
       7,    1,  112,    2, 0x0a /* Public */,
       8,    1,  115,    2, 0x08 /* Private */,
       9,    0,  118,    2, 0x08 /* Private */,
      10,    0,  119,    2, 0x08 /* Private */,
      11,    0,  120,    2, 0x08 /* Private */,
      12,    0,  121,    2, 0x08 /* Private */,
      13,    0,  122,    2, 0x08 /* Private */,
      14,    0,  123,    2, 0x08 /* Private */,
      15,    0,  124,    2, 0x08 /* Private */,
      16,    0,  125,    2, 0x08 /* Private */,
      17,    0,  126,    2, 0x08 /* Private */,
      18,    0,  127,    2, 0x08 /* Private */,
      19,    0,  128,    2, 0x08 /* Private */,
      20,    1,  129,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->randomButtonPressed(); break;
        case 1: _t->RGBsliderReleased(); break;
        case 2: _t->redSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->greenSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->blueSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_spinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->comboboxItemChanged(); break;
        case 7: _t->play_pressed(); break;
        case 8: _t->stop_pressed(); break;
        case 9: _t->browse_pressed(); break;
        case 10: _t->dump_pressed(); break;
        case 11: _t->frame_pressed(); break;
        case 12: _t->dump2map_pressed(); break;
        case 13: _t->view_check(); break;
        case 14: _t->mode_radio(); break;
        case 15: _t->quality_radio(); break;
        case 16: _t->geobutton_pressed(); break;
        case 17: _t->on_progressbar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
