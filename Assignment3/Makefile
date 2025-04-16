CC = gcc
CFLAGS = -Wall -std=c99 -fPIC
LDFLAGS = -shared -lm
TARGET = main
LIB = libmandelbrot.so

.PHONY: all clean run

all: $(LIB) $(TARGET)

$(LIB): mandelbrot.c mandelbrot.h
	$(CC) $(CFLAGS) -c mandelbrot.c
	$(CC) -o $(LIB) mandelbrot.o $(LDFLAGS)

$(TARGET): main.c mandelbrot.h $(LIB)
	$(CC) -std=c99 -Wall -o $(TARGET) main.c -L. -lmandelbrot -Wl,-rpath=. -lm


run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o  $(TARGET)
