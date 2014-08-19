all : homework4

homework4 : homework4.o rk4.o
	gcc -o homework4 homework4.o rk4.o -lm

homework4.o : homework4.c 
	gcc -c -std=c99 -Wall homework4.c rk4.h

rk4.o : rk4.c
	gcc -c -std=c99 -Wall rk4.c rk4.h
