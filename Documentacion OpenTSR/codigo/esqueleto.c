#include <stdio.h>
#include <stdlib.h>
#include "opencv/cv.h" 
#include "opencv/highgui.h"

int main(int argc, char *argv[])
{
  IplImage *img=NULL;

  char c=NULL;

  // Crea una ventana llamada Original Imagen
  // con tamaño predeterminado.
  cvNamedWindow("Imagen",CV_WINDOW_AUTOSIZE);
 
  // Crea la conexion con la Webcam.
  CvCapture* captura = cvCaptureFromCAM(-1);
 
   // Si la tecla pulsada es ESC se sale del bucle.
   while(c != 27) { 

    // Añade el frame capturado dentro de la imagen img.
    img = cvQueryFrame(captura);

    // PROCESAMIENTO DE LA IMAGEN.
  
    // Se espera la pulsación de alguna tecla 
    // durante 10 milésimas de segundo.
    // De ser alguna tecla pulsada, 
    // se almacena en la variable c.
    c = cvWaitKey(10);
  }

  // Liberación de la cámara.
  cvReleaseCapture(&captura);

  // Eliminamos todas las estructuras ventana existentes. 
  cvDestroyAllWindows(); 
   
  return 0;
}

