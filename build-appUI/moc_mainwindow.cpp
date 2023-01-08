/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../MachiKoro-UI-App/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[22];
    char stringdata0[11];
    char stringdata1[19];
    char stringdata2[9];
    char stringdata3[1];
    char stringdata4[20];
    char stringdata5[19];
    char stringdata6[20];
    char stringdata7[11];
    char stringdata8[36];
    char stringdata9[5];
    char stringdata10[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 18),  // "createDeleteButton"
        QT_MOC_LITERAL(30, 8),  // "QWidget*"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 19),  // "on_deleteBtnClicked"
        QT_MOC_LITERAL(60, 18),  // "on_new_btn_clicked"
        QT_MOC_LITERAL(79, 19),  // "on_next_btn_clicked"
        QT_MOC_LITERAL(99, 10),  // "initWindow"
        QT_MOC_LITERAL(110, 35),  // "on_expansions_cb_currentTextC..."
        QT_MOC_LITERAL(146, 4),  // "arg1"
        QT_MOC_LITERAL(151, 21)   // "on_pushButton_clicked"
    },
    "MainWindow",
    "createDeleteButton",
    "QWidget*",
    "",
    "on_deleteBtnClicked",
    "on_new_btn_clicked",
    "on_next_btn_clicked",
    "initWindow",
    "on_expansions_cb_currentTextChanged",
    "arg1",
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    3, 0x08,    1 /* Private */,
       4,    0,   57,    3, 0x08,    2 /* Private */,
       5,    0,   58,    3, 0x08,    3 /* Private */,
       6,    0,   59,    3, 0x08,    4 /* Private */,
       7,    0,   60,    3, 0x08,    5 /* Private */,
       8,    1,   61,    3, 0x08,    6 /* Private */,
      10,    0,   64,    3, 0x08,    8 /* Private */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'createDeleteButton'
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        // method 'on_deleteBtnClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_new_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_next_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_expansions_cb_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QWidget* _r = _t->createDeleteButton();
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->on_deleteBtnClicked(); break;
        case 2: _t->on_new_btn_clicked(); break;
        case 3: _t->on_next_btn_clicked(); break;
        case 4: _t->initWindow(); break;
        case 5: _t->on_expansions_cb_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
