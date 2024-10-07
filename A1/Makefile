all: ps1
ps1: main.o
	g++ main.o -o hw1 -Wall -ansi -pedantic -Werror
main.o: main.c
	g++ -c -Wall -ansi -pedantic -Werror main.c
clean:
	rm *.o hw1
