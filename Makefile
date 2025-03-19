
CC=gcc
CFLAGS=-O3 -Wall -Werror
LDFLAGS=-Lbin -ltvar

.PHONY: all clean dynamic static install

all: main

main: main.c bin/libtvar.a
	$(CC) $(CFLAGS) -o main main.c $(LDFLAGS)

dynamic: bin/libtvar.so

bin/libtvar.so: bin/probability.o bin/combinations.o
	$(CC) -shared -o $@ $^

bin/probability.o: src/probability.c include/probability.h
	$(CC) $(CFLAGS) -fPIC -o $@ -c $<

bin/combinations.o: src/combinations.c include/combinations.h
	$(CC) $(CFLAGS) -fPIC -o $@ -c $<

static: bin/libtvar.a

bin/libtvar.a: bin/probability.o bin/combinations.o
	ar rcs $@ $^

install: static dynamic
	mkdir -p /usr/include/tvar
	install include/combinations.h /usr/include/tvar/combinations.h
	install include/macros.h /usr/include/tvar/macros.h
	install include/pmath.h /usr/include/tvar/pmath.h
	install include/types.h /usr/include/tvar/types.h
	install include/vec.h /usr/include/tvar/vec.h
	install bin/libtvar.a /usr/lib/libtvar.a
	install bin/libtvar.so /usr/lib/libtvar.so

clean:
	rm -f bin/*.o bin/libtvar.a bin/libtvar.so main
