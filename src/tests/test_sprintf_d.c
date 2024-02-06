#include "s21_test_string.h"

START_TEST(sprintf_1_signed_d) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %d Test %d";
  int a = -2147483648;
  int b = 0;
  int c = 2147483647;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_signed_d) {
  char str1[100];
  char str2[100];
  char *str3 = "%+d Test %+d Test %+d";
  int a = -2147483648;
  int b = 0;
  int c = 2147483647;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_signed_d) {
  char str1[100];
  char str2[100];
  char *str3 = "%-2d Test %-2d Test %-2d";
  int a = -2147483648;
  int b = 0;
  int c = 2147483647;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_signed_d) {
  char str1[100];
  char str2[100];
  char *str3 = "%ld Test %ld Test %hd GOD %hd";
  long int a = 3088675747373646;
  long b = 33030030303;
  short int c = 22600;
  short d = -120;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_signed_d) {
  char str1[100];
  char str2[100];
  char *str3 = "%3d Test %5d Test %10d";
  int a = -3015;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_signed_d) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5d Test %.23d Test %3.d TEST %.d %.6d";
  int a = -3015;
  int b = -712;
  int c = -99;
  int d = -38;
  int e = -100;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_signed_d) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5d Test %-.8d Test %-7d TEST %-.d";
  int a = -3015;
  int b = -712;
  int c = -99;
  int d = -2939;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_signed_d) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %0.d Test %0.0d TEST %d GOD %.*d";
  int a = -3015;
  int b = -712;
  int c = -99;
  int d = -2939;
  int e = -0123;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_signed_d) {
  char str1[200];
  char str2[200];
  char *str3 = "% d Test % 3.d Test % 5.7d TEST % 10d GOD %.d";
  int a = -32;
  int b = -8899;
  int c = -91918;
  int d = -32311;
  int e = -23;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_signed_d) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d Test %+3.d Test %+5.7d TEST %+10d GOD %+.d";
  int a = -32;
  int b = -8899;
  int c = 91918;
  int d = -32311;
  int e = 3261;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_d(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_SIGNED_d \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_signed_d);
  tcase_add_test(tc, sprintf_2_signed_d);
  tcase_add_test(tc, sprintf_3_signed_d);
  tcase_add_test(tc, sprintf_4_signed_d);
  tcase_add_test(tc, sprintf_5_signed_d);
  tcase_add_test(tc, sprintf_6_signed_d);
  tcase_add_test(tc, sprintf_7_signed_d);
  tcase_add_test(tc, sprintf_8_signed_d);
  tcase_add_test(tc, sprintf_9_signed_d);
  tcase_add_test(tc, sprintf_10_signed_d);

  suite_add_tcase(s, tc);
  return s;
}
