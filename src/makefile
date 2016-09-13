# list of object files
OBJECTS = RomanNumeralCalculator.o

# compiler choice
CC = gcc

# compiler flags
CFLAGS = -g -Wall

# targets
all: main

main: $(OBJECTS) main.c
	$(CC) $(CFLAGS) -o main main.c $(OBJECTS)

RomanNumeralCalculator.o: RomanNumeralCalculator.h

.PHONY: clean
clean:
	$(RM) main $(OBJECTS)
