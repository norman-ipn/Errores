#include <stdio.h>
#include <math.h>
#include <string.h>
#define MIN(x,y) ((x) < (y) ? (x) : (y))

int d[100][100];

   void distancia_levenstein(char s[],char t[]);

   int main(int argc,char *argv[])
   {
    if(argc>1&&argc<4)
    {
     distancia_levenstein(argv[1],argv[2]);
    }
    else
    {
     printf("Tiene que insertar 2 palabras ejemplo: ./a.out palabra1 palabra2\n");
    }
    return 0;
   }

	void distancia_levenstein(char s[],char t[])
	{
     int i,j,m,n,temp,tracker;
	    m = strlen(s);
	    n = strlen(t);

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
	    printf("the Levinstein distance is %d\n",d[n][m]);
	}
