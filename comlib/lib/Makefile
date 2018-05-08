CC	?= clang

SRC	= test2.c test3.c

OBJ	= test2.o test3.o

all:	libtest.a
install: libtest.a

libtest.a: $(OBJ)
	ar rv $@ $?
	ranlib $@

clean:
	rm -fr *.a *.o *~
