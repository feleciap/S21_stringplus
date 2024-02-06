#include "s21_test_string.h"

START_TEST(sprintf_1_G) {
  char str1[200];
  char str2[200];
  char *str3 = "%G TEST %.G TEST %4G TEST %4.G TEST %5.10G!";
  double num = 76.756589367;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_G) {
  char str1[200];
  char str2[200];
  char *str3 = "%G TEST %.G TEST %3G TEST %4.G TEST %5.10G!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_G) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.5Gtest: %12.4G!";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_G) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.1Gtest: %16.2Gtest: %18.3G!";
  double num = -48938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_G) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.4Gtest: %25.5G!";
  double num = -48938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_G) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 18.0Gtest: %+10.Gtest: %+25.G!";
  double num = 48938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_G) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-15.4G!test: %-26.1G!test: %-18.0G!";
  double num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_G) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13G!test: %26.15G!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_G) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7G!test: %10.15G!test: %25.15G!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_G) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13G!test: %26.15G!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_G) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7G!test: %10.15G!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_G) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 23.14G!test: %+ 25.15G!";
  double num = 365289.346;
  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
}
END_TEST

START_TEST(sprintf_13_G) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15G!test: % -26G!test: %- 18G!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_G) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 14G!test: %+ 10G!test: % +25G!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_G) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 14G!test: % -27G!test: %- 19G!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_G) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 16G!test: %+ 44G!test: % +35G!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_G) {
  char str1[400];
  char str2[400];
  char *str3 = "GshGkaljck% 10.12G hGsakul";
  double num = 0.235300;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_G(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_G \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_G);
  tcase_add_test(tc, sprintf_2_G);
  tcase_add_test(tc, sprintf_3_G);
  tcase_add_test(tc, sprintf_4_G);
  tcase_add_test(tc, sprintf_5_G);
  tcase_add_test(tc, sprintf_6_G);
  tcase_add_test(tc, sprintf_7_G);
  tcase_add_test(tc, sprintf_8_G);
  tcase_add_test(tc, sprintf_9_G);
  tcase_add_test(tc, sprintf_10_G);
  tcase_add_test(tc, sprintf_11_G);
  tcase_add_test(tc, sprintf_12_G);
  tcase_add_test(tc, sprintf_13_G);
  tcase_add_test(tc, sprintf_14_G);
  tcase_add_test(tc, sprintf_15_G);
  tcase_add_test(tc, sprintf_16_G);
  tcase_add_test(tc, sprintf_17_G);

  suite_add_tcase(s, tc);
  return s;
}
