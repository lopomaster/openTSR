IplImage* seleccion_colorHSV(IplImage* img ){

  // Declaración de variables
  IplImage *hsv_Image, *mono_Image;
  int height , width , step , channels;
  int step_mono , channels_mono;  
  uchar *data_hsv , *data_mono;


  // Declaración de los valores umbral.
  int hupper=175,hlower=110,Saturation=60,Brightness=90,Erode=1,Dilate=1;

  int hupper2=35,hlower2=0,Saturation2=60,Brightness2=60,Erode2=0,Dilate2=3;   
  //

  // Se crean dos imágenes del tamaño de la imagen fuente.
  hsv_Image = cvCreateImage( cvGetSize(img), 8, 3 );
  mono_Image = cvCreateImage( cvGetSize(img), 8, 1 );
  // Se inicializan a cero.
  cvZero(hsv_Image);
  cvZero(mono_Image);

  // Obtenemos atributos de la imagen HSV.
  height     = hsv_Image->height;
  width      = hsv_Image->width;
  step       = hsv_Image->widthStep/sizeof(uchar);
  channels   = hsv_Image->nChannels;
  step_mono   = mono_Image->widthStep/sizeof(uchar);
  channels_mono = mono_Image->nChannels;

  // Convertimos imagen de entrada de RGB a HSV.
  cvCvtColor(img,hsv_Image,CV_RGB2HSV);

  // Obtenemos los valores RGB de la Imagen.
  data_hsv = (uchar *)hsv_Image->imageData;
  data_mono = (uchar *)mono_Image->imageData;

  //Recorremos la imagen.
  for(int i = 0; i <height; i++ ) {
    for(int j = 0; j <width; j++ ) {

        // Segmentamos la imagen mediante los valores umbrales 
        // correspondientes al color rojo y azul.
        if (((data_hsv[i*step+j*channels])>= hlower) &&
            ((data_hsv[i*step+j*channels]) <= hupper) && 
            (data_hsv[i*step+j*channels+1]>= Saturation ) && 
            (data_hsv[i*step+j*channels+2]>= Brightness) || 
            ((data_hsv[i*step+j*channels])>= hlower2) &&
            ((data_hsv[i*step+j*channels]) <= hupper2) && 
            (data_hsv[i*step+j*channels+1]>= Saturation2 ) && 
            (data_hsv[i*step+j*channels+2]>= Brightness2)){

             // Coloreamos el píxel deseado en la 
             // imagen de salida.
             data_mono[i*step_mono+j*channels_mono] = 1;
      }
    }
  }

  // Se aplica una erosión y una dilatación,
  // para la eliminacion de píxeles sueltos.
  cvErode(mono_Image,mono_Image,0,Erode);
  cvDilate( mono_Image,mono_Image,0,Dilate);

  // Eliminación de estructuras innecesarias.
  cvReleaseImage(&hsv_Image);

  // Devolución de la imagen de salida.
  return mono_Image;
}

