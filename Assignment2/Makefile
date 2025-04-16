CC = gcc
CFLAGS = -std=c99 -Wall
LDFLAGS = -lm

TARGET = mandelbrot
SRC = mandelbrot.c

.PHONY: all run clean help

all: $(TARGET)


$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)

