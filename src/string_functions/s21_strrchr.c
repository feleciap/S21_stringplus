#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  int is_flag = 0;
  char *char_res = S21_NULL;
  s21_size_t len_str = s21_strlen(str);
  str = str + len_str;

  for (int i = (int)len_str; !is_flag && i >= 0; i--) {
    if (*str == c) {
      char_res = (char *)str;
      is_flag = 1;
    }
    str--;
  }
  return char_res;
}