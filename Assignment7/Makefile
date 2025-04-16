CC=gcc
CFLAGS=-Wall -Wextra -O2

all: add2PB findPhone

add2PB: add2PB.c
	$(CC) $(CFLAGS) -o add2PB add2PB.c

findPhone: findPhone.o logger.o
	$(CC) $(CFLAGS) -o findPhone findPhone.o logger.o

findPhone.o: findPhone.c logger.h
	$(CC) $(CFLAGS) -c findPhone.c -o findPhone.o

logger.o: logger.c logger.h
	$(CC) $(CFLAGS) -c logger.c -o logger.o

clean:
	rm -f *.o findPhone add2PB findPhone.log




