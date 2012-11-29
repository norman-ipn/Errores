run: a.out
	./a.out n
a.out: levenstein.o
	gcc main.c levenstein.o
levenstein.o: 
	gcc -c levenstein.c -ll
clean:
	rm levenstein.o
	rm a.out
