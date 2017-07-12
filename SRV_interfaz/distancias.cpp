// Medidor de distancias mediante captación de los punteros lasers de una imagen
// Vehículo SRV-1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "QtGui"


int distancia(IplImage *img){

    //Definición de algunas constantes.
    //Valores de corte en el espacio HSV para un puntero laser rojo.

    //hue
    double h_min = 150;
    double h_max = 256;

    //saturacion
    double s_min = 50;
    double s_max = 150;

    //valor
    double v_min = 250;
    double v_max = 256;

    int distancia = 0; //Valor a devolver.

    CvSeq* contour, *result;
    CvMemStorage *storage=cvCreateMemStorage(0);

    int piezas =0,cont=0;

    float center1_x=0,center1_y=0;
    float center2_x=0,center2_y=0;

    //Creamos las imagenes para los diferentes canales...

    IplImage *h_img, *s_img, *v_img, *laser_img, *hsv_image;

    CvMoments moments;
    double m00, m10, m01;

    h_img = cvCreateImage (cvGetSize(img), IPL_DEPTH_8U, 1);
    s_img = cvCreateImage (cvGetSize(img), IPL_DEPTH_8U, 1);
    v_img = cvCreateImage (cvGetSize(img), IPL_DEPTH_8U, 1);
    laser_img = cvCreateImage (cvGetSize(img), IPL_DEPTH_8U, 1);

    hsv_image = cvCloneImage(img); //Copia de la imagen de entrada
    cvCvtColor(img, hsv_image, CV_BGR2HSV); //Transformacion a HSV

    //Separamos la imagen en canales.
    cvSplit(hsv_image, h_img, s_img, v_img, 0);


    //Aplicamos los rangos establecidos para cada componente HSV.
    cvInRangeS(h_img, cvScalar(h_min,h_min,h_min,0),cvScalar(h_max,h_max,h_max,0), h_img);
    cvInRangeS(s_img, cvScalar(s_min,s_min,s_min,0), cvScalar(s_max,s_max,s_max,0), s_img);
    cvInRangeS(v_img, cvScalar(v_min,v_min,v_min,0), cvScalar(v_max,v_max,v_max,0), v_img);

    // Operación AND en componentes HSV
    cvAnd(h_img, v_img, laser_img);

    cvDilate(laser_img,laser_img,0,10);

    //Se busca contorno exterior (CV_RETR_EXTERNAL) de la imagen color_seleccionado
    piezas = cvFindContours(laser_img, storage, &contour, sizeof(CvContour),CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);

    if(piezas == 2){ //Si se detectan los dos puntos...

        cont = 0;
        for(; contour != 0; contour = contour->h_next ){

            //Detección del polinomio APROXIMADO que encierra la figura
            result = cvApproxPoly(contour, sizeof(CvContour), storage, CV_POLY_APPROX_DP,2, 0); //2, precisión

            cvMoments(result, &moments, 1);

            m00 = cvGetSpatialMoment(&moments, 0,0);
            m10 = cvGetSpatialMoment(&moments, 1,0);
            m01 = cvGetSpatialMoment(&moments, 0,1);


            if(cont==0){
                center1_x = m10/m00;
                center1_y = m01/m00;

            }

            if(cont == 1){
                center2_x = m10/m00;
                center2_y = m01/m00;
            }
            cont++;

            if(result){
                cvClearSeq(result);
            }
        }

        //////////////////////////////////////////////////// Dibujo línea distancia entre punteros lasers en verde
        cvLine(img,cvPoint(int(center1_x),int(center1_y)),cvPoint(int(center2_x),int(center2_y)),CV_RGB(0,255,0),5,8,0);
        ///////////////////////////////////////////////////

        distancia = sqrt(pow(center1_x - center2_x,2 ) + pow(center1_y - center2_y, 2));

    }


    cvClearMemStorage(storage);
    cvReleaseMemStorage(&storage);

    cvReleaseImage( &h_img);
    cvReleaseImage( &s_img);
    cvReleaseImage( &v_img);
    cvReleaseImage( &laser_img);
    cvReleaseImage( &hsv_image);

    if(distancia >= 420){
        return 20;
    }

    if(distancia > 350 ){

        return 25;
    }

    if(distancia > 290){

        return 30;
    }

    if(distancia > 250){

        return 35;
    }


    if(distancia > 215){

        return 40;
    }

    if(distancia > 190){

        return 45;
    }

    if(distancia > 170){

        return 50;
    }

    if(distancia > 150){

        return 55;
    }

    if(distancia > 140){

        return 60;
    }

    if(distancia > 130){

        return 65;
    }

    if(distancia > 120){

        return 70;
    }


    if(distancia > 110){

        return 75;
    }

    if(distancia > 100){

        return 80;
    }


    if(distancia > 95){

        return 85;
    }


    if(distancia > 90){

        return 90;
    }


    if(distancia > 85){

        return 95;
    }

    if(distancia > 80){

        return 100;
    }

    if(distancia > 78){

        return 105;
    }

    if(distancia > 75){

        return 110;
    }

    if(distancia > 70){

        return 115;
    }

    if(distancia > 65){

        return 120;
    }

    return 0;
}
