#include <check.h>
#include <stdlib.h>
#include "../src/RomanNumeralCalculator.h"

/* ******************************************************** *
 * 						Addition Tests						*
 * ******************************************************** */
START_TEST(test_sampleAdditionTests) {
	char* sum = RomanNumeralAddition("II", "II");
	ck_assert_str_eq("IV",sum);
	free(sum);
	
	sum = RomanNumeralAddition("D", "D");	// 500 + 500 = 1000
	ck_assert_str_eq("M",sum);
	free(sum);
	
	sum = RomanNumeralAddition("DIV", "V");	// 504 + 5 = 509
	ck_assert_str_eq("DIX",sum);
	free(sum);
	
	sum = RomanNumeralAddition("CMXLVIII", "DCCXXXIII");	// 948 + 733 = 1681
	ck_assert_str_eq("MDCLXXXI",sum);
	free(sum);
}
END_TEST

START_TEST(test_additionLoopTest) {
	char* numeral1 = convertIntToRomanNumeral(_i);
	char* numeral2;
	char* sum;
	int j, sumValue;
	
	for(j=1; j<3999-_i; j++) {
		numeral2 = convertIntToRomanNumeral(j);
		sum = RomanNumeralAddition(numeral1, numeral2);
		sumValue = convertRomanNumeralToInt(sum);
		ck_assert_int_eq(sumValue, _i+j);
		free(numeral2);
		free(sum);
	}
	free(numeral1);
}
END_TEST

/* ******************************************************** *
 * 					Subtraction Tests						*
 * ******************************************************** */
START_TEST(test_sampleSubtractionTests) {
	char* dif = RomanNumeralSubtraction("IV", "II");	// 4 - 2 = 2
	ck_assert_str_eq("II",dif);
	free(dif);
	
	dif = RomanNumeralSubtraction("M", "D");	// 1000 - 500 = 500
	ck_assert_str_eq("D",dif);
	free(dif);
	
	dif = RomanNumeralSubtraction("DIX", "V");	// 509 - 5 = 504
	ck_assert_str_eq("DIV",dif);
	free(dif);
	
	dif = RomanNumeralSubtraction("MDCLXXXI", "DCCXXXIII");	// 1681 - 733 = 948
	ck_assert_str_eq("CMXLVIII",dif);
	free(dif);
}
END_TEST

START_TEST(test_subtractionLoopTest) {
	char* numeral1 = convertIntToRomanNumeral(_i);
	char* numeral2;
	char* dif;
	int j, difValue;
	
	for(j=_i; j<4000; j++) {
		if(_i == j) {
			continue;
		}
		numeral2 = convertIntToRomanNumeral(j);
		dif = RomanNumeralSubtraction(numeral1, numeral2);
		difValue = convertRomanNumeralToInt(dif);
		ck_assert_int_eq(difValue, abs(_i-j) );
		free(numeral2);
		free(dif);
	}
	free(numeral1);
}
END_TEST

/* ******************************************************** *
 *		loop test for both conversion functions				*
 * ******************************************************** */
START_TEST(test_conversionLoopVerification) {
	/* variable _i available through check.h tcase_add_loop_test
	 * 
	 * test case looped for valid Roman Numeral domain [1,3999]
	 * 
	 * test functions by passing successive values (based on i)
	 * into Roman Numeral conversion, and passing the returned
	 * Roman Numeral through the reverse conversion, giving back
	 * the initial value */
	 
	 char* numeral = convertIntToRomanNumeral(_i);
	 int value = convertRomanNumeralToInt(numeral);
	 free(numeral);
	 
	 // 'value' output should equal '_i' input
	 ck_assert_int_eq(_i,value);
}
END_TEST

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
	
	numeral = convertIntToRomanNumeral(2884);
	ck_assert_str_eq("MMDCCCLXXXIV",numeral);
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

START_TEST(test_lt40toInt) {
	int value = convertRomanNumeralToInt("XXI");
	ck_assert_int_eq(21,value);
	
	value = convertRomanNumeralToInt("XXXII");
	ck_assert_int_eq(32,value);
	
	value = convertRomanNumeralToInt("XXXVII");
	ck_assert_int_eq(37,value);
}
END_TEST

START_TEST(test_lt50toInt) {
	int value = convertRomanNumeralToInt("XL");
	ck_assert_int_eq(40,value);
	
	value = convertRomanNumeralToInt("XLIV");
	ck_assert_int_eq(44,value);
	
	value = convertRomanNumeralToInt("XLVIII");
	ck_assert_int_eq(48,value);
}
END_TEST

START_TEST(test_lt90toInt) {
	int value = convertRomanNumeralToInt("L");
	ck_assert_int_eq(50,value);
	
	value = convertRomanNumeralToInt("LVII");
	ck_assert_int_eq(57,value);
	
	value = convertRomanNumeralToInt("LXVI");
	ck_assert_int_eq(66,value);
	
	value = convertRomanNumeralToInt("LXXVIII");
	ck_assert_int_eq(78,value);
	
	value = convertRomanNumeralToInt("LXXXIX");
	ck_assert_int_eq(89,value);
}
END_TEST

START_TEST(test_lt100toInt) {
	int value = convertRomanNumeralToInt("XC");
	ck_assert_int_eq(90,value);
	
	value = convertRomanNumeralToInt("XCII");
	ck_assert_int_eq(92,value);
	
	value = convertRomanNumeralToInt("XCVII");
	ck_assert_int_eq(97,value);
}
END_TEST

START_TEST(test_lt400toInt) {
	int value = convertRomanNumeralToInt("C");
	ck_assert_int_eq(100,value);
	
	value = convertRomanNumeralToInt("CI");
	ck_assert_int_eq(101,value);
	
	value = convertRomanNumeralToInt("CIX");
	ck_assert_int_eq(109,value);
	
	value = convertRomanNumeralToInt("CXI");
	ck_assert_int_eq(111,value);
	
	value = convertRomanNumeralToInt("CXXIV");
	ck_assert_int_eq(124,value);
	
	value = convertRomanNumeralToInt("CCXXXVII");
	ck_assert_int_eq(237,value);
	
	value = convertRomanNumeralToInt("CCCLXXXIX");
	ck_assert_int_eq(389,value);
}
END_TEST

START_TEST(test_lt500toInt) {
	int value = convertRomanNumeralToInt("CD");
	ck_assert_int_eq(400,value);
	
	value = convertRomanNumeralToInt("CDXLIV");
	ck_assert_int_eq(444,value);
}
END_TEST

START_TEST(test_lt900toInt) {
	int value = convertRomanNumeralToInt("D");
	ck_assert_int_eq(500,value);
	
	value = convertRomanNumeralToInt("DXLVII");
	ck_assert_int_eq(547,value);
	
	value = convertRomanNumeralToInt("DLV");
	ck_assert_int_eq(555,value);
	
	value = convertRomanNumeralToInt("DCLXVI");
	ck_assert_int_eq(666,value);
	
	value = convertRomanNumeralToInt("DCCLXXVII");
	ck_assert_int_eq(777,value);
	
	value = convertRomanNumeralToInt("DCCCLXXXVIII");
	ck_assert_int_eq(888,value);
}
END_TEST

START_TEST(test_lt1000toInt) {
	int value = convertRomanNumeralToInt("CM");
	ck_assert_int_eq(900,value);
	
	value = convertRomanNumeralToInt("CMIX");
	ck_assert_int_eq(909,value);
	
	value = convertRomanNumeralToInt("CMXCI");
	ck_assert_int_eq(991,value);
}
END_TEST

START_TEST(test_lt4000toInt) {
	int value = convertRomanNumeralToInt("M");
	ck_assert_int_eq(1000,value);
	
	value = convertRomanNumeralToInt("MI");
	ck_assert_int_eq(1001,value);
	
	value = convertRomanNumeralToInt("MMXVI");
	ck_assert_int_eq(2016,value);
	
	value = convertRomanNumeralToInt("MMCCLXVII");
	ck_assert_int_eq(2267,value);
	
	value = convertRomanNumeralToInt("MMMCCCXXXIII");
	ck_assert_int_eq(3333,value);
	
	value = convertRomanNumeralToInt("MMMCMXCIX");
	ck_assert_int_eq(3999,value);
}
END_TEST

/* ******************************************************** *
 *				Roman Numeral Test Suite					*
 * ******************************************************** */
Suite* RomanNumeralCalculatorSuite(void) {
	Suite *s = suite_create("Test");

	/* Loop tests */
	TCase *tc_loopTests = tcase_create("LoopTests");
	/*tcase_add_loop_test(tc_loopTests, test_additionLoopTest,1,4000);
	tcase_add_loop_test(tc_loopTests, test_subtractionLoopTest,1,4000);*/
	tcase_add_loop_test(tc_loopTests, test_conversionLoopVerification, 1, 4000);
	suite_add_tcase(s, tc_loopTests);

	/* Addition test cases */
	TCase *tc_additionTest = tcase_create("AdditionTests");
	tcase_add_test(tc_additionTest, test_sampleAdditionTests);
	suite_add_tcase(s, tc_additionTest);
	
	/* Subtraction test cases */
	TCase *tc_subtractionTest = tcase_create("SubtractionTests");
	tcase_add_test(tc_subtractionTest, test_sampleSubtractionTests);
	suite_add_tcase(s, tc_subtractionTest);

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
	tcase_add_test(tc_RomanToInt, test_lt40toInt);
	tcase_add_test(tc_RomanToInt, test_lt50toInt);
	tcase_add_test(tc_RomanToInt, test_lt90toInt);
	tcase_add_test(tc_RomanToInt, test_lt100toInt);
	tcase_add_test(tc_RomanToInt, test_lt400toInt);
	tcase_add_test(tc_RomanToInt, test_lt500toInt);
	tcase_add_test(tc_RomanToInt, test_lt900toInt);
	tcase_add_test(tc_RomanToInt, test_lt1000toInt);
	tcase_add_test(tc_RomanToInt, test_lt4000toInt);
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
