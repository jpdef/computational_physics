all : homework6

homework6 : homework6.o ./Integration/integration.o
	gcc -o homework6 homework6.o ./Integration/integration.o -lm

homework6.o : homework6.c 
	gcc -c -std=c99 -Wall homework6.c ./Integration/integration.h

./Integration/integration.o : ./Integration/integration.c
	gcc -c -std=c99 -Wall ./Integration/integration.c ./Integration/integration.h
