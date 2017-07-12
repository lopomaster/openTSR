#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <stdlib.h>

void mouseHandler(int event, int x, int y, int flags, void* param)
{
    // Declaración de variables.
    IplImage* img0, * img1;
    CvFont    font;
    uchar*    ptr;
    char      label[20];

    img0 = (IplImage*) param;
    img1 = cvCloneImage(img0);


    cvInitFont(&font, CV_FONT_HERSHEY_PLAIN, .8, .8, 0, 1, 8);

    if (event == CV_EVENT_LBUTTONDOWN)
    {
        // Se realiza la lectura del píxel pulsado.
        ptr = cvPtr2D(img1, y, x, NULL);

        // Se muestra el valor RGB.
        sprintf(label, "(%d, %d, %d)", ptr[0], ptr[1], ptr[2]);
        
        // Se crea un rectángulo de color en la imagen...
        cvRectangle( 
            img1,
            cvPoint(x, y - 12),
            cvPoint(x + 100, y + 4),
            CV_RGB(255, 0, 0),
            CV_FILLED,
            8, 0
        );
        // Y se dibuja los valores numéricos en su interior.
        cvPutText(
            img1,
            label,
            cvPoint(x, y),
            &font,
            CV_RGB(255, 255, 0)
        );

        // Finalmente se muestra la imagen.
        cvShowImage("img", img1);
    }
}


int main(int argc, char *argv[]){

    IplImage* img,*hsv_image;

    // Se comprueba que se ha introducido un argumento.
    if (argc != 2) {
        printf("Usage: %s <image>\n", argv[0]);
        return 1;
    }

    // Se realiza la carga de la imagen a partir de la ruta pasada 
    // como argumento de entrada.
    img = cvLoadImage(argv[1], 1);

    //Copia de la imagen de entrada en una nueva imagen.
    hsv_image = cvCloneImage(img); 
    
    //Transformacion a HSV
    cvCvtColor(img, hsv_image, CV_BGR2HSV);

    // Se crea una ventana con los eventos del ratón.
    cvNamedWindow("img", 1);
    cvSetMouseCallback("img", mouseHandler, (void*)hsv_image);

    cvShowImage("img", hsv_image);
    cvWaitKey(0);

    // Eliminación de estructuras.
    cvDestroyAllWindows();
    cvReleaseImage(&img);
    cvReleaseImage(&hsv_image);

    return 0;
}













