#include "../s21_string.h"

char *s21_str_from_f(char *str, va_list *args, Flags *spec) {
  long double ld_number;
  double d_number;
  double f_number;
  if (spec->flag_minus) spec->flag_zero = 0;

  switch (spec->len) {
    case 'l':
      d_number = (double)va_arg(*args, double);
      s21_lf_to_str(str, d_number, spec);
      break;
    case 'L':
      ld_number = va_arg(*args, long double);
      s21_lf_to_str(str, ld_number, spec);
      break;
    default:
      d_number = va_arg(*args, double);
      f_number = d_number;
      s21_lf_to_str(str, f_number, spec);
  }
  s21_sign_flag(str, spec);
  s21_lf_width_flag(str, spec);
  return str;
}