CC=gcc
CFLAGS=-O3 -Wall -Werror
LDFLAGS=-l:libtvar.o

.PHONY: %.o main

main: main.c combinations.o
	@$(CC) $(CFLAGS) -o main main.c $(LDFLAGS)

static:
	@$(CC) $(CFLAGS) -o combinations.a -c src/combinations.c

install: static combinations.o
	@mkdir -p /usr/include/tvar
	@install include/combinations.h /usr/include/tvar/combinations.h
	@install include/macros.h /usr/include/tvar/macros.h
	@install include/pmath.h /usr/include/tvar/pmath.h
	@install include/types.h /usr/include/tvar/types.h
	@install include/vec.h /usr/include/tvar/vec.h
	@install combinations.a /usr/lib/libtvar.a
	@install combinations.o /usr/lib/libtvar.o

%.o: src/%.c include/%.h 
	@$(CC) $(CFLAGS) -o $@ -c $<
