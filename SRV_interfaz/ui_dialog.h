/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Tue Sep 11 01:07:46 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton_2;
    QGraphicsView *graphicsView;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(953, 623);
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(820, 580, 98, 27));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/1346016924_tick.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        graphicsView = new QGraphicsView(Dialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(220, 71, 531, 281));
        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(170, 460, 51, 27));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(770, 230, 81, 17));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(770, 130, 67, 17));
        label_2->setFont(font);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 420, 271, 17));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 510, 111, 17));
        label_4->setFont(font1);
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(770, 110, 171, 20));
        label_5->setFont(font);
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(770, 170, 161, 17));
        label_6->setFont(font);
        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(770, 250, 161, 17));
        label_7->setFont(font);
        label_8 = new QLabel(Dialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(770, 270, 161, 17));
        label_8->setFont(font);
        label_9 = new QLabel(Dialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 10, 131, 17));
        label_9->setFont(font1);
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 550, 41, 27));
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 550, 41, 27));
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(Dialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(190, 550, 41, 27));
        lineEdit_3->setReadOnly(true);
        lineEdit_4 = new QLineEdit(Dialog);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(250, 550, 41, 27));
        lineEdit_4->setReadOnly(true);
        lineEdit_5 = new QLineEdit(Dialog);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(310, 550, 51, 27));
        lineEdit_5->setReadOnly(true);
        label_10 = new QLabel(Dialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(120, 560, 16, 17));
        label_10->setFont(font1);
        label_11 = new QLabel(Dialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(180, 560, 16, 17));
        label_11->setFont(font1);
        label_12 = new QLabel(Dialog);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(240, 560, 16, 17));
        label_12->setFont(font1);
        label_13 = new QLabel(Dialog);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(300, 560, 16, 17));
        label_13->setFont(font1);
        label_14 = new QLabel(Dialog);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(80, 460, 81, 17));
        label_15 = new QLabel(Dialog);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(500, 360, 241, 17));
        label_15->setFont(font);
        label_16 = new QLabel(Dialog);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(120, 270, 81, 17));
        label_16->setFont(font);
        label_17 = new QLabel(Dialog);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(40, 110, 171, 20));
        label_17->setFont(font);
        label_18 = new QLabel(Dialog);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(40, 190, 171, 20));
        label_18->setFont(font);
        label_19 = new QLabel(Dialog);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(60, 220, 151, 20));
        label_19->setFont(font);
        label_20 = new QLabel(Dialog);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(230, 360, 81, 17));
        label_20->setFont(font);
        label_21 = new QLabel(Dialog);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(390, 360, 81, 17));
        label_21->setFont(font);
        label_22 = new QLabel(Dialog);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(350, 50, 81, 17));
        label_22->setFont(font);
        label_23 = new QLabel(Dialog);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(470, 50, 81, 17));
        label_23->setFont(font);

        retranslateUi(Dialog);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Dialog, SLOT(cerrar_configuracion()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Dialog", "Aceptar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Retroceder", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Avanzar", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "Dispositivo de captura de imagen", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "Direcci\303\263n ip ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Dialog", "Incrementar velocidad", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Dialog", "Girar a la derecha", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Dialog", "Girar a la izquierda", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Dialog", "Disminuir velocidad", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Dialog", "Controles", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("Dialog", "75", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("Dialog", "15", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QApplication::translate("Dialog", "156", 0, QApplication::UnicodeUTF8));
        lineEdit_4->setText(QApplication::translate("Dialog", "238", 0, QApplication::UnicodeUTF8));
        lineEdit_5->setText(QApplication::translate("Dialog", "10001", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Dialog", ".", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Dialog", ".", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Dialog", ".", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Dialog", ":", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Dialog", "/dev/video", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Dialog", "Activar / Desactivar l\303\241seres", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Dialog", "Tomar foto", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Dialog", "Cruceta de direcciones", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("Dialog", "Incrementar velocidad", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("Dialog", "Disminuir velocidad", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("Dialog", "Sin funci\303\263n", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("Dialog", "Sin funci\303\263n", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("Dialog", "Sin funci\303\263n", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("Dialog", "Sin funci\303\263n", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
