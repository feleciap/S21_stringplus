#include "../s21_string.h"

char *s21_strchr(const char *str, int ch) {
  char *res = S21_NULL;
  int flag = 0;

  for (; !flag && *str != '\0'; str++) {
    if (*str == ch) {
      res = (char *)str;
      flag = 1;
    }
  }

  if (ch == '\0') res = (char *)str;
  return res;
}
