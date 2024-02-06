#include "s21_test_string.h"

START_TEST(sprintf_1_u) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %u Test";
  unsigned int a = 012;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_u) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test %u Test %u";
  unsigned int a = 012;
  unsigned int b = 017;
  unsigned int c = 07464;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_u) {
  char str1[100];
  char str2[100];
  char *str3 = "%-u Test %-u Test %-u";
  unsigned int a = 3015;
  unsigned int b = 712;
  unsigned int c = 99;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_u) {
  char str1[100];
  char str2[100];
  char *str3 = "%lu Test %lu Test %hu GOD %hu";
  long unsigned int a = 3088675747373646;
  long unsigned b = 33030030303;
  unsigned short c = 22600;
  unsigned short d = 120;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_u) {
  char str1[100];
  char str2[100];
  char *str3 = "%03u Test %05u Test %010u";
  unsigned int a = 3015;
  unsigned int b = 01234;
  unsigned int c = 99;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%.2u Test %.4u Test %0.3u TEST %.u";
  unsigned int a = 3015;
  unsigned int b = 712;
  unsigned int c = 99;
  unsigned int d = 38;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5u Test %-.8u Test %-7u TEST %-.u";
  unsigned int a = 3015;
  unsigned int b = 712;
  unsigned int c = 99;
  unsigned int d = 2939;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Test %0.u Test %0.0u TEST %0u GOD %.u";
  unsigned int a = 3015;
  unsigned int b = 712;
  unsigned int c = 99;
  unsigned int d = 2939;
  unsigned int e = 0123;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%u Test %3.u Test %5.7u TEST %10u";
  unsigned int a = 3015;
  unsigned int b = 712;
  unsigned int c = 99;
  unsigned int d = 2939;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%u Test %3.u Test %5.7u TEST %10u GOD %.u";
  unsigned int a = 32;
  unsigned int b = 8899;
  unsigned int c = 91918;
  unsigned int d = 32311;
  unsigned int e = 23;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%u Test %3.u Test %5.7u TEST %10u GOD %.u";
  unsigned int a = 32;
  unsigned int b = 8899;
  unsigned int c = 91918;
  unsigned int d = 32311;
  unsigned int e = 3261;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_u) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lu";
  unsigned long int a = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%- u Test %-15u sdasda %-15u sdsad %-u";
  unsigned int a = -3231;
  unsigned int b = -3231;
  unsigned int c = 3231;
  unsigned int d = 3231;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_u) {
  char str1[100] = "";
  char str2[100] = "";
  char format_str[100] = "% u";
  unsigned int u = 5;
  int res1 = sprintf(str1, format_str, u);
  int res2 = s21_sprintf(str2, format_str, u);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_19_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Test %+3.u Test %+5.7u TEST %+10u";
  unsigned int a = 3015;
  unsigned int b = 712;
  unsigned int c = 99;
  unsigned int d = 2939;
  int res1 = sprintf(str1, str3, a, b, c, d);
  int res2 = s21_sprintf(str2, str3, a, b, c, d);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_20_u) {
  char str1[200];
  char str2[200];
  char *str3 = "% u Test % 3.u Test % 5.7u TEST % 10u GOD %.u";
  unsigned int a = 32;
  unsigned int b = 8899;
  unsigned int c = 91918;
  unsigned int d = 32311;
  unsigned int e = 23;
  int res1 = sprintf(str1, str3, a, b, c, d, e);
  int res2 = s21_sprintf(str2, str3, a, b, c, d, e);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_21_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Test %+3.u Test %+5.7u TEST %+10u GOD %+.u";
  unsigned int a = 32;
  unsigned int b = 8899;
  unsigned int c = 91918;
  unsigned int d = 32311;
  unsigned int e = 3261;
  int res1 = sprintf(str1, str3, a, b, c, d, e);
  int res2 = s21_sprintf(str2, str3, a, b, c, d, e);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_sprintf_u(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_U \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_u);
  tcase_add_test(tc, sprintf_2_u);
  tcase_add_test(tc, sprintf_3_u);
  tcase_add_test(tc, sprintf_4_u);
  tcase_add_test(tc, sprintf_5_u);
  tcase_add_test(tc, sprintf_6_u);
  tcase_add_test(tc, sprintf_7_u);
  tcase_add_test(tc, sprintf_8_u);
  tcase_add_test(tc, sprintf_9_u);
  tcase_add_test(tc, sprintf_11_u);
  tcase_add_test(tc, sprintf_12_u);
  tcase_add_test(tc, sprintf_16_u);
  tcase_add_test(tc, sprintf_17_u);
  tcase_add_test(tc, sprintf_18_u);
  tcase_add_test(tc, sprintf_19_u);
  tcase_add_test(tc, sprintf_20_u);
  tcase_add_test(tc, sprintf_21_u);

  suite_add_tcase(s, tc);
  return s;
}
