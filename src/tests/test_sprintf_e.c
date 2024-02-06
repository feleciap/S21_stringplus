#include "s21_test_string.h"

START_TEST(sprintf_1_e) {
  char str1[200];
  char str2[200];
  char *str3 = "%e TEST %.e TEST %4e TEST %4.e TEST %5.10e!";
  double num = 76.756589367;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_e) {
  char str1[200];
  char str2[200];
  char *str3 = "%e TEST %.e TEST %3e TEST %4.e TEST %5.10e!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.5e test: %12.4e!";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.1e test: %16.2e test: %18.3e!";
  double num = -48938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.4e test: %25.5e!";
  double num = -48938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 18.0e test: %+10.e test: %+25.e!";
  double num = 48938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-15.4e !test: %-26.1e !test: %-18.0e!";
  double num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13e !test: %26.15e!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7le !test: %10.15le !test: %25.15le!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13le !test: %26.15le!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7e !test: %10.15e!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 23.14e !test: %+ 25.15e!";
  double num = 365289.346;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
}
END_TEST

START_TEST(sprintf_13_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15e !test: % -26e !test: %- 18e!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 14e!test: %+ 10e !test: % +25e!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 14e !test: % -27e !test: %- 19e!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 16e !test: %+ 44e !test: % +35e!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_e) {
  char str1[400];
  char str2[400];
  char *str3 = "fshgkaljck % 10.12e hgsakul";
  double num = 0.235300;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_e(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_e \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_e);
  tcase_add_test(tc, sprintf_2_e);
  tcase_add_test(tc, sprintf_3_e);
  tcase_add_test(tc, sprintf_4_e);
  tcase_add_test(tc, sprintf_5_e);
  tcase_add_test(tc, sprintf_6_e);
  tcase_add_test(tc, sprintf_7_e);
  tcase_add_test(tc, sprintf_8_e);
  tcase_add_test(tc, sprintf_9_e);
  tcase_add_test(tc, sprintf_10_e);
  tcase_add_test(tc, sprintf_11_e);
  tcase_add_test(tc, sprintf_12_e);
  tcase_add_test(tc, sprintf_13_e);
  tcase_add_test(tc, sprintf_14_e);
  tcase_add_test(tc, sprintf_15_e);
  tcase_add_test(tc, sprintf_16_e);
  tcase_add_test(tc, sprintf_17_e);

  suite_add_tcase(s, tc);
  return s;
}
