#include <check.h>
#include <stdlib.h>
#include "../src/RomanNumeralCalculator.h"

/* **********************************************************
 *				convertIntToRomanNumeral tests				*
 * ******************************************************** */
START_TEST(test_1returnsI) {
	char* numeral = convertIntToRomanNumeral(1);
	ck_assert_str_eq("I",numeral);
}
END_TEST

Suite* RomanNumeralCalculatorSuite(void) {
	Suite *s = suite_create("Test");

	/* convertIntToRomanNumeral test cases */
	TCase *tc_core = tcase_create("convertIntToRomanNumeral");
	tcase_add_test(tc_core, test_1returnsI);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void) {
	int number_failed;
	Suite *s = RomanNumeralCalculatorSuite();
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0)? EXIT_SUCCESS : EXIT_FAILURE;
}
