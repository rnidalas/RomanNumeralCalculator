# list of object files
objects = RomanNumeralCalculator.o

# compiler choice
CC = gcc

# compiler flags
CFLAGS = -g -Wall

# targets
all: $(objects)
	$(CC) $(CFLAGS) -o main main.c $(objects)

RomanNumeralCalculator.o:

.PHONY: clean
clean:
	$(RM) main $(objects)
