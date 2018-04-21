CFLAGS = g++
LIBFLAGS = ar rcvs 

default: ANSIcommands.hpp
	$(CFLAGS) -c ANSIcommands.cpp
	$(LIBFLAGS) libANSIcommands.a ANSIcommands.o
	mv libANSIcommands.a ../lib/libANSIcommands.a
