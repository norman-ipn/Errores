#include "levenstein.h"

#define MIN(x,y) ((x) < (y) ? (x) : (y))

int distancia_levenstein(char s[],char t[])
	{
     int i,j,m,n,temp,tracker;
	    m = strlen(s);
	    n = strlen(t);
       int d[100][100];

	    for(i=0;i<=m;i++)
	        d[0][i] = i;
	    for(j=0;j<=n;j++)
	        d[j][0] = j;

	    for (j=1;j<=m;j++)
	    {
	        for(i=1;i<=n;i++)
	        {
	            if(s[i-1] == t[j-1])
	            {
	                tracker = 0;
	            }
	            else{
	                tracker = 1;
	            }
	            temp = MIN((d[i-1][j]+1),(d[i][j-1]+1));
	            d[i][j] = MIN(temp,(d[i-1][j-1]+tracker));
	        }
	    }
        return d[n][m];
	}

   void total_palabras(FILE *pFile,int *num)
   {
     char  palabra[50];

     pFile = fopen ("diccionario.txt","r");

     while (fgets(palabra,50,pFile)!=NULL) {
          *num=*num+1;
     }
     fclose(pFile);
     return;
   }

   void llenar_distancias(FILE *pFile,int num [], char s[],char **pal)
   {
     char  palabra[50];
     int n=0;
     pFile = fopen ("diccionario.txt","r");

     while (fgets(palabra,50,pFile)!= NULL) { //usaba fscanf, ya que es el que siempre he usado en windows, al correrlo en linux, me marcaba error por lo cual recurri a usar fgets, pero como tengo entendido fgets me lee tambien el caracter de salto de linea, por lo cual gracias a ese caracter la distancia de levenstein no se cumple, ya que siempre dara un excedente de +2, no se me ocurre como solucionarlo
        num[n]=distancia_levenstein(s,palabra);
        pal[n]=palabra;     //no se por que no guarda la palabra en el lugar del apuntador, lo imprime dentro de esta funcion solamente, que tengo que hacer para que se mantenga el valor
        printf("%i -- %s ---%i\n",n,palabra,num[n]);
        n++;
     }
     fclose(pFile);
     return;
   }
   
   void aproximacion(int num[],int x,char **pal)
   {
     int y=0;
     int aprox=100;
     int *posiciones=(int *)malloc(x);
     int z=0;
     
     for(y=0;y<x;y++)
     { 
       //printf("--%i < %i\n",num[y],aprox);
       if(num[y]<aprox)
       {
        aprox=num[y];
       }
     }
     
     for(y=0;y<x;y++)
     {
       if(num[y]==aprox)
       {
         posiciones[z]=y;
         z++;
       }
     }
    
     if(aprox==0)
     {
      printf("La palabra pertenece al lenguaje C\n");
     }
     else
     {
     printf("La palabra no pertenece al lenguaje C, pero se aproxima a: \n");
       for(y=0;y<z;y++)
       {
         printf("%i \n",posiciones[y]);
         //printf("%i -- %s \n",posiciones[y],pal[posiciones[y]]); aqui es donde imprime la palabra, imprime la posicion, pero no el valor que tiene el apuntador que llene con todas las palabras
       }
     }
     return;
   }
  

