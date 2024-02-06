#include "../s21_string.h"

void *s21_memset(void *destination, int c, s21_size_t n) {
  unsigned char *p = (unsigned char *)destination;
  unsigned char v = (unsigned char)c;

  for (s21_size_t i = 0; i < n; i++) {
    p[i] = v;
  }

  return destination;
}
