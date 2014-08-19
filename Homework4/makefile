all : homework1

homework1 : homework1.o ./Integration/integration.o ./Root_Find/root_find.o
	gcc -o homework1 homework1.o ./Integration/integration.o  ./Root_Find/root_find.o -lm

homework1.o : homework1.c
	gcc -c -std=c99 -Wall homework1.c ./Integration/integration.h ./Root_Find/root_find.h

./Integration/integration.o : ./Integration/integration.c
	gcc -c -std=c99 -Wall ./Integration/integration.c ./Integration/integration.h

./Root_Find/root_find.o : ./Root_Find/root_find.c
	gcc -c -std=c99 -Wall ./Root_Find/root_find.c ./Root_Find/root_find.h
clean :
	rm -rf *.o