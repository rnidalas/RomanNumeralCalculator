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
	return convertIntToRomanNumeral( value1 + value2 );
}

/* Function RomanNumeralSubtraction
 * Input parameters: 	numeral1 - pointer to first roman numeral
 * 						numeral2 - pointer to second roman numeral
 * Returns:				pointer to roman numeral difference of numeral1 and numeral2
 */
char* RomanNumeralSubtraction(const char* numeral1, const char* numeral2) {
	int value1 = convertRomanNumeralToInt(numeral1);
	int value2 = convertRomanNumeralToInt(numeral2);
	return convertIntToRomanNumeral( abs(value1 - value2) );
}

/* Function convertIntToRomanNumeral
 * Input parameters: 	integer value (in range [1,3999] to convert to Roman Numeral
 * Returns:				character pointer to roman numeral cstring
 */
char* convertIntToRomanNumeral(int value) {
	
	char* numeral = malloc(sizeof(char)*SIZE_OF_MAX_NUMERAL);
	int i=0, tableIndex=0;	// i is index into numeral to prevent buffer overflow
	
	/* Ensure numeral string initially empty */
	strcpy(numeral,"");

	// iterate adding numeral characters until entire numeral completed
	while( value > 0 ) {
		// add numeral character if value is gte numeral at current table index
		if(value >= numeralValueTable[tableIndex]) {
			/* for loop using i to prevent buffer overflow */
			for(; i<SIZE_OF_MAX_NUMERAL; i+=strlen(numeralTable[tableIndex])) {
				strcat(numeral, numeralTable[tableIndex]);
				
				// Break if under value
				if((value -= numeralValueTable[tableIndex]) < numeralValueTable[tableIndex])
					break;
			}
		}
		
		// increment to next table index
		tableIndex++;
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
	int tableNumLength, tableIndex=12;	// tableIndex set to last index of table
	
	// iterate while there are still characters in the numeral and still options in the table
	while(i >= 0 && tableIndex >= 0) {
		tableNumLength = strlen(numeralTable[tableIndex]); // either 2 or 1 with above table
		
		// If testing a single character numeral piece
		if(tableNumLength == 1) {
			// check if numeral part match
			if(numeral[i] == numeralTable[tableIndex][0]) {
				// increment value and decrement numeral index
				value += numeralValueTable[tableIndex];
				i--;
			}
			else {
				// else change tableIndex to check next numeral
				tableIndex--;
			}
		}
		// If testing a 2 character numeral piece
		else if(tableNumLength == 2) {
			// check if both characters of numeral match up
			if( i>0 && numeral[i] == numeralTable[tableIndex][1]
					&& numeral[i-1] == numeralTable[tableIndex][0] ) {
				// if match, increment value and decrement numeral index appropriately
				value += numeralValueTable[tableIndex];
				i -= 2;
			}
			else {
				// else change tableIndex to check next numeral
				tableIndex--;
			}
		}
		
	}
	
	return value;
}
