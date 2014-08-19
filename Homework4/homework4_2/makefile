all : homework2

homework2 : homework2.o ./leapfrog/leapfrog.o ./rk4/rk4.o
	gcc -o homework2 homework2.o ./leapfrog/leapfrog.o ./rk4/rk4.o -lm

homework2.o : homework2.c ./leapfrog/leapfrog.h ./rk4/rk4.h
	gcc -c -std=c99 -Wall homework2.c ./leapfrog/leapfrog.h ./rk4/rk4.h

./leapfrog/leapfrog.o : ./leapfrog/leapfrog.c
	gcc -c -std=c99 -Wall ./leapfrog/leapfrog.c ./leapfrog/leapfrog.h

./rk4/rk4.o : ./rk4/rk4.c
	gcc -c -std=c99 -Wall ./rk4/rk4.c ./rk4/rk4.h
clean :
	rm -rf *.o