#include "../s21_string.h"

void s21_str_from_n(s21_size_t const str_len, va_list *args) {
  int *p = va_arg(*args, int *);
  *p = (int)str_len;
}