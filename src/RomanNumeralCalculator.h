#ifndef ROMANNUMERALCALCULATOR_H
#define ROMANNUMERALCALCULATOR_H

// Constants
// Size of buffer returned holding roman numeral character - at least 1 greater than max length
static const int SIZE_OF_MAX_NUMERAL = 20;
static const char* numeralTable[] = 
		{ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
static const int numeralValueTable[] = 
		{1000,  900, 500,  400, 100,   90,  50,   40,  10,    9,   5,    4,   1 };

// Library functions
char*	convertIntToRomanNumeral(int value);
int		convertRomanNumeralToInt(const char* numeral);

char*	RomanNumeralAddition(const char* numeral1, const char* numeral2);
char*	RomanNumeralSubtraction(const char* numeral1, const char* numeral2);

#endif /* ROMANNUMERALCALCULATOR_H */
