# list of object files
OBJECTS = RomanNumeralCalculatorCheck.o

# compiler
CC = gcc

# compiler flags
CFLAGS = -g -Wall

# targets
all: check

check: $(OBJECTS) ../src/RomanNumeralCalculator.o
	$(CC) $(CFLAGS) -o check $(OBJECTS) ../src/RomanNumeralCalculator.o `pkg-config --cflags --libs check`

RomanNumeralCalculatorCheck.o:

.PHONY: clean
clean:
	$(RM) check $(OBJECTS)
