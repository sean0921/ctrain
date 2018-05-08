## comlib test --- main Makefile

PREFIX	= ../

CC	= clang
CFLAGS	= -I../include
LDFLAGS	= -L../lib -ltest

OBJ	= main.o test1.o

BIN	= comlib

comlib: $(OBJ)
	$(CC) -o $(BIN) $(OBJ) $(LDFLAGS)

all: $(BIN)

install: $(BIN)
	install -c -m 0755 $(BIN) $(PREFIX)

clean:
	rm -fr *.a *.o $(BIN)

