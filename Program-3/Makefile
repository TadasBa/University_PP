Programa: main.o function.o
	gcc main.o function.o -o Programa

main.o: main.c
	gcc -c main.c

function.o: function.c header.h
	gcc -c function.c

clean:
	rm *.o Programa