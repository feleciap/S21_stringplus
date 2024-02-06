#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  int is_flag = 0;
  char *char_res = S21_NULL;

  for (; !is_flag && *str1 != '\0'; str1++) {
    for (s21_size_t i = 0; !is_flag && str2[i] != '\0'; i++) {
      if (*str1 == str2[i]) {
        char_res = (char *)str1;
        is_flag = 1;
      }
    }
  }

  return char_res;
}
