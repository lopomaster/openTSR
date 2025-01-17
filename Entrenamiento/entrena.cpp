#include <stdio.h>
#include <stdlib.h>
#include "opencv/cv.h"       //Opencv
#include "opencv/highgui.h"

using namespace cv;

void mostrar_mensaje_bienvenida();
CvMat* aniadir_columna(CvMat* matriz, CvMat* columna);
CvMat* crear_matriz_columna(CvMat* matriz);
  

int main(){

  cvNamedWindow("Imagen",CV_WINDOW_AUTOSIZE);

  int tam = 50;
  
  mostrar_mensaje_bienvenida();

  IplImage *im, *im2, *gris,*binaria, *im_elemento,*im_elemento_reducido; 
  
  im = cvLoadImage("train8.jpg",CV_LOAD_IMAGE_COLOR); //Leemos la imagen.	
  
  if(!im){
	std::cout << "Error: no se puede cargar la imagen " << std::endl;
	exit(0);
  } 

  CvMat elemento_entrenado;

  vector<int> respuestas;  //Vector que contendrá las clases resultantes del entrenamiento.
  vector<int>::iterator it;


  CvMat* respuesta = cvCreateMat(tam * tam,1,CV_32FC1);
  CvMat* modelos = NULL;

  cvNamedWindow("Procesamiento",CV_WINDOW_AUTOSIZE);
  
  CvRect rect;
  CvPoint pt1,pt2;
  
  CvSeq *contour;
  CvMemStorage* storage=cvCreateMemStorage(0);
 

  int tecla, pos;
  gris = cvCreateImage(cvGetSize(im),im->depth,1);
  cvCvtColor(im,gris,CV_RGB2GRAY); 
 
  binaria = cvCreateImage(cvGetSize(im),IPL_DEPTH_8U,1);
  cvZero(binaria);  

  cvThreshold(gris,binaria,100,255, CV_THRESH_BINARY ); //100 - 255

  // Localización de contornos. 
  
  IplImage *aux = cvCreateImage(cvGetSize(binaria),binaria->depth,1);
  cvCopy(binaria,aux);

  cvFindContours(aux, storage, &contour, sizeof(CvContour),CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);     
  for (pos = 1;contour->h_next!=NULL;pos++,contour=contour->h_next){
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
		cvRectangle( im, pt1, pt2, CV_RGB(0,255,0), 3, 8, 0 );
        
		cvShowImage( "Procesamiento",im);
		tecla = cvWaitKey(0);
		
		if(tecla == 27){
		  pos --;
		  break;
		  
		} else{ 
		  
		        //Códigos ASCII de los números 0-9.
			
			cvSetImageROI(binaria,rect);

			it = respuestas.end();
			it = respuestas.insert (it ,tecla);

			im_elemento = cvCreateImage( cvSize(rect.width, rect.height),binaria->depth,binaria->nChannels);
			cvCopy(binaria,im_elemento);
			
			im_elemento_reducido = cvCreateImage(cvSize(tam,tam),binaria->depth,1);
			cvResize(im_elemento,im_elemento_reducido);

			cvNot(im_elemento_reducido,im_elemento_reducido);  

                         cvShowImage("Imagen",im_elemento_reducido);


	                CvMat* matImagen = cvCreateMat(tam,tam,CV_32FC1);	 //Paso de IplImage a CvMat;
			cvConvert(im_elemento_reducido, matImagen);

			CvMat* elemento_columna = crear_matriz_columna(matImagen); //Añadimos a la matriz modelos los datos de la nueva imagen.
                        modelos = aniadir_columna(modelos,elemento_columna);

			cvResetImageROI(binaria);
		  
		}
	  }
	}
  }

  Mat matriz_intermedia = Mat(respuestas,1); //nueva matriz con el contenido del vector respuestas.
  // Trasponer la matriz

  matriz_intermedia.t();

  Mat m = modelos;
  Mat m2 = m.t();

  CvMat model = m2;

  CvMat clases = matriz_intermedia;  //Conversión cv::mat a CvMat.

  std::cout << " Entrenamiento completado " << std::endl;

  cvSave("clases.yml", &clases);
  cvSave("modelos.yml",&model);

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



CvMat* aniadir_columna(CvMat* matriz, CvMat* matriz_columna){

CvMat* salida;

 if(matriz == NULL && matriz_columna != NULL){
   salida = cvCreateMat(matriz_columna->rows,1,CV_32FC1);
   
   for (int a=0; a < salida->rows; a++){
	cvSetReal2D(salida,a,0,cvGetReal2D(matriz_columna,a,0));
   }
   
   
 }else{

   if(matriz->rows != matriz_columna->rows){
	 std::cout << "matriz.cols != matriz_columna.rows" << std::endl;
	 exit(1);
  }
   
   if(matriz_columna->cols != 1){
	 std::cout << "matriz_columna.cols != 1" << std::endl;
	 exit(1);
  }
   
 	salida = cvCreateMat(matriz->rows,matriz->cols +1,CV_32FC1);
	
	for (int a=0; a < matriz->rows; a++){
	  cvSetReal2D(salida,a,matriz->cols,cvGetReal2D(matriz_columna,a,0));
	  for (int b=0;b < matriz->cols; b++){
		cvSetReal2D(salida,a,b,cvGetReal2D(matriz,a,b)); 
	  }	
	}
	
}
 
 return salida;
}



void mostrar_mensaje_bienvenida(){
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "............................................." << std::endl;
  std::cout << ".......... SRV Trafic Recognition ..........." << std::endl;
  std::cout << "............................................." << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;



  std::cout << "Algoritmo reconocedor de señales de tráfico." << std::endl;
  std::cout << std::endl;

  std::cout << "Fase de entrenamiento: " << std::endl;
  std::cout << "Asigne a cada elemento un carácter, Enter para descartar. " << std::endl;


  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "............................................." << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;  


}


