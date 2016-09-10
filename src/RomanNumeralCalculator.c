#include <stdlib.h>
#include <string.h>
#include "RomanNumeralCalculator.h"

/* Function convertIntToRomanNumeral
 * Input parameters: 	integer value (in range [1,3999] to convert to Roman Numeral
 * Returns:				character pointer to roman numeral cstring
 */
char* convertIntToRomanNumeral(int value) {
	char* numeral = malloc(sizeof(char)*SIZE_OF_MAX_NUMERAL);
	
	int i;
	
	/* for loop using i to prevent buffer overflow */
	for(i=0; i<SIZE_OF_MAX_NUMERAL; i++) {
		strcat(numeral, "I");
		
		// Break if numeral completed
		if((value -= 1) == 0)
			break;
	}

	return numeral;
}
