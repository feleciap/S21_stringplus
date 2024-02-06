#include "../s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  int i = 0;
  int length = s21_strlen(src);

  for (i = 0; i < length; i++) {
    dest[i] = src[i];
  }

  dest[i] = '\0';

  return dest;
}
