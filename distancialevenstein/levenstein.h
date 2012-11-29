#ifndef __LEVENSTEIN_H__
#define __LEVENSTEIN_H__

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

   int distancia_levenstein(char s[],char t[]);
   void total_palabras(FILE *pFile,int *num);
   void llenar_distancias(FILE *pFile,int num [], char s[],char **pal);
   void aproximacion(int num[],int x,char **pal);

#endif
