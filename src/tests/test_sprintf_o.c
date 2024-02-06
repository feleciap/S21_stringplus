#include "s21_test_string.h"

START_TEST(sprintf_1_o) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %o Test";
  unsigned int a = 0377;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_o) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  unsigned int a = 012;
  unsigned int b = 017;
  unsigned int c = 07464;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_o) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  unsigned int a = 03015;
  unsigned int b = 0712;
  unsigned int c = 030;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_o) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo Test %lo Test %ho GOD %ho";
  long unsigned int a = 0306757;
  long unsigned b = 033030030303;
  unsigned short c = 022600;
  unsigned short d = 0120;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_o) {
  char str1[100];
  char str2[100];
  char *str3 = "%3o Test %5o Test %10o";
  unsigned int a = 03015;
  unsigned int b = 001234;
  unsigned int c = 00;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5o Test %.23o Test %3.o TEST %.o";
  unsigned int a = 03015;
  unsigned int b = 0712;
  unsigned int c = 077;
  unsigned int d = 066;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5o Test %-.8o Test %-7o TEST %-.o";
  unsigned int a = 03015;
  unsigned int b = 0712;
  unsigned int c = 077;
  unsigned int d = 02727;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %0.o Test %0.0o TEST %0o GOD %.o";
  unsigned int a = 03015;
  unsigned int b = 0712;
  unsigned int c = 011;
  unsigned int d = 06767;
  unsigned int e = 0123;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%o Test %3.o Test %5.7o TEST %10o";
  unsigned int a = 03015;
  unsigned int b = 0712;
  unsigned int c = 06767;
  unsigned int d = 06464;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%o Test %3.o Test %5.7o TEST %10o GOD %.o";
  unsigned int a = 032;
  unsigned int b = 06677;
  unsigned int c = 07654321;
  unsigned int d = 01234567;
  unsigned int e = 0000001;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%o Test %3.o Test %5.7o TEST %10o GOD %.o";
  unsigned int a = 032;
  unsigned int b = 06677;
  unsigned int c = 07654321;
  unsigned int d = 01234567;
  unsigned int e = 0000001;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_o) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lo";
  unsigned long int a = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%-o Test %-15o sdasda %-15o sdsad %-o";
  unsigned int a = 032;
  unsigned int b = 06677;
  unsigned int c = 07654321;
  unsigned int d = 01234567;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%o Test %3.o Test %5.7o TEST %10o";
  int a = 03015;
  int b = 0712;
  int c = 077;
  int d = 01234567;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_o) {
  char str1[200];
  char str2[200];
  char *str3 = "% o Test % 3.o Test % 5.7o TEST % 10o GOD %.o";
  int a = 32;
  int b = 8899;
  int c = 91918;
  int d = 32311;
  int e = 23;
  int res1 = sprintf(str1, str3, a, b, c, d, e);
  int res2 = s21_sprintf(str2, str3, a, b, c, d, e);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// Plus
START_TEST(sprintf_21_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%o Test %3.o Test %5.7o TEST %10o GOD %.o";
  int a = 32;
  int b = 8899;
  int c = 91918;
  int d = 32311;
  int e = 3261;
  int res1 = sprintf(str1, str3, a, b, c, d, e);
  int res2 = s21_sprintf(str2, str3, a, b, c, d, e);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_22_o) {
  char str1[200];
  char str2[200];
  char *str3 = "%- o Test %- 15o sdasda %- 15o sdsad %- o";
  int a = -3231;
  int b = -3231;
  int c = 3231;
  int d = 3231;
  int res1 = sprintf(str1, str3, a, b, c, d);
  int res2 = s21_sprintf(str2, str3, a, b, c, d);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_sprintf_o(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_o \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_o);
  tcase_add_test(tc, sprintf_2_o);
  tcase_add_test(tc, sprintf_3_o);
  tcase_add_test(tc, sprintf_4_o);
  tcase_add_test(tc, sprintf_5_o);
  tcase_add_test(tc, sprintf_6_o);
  tcase_add_test(tc, sprintf_7_o);
  tcase_add_test(tc, sprintf_8_o);
  tcase_add_test(tc, sprintf_9_o);
  tcase_add_test(tc, sprintf_11_o);
  tcase_add_test(tc, sprintf_12_o);
  tcase_add_test(tc, sprintf_16_o);
  tcase_add_test(tc, sprintf_17_o);
  tcase_add_test(tc, sprintf_18_o);
  tcase_add_test(tc, sprintf_20_o);
  tcase_add_test(tc, sprintf_21_o);
  tcase_add_test(tc, sprintf_22_o);

  suite_add_tcase(s, tc);
  return s;
}
