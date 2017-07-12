#include <stdio.h>
#include <stdlib.h>
#include "opencv/cv.h"       //Opencv
#include "opencv/highgui.h"
#include "opencv/ml.h"       //Kvecinos
#include "reconocedor.h"
#include <math.h>
#include "dialog.h"
#include "QtGui"

#define elementos 11      //Número de imágenes que compone la base de datos de imágenes

#define PI 3.14159265

IplImage* extraer_imagen_plantilla(int indice);
int tipo_figura(CvSeq* result,IplImage* plantilla);
double angulo( CvPoint* pt1, CvPoint* pt2, CvPoint* pt0 );
void dibuja_poligono(IplImage* plantilla,CvSeq* result);
IplImage* seleccion_colorHSV(IplImage* im_entrada);



///////////////////////////////////////////////////////////////
//////////     IMPLEMANTACIÓN DE FUNCIONES   //////////////////
///////////////////////////////////////////////////////////////


int tipo_figura(CvSeq* result){  //Localiza la forma de la figura a partir de un polígono.


  double A,B,C,D;//,E,F,G,H;
  int i; //variable para control de bucles


  // hough detector works better with some smoothing of the image
  //cvSmooth(plantilla,plantilla, CV_GAUSSIAN, 9, 9 );


  //CUADRADO, cuatro vértices, área superior a 1000 y estructura convexa
  //En un conjunto convexo se puede ir de cualquier punto a cualquier otro en vía recta, sin salir del mismo.
  //Formalmente: para todo (A,B) € C ->  [A,B] C C


  if(result->total==4 && fabs(cvContourArea(result,CV_WHOLE_SEQ,0)) > 1000 && cvCheckContourConvexity(result)) //CUADRADO
    {
      CvPoint *pt[4];

      //Extraemos los puntos de los vértices
      for(i=0;i<4;i++)
        pt[i] = (CvPoint*)cvGetSeqElem(result, i);

      ///////////////////////////////////////////////  Dibujo cuadrado

      for (i=0;i<result->total-1;i++){
        //cvLine(plantilla, *pt[i], *pt[i+1],CV_RGB(255,0,0),5,8,0);
      }
      //cvLine(plantilla, *pt[result->total-1], *pt[0],CV_RGB(255,0,0),5,8,0);
      //////////////////////////////////////////////

      //Procedemos a calcular el ángulo de los 4 vértices (condición: 90 grados cada uno)
      //std::cout <<"angulo cuadrado " << acos(angulo(pt[3],pt[1],pt[0]))*180/PI << std::endl;
      //std::cout <<"angulo cuadrado " << acos(angulo(pt[0],pt[2],pt[1]))*180/PI << std::endl;
      //std::cout <<"angulo cuadrado " << acos(angulo(pt[3],pt[1],pt[2]))*180/PI << std::endl;
      //std::cout <<"angulo cuadrado " << acos(angulo(pt[0],pt[2],pt[3]))*180/PI << std::endl;

      A = acos(angulo(pt[3],pt[1],pt[0]))*180/PI;
      B = acos(angulo(pt[0],pt[2],pt[1]))*180/PI;
      C = acos(angulo(pt[3],pt[1],pt[2]))*180/PI;
      D = acos(angulo(pt[0],pt[2],pt[3]))*180/PI;

      if( A < 92 && A > 88 && B < 92 && B > 88 &&  C < 92 && C > 88 &&  D < 92 && D > 88   ){
        //std::cout << "¡¡¡CUADRADO DETECTADO!!" << std::endl;
        return 4;
      }
    }

  //OCTÓGONO
  if(result->total==8 && cvCheckContourConvexity(result))
    {

      //Extraemos los puntos de los vértices
      //CvPoint *pt[8];

     // for(i=0;i<8;i++)
       // pt[i] = (CvPoint*)cvGetSeqElem(result, i);

      /////Dibujo octógono
      //for (i=0;i<result->total-1;i++)
        //cvLine(plantilla, *pt[i], *pt[i+1],CV_RGB(0,255,255),5,8,0);

      //cvLine(plantilla, *pt[result->total-1], *pt[0],CV_RGB(0,255,255),5,8,0);
      ///////////////////////

      //Procedemos a calcular el ángulo de los 8 vértices. Hexágono regular, 135 grados por vértice, 1080 en total.
      //std::cout <<"angulo hexágono " << acos(angulo(pt[7],pt[1],pt[0]))*180/PI << std::endl;
      //std::cout <<"angulo hexágono " << acos(angulo(pt[0],pt[2],pt[1]))*180/PI << std::endl;
      //std::cout <<"angulo hexágono " << acos(angulo(pt[3],pt[1],pt[2]))*180/PI << std::endl;
      //std::cout <<"angulo hexágono " << acos(angulo(pt[4],pt[2],pt[3]))*180/PI << std::endl;
      //std::cout <<"angulo hexágono " << acos(angulo(pt[5],pt[3],pt[4]))*180/PI << std::endl;
      //std::cout <<"angulo hexágono " << acos(angulo(pt[6],pt[4],pt[5]))*180/PI << std::endl;
      //std::cout <<"angulo hexágono " << acos(angulo(pt[7],pt[5],pt[6]))*180/PI << std::endl;
      //std::cout <<"angulo hexágono " << acos(angulo(pt[0],pt[6],pt[7]))*180/PI << std::endl;

      /*
      A = acos(angulo(pt[7],pt[1],pt[0]))*180/PI;
      B = acos(angulo(pt[0],pt[2],pt[1]))*180/PI;
      C = acos(angulo(pt[3],pt[1],pt[2]))*180/PI;
      D = acos(angulo(pt[4],pt[2],pt[3]))*180/PI;
      E = acos(angulo(pt[5],pt[3],pt[4]))*180/PI;
      F = acos(angulo(pt[6],pt[4],pt[5]))*180/PI;
      G = acos(angulo(pt[7],pt[5],pt[6]))*180/PI;
      H = acos(angulo(pt[0],pt[6],pt[7]))*180/PI;
      */

/*
      if( A < 137 && A > 133 && B < 137 && B > 133 &&  C < 137 && C > 133 &&
          D < 137 && D > 133 && E < 137 && E > 133 &&  F < 137 && F > 133 &&
          G < 137 && G > 133 && H < 137 && H > 133){

*/


        //std::cout << "¡¡¡OCTÓGONO DETECTADO!!" << std::endl;
        return 8;
      //}
    }

  if(result->total==3) //TRIANGULO
    {

      //Extraemos los puntos de los vértices
      CvPoint *pt[3];
      for(i=0;i<3;i++)
        pt[i] = (CvPoint*)cvGetSeqElem(result, i);

      /////////////////////////////////// Dibujo de la figura en la imagen original
      for (i=0;i<result->total-1;i++){
        //cvLine(plantilla, *pt[i], *pt[i+1],CV_RGB(0,0,255),5,8,0);
      }
      //cvLine(plantilla, *pt[result->total-1], *pt[0],CV_RGB(0,0,255),5,8,0);
      //////////////////////////////////

      //Procedemos a calcular el ángulo de los 3 vértices (condición: 60 grados cada uno aproximadamente)
      //std::cout <<"angulo triangulo " << acos(angulo(pt[2],pt[1],pt[0]))*180/PI << std::endl;
      //std::cout <<"angulo triangulo " << acos(angulo(pt[0],pt[2],pt[1]))*180/PI << std::endl;
      //std::cout <<"angulo triangulo " << acos(angulo(pt[0],pt[1],pt[2]))*180/PI << std::endl;

      A = acos(angulo(pt[2],pt[1],pt[0]))*180/PI;
      B = acos(angulo(pt[0],pt[2],pt[1]))*180/PI;
      C = acos(angulo(pt[0],pt[1],pt[2]))*180/PI;

      if( A < 66 && A > 50 && B < 67 && B > 50 &&  C < 67 && C > 50 ){
        //std::cout << "¡¡¡TRIANGULO DETECTADO!!" << std::endl;
        return 3;
      }

    }

  return 0;
}





void dibuja_poligono(IplImage* plantilla,CvSeq* result){
  
  int i;
  CvPoint *pt[result->total];
  for(i=0;i<result->total;i++)
    pt[i] = (CvPoint*)cvGetSeqElem(result, i);
  
  for (i=0;i<result->total-1;i++){
    cvLine(plantilla, *pt[i], *pt[i+1],CV_RGB(255,0,0),5,8,0);
  }
  cvLine(plantilla, *pt[result->total-1], *pt[0],CV_RGB(255,0,0),5,8,0);
  
}



IplImage* redimensionar(IplImage *origen,int ancho, int alto){
  
  /////////////////////////////////////// REDIMENSIONAR
  int px = ancho; // píxeles en el eje x de la imagen escalada,
                  // es decir, estamos definiendo la escala 'X'
  int py = alto; // píxeles en el eje x de la imagen escalada,
  // es decir, estamos definiendo la escala 'Y'
  IplImage *destino = cvCreateImage( cvSize(px,py),origen->depth,origen->nChannels);
  // creamos la estructura
  // donde ubicaremos la imagen escalada,
  // siendo px y py los píxeles de la imagen
  // destino, es decir, el propio factor de escala
  
  cvResize(origen,destino,CV_INTER_LINEAR);
  //////////////////////////////////////
  
  return destino;
}



IplImage* seleccion_colorHSV(IplImage* img ){

  // Declaraciones

  IplImage *hsv_Image, *mono_Image;
  int height , width , step , channels;
  int step_mono , channels_mono;  
  uchar *data_hsv , *data_mono;


  ////////VALORES UMBRAL
  ////////////////////////////////////////////////////////////////
  //int hupper=125,hlower=115,Saturation=100,Brightness=100,Erode=0,Dilate=3;        //Color Rojo, funciona bien.

   //int hupper=175,hlower=110,Saturation=90,Brightness=90,Erode=0,Dilate=1;        //Color Rojo, prueba ok
   int hupper=175,hlower=110,Saturation=60,Brightness=90,Erode=1,Dilate=1;

   int hupper2=35,hlower2=0,Saturation2=60,Brightness2=60,Erode2=0,Dilate2=3;        //Color Azul
  ////////////////////////////////////////////////////////////////

  // Creamos 2 imagenes partiendo de la imagen Fuente
  hsv_Image = cvCreateImage( cvGetSize(img), 8, 3 );
  mono_Image = cvCreateImage( cvGetSize(img), 8, 1 );
  cvZero(hsv_Image);
  cvZero(mono_Image);

  // Obtenemos atributos de la imagen HSV
  height     = hsv_Image->height;
  width      = hsv_Image->width;
  step       = hsv_Image->widthStep/sizeof(uchar);
  channels   = hsv_Image->nChannels;

  step_mono   = mono_Image->widthStep/sizeof(uchar);
  channels_mono = mono_Image->nChannels;

  // Convertimos imagen RGB a HSV
  cvCvtColor(img,hsv_Image,CV_RGB2HSV);

  // Obtenemos los valores RGB de la Imagen
  data_hsv = (uchar *)hsv_Image->imageData;
  data_mono = (uchar *)mono_Image->imageData;

  //Recorremos la imagen
  for(int i = 0; i <height; i++ ) {
    for(int j = 0; j <width; j++ ) {

      // Segmentamos la imagen mediante los angulos de Hue
        if (((data_hsv[i*step+j*channels])>= hlower) &&
            ((data_hsv[i*step+j*channels]) <= hupper) && (data_hsv[i*step+j*channels+1]>= Saturation ) && (data_hsv[i*step+j*channels+2]>= Brightness) || ((data_hsv[i*step+j*channels])>= hlower2) &&
            ((data_hsv[i*step+j*channels]) <= hupper2) && (data_hsv[i*step+j*channels+1]>= Saturation2 ) && (data_hsv[i*step+j*channels+2]>= Brightness2)){
        // Coloreamos el pixel deseado
        data_mono[i*step_mono+j*channels_mono] = 255;
      }
    }
  }

  // Erocionar y Dilatar , para la eliminacion de pixeles sueltos
  cvErode(mono_Image,mono_Image,0,Erode);
  cvDilate( mono_Image,mono_Image,0,Dilate);

  cvReleaseImage(&hsv_Image);

  return mono_Image;
}


CvMat* crear_matriz_fila(CvMat* matriz){

  CvMat* salida = cvCreateMat(1,matriz->rows * matriz->cols, CV_32FC1);

  int elemento;
  for (int a=0; a < matriz->rows; a++){
    for (int b=0; b < matriz->cols; b++){
      elemento = cvGetReal2D(matriz,a,b);
      cvSetReal2D(salida,0, a + (matriz->rows * b),elemento);
    }
  }

  return salida;
}



IplImage* QImage2IplImage(QImage *qimg)
{
    IplImage *imgHeader = cvCreateImageHeader( cvSize(qimg->width(), qimg->height()), IPL_DEPTH_8U, 4);
    imgHeader->imageData = (char*) qimg->bits();

    uchar* newdata = (uchar*) malloc(sizeof(uchar) * qimg->byteCount());
    memcpy(newdata, qimg->bits(), qimg->byteCount());

    //qimg->~QImage();

    return imgHeader;
}

QImage*  IplImage2QImage(IplImage *iplImg)
{
    int h = iplImg->height;
    int w = iplImg->width;
    int channels = iplImg->nChannels;
    QImage *qimg = new QImage(w, h, QImage::Format_ARGB32);
    char *data = iplImg->imageData;


    for (int y = 0; y < h; y++, data += iplImg->widthStep)
    {
        for (int x = 0; x < w; x++)
        {
            char r=0, g=0, b=0, a = 0;
            if (channels == 1)
            {
                r = data[x * channels];
                g = data[x * channels];
                b = data[x * channels];
            }
            else if (channels == 3 || channels == 4)
            {
                r = data[x * channels + 2];
                g = data[x * channels + 1];
                b = data[x * channels];
            }

            if (channels == 4)
            {
                a = data[x * channels + 3];
                qimg->setPixel(x, y, qRgba(r, g, b, a));
            }
            else
            {
               qimg->setPixel(x, y, qRgb(r, g, b));
            }
        }
    }
    //cvReleaseImage(&iplImg);
    return qimg;
}




double angulo( CvPoint* pt1, CvPoint* pt2, CvPoint* pt0 )
{
  double dx1 = pt1->x - pt0->x;
  double dy1 = pt1->y - pt0->y;
  double dx2 = pt2->x - pt0->x;
  double dy2 = pt2->y - pt0->y;

  return ((dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10));
}


