CC=gcc
CFLAGS=-Wall -pedantic

ksamp: ksamp.o
	$(CC)	-o ksamp ksamp.o
