/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Sep 17 12:51:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConectar_Desconectar;
    QAction *actionSobre_Traffic_SRV_1;
    QAction *actionControles;
    QAction *actionSalir;
    QAction *actionGuia_de_usuario;
    QAction *actionDerecha;
    QAction *actionIzquierda;
    QAction *actionArriba;
    QAction *actionAbajo;
    QAction *actionActivar_desactivar_lasers;
    QAction *actionParar;
    QAction *action_Modificar_velocidad;
    QAction *actionControles_2;
    QAction *actionIniciar_detener_v_deo;
    QWidget *centralWidget;
    QGraphicsView *graphicsView_2;
    QFrame *line;
    QPushButton *boton_foto;
    QCheckBox *checkBox_2;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *boton_left;
    QPushButton *boton_right;
    QPushButton *boton_down;
    QPushButton *boton_stop;
    QPushButton *boton_up;
    QPushButton *boton_laser;
    QGroupBox *groupBox_2;
    QPushButton *boton_velocidad;
    QSpinBox *spinBox_velocidad;
    QSlider *verticalSlider;
    QGroupBox *groupBox_3;
    QLCDNumber *lcdNumber;
    QCheckBox *checkBox_distancias;
    QGroupBox *groupBox_4;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox_5;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuAyuda;
    QMenu *menuConfiguraci_n;
    QMenu *menuArchivo;
    QMenu *menuAccion;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1006, 704);
        actionConectar_Desconectar = new QAction(MainWindow);
        actionConectar_Desconectar->setObjectName(QString::fromUtf8("actionConectar_Desconectar"));
        actionConectar_Desconectar->setCheckable(true);
        actionConectar_Desconectar->setEnabled(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/1322222705_disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/new/prefix1/1322222492_connect.png"), QSize(), QIcon::Normal, QIcon::On);
        actionConectar_Desconectar->setIcon(icon);
        actionConectar_Desconectar->setIconVisibleInMenu(true);
        actionSobre_Traffic_SRV_1 = new QAction(MainWindow);
        actionSobre_Traffic_SRV_1->setObjectName(QString::fromUtf8("actionSobre_Traffic_SRV_1"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/1323444825_About.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSobre_Traffic_SRV_1->setIcon(icon1);
        actionSobre_Traffic_SRV_1->setIconVisibleInMenu(true);
        actionControles = new QAction(MainWindow);
        actionControles->setObjectName(QString::fromUtf8("actionControles"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/1323446197_preferences-system.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionControles->setIcon(icon2);
        actionControles->setIconVisibleInMenu(true);
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/1323451436_button_cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSalir->setIcon(icon3);
        actionSalir->setIconVisibleInMenu(true);
        actionGuia_de_usuario = new QAction(MainWindow);
        actionGuia_de_usuario->setObjectName(QString::fromUtf8("actionGuia_de_usuario"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/1322571319_help_64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGuia_de_usuario->setIcon(icon4);
        actionGuia_de_usuario->setIconVisibleInMenu(true);
        actionDerecha = new QAction(MainWindow);
        actionDerecha->setObjectName(QString::fromUtf8("actionDerecha"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/1322221692_derecha.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDerecha->setIcon(icon5);
        actionDerecha->setVisible(true);
        actionDerecha->setIconVisibleInMenu(true);
        actionIzquierda = new QAction(MainWindow);
        actionIzquierda->setObjectName(QString::fromUtf8("actionIzquierda"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/1322221692_izquierda.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIzquierda->setIcon(icon6);
        actionIzquierda->setIconVisibleInMenu(true);
        actionArriba = new QAction(MainWindow);
        actionArriba->setObjectName(QString::fromUtf8("actionArriba"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/1322221692_.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionArriba->setIcon(icon7);
        actionArriba->setIconVisibleInMenu(true);
        actionAbajo = new QAction(MainWindow);
        actionAbajo->setObjectName(QString::fromUtf8("actionAbajo"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/1322221692_abajo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbajo->setIcon(icon8);
        actionAbajo->setIconVisibleInMenu(true);
        actionActivar_desactivar_lasers = new QAction(MainWindow);
        actionActivar_desactivar_lasers->setObjectName(QString::fromUtf8("actionActivar_desactivar_lasers"));
        actionActivar_desactivar_lasers->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/1322506788_Gnome-Dialog-Information-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon9.addFile(QString::fromUtf8(":/new/prefix1/1322506788_Gnome-Dialog-Information-60.png"), QSize(), QIcon::Normal, QIcon::On);
        actionActivar_desactivar_lasers->setIcon(icon9);
        actionActivar_desactivar_lasers->setIconVisibleInMenu(true);
        actionParar = new QAction(MainWindow);
        actionParar->setObjectName(QString::fromUtf8("actionParar"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/1322483551_Signal_stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionParar->setIcon(icon10);
        actionParar->setIconVisibleInMenu(true);
        action_Modificar_velocidad = new QAction(MainWindow);
        action_Modificar_velocidad->setObjectName(QString::fromUtf8("action_Modificar_velocidad"));
        action_Modificar_velocidad->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/1322569016_speed_low.png"), QSize(), QIcon::Normal, QIcon::On);
        action_Modificar_velocidad->setIcon(icon11);
        action_Modificar_velocidad->setIconVisibleInMenu(true);
        actionControles_2 = new QAction(MainWindow);
        actionControles_2->setObjectName(QString::fromUtf8("actionControles_2"));
        actionControles_2->setIcon(icon2);
        actionControles_2->setIconVisibleInMenu(true);
        actionIniciar_detener_v_deo = new QAction(MainWindow);
        actionIniciar_detener_v_deo->setObjectName(QString::fromUtf8("actionIniciar_detener_v_deo"));
        actionIniciar_detener_v_deo->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/1346018221_player_play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon12.addFile(QString::fromUtf8(":/new/prefix1/1346018303_player_stop.png"), QSize(), QIcon::Normal, QIcon::On);
        actionIniciar_detener_v_deo->setIcon(icon12);
        actionIniciar_detener_v_deo->setIconVisibleInMenu(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(20, 20, 661, 421));
        graphicsView_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        graphicsView_2->setStyleSheet(QString::fromUtf8("     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;"));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(780, -40, 20, 651));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        boton_foto = new QPushButton(centralWidget);
        boton_foto->setObjectName(QString::fromUtf8("boton_foto"));
        boton_foto->setEnabled(false);
        boton_foto->setGeometry(QRect(720, 30, 52, 40));
        boton_foto->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }   \n"
"\n"
"\n"
"\n"
" QPushButton:open { /* when the button has its menu open */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton::menu-indicator {\n"
"     image: url(menu_indicator.png);\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: bottom ri"
                        "ght;\n"
" }\n"
"\n"
" QPushButton::menu-indicator:pressed, QPushButton::menu-indicator:open {\n"
"     position: relative;\n"
"     top: 2px; left: 2px; /* shift the arrow by 2 px */\n"
" }\n"
""));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/1322484513_camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        boton_foto->setIcon(icon13);
        boton_foto->setIconSize(QSize(30, 30));
        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(850, 190, 151, 22));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(90, 450, 261, 161));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 128, 116));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        boton_left = new QPushButton(layoutWidget);
        boton_left->setObjectName(QString::fromUtf8("boton_left"));
        boton_left->setEnabled(false);
        boton_left->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }   \n"
"\n"
"\n"
"\n"
" QPushButton:open { /* when the button has its menu open */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton::menu-indicator {\n"
"     image: url(menu_indicator.png);\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: bottom ri"
                        "ght;\n"
" }\n"
"\n"
" QPushButton::menu-indicator:pressed, QPushButton::menu-indicator:open {\n"
"     position: relative;\n"
"     top: 2px; left: 2px; /* shift the arrow by 2 px */\n"
" }\n"
""));
        boton_left->setIcon(icon6);
        boton_left->setIconSize(QSize(30, 30));
        boton_left->setCheckable(false);
        boton_left->setAutoRepeat(false);
        boton_left->setAutoExclusive(false);

        gridLayout->addWidget(boton_left, 2, 0, 1, 1);

        boton_right = new QPushButton(layoutWidget);
        boton_right->setObjectName(QString::fromUtf8("boton_right"));
        boton_right->setEnabled(false);
        boton_right->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }   \n"
"\n"
"\n"
"\n"
" QPushButton:open { /* when the button has its menu open */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton::menu-indicator {\n"
"     image: url(menu_indicator.png);\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: bottom ri"
                        "ght;\n"
" }\n"
"\n"
" QPushButton::menu-indicator:pressed, QPushButton::menu-indicator:open {\n"
"     position: relative;\n"
"     top: 2px; left: 2px; /* shift the arrow by 2 px */\n"
" }\n"
""));
        boton_right->setIcon(icon5);
        boton_right->setIconSize(QSize(30, 30));
        boton_right->setCheckable(false);
        boton_right->setAutoRepeat(false);
        boton_right->setAutoExclusive(false);

        gridLayout->addWidget(boton_right, 2, 2, 1, 1);

        boton_down = new QPushButton(layoutWidget);
        boton_down->setObjectName(QString::fromUtf8("boton_down"));
        boton_down->setEnabled(false);
        boton_down->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }   \n"
"\n"
"\n"
"\n"
" QPushButton:open { /* when the button has its menu open */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton::menu-indicator {\n"
"     image: url(menu_indicator.png);\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: bottom ri"
                        "ght;\n"
" }\n"
"\n"
" QPushButton::menu-indicator:pressed, QPushButton::menu-indicator:open {\n"
"     position: relative;\n"
"     top: 2px; left: 2px; /* shift the arrow by 2 px */\n"
" }\n"
""));
        boton_down->setIcon(icon8);
        boton_down->setIconSize(QSize(30, 30));
        boton_down->setCheckable(false);
        boton_down->setAutoRepeat(false);
        boton_down->setAutoExclusive(false);

        gridLayout->addWidget(boton_down, 3, 1, 1, 1);

        boton_stop = new QPushButton(layoutWidget);
        boton_stop->setObjectName(QString::fromUtf8("boton_stop"));
        boton_stop->setEnabled(false);
        boton_stop->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }   \n"
"\n"
"\n"
"\n"
" QPushButton:open { /* when the button has its menu open */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton::menu-indicator {\n"
"     image: url(menu_indicator.png);\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: bottom ri"
                        "ght;\n"
" }\n"
"\n"
" QPushButton::menu-indicator:pressed, QPushButton::menu-indicator:open {\n"
"     position: relative;\n"
"     top: 2px; left: 2px; /* shift the arrow by 2 px */\n"
" }\n"
""));
        boton_stop->setIcon(icon10);
        boton_stop->setIconSize(QSize(30, 30));
        boton_stop->setCheckable(false);
        boton_stop->setAutoRepeat(false);
        boton_stop->setAutoExclusive(false);

        gridLayout->addWidget(boton_stop, 2, 1, 1, 1);

        boton_up = new QPushButton(layoutWidget);
        boton_up->setObjectName(QString::fromUtf8("boton_up"));
        boton_up->setEnabled(false);
        boton_up->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }   \n"
"\n"
"\n"
"\n"
" QPushButton:open { /* when the button has its menu open */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton::menu-indicator {\n"
"     image: url(menu_indicator.png);\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: bottom ri"
                        "ght;\n"
" }\n"
"\n"
" QPushButton::menu-indicator:pressed, QPushButton::menu-indicator:open {\n"
"     position: relative;\n"
"     top: 2px; left: 2px; /* shift the arrow by 2 px */\n"
" }\n"
""));
        boton_up->setIcon(icon7);
        boton_up->setIconSize(QSize(30, 30));
        boton_up->setCheckable(false);
        boton_up->setAutoRepeat(false);
        boton_up->setAutoExclusive(false);

        gridLayout->addWidget(boton_up, 1, 1, 1, 1);

        boton_laser = new QPushButton(groupBox);
        boton_laser->setObjectName(QString::fromUtf8("boton_laser"));
        boton_laser->setEnabled(false);
        boton_laser->setGeometry(QRect(210, 30, 38, 34));
        boton_laser->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }   \n"
"\n"
"\n"
"\n"
" QPushButton:open { /* when the button has its menu open */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton::menu-indicator {\n"
"     image: url(menu_indicator.png);\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: bottom rig"
                        "ht;\n"
" }\n"
"\n"
""));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/1322506788_Gnome-Dialog-Information-60.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon14.addFile(QString::fromUtf8(":/new/prefix1/1322506788_Gnome-Dialog-Information-64.png"), QSize(), QIcon::Normal, QIcon::On);
        boton_laser->setIcon(icon14);
        boton_laser->setIconSize(QSize(30, 30));
        boton_laser->setCheckable(true);
        boton_laser->setChecked(true);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(450, 450, 181, 161));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        boton_velocidad = new QPushButton(groupBox_2);
        boton_velocidad->setObjectName(QString::fromUtf8("boton_velocidad"));
        boton_velocidad->setEnabled(false);
        boton_velocidad->setGeometry(QRect(40, 30, 38, 34));
        boton_velocidad->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }   \n"
"\n"
"\n"
"\n"
" QPushButton:open { /* when the button has its menu open */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton::menu-indicator {\n"
"     image: url(menu_indicator.png);\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: bottom rig"
                        "ht;\n"
" }\n"
"\n"
""));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix1/1322569016_speed_low.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon15.addFile(QString::fromUtf8(":/new/prefix1/1322569016_speed.png"), QSize(), QIcon::Normal, QIcon::On);
        boton_velocidad->setIcon(icon15);
        boton_velocidad->setIconSize(QSize(30, 30));
        boton_velocidad->setCheckable(true);
        spinBox_velocidad = new QSpinBox(groupBox_2);
        spinBox_velocidad->setObjectName(QString::fromUtf8("spinBox_velocidad"));
        spinBox_velocidad->setEnabled(false);
        spinBox_velocidad->setGeometry(QRect(40, 100, 51, 27));
        spinBox_velocidad->setStyleSheet(QString::fromUtf8("     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
""));
        verticalSlider = new QSlider(groupBox_2);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setEnabled(false);
        verticalSlider->setGeometry(QRect(130, 30, 41, 101));
        verticalSlider->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QSlider::groove:horizontal\n"
"{\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"width: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:vertical\n"
"{\n"
"background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #fff, stop: 0.4999 #eee, stop: 0.5 #ddd, stop: 1 #eee );\n"
"border: 1px solid #777;\n"
"width: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:vertical {\n"
"background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #78d, stop: 0.4999 #46a, stop: 0.5 #45a, stop: 1 #238 );\n"
"\n"
"border: 1px solid #777;\n"
"width: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"height: 13px;\n"
"margin-top: -2px;\n"
"margin-bottom: -2px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:vertical:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
""
                        "border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:vertical:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:vertical:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:vertical:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        verticalSlider->setOrientation(Qt::Vertical);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(810, 240, 161, 121));
        groupBox_3->setStyleSheet(QString::fromUtf8(""));
        groupBox_3->setFlat(true);
        lcdNumber = new QLCDNumber(groupBox_3);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(40, 40, 64, 23));
        lcdNumber->setStyleSheet(QString::fromUtf8("     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"\n"
"QLCDNumber::section{background-color::green}"));
        checkBox_distancias = new QCheckBox(groupBox_3);
        checkBox_distancias->setObjectName(QString::fromUtf8("checkBox_distancias"));
        checkBox_distancias->setGeometry(QRect(40, 90, 111, 22));
        checkBox_distancias->setStyleSheet(QString::fromUtf8(""));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(810, 20, 171, 161));
        graphicsView = new QGraphicsView(groupBox_4);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(40, 40, 111, 111));
        graphicsView->setMinimumSize(QSize(100, 100));
        graphicsView->setMaximumSize(QSize(120, 120));
        graphicsView->setStyleSheet(QString::fromUtf8("     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;"));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(810, 400, 211, 81));
        pushButton = new QPushButton(groupBox_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 40, 98, 27));
        pushButton->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }   \n"
"\n"
"\n"
"\n"
" QPushButton:open { /* when the button has its menu open */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton::menu-indicator {\n"
"     image: url(menu_indicator.png);\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: bottom ri"
                        "ght;\n"
" }\n"
"\n"
" QPushButton::menu-indicator:pressed, QPushButton::menu-indicator:open {\n"
"     position: relative;\n"
"     top: 2px; left: 2px; /* shift the arrow by 2 px */\n"
" }\n"
""));
        pushButton->setIcon(icon12);
        pushButton->setCheckable(true);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(900, 490, 51, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(820, 490, 81, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1006, 25));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QString::fromUtf8("menuAyuda"));
        menuConfiguraci_n = new QMenu(menuBar);
        menuConfiguraci_n->setObjectName(QString::fromUtf8("menuConfiguraci_n"));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuAccion = new QMenu(menuArchivo);
        menuAccion->setObjectName(QString::fromUtf8("menuAccion"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8("../../1346019662_gear_64.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuAccion->setIcon(icon16);
        menuAccion->setSeparatorsCollapsible(true);
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuConfiguraci_n->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuAyuda->addSeparator();
        menuAyuda->addAction(actionSobre_Traffic_SRV_1);
        menuAyuda->addAction(actionGuia_de_usuario);
        menuConfiguraci_n->addAction(actionControles_2);
        menuArchivo->addAction(actionConectar_Desconectar);
        menuArchivo->addAction(menuAccion->menuAction());
        menuArchivo->addAction(actionIniciar_detener_v_deo);
        menuArchivo->addAction(actionSalir);
        menuAccion->addAction(actionDerecha);
        menuAccion->addAction(actionIzquierda);
        menuAccion->addAction(actionArriba);
        menuAccion->addAction(actionAbajo);
        menuAccion->addAction(actionParar);
        menuAccion->addAction(actionActivar_desactivar_lasers);
        menuAccion->addAction(action_Modificar_velocidad);
        mainToolBar->addAction(actionConectar_Desconectar);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionControles);
        mainToolBar->addAction(actionGuia_de_usuario);
        mainToolBar->addAction(actionSobre_Traffic_SRV_1);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(inicio_reconocimiento()));
        QObject::connect(boton_foto, SIGNAL(clicked()), MainWindow, SLOT(foto()));
        QObject::connect(boton_right, SIGNAL(clicked()), MainWindow, SLOT(boton_derecha_svr()));
        QObject::connect(boton_laser, SIGNAL(clicked()), MainWindow, SLOT(laser()));
        QObject::connect(boton_stop, SIGNAL(clicked()), MainWindow, SLOT(boton_stop_svr()));
        QObject::connect(boton_velocidad, SIGNAL(clicked()), MainWindow, SLOT(speed()));
        QObject::connect(boton_down, SIGNAL(clicked()), MainWindow, SLOT(boton_abajo_svr()));
        QObject::connect(boton_left, SIGNAL(clicked()), MainWindow, SLOT(boton_izquierda_svr()));
        QObject::connect(boton_up, SIGNAL(pressed()), MainWindow, SLOT(boton_arriba_svr()));
        QObject::connect(spinBox_velocidad, SIGNAL(valueChanged(int)), verticalSlider, SLOT(setValue(int)));
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), spinBox_velocidad, SLOT(setValue(int)));
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(modificar_velocidad()));
        QObject::connect(spinBox_velocidad, SIGNAL(valueChanged(int)), MainWindow, SLOT(modificar_velocidad()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(fin_reconocimiento()));
        QObject::connect(checkBox_2, SIGNAL(stateChanged(int)), MainWindow, SLOT(comenzar_piloto_autonomo()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionConectar_Desconectar->setText(QApplication::translate("MainWindow", " Conectar - desconectar", 0, QApplication::UnicodeUTF8));
        actionConectar_Desconectar->setIconText(QApplication::translate("MainWindow", "Conectar - Desconectar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionConectar_Desconectar->setToolTip(QApplication::translate("MainWindow", "Conectar - Desconectar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSobre_Traffic_SRV_1->setText(QApplication::translate("MainWindow", "Acerca de Traffic Console SRV-1", 0, QApplication::UnicodeUTF8));
        actionControles->setText(QApplication::translate("MainWindow", "Controles", 0, QApplication::UnicodeUTF8));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0, QApplication::UnicodeUTF8));
        actionGuia_de_usuario->setText(QApplication::translate("MainWindow", "Guia de usuario", 0, QApplication::UnicodeUTF8));
        actionDerecha->setText(QApplication::translate("MainWindow", "Derecha", 0, QApplication::UnicodeUTF8));
        actionDerecha->setShortcut(QString());
        actionIzquierda->setText(QApplication::translate("MainWindow", "Izquierda", 0, QApplication::UnicodeUTF8));
        actionArriba->setText(QApplication::translate("MainWindow", "Arriba", 0, QApplication::UnicodeUTF8));
        actionAbajo->setText(QApplication::translate("MainWindow", "Abajo", 0, QApplication::UnicodeUTF8));
        actionActivar_desactivar_lasers->setText(QApplication::translate("MainWindow", "Activar - desactivar lasers", 0, QApplication::UnicodeUTF8));
        actionParar->setText(QApplication::translate("MainWindow", "Detener", 0, QApplication::UnicodeUTF8));
        action_Modificar_velocidad->setText(QApplication::translate("MainWindow", " Modificar velocidad", 0, QApplication::UnicodeUTF8));
        actionControles_2->setText(QApplication::translate("MainWindow", "Controles", 0, QApplication::UnicodeUTF8));
        actionIniciar_detener_v_deo->setText(QApplication::translate("MainWindow", "Iniciar - detener v\303\255deo", 0, QApplication::UnicodeUTF8));
        boton_foto->setText(QString());
        checkBox_2->setText(QApplication::translate("MainWindow", "Piloto autom\303\241tico", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Control", 0, QApplication::UnicodeUTF8));
        boton_left->setText(QString());
        boton_right->setText(QString());
        boton_down->setText(QString());
        boton_stop->setText(QString());
        boton_up->setText(QString());
        boton_laser->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Velocidad", 0, QApplication::UnicodeUTF8));
        boton_velocidad->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Distancia", 0, QApplication::UnicodeUTF8));
        checkBox_distancias->setText(QApplication::translate("MainWindow", "Activado", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Procesamiento de v\303\255deo", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Visualizaci\303\263n de v\303\255deo", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Iniciar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "/dev/video", 0, QApplication::UnicodeUTF8));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", 0, QApplication::UnicodeUTF8));
        menuConfiguraci_n->setTitle(QApplication::translate("MainWindow", "Ver", 0, QApplication::UnicodeUTF8));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0, QApplication::UnicodeUTF8));
        menuAccion->setTitle(QApplication::translate("MainWindow", "Acci\303\263n", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
