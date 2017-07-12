/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Sep 9 22:07:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      36,   11,   11,   11, 0x0a,
      57,   11,   11,   11, 0x0a,
      79,   11,   11,   11, 0x0a,
      86,   11,   11,   11, 0x0a,
      94,   11,   11,   11, 0x0a,
     102,   11,   11,   11, 0x0a,
     119,   11,   11,   11, 0x0a,
     139,   11,   11,   11, 0x0a,
     161,   11,   11,   11, 0x0a,
     180,   11,   11,   11, 0x0a,
     198,   11,   11,   11, 0x0a,
     236,  225,   11,   11, 0x0a,
     262,  260,  256,   11, 0x08,
     293,   11,   11,   11, 0x08,
     320,   11,   11,   11, 0x08,
     351,   11,   11,   11, 0x08,
     393,   11,   11,   11, 0x08,
     434,   11,   11,   11, 0x08,
     477,  471,   11,   11, 0x08,
     521,  511,   11,   11, 0x08,
     566,  555,   11,   11, 0x08,
     600,  592,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0inicio_reconocimiento()\0"
    "fin_reconocimiento()\0modificar_velocidad()\0"
    "foto()\0laser()\0speed()\0boton_stop_svr()\0"
    "boton_derecha_svr()\0boton_izquierda_svr()\0"
    "boton_arriba_svr()\0boton_abajo_svr()\0"
    "comenzar_piloto_autonomo()\0movimiento\0"
    "movimiento_SRV(int)\0int\0v\0"
    "accion_SVR(std::vector<char>&)\0"
    "on_actionSalir_triggered()\0"
    "on_actionControles_triggered()\0"
    "on_actionConectar_Desconectar_triggered()\0"
    "on_actionSobre_Traffic_SRV_1_triggered()\0"
    "on_actionGuia_de_usuario_triggered()\0"
    "valor\0mostrar_distancias_obstaculo(int)\0"
    "nombre_im\0mostrar_senial_detectada(QString)\0"
    "axis,value\0axisValueChanged(int,int)\0"
    "boton,b\0buttonValueChanged(int,bool)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->inicio_reconocimiento(); break;
        case 1: _t->fin_reconocimiento(); break;
        case 2: _t->modificar_velocidad(); break;
        case 3: _t->foto(); break;
        case 4: _t->laser(); break;
        case 5: _t->speed(); break;
        case 6: _t->boton_stop_svr(); break;
        case 7: _t->boton_derecha_svr(); break;
        case 8: _t->boton_izquierda_svr(); break;
        case 9: _t->boton_arriba_svr(); break;
        case 10: _t->boton_abajo_svr(); break;
        case 11: _t->comenzar_piloto_autonomo(); break;
        case 12: _t->movimiento_SRV((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: { int _r = _t->accion_SVR((*reinterpret_cast< std::vector<char>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 14: _t->on_actionSalir_triggered(); break;
        case 15: _t->on_actionControles_triggered(); break;
        case 16: _t->on_actionConectar_Desconectar_triggered(); break;
        case 17: _t->on_actionSobre_Traffic_SRV_1_triggered(); break;
        case 18: _t->on_actionGuia_de_usuario_triggered(); break;
        case 19: _t->mostrar_distancias_obstaculo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->mostrar_senial_detectada((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->axisValueChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 22: _t->buttonValueChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
