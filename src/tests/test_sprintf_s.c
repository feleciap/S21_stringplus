#include "s21_test_string.h"

START_TEST(sprintf_1_string) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %s Test";
  char *a = "Why am I here?!";
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *a = "I'm so tired";
  char *b = "Who invented this?";
  char *c = "This project gave me hemmoroids";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *a = "Don't need this test";
  char *b = "Just for the kicks";
  char *c = "Lol";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_string) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %ls Test2";
  wchar_t *a = L"3wtf80";

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%3s Test %5s Test %10s";
  char *a = "WHAT IS THIS";
  char *b = "i don't care anymore";
  char *c = "PPAP";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5s Test %.23s Test %3.s TEST %.s";
  char *a = "WHAT IS THIS";
  char *b = "i don't care anymore, really";
  char *c = "PPAP";
  char *d = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5s Test %-.8s Test %-7s TEST %-.s";
  char *a = "WHAT IS THIS";
  char *b = "i don't care anymore, really";
  char *c = "PPAP";
  char *d = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%0s Test %0.s Test %0.0s TEST %0s GOD %.s";
  char *a = "WHAT IS THIS";
  char *b = "i don't care anymore, really";
  char *c = "PPAP";
  char *d = "I don't feel so good";
  char *e = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3.s Test %5.7s TEST %10s";
  char *a = "WHAT IS THIS";
  char *b = "i don't care anymore, really";
  char *c = "abcd";
  char *d = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_string) {
  char str1[200];
  char str2[200];
  char *str3 = "% s Test % 3.s Test % 5.7s TEST % 10s GOD %.s";
  char *a = "WHAT IS THIS";
  char *b = "i don't care anymore, really";
  char *c = "PPAP";
  char *d = "I don't feel so good";
  char *e = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3.s Test %+5.7s TEST %+10s GOD %+.s";
  char *a = '\0';
  char *b = '\0';
  char *c = '\0';
  char *d = '\0';
  char *e = '\0';
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s %s %s %% %d";
  char *a = "This";
  char *b = '\0';
  int c = 65;
  char *d = "string";
  ck_assert_int_eq(sprintf(str1, str3, a, b, d, c),
                   s21_sprintf(str2, str3, a, b, d, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_string) {
  char str1[1000];
  char str2[1000];
  char s[10] = {'h', 'e', 'l', 'l', 'o'};
  int r1 =
      sprintf(str1, "1:%ls 2:%10ls 3:%.0s 4:%7.2ls 5:%-10.3ls 6:%5.3s 7:%-5.0s",
              L"al", L"helloworld", "SCHOOL21", L"MAF", L"GAV", s, s);
  int r2 = s21_sprintf(
      str2, "1:%ls 2:%10ls 3:%.0s 4:%7.2ls 5:%-10.3ls 6:%5.3s 7:%-5.0s", L"al",
      L"helloworld", "SCHOOL21", L"MAF", L"GAV", s, s);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

Suite *test_sprintf_s(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_S \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_string);
  tcase_add_test(tc, sprintf_2_string);
  tcase_add_test(tc, sprintf_3_string);
  tcase_add_test(tc, sprintf_4_string);
  tcase_add_test(tc, sprintf_5_string);
  tcase_add_test(tc, sprintf_6_string);
  tcase_add_test(tc, sprintf_7_string);
  tcase_add_test(tc, sprintf_8_string);
  tcase_add_test(tc, sprintf_9_string);
  tcase_add_test(tc, sprintf_11_string);
  tcase_add_test(tc, sprintf_12_string);
  tcase_add_test(tc, sprintf_16_string);
  tcase_add_test(tc, sprintf_17_string);

  suite_add_tcase(s, tc);
  return s;
}
