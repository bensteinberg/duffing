CC=gcc
CFLAGS=-I.
DEPS=equation.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

duffing-rk4: solve.o duffing.o rk4.o
	$(CC) -o duffing-rk4 solve.o duffing.o rk4.o

.PHONY: clean

clean:
	rm -f *.o core a.out duffing-rk4
