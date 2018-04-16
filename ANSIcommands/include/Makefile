CFLAGS = gcc
LIBFLAGS = ar rcvs 

default: ANSIcommands.h
	$(CFLAGS) -c -static ANSIcommands.c
	$(LIBFLAGS) libANSIcommands.a ANSIcommands.o
