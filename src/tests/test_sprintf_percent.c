#include "s21_test_string.h"

START_TEST(sprintf_1_percent) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%%Test %d Test";
  int a = 12;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_percent) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %d Tes%%%%t %d";
  int a = 12;
  int b = 17;
  ck_assert_int_eq(sprintf(str1, str3, a, b), s21_sprintf(str2, str3, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_percent) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Te%%st %d Test %d";
  int a = 3015;
  int b = 712;
  int c = 99;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_percent(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_PERCENT \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_percent);
  tcase_add_test(tc, sprintf_2_percent);
  tcase_add_test(tc, sprintf_3_percent);

  suite_add_tcase(s, tc);
  return s;
}
