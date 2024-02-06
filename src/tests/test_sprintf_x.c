#include "s21_test_string.h"

START_TEST(sprintf_1_x) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %x Test";
  unsigned int a = 0x3ff;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_x) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %x Test %x";
  unsigned int a = 0x12;
  unsigned int b = 0x17;
  unsigned int c = 0x7464;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_x) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %x Test %x";
  unsigned int a = 0x3015;
  unsigned int b = 0x712;
  unsigned int c = 0xff;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_x) {
  char str1[100];
  char str2[100];
  char *str3 = "%lx Test %lx Test %hx GxD %hx";
  long unsigned int a = 0x30ff57;
  long unsigned b = 0x33030030303;
  unsigned short c = 0x2f;
  unsigned short d = 0xff;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_x) {
  char str1[100];
  char str2[100];
  char *str3 = "%3x Test %5x Test %10x";
  unsigned int a = 0x3015;
  unsigned int b = 0x01234;
  unsigned int c = 0x0;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_x) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5x Test %.23x Test %3.x TEST %.x";
  unsigned int a = 0x3015;
  unsigned int b = 0x712;
  unsigned int c = 0xff;
  unsigned int d = 0x66;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_x) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5x Test %-.8x Test %-7x TEST %-.x";
  unsigned int a = 0x3015;
  unsigned int b = 0x712;
  unsigned int c = 0xff;
  unsigned int d = 0x2727;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_x) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %0.x Test %0.0x TEST %0x GxD %.x";
  unsigned int a = 0x3015;
  unsigned int b = 0x712;
  unsigned int c = 0x11;
  unsigned int d = 0xffff;
  unsigned int e = 0x123;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_x) {
  char str1[200];
  char str2[200];
  char *str3 = "%x Test %3.x Test %5.7x TEST %10x";
  unsigned int a = 0x3015;
  unsigned int b = 0x712;
  unsigned int c = 0xffff;
  unsigned int d = 0x6464;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_x) {
  char str1[200];
  char str2[200];
  char *str3 = "%x Test %3.x Test %5.7x TEST %10x GxD %.x";
  unsigned int a = 0x32;
  unsigned int b = 0x66ff;
  unsigned int c = 0x7654321;
  unsigned int d = 0x12345ff;
  unsigned int e = 0x000001;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_x) {
  char str1[200];
  char str2[200];
  char *str3 = "%x Test %3.x Test %5.7x TEST %10x GxD %.x";
  unsigned int a = 0x32;
  unsigned int b = 0x66ff;
  unsigned int c = 0x7654321;
  unsigned int d = 0x12345ff;
  unsigned int e = 0x000001;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_x) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lx";
  unsigned long int a = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_x) {
  char str1[200];
  char str2[200];
  char *str3 = "%-x Test %-15x sdasda %-15x sdsad %-x";
  unsigned int a = 0x32;
  unsigned int b = 0x66ff;
  unsigned int c = 0x7654321;
  unsigned int d = 0x12345ff;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_x(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_x \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_x);
  tcase_add_test(tc, sprintf_2_x);
  tcase_add_test(tc, sprintf_3_x);
  tcase_add_test(tc, sprintf_4_x);
  tcase_add_test(tc, sprintf_5_x);
  tcase_add_test(tc, sprintf_6_x);
  tcase_add_test(tc, sprintf_7_x);
  tcase_add_test(tc, sprintf_8_x);
  tcase_add_test(tc, sprintf_9_x);
  tcase_add_test(tc, sprintf_11_x);
  tcase_add_test(tc, sprintf_12_x);
  tcase_add_test(tc, sprintf_16_x);
  tcase_add_test(tc, sprintf_17_x);

  suite_add_tcase(s, tc);
  return s;
}
