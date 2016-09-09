#include <check.h>
#include <stdlib.h>

// "Test" test case - to be replaced
START_TEST(test_test) {
	ck_assert_int_eq(5,5);
}
END_TEST

Suite* money_suite(void) {
	Suite *s = suite_create("Test");

	/* Core test cases */
	TCase *tc_core = tcase_create("Test");
	tcase_add_test(tc_core, test_test);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void) {
	int number_failed;
	Suite *s = money_suite();
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0)? EXIT_SUCCESS : EXIT_FAILURE;
}
