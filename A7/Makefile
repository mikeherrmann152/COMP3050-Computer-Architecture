CC = gcc
CFLAGS = -c -g -Wall -Werror -pedantic
OBJ = main.o

all: a7

a7: main.o
	$(CC) -o a7 $(OBJ)

$(OBJ): main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm -f a7 main.o
