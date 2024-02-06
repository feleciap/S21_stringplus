#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  int is_flag = 0;
  char *char_res = S21_NULL;

  if (*needle == '\0') char_res = (char *)haystack;

  for (; !is_flag && *haystack != '\0'; haystack++) {
    if (*haystack == needle[0]) {
      is_flag = 1;
      char_res = (char *)haystack;

      for (s21_size_t i = 0; is_flag && needle[i] != '\0'; i++) {
        if (*haystack == needle[i]) {
          haystack++;
        } else {
          is_flag = 0;
          char_res = S21_NULL;
          haystack++;
        }
      }
    }
  }
  return char_res;
}