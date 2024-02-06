#include "../s21_string.h"

char *s21_str_from_d_i(char *str, va_list *args, Flags *spec) {
  long int ld_number;
  short int sd_number;
  int number;

  switch (spec->len) {
    case 'h':
      sd_number = (short int)va_arg(*args, int);
      s21_ll_to_str(str, sd_number);
      break;
    case 'l':
      ld_number = (long int)va_arg(*args, long int);
      s21_ll_to_str(str, ld_number);
      break;
    default:
      number = va_arg(*args, int);
      s21_ll_to_str(str, number);
  }
  s21_ll_tolerance(str, spec);
  s21_sign_flag(str, spec);
  s21_ll_width_flag(str, spec);
  return str;
}
