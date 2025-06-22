/****************************************************************************
** Meta object code from reading C++ file 'wControl.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../wControl.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN8WControlE_t {};
} // unnamed namespace

template <> constexpr inline auto WControl::qt_create_metaobjectdata<qt_meta_tag_ZN8WControlE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "WControl",
        "dataPos",
        "",
        "QList<double>",
        "xpos",
        "ypos",
        "uint32_t",
        "count",
        "listFiles",
        "onDirectoryChanged",
        "path",
        "openFileButton",
        "openFolderButton",
        "openFile",
        "fileName"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'dataPos'
        QtMocHelpers::SignalData<void(const QList<double> &, const QList<double> &, uint32_t)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 3, 5 }, { 0x80000000 | 6, 7 },
        }}),
        // Signal 'listFiles'
        QtMocHelpers::SignalData<void(const QList<QString> &, uint32_t)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 4 }, { 0x80000000 | 6, 7 },
        }}),
        // Slot 'onDirectoryChanged'
        QtMocHelpers::SlotData<void(const QString &)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 10 },
        }}),
        // Method 'openFileButton'
        QtMocHelpers::MethodData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'openFolderButton'
        QtMocHelpers::MethodData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'openFile'
        QtMocHelpers::MethodData<void(QString)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<WControl, qt_meta_tag_ZN8WControlE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject WControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8WControlE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8WControlE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8WControlE_t>.metaTypes,
    nullptr
} };

void WControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WControl *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dataPos((*reinterpret_cast< std::add_pointer_t<QList<double>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<double>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[3]))); break;
        case 1: _t->listFiles((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[2]))); break;
        case 2: _t->onDirectoryChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->openFileButton(); break;
        case 4: _t->openFolderButton(); break;
        case 5: _t->openFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<double> >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (WControl::*)(const QList<double> & , const QList<double> & , uint32_t )>(_a, &WControl::dataPos, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (WControl::*)(const QList<QString> & , uint32_t )>(_a, &WControl::listFiles, 1))
            return;
    }
}

const QMetaObject *WControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8WControlE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void WControl::dataPos(const QList<double> & _t1, const QList<double> & _t2, uint32_t _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3);
}

// SIGNAL 1
void WControl::listFiles(const QList<QString> & _t1, uint32_t _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}
QT_WARNING_POP
