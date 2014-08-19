all : homework3

homework3 : homework3.o leapfrog.o
	gcc -o homework3 homework3.o leapfrog.o -lm

homework3.o : homework3.c ./leapfrog/leapfrog.h
	gcc -c -std=c99 -Wall homework3.c ./leapfrog/leapfrog.h

leapfrog.o : ./leapfrog/leapfrog.c ./leapfrog/leapfrog.h
	gcc -c -std=c99 -Wall ./leapfrog/leapfrog.c ./leapfrog/leapfrog.h

clean :
	rm -rf *.o