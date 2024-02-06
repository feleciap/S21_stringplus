#include "../s21_string.h"

char *s21_str_from_p(char *str, va_list *argList, Flags *spec) {
  int width = spec->width < 15 ? 15 : spec->width;
  char *str_start = S21_NULL;
  str_start = str;
  int *p = va_arg(*argList, int *);
  char buf[4] = "x0";
  if (p == S21_NULL) {
    s21_strcpy(buf, "0x0");
  }

  for (int *j = p, k = 0; j && k < width;
       j = (void *)(((s21_size_t)j) >> 4), k++) {
    unsigned int dig = ((s21_size_t)j) % 0x10;
    if (dig < 10 && spec->tem == 'p')
      *(str_start++) = (char)('0' + dig);
    else
      *(str_start++) = (char)('a' + (dig - 10));
  }
  *str_start = '\0';
  s21_strcat(str, buf);
  s21_reverse_str(str);
  s21_ll_width_flag(str, spec);
  return str;
}
