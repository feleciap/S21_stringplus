#include "../s21_string.h"

char *s21_strcat(char *destination, const char *append) {
  char *dest = destination;

  while (*dest != '\0') {
    dest++;
  }

  while (*append != '\0') {
    *dest++ = *append++;
  }

  *dest = '\0';
  return destination;
}
