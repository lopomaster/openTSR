#include "dialog.h"
#include "ui_dialog.h"
#include "QtGui"
#include "mainwindow.h"

int listado_dispositivos_cam();

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setWindowTitle("Detalles");

    //Listado de cámaras disponibles
    int ncams = listado_dispositivos_cam();
    char buffer [33];
    for (int i=1 ; i<= ncams; i++){
        sprintf(buffer,"%d",i);
        ui->comboBox->addItem(buffer);
    }

    camselect = ui->comboBox->currentIndex();

    QImage image("pad.jpg");
    QGraphicsScene *scene = new QGraphicsScene (this);
    QPixmap pixmap = QPixmap::fromImage(image);
    scene->addPixmap(pixmap);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::keyPressEvent(QKeyEvent *event){

//    //http://stackoverflow.com/questions/6647970/how-can-i-capture-qkeysequence-from-qkeyevent-depending-on-current-keyboard-layo

//    if (event->type() == QEvent::KeyPress){
//    QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

//    int keyInt = keyEvent->key();
//    Qt::Key key = static_cast<Qt::Key>(keyInt);
//    if(key == Qt::Key_unknown){
//        qDebug() << "Unknown key from a macro probably";
//    }
//    // the user have clicked just and only the special keys Ctrl, Shift, Alt, Meta.
//    if(key == Qt::Key_Control ||
//        key == Qt::Key_Shift ||
//        key == Qt::Key_Alt ||
//        key == Qt::Key_Meta)
//    {
//        qDebug() << "Single click of special key: Ctrl, Shift, Alt or Meta";
//        qDebug() << "New KeySequence:" << QKeySequence(keyInt).toString(QKeySequence::NativeText);
//    }

//    // check for a combination of user clicks
//    Qt::KeyboardModifiers modifiers = keyEvent->modifiers();
//    QString keyText = keyEvent->text();
//    // if the keyText is empty than it's a special key like F1, F5, ...
//    qDebug() << "Pressed Key:" << keyText;


//    QList<Qt::Key> modifiersList;
//    if(modifiers & Qt::ShiftModifier)
//        keyInt += Qt::SHIFT;
//    if(modifiers & Qt::ControlModifier)
//        keyInt += Qt::CTRL;
//    if(modifiers & Qt::AltModifier)
//        keyInt += Qt::ALT;
//    if(modifiers & Qt::MetaModifier)
//        keyInt += Qt::META;

//    qDebug() << "New KeySequence:" << QKeySequence(keyInt).toString(QKeySequence::NativeText);

//    //ui->lineEdit->setText(QKeySequence(keyInt).toString(QKeySequence::NativeText));

}


void Dialog::cerrar_configuracion(){

//    QMessageBox msgBox;
//    msgBox.setText("La configuración ha sido modificada.");
//    msgBox.setInformativeText("¿Desea guardar los cambios?");
//    msgBox.setStandardButtons(QMessageBox.Save | QMessageBox.Discard | QMessageBox.Cancel);

//    msgBox.setDefaultButton(QMessageBox.Save);
//    msgBox.exec();

//    QMessageBox::information(
//            this,
//            tr("SRV-1 Console"),
//            tr("Desea salir sin guardar la configuraci&oacute;n"));
    this->close();
}

void Dialog::closeEvent(QCloseEvent *event){
}
