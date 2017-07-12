CvMat extraeDatosIMG(IplImage* candidato){
  
  
  CvMat *DatosExtraidos = cvCreateMat(1,5,CV_32FC1);
  
  // Se almacenan las características de la imagen en un vector:
  
  // Columna 0, contiene su forma, 3 -> triángulo,
  // 4 -> cuadrado, 8 -> octógono, 9 -> círculo.

  // Columna 1, contiene el perímetro del objeto/objetos 
  // situado en interior de la señal.

  // Columna 2, contiene el área del objeto/objetos situado
  // en interior de la señal.

  // Columna 3, contiene el número de vértices del objeto/objetos
  // situado en interior de la señal.

  // Columna 4, contiene el número de objetos situados en 
  // interior de la señal.

  // Declaraciones
  CvSeq* circles, *result,*contour,*contour2,*contour3;

  IplImage *color_seleccionado,*dibujo_interior,*gray,*binaria,*basura1,
  *basura2;  

  double area=0, perimetro=0;
  int piezas=0, vertices=0;
  CvSeq *result2;

  CvMemStorage* storage=cvCreateMemStorage(0),*storage2=cvCreateMemStorage(0),
    *storage3=cvCreateMemStorage(0),*storage4=cvCreateMemStorage(0);
  
  // Paso a escala de grises de la imagen original.
  gray  = cvCreateImage( cvGetSize(candidato), IPL_DEPTH_8U, 1 );
  cvCvtColor(candidato, gray, CV_RGB2GRAY );
  
  // Binarización de la imagen anterior.
  binaria  = cvCreateImage( cvGetSize(candidato), IPL_DEPTH_8U, 1 );
  cvThreshold(gray,binaria,100,255, CV_THRESH_BINARY );
  
  // Se busca contorno exterior (CV_RETR_EXTERNAL) de la imagen.  
  piezas = cvFindContours(binaria, storage, &contour, sizeof(CvContour),
  CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);
  
  int forma_figura =0;
  
  // Si el contorno es único en la imagen 
  // (solo un contorno externo) se analiza.
  if( piezas == 1 ){ 
    
    cvDrawContours(binaria, contour,cvRealScalar(255),cvRealScalar(255),
    0,CV_FILLED,8);

    // Detectamos si se trata de un círculo
    circles = cvHoughCircles(binaria, storage4, CV_HOUGH_GRADIENT,
    2,600,10,11,90,300);      
    
    if(circles->total == 1){ // Si es un círculo...
      forma_figura=9;
      cvSetReal2D(DatosExtraidos,0,0,9);
    }
    else{ // Si no, se busca que otra figura pude ser.
      
      // Detección del polinomio APROXIMADO que encierra la figura.
      result = cvApproxPoly(contour, sizeof(CvContour), storage, 
      CV_POLY_APPROX_DP,15, 0);
      
      forma_figura = tipo_figura(result,candidato);
      cvSetReal2D(DatosExtraidos,0,0,forma_figura);
    }

    // Si la forma de la figura es alguna de las buscadas...
    if (forma_figura != 0){ 
      
      dibujo_interior = cvCreateImage(cvGetSize(candidato),IPL_DEPTH_8U,1);
      basura1 = cvCreateImage(cvGetSize(candidato),IPL_DEPTH_8U,1);
      basura2 = cvCreateImage(cvGetSize(candidato),IPL_DEPTH_8U,1);
      
      cvZero(dibujo_interior);
      cvZero(basura1);
      cvZero(basura2);
      
      // Se localizan los contronos interiores
      cvFindContours(binaria, storage2, &contour2, sizeof(CvContour),
      CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
      
      // Se dibujan:
      
      // Dibuja contorno externo.	
      cvDrawContours(basura1, contour2, CV_RGB(255,255,255),
      CV_RGB(255,255,255),1,1,8); 

      // Dibuja todos los contornos.
      cvDrawContours(basura2, contour2, CV_RGB(255,255,255), 
      CV_RGB(255,255,255),10,1,8); 
      
      // Se realiza la diferencia de ambas imágenes para quedarnos
      // con los contornos internos.
      cvSub(basura2,basura1,dibujo_interior,NULL);
      
      
      // Extracción  de características del dibujo interior.
      piezas = cvFindContours(dibujo_interior, storage3,
      &contour3, sizeof(CvContour),CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE);
      
      if(piezas > 0){ // Si existen piezas interiores
	CvSeq *contour_aux = contour3;
	for(; contour3 != 0; contour3 = contour3->h_next ){ 
          // Se calcula el área del objeto.
	  area = area + fabs(cvContourArea(contour3)); 
         
          // Se calcula el perimetro del objeto.
	  perimetro = perimetro + cvContourPerimeter(contour3);
 
          //Número de vertices.
	  result2 = cvApproxPoly(contour3, sizeof(CvContour), 
          storage3, CV_POLY_APPROX_DP,1.5, 0);

	  vertices = vertices + result2->total;                 
	}
	
	if(contour_aux!=NULL){
	  cvClearSeq(contour_aux);
	}
	
	// Eliminación de estructuras.
	cvReleaseImage( &basura2 );
	cvReleaseImage( &basura1 );
	cvReleaseImage( &candidato );
	cvReleaseImage( &color_seleccionado); 
	cvReleaseImage(&dibujo_interior);
	cvReleaseImage(&gray);
	cvReleaseImage(&binaria);
	
      }
    }
    
    cvShowImage( "Plantilla",candidato );
  }
  
  // Se devuelven los datos extraídos de la imagen.
  return *DatosExtraidos;
}


