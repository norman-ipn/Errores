/* scanner for a toy Pascal-like language*/
%{
/*need this for the call to atof() below*/
#include "levenstein.h"
#include<math.h>
FILE *pFile=NULL;
%}

PALABRAS        [a-z|A-Z|0-9]* 
LIBRERIAS       #[a-z]*
LIBRERIAS2      [a-z]*"."h
VARIABLES       void|int|float|boolean|char|string|array|long|short|byte
GRUPOS          "{"|"}"|"("|")"|"["|"]"|"<"|">"
COMENTARIOS     "/*"[a-z|A-Z|" "|0-9|\n]*"*/"|"//"[a-z|A-Z|" "|0-9]*


%%

{LIBRERIAS}+   total_palabras(pFile,num); 

{LIBRERIAS2}+   total_palabras(pFile,num);

{VARIABLES}+    total_palabras(pFile,num);

{GRUPOS}+       total_palabras(pFile,num);

{COMENTARIOS}+  total_palabras(pFile,num);






%%
int main( int argc, char **argv )
   {
   fp = fopen("correciondeerrores.txt","r");
   ++argv, --argc; /*skip over program name*/	
   yylex();   
   fclose(fp);
   }
