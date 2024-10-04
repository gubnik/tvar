CC=gcc
CFLAGS=-O3 -Wall -Werror
LDFLAGS=combinations.o

.PHONY: %.o main

main: main.c combinations.o
	$(CC) $(CFLAGS) -o main main.c $(LDFLAGS)

%.o: src/%.c include/%.h 
	$(CC) $(CFLAGS) -o $@ -c $<
