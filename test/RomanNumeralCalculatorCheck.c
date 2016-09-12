#include <check.h>
#include <stdlib.h>
#include "../src/RomanNumeralCalculator.h"

/* ******************************************************** *
 *				convertIntToRomanNumeral tests				*
 * ******************************************************** */
START_TEST(test_1toRoman) {
	char* numeral = convertIntToRomanNumeral(1);
	ck_assert_str_eq("I",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_2and3toRoman) {
	char* numeral = convertIntToRomanNumeral(2);
	ck_assert_str_eq("II",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(3);
	ck_assert_str_eq("III",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_4toRoman) {
	char* numeral = convertIntToRomanNumeral(4);
	ck_assert_str_eq("IV",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_5toRoman) {
	char* numeral = convertIntToRomanNumeral(5);
	ck_assert_str_eq("V",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_6to8toRoman) {
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

START_TEST(test_9toRoman) {
	char* numeral = convertIntToRomanNumeral(9);
	ck_assert_str_eq("IX",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_10toRoman) {
	char* numeral = convertIntToRomanNumeral(10);
	ck_assert_str_eq("X",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_lt20toRoman) {
	char* numeral = convertIntToRomanNumeral(14);
	ck_assert_str_eq("XIV",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(18);
	ck_assert_str_eq("XVIII",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_lt50toRoman) {
	char* numeral = convertIntToRomanNumeral(21);
	ck_assert_str_eq("XXI",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(32);
	ck_assert_str_eq("XXXII",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(43);
	ck_assert_str_eq("XLIII",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_lt90toRoman) {
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

START_TEST(test_lt100toRoman) {
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

START_TEST(test_lt400toRoman) {
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

START_TEST(test_lt500toRoman) {
	char* numeral = convertIntToRomanNumeral(437);
	ck_assert_str_eq("CDXXXVII",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(499);
	ck_assert_str_eq("CDXCIX",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_lt900toRoman) {
	char* numeral = convertIntToRomanNumeral(500);
	ck_assert_str_eq("D",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(548);
	ck_assert_str_eq("DXLVIII",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(659);
	ck_assert_str_eq("DCLIX",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(870);
	ck_assert_str_eq("DCCCLXX",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(888);
	ck_assert_str_eq("DCCCLXXXVIII",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_lt1000toRoman) {
	char* numeral = convertIntToRomanNumeral(900);
	ck_assert_str_eq("CM",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(949);
	ck_assert_str_eq("CMXLIX",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(993);
	ck_assert_str_eq("CMXCIII",numeral);
	free(numeral);
}
END_TEST

START_TEST(test_lt4000toRoman) {
	char* numeral = convertIntToRomanNumeral(1000);
	ck_assert_str_eq("M",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(1006);
	ck_assert_str_eq("MVI",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(2016);
	ck_assert_str_eq("MMXVI",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(3437);
	ck_assert_str_eq("MMMCDXXXVII",numeral);
	free(numeral);
	
	numeral = convertIntToRomanNumeral(3999);
	ck_assert_str_eq("MMMCMXCIX",numeral);
	free(numeral);
}
END_TEST

/* ******************************************************** *
 *				convertRomanNumeralToInt tests				*
 * ******************************************************** */
START_TEST(test_1toInt) {
	int value = convertRomanNumeralToInt("I");
	ck_assert_int_eq(1,value);
}
END_TEST

START_TEST(test_2and3toInt) {
	int value = convertRomanNumeralToInt("II");
	ck_assert_int_eq(2,value);
	
	value = convertRomanNumeralToInt("III");
	ck_assert_int_eq(3,value);
}
END_TEST

START_TEST(test_4toInt) {
	int value = convertRomanNumeralToInt("IV");
	ck_assert_int_eq(4,value);
}
END_TEST

START_TEST(test_5toInt) {
	int value = convertRomanNumeralToInt("V");
	ck_assert_int_eq(5,value);
}
END_TEST

START_TEST(test_6to8toInt) {
	int value = convertRomanNumeralToInt("VI");
	ck_assert_int_eq(6,value);
	
	value = convertRomanNumeralToInt("VII");
	ck_assert_int_eq(7,value);
	
	value = convertRomanNumeralToInt("VIII");
	ck_assert_int_eq(8,value);
}
END_TEST

START_TEST(test_9toInt) {
	int value = convertRomanNumeralToInt("IX");
	ck_assert_int_eq(9,value);
}
END_TEST

START_TEST(test_10toInt) {
	int value = convertRomanNumeralToInt("X");
	ck_assert_int_eq(10,value);
}
END_TEST

/* ******************************************************** *
 *				Roman Numeral Test Suite					*
 * ******************************************************** */
Suite* RomanNumeralCalculatorSuite(void) {
	Suite *s = suite_create("Test");

	/* convertIntToRomanNumeral test cases */
	TCase *tc_IntToRoman = tcase_create("convertIntToRomanNumeral");
	tcase_add_test(tc_IntToRoman, test_1toRoman);
	tcase_add_test(tc_IntToRoman, test_2and3toRoman);
	tcase_add_test(tc_IntToRoman, test_4toRoman);
	tcase_add_test(tc_IntToRoman, test_5toRoman);
	tcase_add_test(tc_IntToRoman, test_6to8toRoman);
	tcase_add_test(tc_IntToRoman, test_9toRoman);
	tcase_add_test(tc_IntToRoman, test_10toRoman);
	tcase_add_test(tc_IntToRoman, test_lt20toRoman);
	tcase_add_test(tc_IntToRoman, test_lt50toRoman);
	tcase_add_test(tc_IntToRoman, test_lt90toRoman);
	tcase_add_test(tc_IntToRoman, test_lt100toRoman);
	tcase_add_test(tc_IntToRoman, test_lt400toRoman);
	tcase_add_test(tc_IntToRoman, test_lt500toRoman);
	tcase_add_test(tc_IntToRoman, test_lt900toRoman);
	tcase_add_test(tc_IntToRoman, test_lt1000toRoman);
	tcase_add_test(tc_IntToRoman, test_lt4000toRoman);
	suite_add_tcase(s, tc_IntToRoman);
	
	/* convertRomanNumeralToInt test cases */
	TCase *tc_RomanToInt = tcase_create("convertRomanNumeralToInt");
	tcase_add_test(tc_RomanToInt, test_1toInt);
	tcase_add_test(tc_RomanToInt, test_2and3toInt);
	tcase_add_test(tc_RomanToInt, test_4toInt);
	tcase_add_test(tc_RomanToInt, test_5toInt);
	tcase_add_test(tc_RomanToInt, test_6to8toInt);
	tcase_add_test(tc_RomanToInt, test_9toInt);
	tcase_add_test(tc_RomanToInt, test_10toInt);
	suite_add_tcase(s, tc_RomanToInt);

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
