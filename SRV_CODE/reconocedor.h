#include "opencv/cv.h"       //Opencv
#include "opencv/highgui.h"
#include "QtGui"

#ifndef _RECONOCEDOR_
#define _RECONOCEDOR_


CvMat extraeDatosIMG(IplImage* candidato);
IplImage* seleccion_colorHSV(IplImage* im_entrada);
IplImage* redimensionar(IplImage *origen,int ancho, int alto);
int Clasificador(CvMat DatosEntrenamiento, CvMat DatosCandidato);
void ImprimeCvMat(CvMat Clases);
int tipo_figura(CvSeq* result);
CvMat* crear_matriz_fila(CvMat* matriz);
IplImage* QImage2IplImage(QImage *qimg);
QImage*  IplImage2QImage(IplImage *iplImg);

#endif
