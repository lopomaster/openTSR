int Clasificador(CvMat DatosEntrenamiento, CvMat DatosCandidato){

  // Aplicación del algoritmo KNN.
  
  const int K = 1; // Se fija valor de K. (K=1, vecino más cercano).
  int solucion;    // Solución
  
  // Se crea e inicializa el vector de clases, cada elemento columna de 
  // DatosEntrenamiento es una clase
  
  int clases[elementos];	
  CvMat  Clases = cvMat(elementos,1, CV_32FC1,clases);
  
  for (int a=0;a<DatosEntrenamiento.rows;a++){
    for (int b=0;b<Clases.cols;b++){
      // Se añaden los identificadores.
      cvSetReal2D(&Clases,a,b,a+1);
    }
  }
  
  // Se crea el clasificador.
  CvKNearest knn( &DatosEntrenamiento, &Clases, 0, false, K );
  CvMat* nearests = cvCreateMat( 1, K, CV_32FC1);
  
  // Se estima el vecino más cercano.
  solucion = knn.find_nearest(&DatosCandidato,K,0,0,nearests,0);
   
  // Se devuelve el resultado.
  return  solucion;
}
