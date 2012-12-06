/--------------------libreria.h
#ifndef __FUNCIONES_H__ 
#define __FUNCIONES_H__
#include<stdio.h> 

int escribir_archivo (FILE*fp,char *cadena); 

#endif



/--------------------libreria.c
#include "libreria.h"          
#include<stdio.h>

int escribir_archivo (FILE*fp,char *cadena)
{
  fprintf(fp,"%s",cadena);	
	fprintf( fp,"\n");
	return 0;
}


