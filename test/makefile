# list of object files
objects = RomanNumeralCalculatorCheck.o

# compiler
CC = gcc

# compiler flags
CFLAGS = -g -Wall

# targets
all: check

check: $(objects)
	$(CC) $(CFLAGS) -o check $(objects) `pkg-config --cflags --libs check`

RomanNumeralCalculatorCheck.o:

.PHONY: clean
clean:
	$(RM) check $(objects)
