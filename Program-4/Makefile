Programa: test.o functions.o
	gcc test.o functions.o -o Programa

main.o: test.c
	gcc -c test.c

functions.o: functions.c header.h
	gcc -c functions.c

clean:
	rm *.o Programa