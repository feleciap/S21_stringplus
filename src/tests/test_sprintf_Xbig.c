#include "s21_test_string.h"

START_TEST(sprintf_1_X) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %X Test";
  unsigned int a = 0X3FF;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_X) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Test %X Test %X";
  unsigned int a = 0XbF;
  unsigned int b = 0X17;
  unsigned int c = 0X7464;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_X) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Test %X Test %X";
  unsigned int a = 0Xac15;
  unsigned int b = 0X7bF;
  unsigned int c = 0XFF;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_X) {
  char str1[100];
  char str2[100];
  char *str3 = "%lX Test %lX Test %hX GXD %hX";
  long unsigned int a = 0XacFF57;
  long unsigned b = 0X3acac0acac3;
  unsigned short c = 0X2f;
  unsigned short d = 0XFF;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_X) {
  char str1[100];
  char str2[100];
  char *str3 = "%3X Test %5X Test %10X";
  unsigned int a = 0Xac15;
  unsigned int b = 0X0bF34;
  unsigned int c = 0X0;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_X) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5X Test %.23X Test %3.X TEST %.X";
  unsigned int a = 0Xac15;
  unsigned int b = 0X7bF;
  unsigned int c = 0XFF;
  unsigned int d = 0X66;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_X) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5X Test %-.8X Test %-7X TEST %-.X";
  unsigned int a = 0Xac15;
  unsigned int b = 0X7bF;
  unsigned int c = 0XFF;
  unsigned int d = 0X2727;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_X) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X Test %0.X Test %0.0X TEST %0X GXD %.X";
  unsigned int a = 0Xac15;
  unsigned int b = 0X7bF;
  unsigned int c = 0X11;
  unsigned int d = 0XFFFF;
  unsigned int val5 = 0XbF3;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, val5),
                   s21_sprintf(str2, str3, a, b, c, d, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_X) {
  char str1[200];
  char str2[200];
  char *str3 = "%X Test %3.X Test %5.7X TEST %10X";
  unsigned int a = 0Xac15;
  unsigned int b = 0X7bF;
  unsigned int c = 0XFFFF;
  unsigned int d = 0X6464;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_X) {
  char str1[200];
  char str2[200];
  char *str3 = "%X Test %3.X Test %5.7X TEST %10X GXD %.X";
  unsigned int a = 0X32;
  unsigned int b = 0X66FF;
  unsigned int c = 0X7654321;
  unsigned int d = 0XbF345FF;
  unsigned int val5 = 0X000001;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, val5),
                   s21_sprintf(str2, str3, a, b, c, d, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_X) {
  char str1[200];
  char str2[200];
  char *str3 = "%X Test %3.X Test %5.7X TEST %10X GXD %.X";
  unsigned int a = 0X32;
  unsigned int b = 0X66FF;
  unsigned int c = 0X7654321;
  unsigned int d = 0XbF345FF;
  unsigned int val5 = 0X000001;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, val5),
                   s21_sprintf(str2, str3, a, b, c, d, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_X) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lX";
  unsigned long int a = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_X) {
  char str1[200];
  char str2[200];
  char *str3 = "%-X Test %-15X sdasda %-15X sdsad %-X";
  unsigned int a = 0X32;
  unsigned int b = 0X66FF;
  unsigned int c = 0X7654321;
  unsigned int d = 0XbF345FF;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_X(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_X \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_X);
  tcase_add_test(tc, sprintf_2_X);
  tcase_add_test(tc, sprintf_3_X);
  tcase_add_test(tc, sprintf_4_X);
  tcase_add_test(tc, sprintf_5_X);
  tcase_add_test(tc, sprintf_6_X);
  tcase_add_test(tc, sprintf_7_X);
  tcase_add_test(tc, sprintf_8_X);
  tcase_add_test(tc, sprintf_9_X);
  tcase_add_test(tc, sprintf_11_X);
  tcase_add_test(tc, sprintf_12_X);
  tcase_add_test(tc, sprintf_16_X);
  tcase_add_test(tc, sprintf_17_X);

  suite_add_tcase(s, tc);
  return s;
}
