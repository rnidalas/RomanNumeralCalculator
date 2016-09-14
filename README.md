# RomanNumeralCalculator

Project comes with src/ and test/ directories. Both of these
directories have a respective makefile. The makefile in the
top directory will make both. In order to run the test suite
against the Roman Numeral Calculator, run "make check" in the
top directory. This compiles an executable named "check" in the
test/ directory. The unit testing framework will output to the
terminal the results of the unit tests.

Test file test/RomanNumeralCalculatorCheck.c takes some time to
run due to some looping tests that iterate through all possible
addition, subtraction, and conversions that are handled in the
library. If faster testing is desired, the looping test cases are
grouped together and may be commented out. If thoroughness in
testing is desired, these should be left to run.

Project is easily set for possible future expansion for a greater
domain of Roman Numerals by use of the table lookups, by expanding
the tables in the header file. Additional tests should be written
before changes implemented.
