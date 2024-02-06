#include "../s21_string.h"

char *s21_str_from_u(char *str, va_list *args, Flags *spec) {
  unsigned short us_number;
  unsigned long ul_number;
  unsigned int u_number;

  switch (spec->len) {
    case 'h':
      us_number = (unsigned short)va_arg(*args, unsigned int);
      s21_ll_to_str(str, us_number);
      break;
    case 'l':
      ul_number = (unsigned long)va_arg(*args, unsigned long);
      s21_ul_to_str(str, ul_number);
      break;
    default:
      u_number = (unsigned int)va_arg(*args, unsigned int);
      s21_ll_to_str(str, u_number);
  }

  s21_ll_tolerance(str, spec);
  if (spec->flag_plus && !spec->flag_plus) s21_sign_flag(str, spec);
  s21_ll_width_flag(str, spec);
  return str;
}
