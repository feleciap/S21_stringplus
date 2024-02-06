#include "../s21_string.h"

char *s21_str_from_s(char *str, va_list *args, Flags *spec) {
  wchar_t *pw = S21_NULL;
  char *p = S21_NULL;

  switch (spec->len) {
    case 'l':
      pw = va_arg(*args, wchar_t *);
      if (!pw) {
        if (spec->tolerance < 6)
          s21_strncat(str, "(null)", spec->tolerance);
        else
          s21_strcat(str, "(null)");
      } else {
        s21_wch_to_str(str, pw, spec->tolerance > -1 ? spec->tolerance : 0);
      }
      break;
    default:
      p = va_arg(*args, char *);
      if (!p) {
        if (spec->tolerance < 6)
          s21_strncat(str, "(null)", spec->tolerance);
        else
          s21_strcat(str, "(null)");
      } else {
        if (spec->tolerance > -1)
          s21_strncat(str, p, spec->tolerance);
        else
          s21_strcat(str, p);
      }
  }
  s21_ll_width_flag(str, spec);
  return str;
}