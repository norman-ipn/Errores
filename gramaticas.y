%{
  #include <stdio.h>
	#include <stdlib.h>
  	#include <math.h>
	#include "libreria.h"	

	extern int yylex(void);
	extern char *yytext;
	extern int linea;
	extern FILE *yyin;
	void yyerror(char *s);

	FILE *fp;

%}

%union
{
  int entero;
}

%start PROGRAMA

%token DECLARACIONES_VARIABLES

%%
						   		     
PROGRAMA: 	DECLARACIONES_VARIABLES {escribir_archivo (fp,DECLARACIONES_VARIABLES);}					            		      									       ;
	
%%
void yyerror(char *s)
{
  	escribir_archivo (fp,"ERROR");
}
int main(int argc,char **argv)
{
	if ( argc > 0 )
	{    	
		yyin = fopen( argv[0], "rt" );  
		if (yyin==NULL)
		{
			printf("error");	
			exit(1);
		}
		fp = fopen("codigo_corregido.c", "w");
		yyparse();
	}

	fclose(fp);
	return 0;
}