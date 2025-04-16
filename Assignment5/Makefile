CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pg
OBJS = main.o max_sub_arr.o

all: prog

prog: $(OBJS)
	$(CC) $(CFLAGS) -o prog $(OBJS)

main.o: main.c max_sub_arr.h
	$(CC) $(CFLAGS) -c main.c

max_sub_arr.o: max_sub_arr.c max_sub_arr.h
	$(CC) $(CFLAGS) -c max_sub_arr.c


clean:
	rm -f *.o prog gmon.out profile.txt

.PHONY: all clean run