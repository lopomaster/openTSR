#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtGui"
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "dialog.h"
#include "SVR.h"
#include "distancias.h"
#include "reconocedor.h"
#include "stdio.h"
#include "opencv/ml.h"       //Kvecinos
#include <errno.h>
#include "qjoystick.h"

using namespace std;

//Surveyor robot();//(char *)ADDRESS);
PosixSock robot;


void movimiento_SRV(int movimiento);
int listado_dispositivos_cam();
int accion_SVR(const std::vector<char> &v);



MainWindow::MainWindow(QWidget *parent) :  //Constructor de la ventana principal
    QMainWindow(parent),

    ui(new Ui::MainWindow){
    ui->setupUi(this);
    setWindowTitle("OpenTSR");
    this->setFocus();

    ui->lcdNumber->setSegmentStyle(ui->lcdNumber->Flat);

    //adjustSize();
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    //Inicialización Joystick//
    ////////////////////////////////////////////////////////////////////////////////////////////////
    QJoystick * joy = new QJoystick();
    joy->open(0);
    connect(joy, SIGNAL(axisValueChanged(int,int)), this, SLOT(axisValueChanged(int,int)));
    connect(joy, SIGNAL(buttonValueChanged(int,bool)), this, SLOT(buttonValueChanged(int,bool)));
    /////////////////////////////////////////////////////////////////////////////////////////////////


    control=false;
    laser_on = false;
    low_speed = true;
    video_on = false;
    conectado = false;
    ultima_senial = 0; //Indicador de última señal detectada, inicialmente 0.
    velocidad = 50;    //Velocidad inicial.

    ui->spinBox_velocidad->setMaximum(101);
    ui->spinBox_velocidad->setMinimum(0);
    ui->spinBox_velocidad->setValue(50);

    teclas_pulsadas[0] = teclas_pulsadas[1] = 0;   //Buffer para control de dobles teclas pulsadas.

    //Carga de imagen inicial de la aplicación
    QPixmap imagen(":/new/prefix2/srv1.png");

    QGraphicsScene *escena = new QGraphicsScene (this);
    escena->addPixmap(imagen);
    ui->graphicsView_2->setScene(escena);
    ui->graphicsView_2->show();

    QImage imagen2("radar.jpg");
    QGraphicsScene *escena2 = new QGraphicsScene (this);
    QPixmap pixmap2 = QPixmap::fromImage(imagen2);
    escena2->addPixmap(pixmap2);
    ui->graphicsView->setScene(escena2);
    ui->graphicsView->show();
    //

    //Listado de cámaras disponibles
    int ncams = listado_dispositivos_cam();
    char buffer [33];
    for (int i=1 ; i<= ncams; i++){
        sprintf(buffer,"%d",i);
        ui->comboBox->addItem(buffer);
    }



    // Creación del display en la interfaz.
    ui->lcdNumber->setAutoFillBackground(true);
    QPalette Pal = ui->lcdNumber->palette();
    Pal.setColor(QPalette::Normal, QPalette::Window, Qt::black);
    ui->lcdNumber->setPalette(Pal);
    ui->lcdNumber->show();
    //LCD inicalizado con valor 0.
    ui->lcdNumber->display(0);
    /////////////////////////

}


MainWindow::~MainWindow()
{
      delete ui;
}


void MainWindow::modificar_velocidad(){
    this->velocidad = ui->spinBox_velocidad->value();
}



void MainWindow::inicio_reconocimiento(){

    QImage *qtimg;
    QGraphicsScene *scene = new QGraphicsScene (this);
    QPixmap pixmap;

    double umbral_minimo = 1.34531e+07; //1.54531e+07 ultimo valor; //1.34531e+07;

    ui->pushButton->setText("Detener");

    if(this->control==false){   //Control (cámara activada-desactivada)

        this->control=true;

        //Vemos que cámara se encuentra seleccionada...(la 1, la 2, etc)
        int camselect = ui->comboBox->currentIndex();

        // Crea la conexion con la Webcam.
        CvCapture* captura = cvCaptureFromCAM(camselect);

        if(!captura){
            QMessageBox::critical(this, "Error", "No se obtiene imagen de la cámara");
            exit(1);
        }


        /////////////////////////////////////////////////////////// CLASIFICADOR DECLARACIONES K-Vecinos
        int resultado,K = 1;

        CvMat* Clases =(CvMat*) cvLoad("clases.yml");  //Carga de los ficheros de entrenamiento.

        CvMat* DatosEntrenamiento =(CvMat*) cvLoad("modelos.yml");

        if(!DatosEntrenamiento || !Clases){
            QMessageBox::critical(this, "Error", "No se encuentran los datos del entrenamiento");
            exit(1);
        }

        CvMat* distancias = cvCreateMat(1,K,CV_32FC1);

        CvKNearest knn(DatosEntrenamiento, Clases,  0, false, K );
        CvMat* nearests = cvCreateMat( 1, K, CV_32FC1);

        CvMat *elemento_analisis, *matImagen;
        ////////////////////////////////////////////////////////////

        int tam = 50;
        int dist = 0;

        //Declaraciones.
        CvSeq *contour,*contour2, *result;
        CvRect rect,rect2;

        vector<char> respuestas;  // Vector que contendrá las salidas obtenidas del reconocimiento.
        vector<char>::iterator it; // Declaración de su correspondiente iterador.


        //Declaración e inicialización de imágenes.
        IplImage  *img, *color_seleccionado,*gray,*binaria,*numeros, *identificar, *reducida;

        //Declaración de las estructuras de almacenamiento.
        CvMemStorage *storage=cvCreateMemStorage(0),*storage2=cvCreateMemStorage(0);

        double area;
        //


        //Variables para la conversión de char (ASCII a int).
        char cadena_resultado[5];  //Almacenamiento de resultado obtenido al procesar la imagen.
        char c;


        while(this->control){

            // Pongo el img capturado dentro de la imagen img.
            img = cvQueryFrame(captura);

            if(!img) {
                QMessageBox::critical(this, "Error", "No se obtiene imagen de la cámara");
                exit(1);
            }

             //Si modo de reconocimiento de señales está activado:

            ///////////////////////////////////////  Modo distancia
            if(ui->checkBox_distancias->isChecked()){

                dist = distancia(img);    //Cálculo de distancias por lasers...
                //Completar: Laser puestos?
                //Quiero calcular las distancias ahora?  etc.

                if(dist != 0){
                    ui->lcdNumber->display(dist);
                }
            }
            ////////////////////////////////////////


            //////////////////////////////////////// Modo reconocimiento
            //Se realiza una selección por color en la imagen  (rojos y azules).
            color_seleccionado=seleccion_colorHSV(img);

            cvFindContours(color_seleccionado, storage, &contour, sizeof(CvContour),CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

            for(; contour != 0; contour = contour->h_next ){  /// Se recorre la lista de objetos candidatos detectados.

                area=fabs(cvContourArea(contour,CV_WHOLE_SEQ)); /// Se calcula el área del objeto.


                if(area>=500){  /// Si el objeto es demasiado pequeño se desecha.
                    //Sería útil descartarlo también por su forma.  MEJORAR FUNCION FORMA FIGURA

                    //cvDrawContours(color_seleccionado, contour, cvRealScalar(1),cvRealScalar(1),CV_RETR_EXTERNAL, CV_FILLED, 8);

                    rect = cvBoundingRect(contour); //Rectángulo mínimo que encierra el objeto a analizar.

                    //Selección de las regiones de interés
                    cvSetImageROI(img,rect);  //Contendrá el objeto (Posible señal) en RGB
                    cvSetImageROI(color_seleccionado,rect);  //Contendrá el objeto (Posuble señal) en binario.

                    ///SEGUNDA PARTE: Búsqueda de contornos interiores.
                    /////  PASO A ESCALA DE GRISES EL OBJETO DE LA IMAGEN ORIGINAL
                    gray = cvCreateImage(cvSize(rect.width, rect.height),img->depth,1);
                    cvCvtColor(img, gray, CV_RGB2GRAY );
                    ////

                    ///// BINARIZAR IMAGEN ANTERIOR
                    binaria = cvCreateImage(cvSize(rect.width, rect.height),img->depth,1);
                    cvThreshold(gray,binaria,200,255, CV_THRESH_BINARY ); //100 - 255 //200

                    //Detección del polinomio APROXIMADO que encierra la figura para saber su forma
                    result = cvApproxPoly(contour, sizeof(CvContour), storage, CV_POLY_APPROX_DP,15, 0); //15, precisión

                    if (tipo_figura(result)!= 8){  //Si es octógono
                    }

                    cvNot(binaria,binaria);

                    ///// CODIGO NUEVO
                    cvSmooth(gray, gray, CV_GAUSSIAN, 7, 7); //Suavizado
                    cvCanny(gray, gray, 10, 30, 3);          // Canny
                    //cvShowImage("Color",gray);
                    //cvWaitKey();
                    /////

                    //// LOCALIZACIÓN DE CONTORNOS INTERIORES,
                    numeros = cvCreateImage(cvSize(rect.width, rect.height),img->depth,1);
                    cvCopy(binaria,numeros);
                    //En la imagen numeros tenemos la señal en binaria.

                    cvFindContours(gray, storage2, &contour2, sizeof(CvContour),CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE);
    //!             //Sustituido gray por numeros


                    if(contour2 != NULL){
                        for(; contour2->h_next != NULL; contour2 = contour2->h_next){ //Para cada contorno en la figura:

                            area=fabs(cvContourArea(contour2,CV_WHOLE_SEQ)); /// Se calcula el área del objeto.

                            if(area>=100){

                                cvZero(binaria);
                                cvDrawContours(binaria,contour2,cvScalar(255),cvScalar(255),0,CV_FILLED,8);
                                //cvShowImage("Color",binaria);
                                //cvWaitKey();
                                ///

                                rect2 = cvBoundingRect( contour2, 0 ); //Rectángulo mínimo que encierra el objeto a analizar.


                                //Selección de las regiones de interiores:
                                cvSetImageROI(binaria,rect2);  //Contendrá los objetos en binario.

                                //Delimitamos área tal cual a analizar en la imagen principal en una nueva imagen.
                                identificar = cvCreateImage( cvSize(rect2.width, rect2.height), binaria->depth,1);
                                cvCopy(binaria,identificar);

                                reducida = redimensionar(identificar,tam,tam);

                                matImagen = cvCreateMat(tam,tam,CV_32FC1);	 //Paso de IplImage a CvMat;
                                cvConvert(reducida, matImagen);

                                elemento_analisis = crear_matriz_fila(matImagen);

                                //Encontrar elemento más cercano.
                                resultado = knn.find_nearest(elemento_analisis,K,0,0,nearests,distancias);

                                //Muestra de resultados. Conversión.
                                sprintf(cadena_resultado,"%d",resultado);
                                c = (char) resultado;
                                //

                                //std::cout <<"Detectado: " << c << " Distancia: "<< cvGetReal2D(distancias,0,0)  ;

                                if (cvGetReal2D(distancias,0,0) < umbral_minimo){ // 1.04531e+07 //Si hay bastante semejanza, aceptamos como válido.
                                    it = respuestas.end();
                                    it = respuestas.insert(it,c);
                                }

                                //Eliminamos estructuras creadas
                                cvResetImageROI(binaria); // borramos la ROI en la imagen binaria
                                cvReleaseImage(&identificar);
                                cvReleaseImage(&reducida);
                                cvReleaseMat(&elemento_analisis);
                                cvReleaseMat(&matImagen);
                            }
                        }

                        accion_SVR(respuestas);

                        //Eliminamos contenido del vector respuestas obtenidas del procesamiento de un objeto.
                        respuestas.erase(respuestas.begin(),respuestas.end());

                        cvClearMemStorage(storage2);

                    }

                    if(result){
                        cvClearSeq(result);
                    }
                    cvReleaseImage(&gray);
                    cvReleaseImage(&binaria);
                    cvReleaseImage(&numeros);
                }

                cvResetImageROI(color_seleccionado); // borramos la ROI en la imagen binaria
                cvResetImageROI(img); // borramos la ROI en la imagen binaria

            }  // Fin de procesamiento de un objeto de un img entre todos los detectados. (Bucle for)

            ////////////////////////////////////////   FIN RECONOCIMIENTO


            //////////////////////////////////////// Mostrar imagen de la cámara en la interfaz
            qtimg = IplImage2QImage(img);
            pixmap = QPixmap::fromImage(*qtimg);
            scene->clear();
            scene->addPixmap(pixmap);

            ui->graphicsView_2->setScene(scene);
            ui->graphicsView_2->show();
            ////////////////////////////////////////

            //Liberación de memoria
            cvReleaseImage(&color_seleccionado);
            cvClearMemStorage(storage);
            cvClearMemStorage(storage2);
            qtimg->~QImage();
            QPixmapCache::clear();
            pixmap.~QPixmap();

            cvWaitKey(2);

        }


        cvReleaseMat(&Clases);
        cvReleaseMat(&DatosEntrenamiento);
        cvReleaseMat(&nearests);
        cvReleaseMat(&distancias);

        knn.~CvKNearest();

        scene->clear();
        cvReleaseImage(&img);
        cvReleaseCapture(&captura);
        cvReleaseMemStorage(&storage);
        cvReleaseMemStorage(&storage2);
    }
}



void MainWindow::fin_reconocimiento(){

    control=false;
    ui->pushButton->setText("Iniciar");
    conectado=false;

    QPixmap imagen(":/new/prefix2/srv1.png");
    QGraphicsScene *escena = new QGraphicsScene (this);
    escena->addPixmap(imagen);

    QImage image2("radar.jpg");
    QGraphicsScene *scene2 = new QGraphicsScene (this);
    QPixmap pixmap2 = QPixmap::fromImage(image2);
    scene2->addPixmap(pixmap2);

    ui->graphicsView_2->setScene(escena);
    ui->graphicsView_2->show();
    ui->graphicsView->setScene(scene2);
    ui->graphicsView->show();

}




//////////////////////////////////////////// Acción botones de teclado ////////////////////////////////////////

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    this->setFocus();
    if(conectado){
        if(teclas_pulsadas[1] == 0 && teclas_pulsadas[0]!= 0 && event->key()!= teclas_pulsadas[0] && event->key() != teclas_pulsadas[1]){

            teclas_pulsadas[1] = event->key();

            qDebug()<< "vector estado:" << teclas_pulsadas[0] << "-" << teclas_pulsadas[1];

            switch (teclas_pulsadas[0]){

            case DERECHA:

                if(teclas_pulsadas[1] == ARRIBA){
                    qDebug() << "DERECHA + ARRIBA!!! ";
                    robot.drive(this->velocidad,this->velocidad/2);
                }

                if(teclas_pulsadas[1] == ABAJO ){
                    qDebug() << "DERECHA + ABAJO!!! ";
                    robot.drive(-this->velocidad/2,-this->velocidad);
                }

                break;

            case ARRIBA:

                if(teclas_pulsadas[1] == DERECHA){
                    qDebug() << "ARRIBA + DERECHA!!! ";
                    robot.drive(this->velocidad,this->velocidad/2);
                }

                if(teclas_pulsadas[1] == IZQUIERDA ){
                    qDebug() << "ARRIBA + IZQUIERDA!!! ";
                    robot.drive(this->velocidad/2,this->velocidad);
                }

                break;

            case ABAJO:

                if(teclas_pulsadas[1] == DERECHA ){
                    qDebug() << "ABAJO + DERECHA!!! ";
                    robot.drive(-this->velocidad,-this->velocidad/2);
                }

                if(teclas_pulsadas[1] == IZQUIERDA ){
                    qDebug() << "ABAJO + IZQUIERDA!!! ";
                    robot.drive(-this->velocidad/2,-this->velocidad);
                }

                break;

            case IZQUIERDA:

                if(teclas_pulsadas[1] == ARRIBA ){
                    qDebug() << "IZQUIERDA + ARRIBA!!! ";
                    robot.drive(this->velocidad/2,this->velocidad);
                }

                if(teclas_pulsadas[1] == ABAJO ){
                    qDebug() << "IZQUIERDA + ABAJO!!! ";
                    robot.drive(-this->velocidad/2,-this->velocidad);
                }
                break;
            default:
                event->ignore();
                break;
            }
        }else
        {
            if (teclas_pulsadas[0] == 0 && teclas_pulsadas[1] == 0){

                teclas_pulsadas[0] = event->key();

                qDebug()<< "vector estado:" << teclas_pulsadas[0] << "-" << teclas_pulsadas[1];
                movimiento_SRV(teclas_pulsadas[0]);
            }

            switch (event->key()){

                case 43:  //Tecla '+' aumento de velocidad.
                    this->velocidad++;
                    ui->spinBox_velocidad->setValue(this->velocidad);
                    ui->verticalSlider->setValue(this->velocidad);
                    break;
                case 45:  //Tecla '-' disminución de velocidad.
                    this->velocidad--;
                    ui->spinBox_velocidad->setValue(this->velocidad);
                    ui->verticalSlider->setValue(this->velocidad);
                    break;
                default:
                    event->ignore();
                    break;
            }

        }
    }
}

//////////////////////////////////////////////////////////////


void MainWindow::keyReleaseEvent(QKeyEvent *event){ //Control de las parejas de teclas pulsadas en cada momento.


    this->setFocus();
    if(conectado){
        if( !event->isAutoRepeat()){

                int tecla_soltada = event->key();
                //qDebug() << "tecla soltada" << tecla_soltada;
                //qDebug()<< "vector estado:" << teclas_pulsadas[0] << "-" << teclas_pulsadas[1];

                if (tecla_soltada == teclas_pulsadas[1] && teclas_pulsadas[0] != teclas_pulsadas[1]){
                    teclas_pulsadas[1] = 0;
                    //teclas_pulsadas[0] = 0;

                    //robot.move(teclas_pulsadas[0]);
                    movimiento_SRV(teclas_pulsadas[0]);
                    //qDebug()<< "vector estado:" << teclas_pulsadas[0] << "-" << teclas_pulsadas[1];

                }
                else{
                    if(tecla_soltada == teclas_pulsadas[0]){
                        teclas_pulsadas[0] = teclas_pulsadas[1];
                        teclas_pulsadas[1] = 0;

                        movimiento_SRV(teclas_pulsadas[0]);
                        //qDebug()<< "vector estado:" << teclas_pulsadas[0] << "-" << teclas_pulsadas[1];
                    }
                }

                if(teclas_pulsadas[0] == teclas_pulsadas[1] && teclas_pulsadas[1] == 0){
                    robot.move(STOP);
                    //qDebug() << "STOP";
                    teclas_pulsadas[0]=0;
                    teclas_pulsadas[1]=0;
                    //qDebug()<< "vector estado:" << teclas_pulsadas[0] << "-" << teclas_pulsadas[1];
                }
        }
    }
}


// Movimiento teclas SRV (SOLO UNA)
void MainWindow::movimiento_SRV(int movimiento){

        this->setFocus();
        switch (movimiento){

        case FRENAR:
            qDebug() << "FRENAR!! ";
            robot.drive(0,0); //move(STOP);
            break;

        case DERECHA:
            qDebug() << "DERECHA!! ";
            robot.drive(this->velocidad,0); //move(RIGHT);
            break;

        case ARRIBA:
            qDebug() << "ARRIBA!! ";
            robot.drive(this->velocidad,this->velocidad); //move(FORWARD);
            break;

        case ABAJO:
            qDebug() << "ABAJO!! ";
            robot.drive(-this->velocidad,-this->velocidad); //move(BACK);
            break;

        case IZQUIERDA:
            qDebug() << "IZQUIERDA!! ";
            robot.drive(0,this->velocidad); //move(LEFT);
            break;

        default:
            break;
        }
}



///////////////////////////////// Acción botones interfaz//////////////////////////////////////
void MainWindow::laser(){

    if(conectado){
        if (laser_on == false){
            laser_on = true;
            robot.setLasers(1); //Encendido
        }else{
            laser_on = false;
            robot.setLasers(0);  //Apagado
        }

    }
    else{
        No_conectado_mensaje();
    }

}


void MainWindow::speed(){

    if(conectado){
        if (low_speed == true){
            low_speed = false;
            this->velocidad=100;
            ui->spinBox_velocidad->setValue(100);
            //robot.move(LOW_SPEED);
        }else{
            low_speed = true;
            this->velocidad=50;
            ui->spinBox_velocidad->setValue(50);
            //robot.move(HIGH_SPEED);
        }
    }
}

void  MainWindow::boton_stop_svr(){

    if(conectado){
        robot.move(STOP);
    }
}

void  MainWindow::boton_derecha_svr(){

    if(conectado){
        robot.drive(this->velocidad,0); //move(RIGHT);
    }
}

void  MainWindow::boton_izquierda_svr(){

    if(conectado){
                     robot.drive(0,this->velocidad); //move(RIGHT);//robot.move(LEFT);
    }
}


void  MainWindow::boton_abajo_svr(){

    if(conectado){
                   robot.drive(-this->velocidad,-this->velocidad); //robot.move(BACK);
    }
}

void  MainWindow::boton_arriba_svr(){
    if(conectado){
          robot.drive(this->velocidad,this->velocidad);//robot.move(FORWARD);
    }
}

void MainWindow::closeEvent(QCloseEvent *event){

    if(this->control){
        this->fin_reconocimiento();
    }
}



///////////////////////////////////////////////////////// Menú.
void MainWindow::on_actionSobre_Traffic_SRV_1_triggered()
{
    QMessageBox about;

    about.setWindowTitle("Sobre OpenTSR");

    about.setText("<BR><BR> <BR><b>Proyecto OpenTSR</b> <BR>"
                      "<BR> Autor: Manuel L&oacute;pez Urbina"
                      "<BR> Universidad de C&aacute;diz <BR>");

    about.setStandardButtons(QMessageBox::Ok);
    about.setButtonText(1,"Aceptar");


    QImage imagen("uca-openTSR.png");
    QPixmap pixmap = QPixmap::fromImage(imagen);

    about.setIconPixmap(pixmap);
    about.setDefaultButton(QMessageBox::Ok);
    about.show();
    about.exec();

}

void MainWindow::on_actionGuia_de_usuario_triggered()
{
    if(!QDesktopServices::openUrl(QUrl("guia.pdf"))){
        qDebug() << "No se encuentra manual";
    }
}

void MainWindow::on_actionConectar_Desconectar_triggered()
{

    int conectado_exito;

    if(!conectado){

        conectado_exito = robot.openRobotLink();

        if(conectado_exito == 0){
            char	buffer[256];

            robot.getVersion(buffer);
            qDebug() << "SRV-1 version " << buffer << endl;
            robot.drive(20,20,1);

            conectado = true;

            //Activar botones
            ui->boton_velocidad->setEnabled(1);
            ui->boton_laser->setEnabled(1);
            ui->boton_down->setEnabled(1);
            ui->boton_up->setEnabled(1);
            ui->boton_left->setEnabled(1);
            ui->boton_right->setEnabled(1);
            ui->boton_stop->setEnabled(1);
            ui->boton_foto->setEnabled(1);
            ui->spinBox_velocidad->setEnabled(1);
            ui->verticalSlider->setEnabled(1);
            ui->spinBox_velocidad->setEnabled(1);
            ui->verticalSlider->setEnabled(1);

            QMessageBox::information(this,tr("SRV-1 Console"),tr("<b>Conectado con &eacute;xito<\b>") );


        }
        else{

            QMessageBox::information(this,tr("SRV-1 Console"),strerror(errno));
            QMessageBox::information(this,tr("SRV-1 Console"),tr("<b>No se ha establecido conexi&oacute;n con SRV-1<\b>") );

            ui->actionConectar_Desconectar->setChecked(0);
            conectado = false;
        }
    }
    else{
        robot.closeRobotLink();
        //robot.~PosixSock();
        //robot.~VirtSurveyor();

        QMessageBox::information(this, tr("Traffic Console SRV-1"),tr("Desconectado"));
        conectado = false;
    }
}



void MainWindow::on_actionControles_triggered()  //Ventana de configuración de controles
{
    //QDialog info(this);
    //info.exec();
    Dialog d;
    d.exec();
}

void MainWindow::No_conectado_mensaje()
{
        QMessageBox::information(this,tr("SRV-1 Console"),tr("<b>No se ha establecido conexi&oacute;n con SRV-1<\b>") );
}

void MainWindow::on_actionSalir_triggered()
{
   this->fin_reconocimiento();
   this->close();
}



/////////////////////////////////////////////////////////
void MainWindow::mostrar_distancias_obstaculo(int valor){
    ui->lcdNumber->display(valor);
}
//////////////////////////////////////////////////////////


int listado_dispositivos_cam(){

    CvCapture *cap;
    int n = 0;
    while(1)
    {
       cap = cvCreateCameraCapture(n++);
       if (cap == NULL) break;
       cvReleaseCapture(&cap);
    }

    return n-1;
}

void MainWindow::foto(){

  if(conectado){

     QDateTime dateTime = QDateTime::currentDateTime();
     QString dateTimeString = dateTime.toString("hh_mm_ss yyyy_MMM_dd");

     QPixmap pixMap = QPixmap::grabWindow(ui->graphicsView_2->winId());

     pixMap.save(dateTimeString+".jpg");

 }
 else{
    No_conectado_mensaje();

 }
}


int  MainWindow::accion_SVR(std::vector<char> &v){


    // 100 km/h
    if ((std::find(v.begin(), v.end(),'1')!= v.end()) &&
        (std::find(v.begin(), v.end(),'0') != v.end())){

        // Se elimina un '0'.
        std::vector<char>::iterator pos = std::find(v.begin(), v.end(),'0');
        v.erase(pos);

        // Si existe otro cero...
        if(std::find(v.begin(), v.end(),'0')!= v.end()){

            // 100 km/h
            if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 10){
                ultima_senial = 10;
                robot.move(STOP);
                this->velocidad = 41;
                robot.drive(this->velocidad,this->velocidad);
            }
            //Mostrar señal detectada
            mostrar_senial_detectada("10.jpg");

            return 0;
        }
    }


    // 20 km/h
    if ((std::find(v.begin(), v.end(),'2') != v.end()) &&
        (std::find(v.begin(), v.end(),'0') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 2){
            ultima_senial = 2;
            robot.move(STOP);
            this->velocidad = 25;
            robot.drive(this->velocidad,this->velocidad);
        }
        //Mostrar señal detectada
        mostrar_senial_detectada("2.jpg");
        return 0;
    }

    // 30 km/h
    if ((std::find(v.begin(), v.end(),'3') != v.end()) &&
       (std::find(v.begin(), v.end(),'0') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 3){
            ultima_senial = 3;

            robot.move(STOP);
            this->velocidad = 27;
            robot.drive(this->velocidad,this->velocidad);
        }
        //Mostrar señal detectada
        mostrar_senial_detectada("3.jpg");
        return 0;
    }

    // 40 km/h
    if ((std::find(v.begin(), v.end(),'4') != v.end()) &&
        (std::find(v.begin(), v.end(),'0') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 4){
            ultima_senial = 4;
            robot.move(STOP);
            this->velocidad = 29;
            robot.drive(this->velocidad,this->velocidad);
        }
        //Mostrar señal detectada
        mostrar_senial_detectada("4.jpg");
        return 0;
    }

    // 50 km/h
    if ((std::find(v.begin(), v.end(),'5')!=v.end()) &&
        (std::find(v.begin(), v.end(),'0') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 5){
            ultima_senial = 5;
            robot.move(STOP);
            this->velocidad = 31;
            robot.drive(this->velocidad,this->velocidad);
        }

        //Mostrar señal detectada
        mostrar_senial_detectada("5.jpg");
        return 0;
    }

    // 60 km/h
    if ((std::find(v.begin(), v.end(),'6')!= v.end()) &&
        (std::find(v.begin(), v.end(),'0') != v.end())){


        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 6){
            ultima_senial = 6;
            robot.move(STOP);
            this->velocidad = 33;
            robot.drive(this->velocidad,this->velocidad);
        }
        //Mostrar señal detectada
        mostrar_senial_detectada("6.jpg");
        return 0;
    }

    // 70 km/h
    if ((std::find(v.begin(), v.end(),'7')!= v.end()) &&
        (std::find(v.begin(), v.end(),'0') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 7){
            ultima_senial = 7;
            robot.move(STOP);
            this->velocidad = 35;
            robot.drive(this->velocidad,this->velocidad);
        }

        mostrar_senial_detectada("7.jpg");
        return 0;
    }

    // 80 km/h
    if ((std::find(v.begin(), v.end(),'8')!= v.end()) &&
        (std::find(v.begin(), v.end(),'0') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 8){
            ultima_senial = 8;
            robot.move(STOP);
            this->velocidad = 37;
            robot.drive(this->velocidad,this->velocidad);
        }

        //Mostrar señal detectada
        mostrar_senial_detectada("8.jpg");
        return 0;
    }

    // 90 km/h
    if ((std::find(v.begin(), v.end(),'9')!= v.end()) &&
        (std::find(v.begin(), v.end(),'0') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 9){
            ultima_senial = 9;

            robot.move(STOP);
            this->velocidad = 39;
            robot.drive(this->velocidad,this->velocidad);
        }


        //Mostrar señal detectada
        mostrar_senial_detectada("9.jpg");
        return 0;
    }


    // Stop
    if ((std::find(v.begin(), v.end(),'t')!= v.end()) &&
        (std::find(v.begin(), v.end(),'p') != v.end())){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 1){
            ultima_senial = 1;
            robot.move(STOP);
            robot.drive(0,0); //Realiza una pausa durante un tiempo.
            //robot.drive(this->velocidad,this->velocidad);

        }

        //Mostrar señal detectada
        mostrar_senial_detectada("1.jpg");
        return 0;
    }


    // Derecha
    if (std::find(v.begin(), v.end(),'d')!= v.end() && v.size() == 1){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 12){
            ultima_senial = 12;


            //robot.drive(this->velocidad,this->velocidad,10000);
            robot.drive(52,0,9999000);
            robot.drive(this->velocidad,this->velocidad);
        }


        //Mostrar señal detectada
        mostrar_senial_detectada("12.jpg");

        return 0;
    }

    // Izquierda
    if (std::find(v.begin(), v.end(),'i')!= v.end() && v.size() == 1){

        if(conectado && ui->checkBox_2->isChecked() && ultima_senial != 13){
            ultima_senial = 13;

            robot.drive(0,52,9999000);
            robot.drive(this->velocidad,this->velocidad);
        }

        //Mostrar señal detectada
        mostrar_senial_detectada("13.jpg");

        return 0;

    }

    return 1;
}

    void MainWindow::comenzar_piloto_autonomo(){

        if(conectado){

            if(ui->checkBox_2->isChecked()){
                this->ultima_senial = 0;
                this->velocidad=25;
                robot.drive(25,25);               //Comienza a andar a mínima velocidad
            }
            else{
                robot.move(STOP);
            }

        }


    }

void MainWindow::mostrar_senial_detectada(QString nombre_imagen){   //Mostrar señal reconocida


    QPixmap imagen(nombre_imagen);
    QGraphicsScene *escena = new QGraphicsScene (this);
    escena->addPixmap(imagen);

    ui->graphicsView->setScene(escena);
    ui->graphicsView->show();


    //QPixmapCache::clear();
    //pixmap.~QPixmap();

    cvWaitKey();

}



//////////////////////////////////////// JOYSTICK //////////////////////////////////////////////////////////

void MainWindow::axisValueChanged(int axis, int value) {

    if (conectado){
        QString s;
        //qWarning("axis: %d value: %d", axis, value);

        s = "c";
        s += axis;
        value = (int)(((float)value)*1000.0/32676.0);

        //qDebug() << value;

        switch(axis) {
        case 0:
            //Derecha
            value = value/10;
            switch(value){
            case 100:
                ui->boton_right->click();
                qDebug() << "DERECHA";
                break;
            case -100:
                ui->boton_left->click();
                qDebug() << "IZQUIERDA";
                break;
            case 0:
                ui->boton_stop->click();
                qDebug() << "STOP";
                break;

            default:
                break;
            }
        case 1:
            value = value/10;
            switch(value){
            case 100:
                ui->boton_down->click();
                qDebug() << "ABAJO";
                break;
            case -100:

                ui->boton_up->click();
                qDebug() << "ARRIBA";
                break;

            case 0:
                ui->boton_stop->click();
                qDebug() << "STOP";
                break;

            default:
                break;
            }
        default:
            break;
        }

        s += (value>>8)&0x00FF;
        s += value&0x00FF;

        //qWarning("enviando: axis: %d value1: %u value2: %u value: %d", axis, (value>>8)&0x00FF, value&0x00FF, value);
        //qWarning("enviando: axis: %d value: %d", axis, value);
    }
}




void MainWindow::buttonValueChanged(int boton, bool b) {
    if(b && conectado) {

        qDebug() << boton;

        switch(boton){

        case 0:         // Incremento de velocidad

            this->velocidad++;
            ui->spinBox_velocidad->setValue(this->velocidad);
            ui->verticalSlider->setValue(this->velocidad);

            break;
        case 1:         // Disminución de velocidad

            this->velocidad--;
            ui->spinBox_velocidad->setValue(this->velocidad);
            ui->verticalSlider->setValue(this->velocidad);

            break;
        case 2:
            break;
        case 3:
            ui->boton_velocidad->click();
            break;
        case 4:
            ui->boton_foto->click();
            qDebug() << "Foto";
            break;
        case 5:
            break;
        case 6:

            if(!laser_on){
                ui->boton_laser->click();
                qDebug() << "laser on";
                //ui->boton_laser->actions();
            }else{
                ui->boton_laser->click();
                qDebug() << "laser off";
            }
            break;
        case 7:
            break;
        case 8:
            break;
        default:
            break;
        }
    }
}

