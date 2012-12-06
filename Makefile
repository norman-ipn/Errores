run: a.out
  ./a.out programa.c

a.out: lex.yy.c 
	gcc lex.yy.c libreria.o -o a.out gramaticas.tab.c -lfl


lex.yy.c: expresiones.l
	flex expresiones.l
	gcc -c -o libreria.o libreria.c
	bison -d gramaticas.y

clean: 
	rm libreria.o
	rm lex.yy.c
	rm gramaticas.tab.h
	rm gramaticas.tab.c
	rm a.out
	rm codigo_corregido.c		
