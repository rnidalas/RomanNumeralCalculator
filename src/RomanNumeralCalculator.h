#ifndef ROMANNUMERALCALCULATOR_H
#define ROMANNUMERALCALCULATOR_H

// Constants
// Size of buffer returned holding roman numeral character - at least 1 greater than max length
static const int SIZE_OF_MAX_NUMERAL = 16;

// Library functions
char*	convertIntToRomanNumeral(int value);
int		convertRomanNumeralToInt(const char* numeral);

char*	RomanNumeralAddition(const char* numeral1, const char* numeral2);

#endif /* ROMANNUMERALCALCULATOR_H */
