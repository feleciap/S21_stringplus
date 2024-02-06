#include "s21_test_string.h"

START_TEST(sprintf_1_e) {
  char str1[200];
  char str2[200];
  char *str3 = "%E TEST %.E TEST %4E TEST %4.E TEST %5.10E!";
  double num = 76.756589367;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_e) {
  char str1[200];
  char str2[200];
  char *str3 = "%E TEST %.E TEST %3E TEST %4.E TEST %5.10E!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.5E test: %12.4E!";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.1E test: %16.2E test: %18.3E!";
  double num = -48938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.4E test: %25.5E!";
  double num = -48938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 18.0E test: %+10.E test: %+25.E!";
  double num = 48938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-15.4E !test: %-26.1E !test: %-18.0E!";
  double num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13E !test: %26.15E!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7E !test: %10.15E !test: %25.15E!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13E !test: %26.15E!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7E !test: %10.15E!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 23.14E !test: %+ 25.15E!";
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
  char *str3 = "test: % 15E !test: % -26E !test: %- 18E!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 14E!test: %+ 10E !test: % +25E!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 14E !test: % -27E !test: %- 19E!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 16E !test: %+ 44E !test: % +35E!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_e) {
  char str1[400];
  char str2[400];
  char *str3 = "fshgkaljck % 10.12E hgsakul";
  double num = 0.235300;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_exp(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_EXP \033[0m");
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
