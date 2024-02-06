#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_test_string.h"

START_TEST(test_sscanf1_c) {
  char format[100] = "%c";
  char str[100] = "s";
  char a, b;
  int original = sscanf(str, format, &a);
  int s21_func = s21_sscanf(str, format, &b);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_sscanf2_c) {
  char format[100] = "%c";
  char str[100] = "";
  char a, b;
  int original = sscanf(str, format, &a);
  int s21_func = s21_sscanf(str, format, &b);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_sscanf3_c) {
  char format[100] = "%c";
  char str[100] = "hi\thi";
  char a, b;
  int original = sscanf(str, format, &a);
  int s21_func = s21_sscanf(str, format, &b);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_sscanf4_c) {
  char format[100] = "%c %c %c";
  char str[100] = "hi\thi h";
  char o1, o2, o3, s1, s2, s3;
  int original = sscanf(str, format, &o1, &o2, &o3);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
}
END_TEST

START_TEST(test_sscanf5_d) {
  char format[100] = "%d %d %d 45%*d %d";
  char str[100] = "1 2 3 45 6 7";
  int o1, o2, o3, o4, s1, s2, s3, s4;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf6_d) {
  char format[100] = "%d %d %d 45%d";
  char str[100] = "";
  char o1, o2, o3, o4, s1, s2, s3, s4;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf7_d) {
  char format[100] = "%hd %4hd %d 45%hd";
  char str[100] = "12 23 34 45 56";
  short o1, o2, o4, s1, s2, s4;
  int o3, s3;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf8_d) {
  char format[100] = "%ld %4ld %d 45%ld";
  char str[100] = "12 -23 34 45 56";
  long int o1, o2, o4, s1, s2, s4;
  int o3, s3;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf7_s) {
  char format[100] = "%s";
  char str[100] = "hello my darling";
  char o1[100], s1[100];
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_str_eq(o1, s1);
}
END_TEST

START_TEST(test_sscanf8_s) {
  char format[100] = "%s %s %s";
  char str[100] = "test1 test2 test3";
  char o1[100], o2[100], o3[100];
  char s1[100], s2[100], s3[100];
  int original = sscanf(str, format, &o1, &o2, &o3);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3);
  ck_assert_int_eq(original, s21_func);
  ck_assert_str_eq(o1, s1);
  ck_assert_str_eq(o2, s2);
  ck_assert_str_eq(o3, s3);
}
END_TEST

START_TEST(test_sscanf9_s) {
  char format[100] = "%s %% %s %s";
  char str[100] = "test1 % test2 test3 test4";
  char o1[100], o2[100], o3[100];
  char s1[100], s2[100], s3[100];
  int original = sscanf(str, format, &o1, &o2, &o3);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3);
  ck_assert_int_eq(original, s21_func);
  ck_assert_str_eq(o1, s1);
  ck_assert_str_eq(o2, s2);
  ck_assert_str_eq(o3, s3);
}
END_TEST

START_TEST(test_sscanf10_s) {
  char format[100] = "%s %s %s %s";
  char str[100] = "test test2 test3 test4";
  char o1[100], o2[100], o3[100], o4[100];
  char s1[100], s2[100], s3[100], s4[100];
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_str_eq(o1, s1);
  ck_assert_str_eq(o2, s2);
  ck_assert_str_eq(o3, s3);
  ck_assert_str_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf11_f) {
  char format[100] = "%14f%3f\t%2f%1f";
  char str[100] = "1.123 -0.0021 12.00001 3.01010202";
  int o1, o2, o3, o4, s1, s2, s3, s4;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf12_f) {
  char format[100] = "%14Lf%3Lf\t%2Lf%1Lf";
  char str[100] = "-1.1e3 0.0021 12.00001 +13.010102e2";
  long double o1, o2, o3, o4, s1, s2, s3, s4;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf13_f) {
  char format[] = "%lf %lf %lf %lf";
  char str[] = "NAN nan -INF +inf";
  double o1, o2, o3, o4, s1, s2, s3, s4;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_double_nan(o1);
  ck_assert_double_nan(s1);
  ck_assert_double_nan(o2);
  ck_assert_double_nan(s2);
  ck_assert_double_eq(o3, s3);
  ck_assert_double_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf14_i) {
  char format[100] = "%14i%3i\t%2i%1i";
  char str[100] = "89 -87 45 56";
  int o1, o2, o3, o4, s1, s2, s3, s4;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf15_i) {
  char format[100] = "%14hi%3hi\t%2hi%1hi";
  char str[100] = "89 -87 45 56";
  short o1, o2, o3, o4, s1, s2, s3, s4;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_float_eq(o1, s1);
  ck_assert_float_eq(o2, s2);
  ck_assert_float_eq(o3, s3);
  ck_assert_float_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf16_i) {
  char format[100] = "%14li%3li\t%2li%1li";
  char str[100] = "0xafbcd 0Xf +450001122 56";
  double o1, o2, o3, o4, s1, s2, s3, s4;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_double_eq(o1, s1);
  ck_assert_double_eq(o2, s2);
  ck_assert_double_eq(o3, s3);
  ck_assert_double_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf17_u) {
  char format[100] = "%14lu%3lu\t%2lu%1lu";
  char str[100] = "84564564569 87 455656 56";
  unsigned long int o1, o2, o3, o4, s1, s2, s3, s4;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf18_u) {
  char format[100] = "%14hu%3hu\t%2hu%1hu";
  char str[100] = "89 87 -5 56";
  unsigned short int o1, o2, o3, o4, s1, s2, s3, s4;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf19_u) {
  char format[100] = "%14hu%hu\t%2hu%1hu";
  char str[100] = "9 87 45 56";
  unsigned short int o1, o2, o3, o4, s1, s2, s3, s4;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf20_o) {
  char format[100] = "%14o%o%o";
  char str[100] = "3 7 45 6";
  unsigned int o1, o2, o3, s1, s2, s3;
  int original = sscanf(str, format, &o1, &o2, &o3);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
}
END_TEST

START_TEST(test_sscanf21_o) {
  char format[100] = "%4ho%o%2ho%1ho";
  char str[100] = "12 34 56 78";
  unsigned short int o1, o2, o3, o4, s1, s2, s3, s4;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST
START_TEST(test_sscanf22_o) {
  char format[100] = "%o";
  char str[100] = "0X";
  int o1, s1;
  int original = sscanf(str, format, &o1);
  int s21_func = s21_sscanf(str, format, &s1);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
}
END_TEST

START_TEST(test_sscanf23_x) {
  char format[100] = "%X %x %X";
  char str[100] = "A A A";
  int o1, o2, o3, s1, s2, s3;
  int original = sscanf(str, format, &o1, &o2, &o3);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
}
END_TEST

START_TEST(test_sscanf24_p) {
  char format[100] = "%p %p %p";
  char str[100] = "0x7ffd5c74d840 0x7ffd5c74d844 0x7ffd5c74d848";
  int *o1, *o2, *o3, *s1, *s2, *s3;
  int original = sscanf(str, format, &o1, &o2, &o3);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3);
  ck_assert_int_eq(original, s21_func);
  ck_assert_ptr_eq(o1, s1);
  ck_assert_ptr_eq(o2, s2);
  ck_assert_ptr_eq(o3, s3);
}
END_TEST

START_TEST(test_sscanf25_n) {
  char format[100] = "%d %n %n %n";
  char str[100] = "12 123 1234 12345";
  int o1, o2, o3, o4, s1, s2, s3, s4;
  int original = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_func = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(original, s21_func);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST

Suite *test_sscanf(void) {
  Suite *s = suite_create("\x1b[93;105m S21_SCANF \x1b[0;0m");
  TCase *tc = tcase_create("tc_sscanf");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_sscanf1_c);
  tcase_add_test(tc, test_sscanf2_c);
  tcase_add_test(tc, test_sscanf3_c);
  tcase_add_test(tc, test_sscanf4_c);
  tcase_add_test(tc, test_sscanf5_d);
  tcase_add_test(tc, test_sscanf6_d);
  tcase_add_test(tc, test_sscanf7_d);
  tcase_add_test(tc, test_sscanf8_d);
  tcase_add_test(tc, test_sscanf7_s);
  tcase_add_test(tc, test_sscanf8_s);
  tcase_add_test(tc, test_sscanf9_s);
  tcase_add_test(tc, test_sscanf10_s);
  tcase_add_test(tc, test_sscanf11_f);
  tcase_add_test(tc, test_sscanf12_f);
  tcase_add_test(tc, test_sscanf13_f);
  tcase_add_test(tc, test_sscanf14_i);
  tcase_add_test(tc, test_sscanf15_i);
  tcase_add_test(tc, test_sscanf16_i);
  tcase_add_test(tc, test_sscanf17_u);
  tcase_add_test(tc, test_sscanf18_u);
  tcase_add_test(tc, test_sscanf19_u);
  tcase_add_test(tc, test_sscanf20_o);
  tcase_add_test(tc, test_sscanf21_o);
  tcase_add_test(tc, test_sscanf22_o);
  tcase_add_test(tc, test_sscanf23_x);
  tcase_add_test(tc, test_sscanf24_p);
  tcase_add_test(tc, test_sscanf25_n);

  suite_add_tcase(s, tc);
  return s;
}
