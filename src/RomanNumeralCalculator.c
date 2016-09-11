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
	
	if(value == 5) {
		// Check to prevent buffer overflow
		if(i < 8) {
			strcat(numeral, "V");
			value -= 5;
		}
		i += 1;
	}
	
	if(value == 4) {
		// Check to prevent buffer overflow
		if(i < 7) {
			strcat(numeral, "IV");
			value -= 4;
		}
		i += 2;
	}
	
	if(value > 0) {
		/* for loop using i to prevent buffer overflow */
		for(i; i<SIZE_OF_MAX_NUMERAL; i+=1) {
			strcat(numeral, "I");
			
			// Break if numeral completed
			if((value -= 1) == 0)
				break;
		}
	}

	return numeral;
}
