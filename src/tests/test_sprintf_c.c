#include "s21_test_string.h"

START_TEST(sprintf_1_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 'a';
  int b = 'b';
  int c = '\0';
  int d = 'D';
  int e = 'e';
  int res1 = sprintf(str1, str3, a, b, c, d, e);
  int res2 = s21_sprintf(str2, str3, a, b, c, d, e);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_2_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%lc Test %c Test %c Test %c Test %c";
  int a = 'A';
  int b = 'B';
  int c = 'C';
  int d = 'D';
  int e = 'E';
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%+c Test %+c Test %+c Test %+c Test %+c";
  int a = 'A';
  int b = 'B';
  int c = 'C';
  int d = 'D';
  int e = 'E';
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_c) {
  char str1[100];
  char str2[100];
  char *str3 = "% c Test % c Test % c Test % c Test % c";
  int a = 'A';
  int b = 'B';
  int c = 'C';
  int d = 'D';
  int e = 'E';
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_c) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %c Test %c Test %03c Test %03c";
  int b = 'B';
  int c = 'C';
  int d = 'D';
  int e = 'E';
  int res1 = sprintf(str1, str3, b, c, d, e);
  int res2 = s21_sprintf(str2, str3, b, c, d, e);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_6_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%-03c Test % -3c Test %-lc";
  int a = 74;
  unsigned long int b = 74;
  int res1 = sprintf(str1, str3, a, a, b);
  int res2 = s21_sprintf(str2, str3, a, a, b);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_7_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%2.3c Test %-2.3c Test %2.10lc Test %-2.10lc Test %-0lc";
  int a = 10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%2.3c Test %-2.3c Test %2.10lc Test %-2.10lc Test %-0lc";
  int a = -10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%#c Test %#c Test %#c Test %#c Test %#c";
  ck_assert_int_eq(sprintf(str1, str3, '+', 'h', '9', ' ', '\\'),
                   s21_sprintf(str2, str3, '+', 'h', '9', ' ', '\\'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int res1 = sprintf(str1, str3, '\n', '\0', '\0', '\0', 'c');
  int res2 = s21_sprintf(str2, str3, '\n', '\0', '\0', '\0', 'c');
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_11_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.5c Test %-5c Test %-0c Test % 5c Test %0c";
  int a = 45;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%5c Test %-5c Test %05c Test %-05c Test %- 5c";
  int a = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  char a = '\0';
  int res1 = sprintf(str1, str3, a, a, a, a, a);
  int res2 = s21_sprintf(str2, str3, a, a, a, a, a);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_14_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%#c Test %#c Test %#c Test %#c Test %#c";
  ck_assert_int_eq(sprintf(str1, str3, L'h', L'e', L'l', L'l', L'o'),
                   s21_sprintf(str2, str3, L'h', L'e', L'l', L'l', L'o'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int res1 = sprintf(str1, str3, 'b', '4', '#', '@', '\0');
  int res2 = s21_sprintf(str2, str3, 'b', '4', '#', '@', '\0');
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_16_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int res1 = sprintf(str1, str3, 'Y', '\0', 'G', 123, 'J');
  int res2 = s21_sprintf(str2, str3, 'Y', '\0', 'G', 123, 'J');
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_sprintf_c(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_C \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_c);
  tcase_add_test(tc, sprintf_2_c);
  tcase_add_test(tc, sprintf_3_c);
  tcase_add_test(tc, sprintf_4_c);
  tcase_add_test(tc, sprintf_5_c);
  tcase_add_test(tc, sprintf_6_c);
  tcase_add_test(tc, sprintf_7_c);
  tcase_add_test(tc, sprintf_8_c);
  tcase_add_test(tc, sprintf_9_c);
  tcase_add_test(tc, sprintf_10_c);
  tcase_add_test(tc, sprintf_11_c);
  tcase_add_test(tc, sprintf_12_c);
  tcase_add_test(tc, sprintf_13_c);
  tcase_add_test(tc, sprintf_14_c);
  tcase_add_test(tc, sprintf_15_c);
  tcase_add_test(tc, sprintf_16_c);

  suite_add_tcase(s, tc);
  return s;
}
