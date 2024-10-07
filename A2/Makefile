all: ps2
ps2: main.o
	g++ main.o -o hw2 -Wall -ansi -pedantic -Werror
main.o: main.c
	g++ -c -Wall -ansi -pedantic -Werror main.c
clean:
	rm *.o hw2
