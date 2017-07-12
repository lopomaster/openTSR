//Localiza la forma de la figura a partir de un polígono.

int tipo_figura(CvSeq* result,IplImage* plantilla){  

  double PI = 3.1415;

  double A,B,C,D,E,F,G,H;

  // CUADRADO, cuatro vértices, área superior a 1000 
  // y estructura convexa. En un conjunto convexo se puede ir
  // de cualquier punto a cualquier otro en vía recta, sin salir del mismo.
  // Formalmente: para todo (A,B) pertenece a C ->  [A,B] pertenece a C.
  if(result->total==4 && fabs(cvContourArea(result,CV_WHOLE_SEQ))
   > 1000 && cvCheckContourConvexity(result))  
    {
      CvPoint *pt[4];

      // Extraemos los puntos de los vértices.
      for(int i=0;i<4;i++)
	pt[i] = (CvPoint*)cvGetSeqElem(result, i);

      // Procedemos a calcular el ángulo de los 4 vértices 
      // (condición: 90 grados cada uno).
      A = (acos(angulo(pt[3],pt[1],pt[0])) * 180)/ PI; 
      B = (acos(angulo(pt[0],pt[2],pt[1])) * 180)/ PI;
      C = (acos(angulo(pt[3],pt[1],pt[2])) * 180)/ PI; 
      D = (acos(angulo(pt[0],pt[2],pt[3])) * 180)/ PI;

      if( A < 92 && A > 88 && B < 92 && B > 88 &&  C < 92 
          && C > 88 &&  D < 92 && D > 88 ){ 
	// Cuadrado detectado.
	return 4;
      }
    }

  // OCTÓGONO
  if(result->total==8 && fabs(cvContourArea(result,CV_WHOLE_SEQ))
   > 1000 && cvCheckContourConvexity(result)) 
    {

      // Extraemos los puntos de los vértices
      CvPoint *pt[8];
      for(int i=0;i<8;i++)
	pt[i] = (CvPoint*)cvGetSeqElem(result, i);

      A = (acos(angulo(pt[7],pt[1],pt[0])) * 180)/ PI; 
      B = (acos(angulo(pt[0],pt[2],pt[1])) * 180)/ PI;
      C = (acos(angulo(pt[3],pt[1],pt[2])) * 180)/ PI; 
      D = (acos(angulo(pt[4],pt[2],pt[3])) * 180)/ PI;
      E = (acos(angulo(pt[5],pt[3],pt[4])) * 180)/ PI;
      F = (acos(angulo(pt[6],pt[4],pt[5])) * 180)/ PI;
      G = (acos(angulo(pt[7],pt[5],pt[6])) * 180)/ PI;
      H = (acos(angulo(pt[0],pt[6],pt[7])) * 180)/ PI;

      if( A < 47 && A > 43 && B < 47 && B > 43
          &&  C < 47 && C > 43 &&  D < 47 &&
          D > 43 && E < 47 && E > 43 &&  F < 47
          && F > 43 && G < 7 && G > 43 && H < 47
          && H > 43){ 

	// Octógono detectado.
	return 8;
      }
	   
    } 
         
  // TRIANGULO
  if(result->total==3) 
    {

      // Extraemos los puntos de los vértices		  
      CvPoint *pt[3];
      for(int i=0;i<3;i++)
	pt[i] = (CvPoint*)cvGetSeqElem(result, i);

      A = (acos(angulo(pt[2],pt[1],pt[0])) * 180)/ PI;
      B = (acos(angulo(pt[0],pt[2],pt[1])) * 180)/ PI;
      C = (acos(angulo(pt[0],pt[1],pt[2])) * 180)/ PI; 

      if( A < 126 && A > 115 && B < 126 && B > 115 &&
          C < 126 && C > 115 ){ 
	// Triángulo detectado.
	return 3;
      }
	  
    }

  // Forma no identificada.
  return 0;
}
