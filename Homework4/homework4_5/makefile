all : homework5

homework5 : homework5.o heapsort.o
	gcc -o homework5 homework5.o heapsort.o -lm

homework5.o : homework5.c heapsort.h
	gcc -c -std=c99 -Wall homework5.c heapsort.h

heapsort.o : heapsort.c heapsort.h
	gcc -c -std=c99 -Wall heapsort.c heapsort.h