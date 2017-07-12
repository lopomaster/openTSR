// ALGORITMO DE IDENTIFICACIÓN

// Carga de imagen referencia o plantilla.
tpl = cvLoadImage( directorio, CV_LOAD_IMAGE_COLOR );

// Cáculo de ancho y alto de la imagen resultado.
width  = identificar->width  - tpl->width + 1;
height = identificar->height - tpl->height + 1;

// Se crea la imagen donde se almacenará el resultado de la comparación.
res = cvCreateImage( cvSize( width, height ), IPL_DEPTH_32F, 1 );

// Se realiza la comparación:
cvMatchTemplate(identificar, tpl, res, CV_TM_SQDIFF_NORMED);

for( i = 0 ; i < height ; i++) {
  for( j = 0 ; j < width ; j++) {

    // sacamos el elemento:
    s = cvGet2D( res, i, j );
    
    // Si el valor se localiza entre el rango establecido...
    if( s.val[0] <= umbral ) {
      // Dibujamos el contorno al objeto identificado ENCONTRADO!
      fprintf( stderr, "¡50 m/h!");
      
      pt1.x = rect.x;
      pt1.y = rect.y;
      pt2.x = rect.x + rect.width;
      pt2.y = rect.y + rect.height;
      
      // Se dibuja el rectángulo que encierra al objeto.
      cvRectangle(img,pt1,pt2,CV_RGB(0,255,0),3,8,0);
    }
  }
 }
