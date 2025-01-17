//import cv2
//import numpy as np

#include <stdio.h>
#include <stdlib.h>
#include "opencv/cv.h"       //Opencv
#include "opencv/highgui.h"
#include "opencv/ml.h"       //Kvecinos

using namespace cv;

CvMat* crear_matriz_columna(CvMat* matriz);


int main(){

int tam = 50;

IplImage *im, *salida, *gris, *binaria, *im_elemento, *im_elemento_reducido;

CvSeq *contour;

CvMemStorage* storage=cvCreateMemStorage(0);

CvRect rect;
CvPoint pt1,pt2;


//Variables para texto.
double hscale = 1.0;
double vscale = 0.8;
double shear = 0.2;
int thickness = 1;
int line_type = 8;
CvFont font1;

cvInitFont(&font1,CV_FONT_HERSHEY_DUPLEX,hscale,vscale,shear,thickness,line_type);

int resultado;

//////////////   Entrenamiento    //////////////////////

CvMat* muestra =(CvMat*) cvLoad("modelos.yml");

CvMat* resultado_muestra =(CvMat*) cvLoad("clases.yml");

int K = 1;

CvKNearest knn(muestra,resultado_muestra, 0, false, K );
CvMat* nearests = cvCreateMat( 1, K, CV_32FC1);

//////////////////////////// Análisis ////////////////////////////////

im = cvLoadImage("train7.jpg",CV_LOAD_IMAGE_COLOR); //Leemos la imagen.	

salida = cvCreateImage(cvGetSize(im), im->depth, im->nChannels);

gris = cvCreateImage(cvGetSize(im), im->depth,1);
cvCvtColor(im,gris,CV_RGB2GRAY);

binaria = cvCreateImage(cvGetSize(im), im->depth,1);
cvAdaptiveThreshold(gris,binaria,255,CV_ADAPTIVE_THRESH_MEAN_C,CV_THRESH_BINARY,11,2);

IplImage *aux = cvCreateImage(cvGetSize(binaria),binaria->depth,1);
cvCopy(binaria,aux);
cvFindContours(aux, storage, &contour, sizeof(CvContour),CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);     


for (;contour->h_next!=NULL;contour=contour->h_next){
	if (cvContourArea(contour,CV_WHOLE_SEQ) > 50 ){
		rect = cvBoundingRect(contour, 0 );
		if(rect.height > 20){

		   //Dibuja rectángulo 
		   //Obtenemos los puntos;
                   pt1.x = rect.x;
                   pt2.x = rect.x + rect.width;
                   pt1.y = rect.y;
                   pt2.y = rect.y + rect.height;

                   // Dibujamos en la imagen de entrada.
                   cvRectangle(im, pt1, pt2, CV_RGB(0,255,0), 3, 8, 0 );
                   cvSetImageROI(binaria,rect);

	           im_elemento = cvCreateImage( cvSize(rect.width, rect.height),binaria->depth,1);
          	   cvCopy(binaria,im_elemento);
		   cvResetImageROI(binaria);

		   im_elemento_reducido = cvCreateImage( cvSize(tam,tam),binaria->depth,1);
                   cvResize(im_elemento,im_elemento_reducido,CV_INTER_LINEAR);

			cvNot(im_elemento_reducido,im_elemento_reducido);  
		   //cvShowImage( "Entrada",im_elemento_reducido);
		   //cvWaitKey(0);


                   CvMat* matImagen = cvCreateMat(tam,tam,CV_32FC1);	 //Paso de IplImage a CvMat;
		   cvConvert(im_elemento_reducido, matImagen);

		   CvMat* elemento_analisis = crear_matriz_columna(matImagen);

		   //Traspuesta
		   Mat element = elemento_analisis;
		   Mat candidato = element.t();

                   CvMat model = candidato;

		   //Encontrar elemento más cercano.
		   resultado = knn.find_nearest(&model,K,0,0,nearests,0);

		   //Muestra de resultados.
                   char cadena_resultado[5];
		   sprintf(cadena_resultado,"%d",resultado);
	           printf("Número %s\n detectado \n", cadena_resultado);

		   int i = resultado;  //Paso de ASCII a su char correspondiente 
		   char c = (char) i;  

	           cvPutText(salida,&c,pt2,&font1,CV_RGB(0,0,255));

		}
	}
     }

 //cv2.imshow('im',im)
 cvShowImage( "Entrada",im);

 //cv2.imshow('out',out)
 cvShowImage( "Salida",salida);

 //cv2.waitKey(0)
 cvWaitKey(0);
 return 0;
}



CvMat* crear_matriz_columna(CvMat* matriz){
  
  CvMat* salida = cvCreateMat(matriz->rows * matriz->cols, 1, CV_32FC1);

  int elemento;
  for (int a=0; a < matriz->rows; a++){
	for (int b=0; b < matriz->cols; b++){
	  elemento = cvGetReal2D(matriz,a,b);
	  cvSetReal2D(salida, a + (matriz->rows * b),0,elemento); 
	}	
  }

  return salida;
}


