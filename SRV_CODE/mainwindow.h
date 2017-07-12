#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


//Movimientos SVR
#define ARRIBA 16777235
#define ABAJO 16777237
#define DERECHA 16777236
#define IZQUIERDA 16777234
#define FRENAR 32


namespace Ui {
    class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    void inicio_reconocimiento();
    void fin_reconocimiento();
    void modificar_velocidad();
    void foto();
    void laser();
    void speed();
    void boton_stop_svr();
    void boton_derecha_svr();
    void boton_izquierda_svr();
    void boton_arriba_svr();
    void boton_abajo_svr();
    void comenzar_piloto_autonomo();
    void movimiento_SRV(int movimiento);


protected:
    void closeEvent(QCloseEvent *event);
    bool eventFilter(QEvent *e);
    void keyReleaseEvent(QKeyEvent *event);
    void No_conectado_mensaje();
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    bool control;
    bool laser_on;
    bool low_speed;
    bool conectado;
    bool video_on;
    int teclas_pulsadas[2];
    int ncams;
    int velocidad;
    int ultima_senial;

private slots:
    int accion_SVR(std::vector<char> &v);
    void on_actionSalir_triggered();
    void on_actionControles_triggered();
    void on_actionConectar_Desconectar_triggered();
    void on_actionSobre_Traffic_SRV_1_triggered();
    void on_actionGuia_de_usuario_triggered();
    void mostrar_distancias_obstaculo(int valor);
    void mostrar_senial_detectada(QString nombre_im);
    //JOYSTICK
    void axisValueChanged(int axis, int value);
    void buttonValueChanged(int boton, bool b);

};

#endif // MAINWINDOW_H
