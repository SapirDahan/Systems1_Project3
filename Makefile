CC = gcc
CFLAGS = -Wall

.PHONY: all clean

all: StrList

StrList: main.o StrList.o
	$(CC) $(CFLAGS) -o StrList main.o StrList.o

main.o: main.c StrList.h
	$(CC) $(CFLAGS) -c main.c -o main.o

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c -o StrList.o

clean:
	rm -f *.o StrList