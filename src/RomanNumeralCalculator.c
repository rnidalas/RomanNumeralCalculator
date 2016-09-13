#include <stdlib.h>
#include <string.h>
#include "RomanNumeralCalculator.h"

/* Function RomanNumeralAddition
 * Input parameters: 	numeral1 - pointer to first roman numeral
 * 						numeral2 - pointer to second roman numeral
 * Returns:				pointer to roman numeral sum of numeral1 and numeral2
 */
char* RomanNumeralAddition(const char* numeral1, const char* numeral2) {
	int value1 = convertRomanNumeralToInt(numeral1);
	int value2 = convertRomanNumeralToInt(numeral2);
	char* sum = convertIntToRomanNumeral( value1 + value2 );
	return sum;
}

/* Function RomanNumeralSubtraction
 * Input parameters: 	numeral1 - pointer to first roman numeral
 * 						numeral2 - pointer to second roman numeral
 * Returns:				pointer to roman numeral difference of numeral1 and numeral2
 */
char* RomanNumeralSubtraction(const char* numeral1, const char* numeral2) {
	int value1 = convertRomanNumeralToInt(numeral1);
	int value2 = convertRomanNumeralToInt(numeral2);
	char* dif = convertIntToRomanNumeral( value1 - value2 );
	return dif;
}

/* Function convertIntToRomanNumeral
 * Input parameters: 	integer value (in range [1,3999] to convert to Roman Numeral
 * Returns:				character pointer to roman numeral cstring
 */
char* convertIntToRomanNumeral(int value) {
	char* numeral = malloc(sizeof(char)*SIZE_OF_MAX_NUMERAL);
	int i=0;			// index into numeral to prevent buffer overflow
	
	/* Ensure numeral string initially empty */
	strcpy(numeral,"");

	if(value >= 1000) {
		/* for loop using i to prevent buffer overflow */
		for(; i<SIZE_OF_MAX_NUMERAL; i+=1) {
			strcat(numeral, "M");
			
			// Break if under value
			if((value -= 1000) < 1000)
				break;
		}
	}

	if(value >= 900) {
		// Check to prevent buffer overflow
		if(i < SIZE_OF_MAX_NUMERAL-3) {
			strcat(numeral, "CM");
			value -= 900;
		}
		i += 2;
	}

	if(value >= 500) {
		// Check to prevent buffer overflow
		if(i < SIZE_OF_MAX_NUMERAL-2) {
			strcat(numeral, "D");
			value -= 500;
		}
		i += 1;
	}

	if(value >= 400) {
		// Check to prevent buffer overflow
		if(i < SIZE_OF_MAX_NUMERAL-3) {
			strcat(numeral, "CD");
			value -= 400;
		}
		i += 2;
	}

	if(value >= 100) {
		/* for loop using i to prevent buffer overflow */
		for(; i<SIZE_OF_MAX_NUMERAL; i+=1) {
			strcat(numeral, "C");
			
			// Break if under value
			if((value -= 100) < 100)
				break;
		}
	}

	if(value >= 90) {
		// Check to prevent buffer overflow
		if(i < SIZE_OF_MAX_NUMERAL-3) {
			strcat(numeral, "XC");
			value -= 90;
		}
		i += 2;
	}

	if(value >= 50) {
		// Check to prevent buffer overflow
		if(i < SIZE_OF_MAX_NUMERAL-2) {
			strcat(numeral, "L");
			value -= 50;
		}
		i += 1;
	}
	
	if(value >= 40) {
		// Check to prevent buffer overflow
		if(i < SIZE_OF_MAX_NUMERAL-3) {
			strcat(numeral, "XL");
			value -= 40;
		}
		i += 2;
	}

	if(value >= 10) {
		/* for loop using i to prevent buffer overflow */
		for(; i<SIZE_OF_MAX_NUMERAL; i+=1) {
			strcat(numeral, "X");
			
			// Break if under value
			if((value -= 10) < 10)
				break;
		}
	}

	if(value >= 9) {
		// Check to prevent buffer overflow
		if(i < SIZE_OF_MAX_NUMERAL-3) {
			strcat(numeral, "IX");
			value -= 9;
		}
		i += 2;
	}
	
	if(value >= 5) {
		// Check to prevent buffer overflow
		if(i < SIZE_OF_MAX_NUMERAL-2) {
			strcat(numeral, "V");
			value -= 5;
		}
		i += 1;
	}
	
	if(value >= 4) {
		// Check to prevent buffer overflow
		if(i < SIZE_OF_MAX_NUMERAL-3) {
			strcat(numeral, "IV");
			value -= 4;
		}
		i += 2;
	}
	
	if(value > 0) {
		/* for loop using i to prevent buffer overflow */
		for(; i<SIZE_OF_MAX_NUMERAL; i+=1) {
			strcat(numeral, "I");
			
			// Break if numeral completed
			if((value -= 1) == 0)
				break;
		}
	}

	return numeral;
}

/* Function convertRomanNumeralToInt
 * Input parameters: 	Roman Numeral value (in range [1,3999] to convert to integer
 * Returns:				integer value of roman numeral
 * 
 * Function assumes well formatted input numeral
 */
int convertRomanNumeralToInt(const char* numeral) {
	int numeralLength = strlen(numeral);
	int value = 0, i = numeralLength-1;
	
	/* start with i value at end of numeral string and iterate back
	 * I values found at the end of numeral, loop for multiples */
	for(; i>=0; i--) {
		if(numeral[i] != 'I') {
			break;
		}
		value++;
	}
	
	/* Check for values of 4 and 5 */
	if(numeral[i] == 'V') {
		if(i > 0 && numeral[i-1] == 'I') {
			value += 4;
			i -= 2;
		} 
		else {
			value += 5;
			i--;
		}
	}
	
	/* Check for values of 10, loop for multiples */
	for(; i>=0; i--) {
		if(numeral[i] != 'X') {
			break;
		} 
		else if(i > 0 && numeral[i-1] == 'I') {
			value += 9;
			i--;
		} 
		else {
			value += 10;
		}
	}
	
	/* Check for values of 40 and 50 */
	if(numeral[i] == 'L') {
		if(i > 0 && numeral[i-1] == 'X') {
			value += 40;
			i -= 2;
		}
		else {
			value += 50;
			i--;
		}
	}
	
	/* Check for values of 90 and 100, loop for multiples */
	for(; i>=0; i--) {
		if(numeral[i] != 'C') {
			break;
		} 
		else if(i > 0 && numeral[i-1] == 'X') {
			value += 90;
			i--;
		} 
		else {
			value += 100;
		}
	}
	
	/* Check for values of 400 and 500 */
	if(numeral[i] == 'D') {
		if(i > 0 && numeral[i-1] == 'C') {
			value += 400;
			i -= 2;
		}
		else {
			value += 500;
			i--;
		}
	}
	
	/* Check for values of 900 and 1000, loop for multiples */
	for(; i>=0; i--) {
		if(numeral[i] != 'M') {
			break;
		} 
		else if(i > 0 && numeral[i-1] == 'C') {
			value += 900;
			i--;
		} 
		else {
			value += 1000;
		}
	}
	
	return value;
}
