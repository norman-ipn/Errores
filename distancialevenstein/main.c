// Codigo Distancia de Levenstein, usando un diccionario de datos en .txt

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

   int main(int argc,char *argv[])
   {
    if(argc>1&&argc<3)
    {
     FILE * pFile;
     int num=0;
     int *levenstein;
     char **listaPalabras;

     total_palabras(pFile,&num);
     levenstein=(int*)malloc((num+1)*sizeof(int));
     listaPalabras  = (char**) malloc(sizeof(char*) * (num+1) * 50);
    
     llenar_distancias(pFile,levenstein,argv[1],listaPalabras);
     aproximacion(levenstein,num,listaPalabras);
     return 0;

    }
    else
    {
     printf("Tiene que insertar 1 palabras ejemplo: ./a.out palabra\n");
    }
    return 0;
   }
