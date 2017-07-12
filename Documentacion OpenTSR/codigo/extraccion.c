// Segmentación por color
img_selec_color = segmentacion_RGB(img);

dst = cvCreateImage( cvGetSize(img),IPL_DEPTH_8U, 1 );
cvZero(dst);

// Búsqueda de contornos en la imagen obtenida tras la selección por color.
cvFindContours(img_selec_color, storage, &contour, sizeof(CvContour),
CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

senial = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 3);
cvZero(senial);     

// Para objeto encontrado:
for(; contour != 0; contour = contour->h_next ){
  
  // Se calcula su área.
  area=fabs(cvContourArea(contour,CV_WHOLE_SEQ));
  
  // Si el área supera un determinado valor de área. 
  if(area>=300){
    
    // Se dibuja el objeto en una imagen.
    cvDrawContours(dst, contour, cvScalar(1),cvScalar(1), -1, CV_FILLED, 8);
    
    // Se calcula el área mínima que encierra al objeto.
    rect = cvBoundingRect(contour,0); 
    
    // Selección de las regiones de interés.
    cvSetImageROI(dst,rect);
    cvSetImageROI(senial,rect);
    cvSetImageROI(img,rect);
    
    // Se realiza la copia mediante la
    // utilización de máscaras para eliminar el fondo del objeto.
    cvCopy(img,senial,dst);

    // Se eliminan las regiones de interés establecidas previamente.
    cvResetImageROI(dst);
    cvResetImageROI(img);
    
    // Se redimensiona la imagen.
    identificar = cvCreateImage( cvSize(100,100),IPL_DEPTH_8U,3);
    cvResize(senial,identificar,CV_INTER_LINEAR);
    
    // Y ya disponemos la imagen con el elemento a identificar.   
    cvShowImage( "Elemento",identificar);

    // ALGORITMO IDENTIFICADOR

  } // Fin if.
 } // Fin for.
