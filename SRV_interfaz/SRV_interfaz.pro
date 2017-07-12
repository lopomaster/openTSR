#-------------------------------------------------
#
# Project created by QtCreator 2011-11-25T16:27:24
#
#-------------------------------------------------

QT       += core gui

TARGET = Interfaz
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        posixSoc.cpp\
        surveyor.cpp\
        dialog.cpp \
        distancias.cpp \
        qjoystick.cpp \
        reconocedor.cpp

HEADERS  += mainwindow.h\
         cv.h \
         surveyor.h \
         posixSoc.h \
         dialog.h \
         distancias.h \
         qjoystick.h \
         reconocedor.h


FORMS    += mainwindow.ui \
         dialog.ui


#INCLUDEPATH += -I/usr/local/include/opencv
#LIBS += -L/usr/local/lib -lcxcore -lcv -lhighgui -lcvaux -lml

CONFIG+=link_pkgconfig PKGCONFIG+=opencv
LIBS += `pkg-config --libs opencv` -lSDL



RESOURCES += \
    Iconos/iconos.qrc

RC_FILE = myapp.rc

