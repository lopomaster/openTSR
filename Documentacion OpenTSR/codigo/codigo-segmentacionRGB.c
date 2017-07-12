IplImage* segmentacion_RGB(IplImage* img){

  // Declaración de variables.
  int altura,anchura,anchura_fila,canales;
  uchar *data;
  int i,j;
  
  // Recopilación de los datos de la imagen de entrada.
  altura = img->height;
  anchura = img->width;
  anchura_fila = img->widthStep;
  canales = img->nChannels;
  data = (uchar *)img->imageData;
     
  // Declaración e inicialización a cero de la imagen de salida.
  IplImage* img_selec_color;  
  img_selec_color = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U,1);
  cvZero(img_selec_color);

  // Recorrido de la imagen de entrada.
  for(i=0;i<altura;i++){ 
    for(j=0;j<anchura;j++){
      
      // Selección de tonalidades rojas.
      if ((data[i*anchura_fila+j*canales + 2] > 80) &&
	  !((data[i*anchura_fila+j*canales + 0] > 
            data[i*anchura_fila+j*canales + 2]/2) || 
	   (data[i*anchura_fila+j*canales + 1] > 
            data[i*anchura_fila+j*canales + 2]/2))) {
    
        //Activación de los píxeles que cumplen la condición de color fijada.
	img_selec_color->imageData[ img_selec_color->widthStep * i + j * 1]=1;
      }
    }
  }
  
  // Erosión para la eliminación de píxeles sueltos.
  cvErode(img_selec_color, img_selec_color,NULL,1);
  
  // Dilatación para expandir los objetos de la imagen.
  cvDilate(img_selec_color,img_selec_color,NULL,3);

  // Se devuelve la imagen resultante.	     
  return img_selec_color;
}

