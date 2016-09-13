#include <stdlib.h>
#include <string.h>
#include "RomanNumeralCalculator.h"

/* Function convertIntToRomanNumeral
 * Input parameters: 	integer value (in range [1,3999] to convert to Roman Numeral
 * Returns:				character pointer to roman numeral cstring
 */
char* convertIntToRomanNumeral(int value) {
	char* numeral = malloc(sizeof(char)*SIZE_OF_MAX_NUMERAL);
	int i=0;			// index into numeral to prevent buffer overflow

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
		if(i < 7) {
			strcat(numeral, "CM");
			value -= 900;
		}
		i += 2;
	}

	if(value >= 500) {
		// Check to prevent buffer overflow
		if(i < 8) {
			strcat(numeral, "D");
			value -= 500;
		}
		i += 1;
	}

	if(value >= 400) {
		// Check to prevent buffer overflow
		if(i < 7) {
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
		if(i < 7) {
			strcat(numeral, "XC");
			value -= 90;
		}
		i += 2;
	}

	if(value >= 50) {
		// Check to prevent buffer overflow
		if(i < 8) {
			strcat(numeral, "L");
			value -= 50;
		}
		i += 1;
	}
	
	if(value >= 40) {
		// Check to prevent buffer overflow
		if(i < 7) {
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
		if(i < 7) {
			strcat(numeral, "IX");
			value -= 9;
		}
		i += 2;
	}
	
	if(value >= 5) {
		// Check to prevent buffer overflow
		if(i < 8) {
			strcat(numeral, "V");
			value -= 5;
		}
		i += 1;
	}
	
	if(value >= 4) {
		// Check to prevent buffer overflow
		if(i < 7) {
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
int convertRomanNumeralToInt(char* numeral) {
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
