## comlib test --- main Makefile

CC	= clang
CFLAGS	= -I../include
LDLAGS	=

OBJ	= main.o test1.o

BIN	= main

all:    $(OBJ)
	$(CC) -o $(BIN) $(OBJ) 

clean:
	rm -fr *.a *.o $(BIN)

