#include <check.h>
#include <stdlib.h>
#include "../src/RomanNumeralCalculator.h"

/* ******************************************************** *
 *				convertIntToRomanNumeral tests				*
 * ******************************************************** */
START_TEST(test_1returnValue) {
	char* numeral = convertIntToRomanNumeral(1);
	ck_assert_str_eq("I",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_2and3returnValues) {
	char* numeral = convertIntToRomanNumeral(2);
	ck_assert_str_eq("II",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(3);
	ck_assert_str_eq("III",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_4returnValue) {
	char* numeral = convertIntToRomanNumeral(4);
	ck_assert_str_eq("IV",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_5returnValue) {
	char* numeral = convertIntToRomanNumeral(5);
	ck_assert_str_eq("V",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_6to8returnValues) {
	char* numeral = convertIntToRomanNumeral(6);
	ck_assert_str_eq("VI",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(7);
	ck_assert_str_eq("VII",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(8);
	ck_assert_str_eq("VIII",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_9returnValue) {
	char* numeral = convertIntToRomanNumeral(9);
	ck_assert_str_eq("IX",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_10returnValue) {
	char* numeral = convertIntToRomanNumeral(10);
	ck_assert_str_eq("X",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_lt20returnValue) {
	char* numeral = convertIntToRomanNumeral(14);
	ck_assert_str_eq("XIV",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(18);
	ck_assert_str_eq("XVIII",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_lt50returnValue) {
	char* numeral = convertIntToRomanNumeral(21);
	ck_assert_str_eq("XXI",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(32);
	ck_assert_str_eq("XXXII",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(43);
	ck_assert_str_eq("XXXXIII",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_lt90returnValue) {
	char* numeral = convertIntToRomanNumeral(50);
	ck_assert_str_eq("L",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(61);
	ck_assert_str_eq("LXI",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(72);
	ck_assert_str_eq("LXXII",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(83);
	ck_assert_str_eq("LXXXIII",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_lt100returnValue) {
	char* numeral = convertIntToRomanNumeral(90);
	ck_assert_str_eq("XC",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(94);
	ck_assert_str_eq("XCIV",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(99);
	ck_assert_str_eq("XCIX",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_lt400returnValue) {
	char* numeral = convertIntToRomanNumeral(100);
	ck_assert_str_eq("C",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(215);
	ck_assert_str_eq("CCXV",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(326);
	ck_assert_str_eq("CCCXXVI",numeral);
	free(numeral);
}
END_TEST

/* ******************************************************** *
 *				Roman Numeral Test Suite					*
 * ******************************************************** */
Suite* RomanNumeralCalculatorSuite(void) {
	Suite *s = suite_create("Test");

	/* convertIntToRomanNumeral test cases */
	TCase *tc_core = tcase_create("convertIntToRomanNumeral");
	tcase_add_test(tc_core, test_1returnValue);
	tcase_add_test(tc_core, test_2and3returnValues);
	tcase_add_test(tc_core, test_4returnValue);
	tcase_add_test(tc_core, test_5returnValue);
	tcase_add_test(tc_core, test_6to8returnValues);
	tcase_add_test(tc_core, test_9returnValue);
	tcase_add_test(tc_core, test_10returnValue);
	tcase_add_test(tc_core, test_lt20returnValue);
	tcase_add_test(tc_core, test_lt50returnValue);
	tcase_add_test(tc_core, test_lt90returnValue);
	tcase_add_test(tc_core, test_lt100returnValue);
	tcase_add_test(tc_core, test_lt400returnValue);
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
