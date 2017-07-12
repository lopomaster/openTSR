int main(int argc, char *argv[])
{

  IplImage *img_selec_color = NULL,*dst = NULL,*senial = NULL,*img=NULL, *identificar = NULL;
 
  CvRect rect;
  int i,j;
  double area=0;

  CvPoint pt1,pt2;

  char c=NULL;
  
  CvSeq* contour;
  CvMemStorage* storage=cvCreateMemStorage(0);


  IplImage    *tpl;
  IplImage    *res;
  int         width, height;
  float       umbral = 0.3;
  char directorio[100]= "seniales/75.jpg";
  CvScalar s;

  // Ventanas para la muestra de resultados.
  cvNamedWindow("Imagen",CV_WINDOW_AUTOSIZE);
  cvNamedWindow("Elemento",CV_WINDOW_AUTOSIZE);

  // Crea la conexion con la Webcam.
  CvCapture* capture = cvCaptureFromCAM(1);
 

   while(c != 27) {

    // Pongo el frame capturado de capture dentro de la imagen img.
     img = cvQueryFrame(capture);
     
     // Segmentación por color
     img_selec_color = segmentacion_RGB(img);
	     
     dst = cvCreateImage( cvGetSize(img),IPL_DEPTH_8U, 1 );
     cvZero(dst);

     cvFindContours(img_selec_color, storage, &contour, sizeof(CvContour),CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
     
     senial = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 3);
     cvZero(senial);     

     for(; contour != 0; contour = contour->h_next ){
	       
       area=fabs(cvContourArea(contour,CV_WHOLE_SEQ));
	       
       if(area>=300){

	 cvDrawContours(dst, contour, cvScalar(1),cvScalar(1), -1, CV_FILLED, 8);
	 
	 // Mínima area que encierra al objeto.
         rect = cvBoundingRect(contour,0); //Rectángulo mínimo que encierra el objeto a analizar.

         //Selección de las regiones de interiores:

	 cvSetImageROI(dst,rect);
	 cvSetImageROI(senial,rect);
	 cvSetImageROI(img,rect);

         // Copia utilización de máscaras.
         cvCopy(img,senial,dst);

	 cvResetImageROI(dst);
	 cvResetImageROI(img);
	 
	 // Redimensionar la imagen.
         identificar = cvCreateImage( cvSize(100,100),IPL_DEPTH_8U,3);
         cvResize(senial,identificar,CV_INTER_LINEAR);
	 
	 cvShowImage( "Elemento",identificar);

         // Ya disponemos el elemento a identificar.   
	 
	 /////////////////////////////////// ALGORITMO DE IDENTIFICACIÓN.
	 	 
	 /* Carga de imagen referencia */
	 tpl = cvLoadImage( directorio, CV_LOAD_IMAGE_COLOR );
	 
	 /* Cáculo de ancho y alto de la imagen resultado */
	 width  = identificar->width  - tpl->width + 1;
	 height = identificar->height - tpl->height + 1;
	 
	 /* Imagen donde almacenaremos el resultado de la comparación */
	 res = cvCreateImage( cvSize( width, height ), IPL_DEPTH_32F, 1 );
	 
	 /* Comparación */
	 cvMatchTemplate(identificar, tpl, res, CV_TM_SQDIFF_NORMED);
	
	 for( i = 0 ; i < height ; i++) {
	   for( j = 0 ; j < width ; j++) {
	     // sacamos el elemento
	     s = cvGet2D( res, i, j );
			
	     // Si el valor se localiza entre el rango establecido...
	     if( s.val[0] <= umbral ) {
	       // Dibujamos el contorno al objeto identificado ENCONTRADO!
	       fprintf( stderr, "50!");

               pt1.x = rect.x;
               pt1.y = rect.y;
	       pt2.x = rect.x + rect.width;
               pt2.y = rect.y + rect.height;

	       cvRectangle(img,pt1,pt2,CV_RGB(0,255,0),3,8,0);
	     }
	   }
	 }

	 //////////////////////////////////           
	 
	 cvShowImage( "Im",identificar);
	 cvResetImageROI(senial);

	 cvReleaseImage(&identificar);
	 cvReleaseImage(&res);
	 cvReleaseImage(&tpl);
       }

       cvClearSeq(contour);
     }
     
     cvShowImage( "Imagen",img );
     
     cvReleaseImage( &senial );
     cvReleaseImage( &img_selec_color );
     cvReleaseImage( &dst );  
     cvClearMemStorage(storage);

     c = cvWaitKey(10);
   }

   cvReleaseMemStorage(&storage);   
   cvReleaseCapture(&capture);
   cvDestroyAllWindows();
   
   return 0;
}
