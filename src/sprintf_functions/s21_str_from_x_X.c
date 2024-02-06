#include "../s21_string.h"

char *s21_str_from_x_X(char *str, va_list *args, Flags *spec) {
  unsigned long int ld_number;
  unsigned short int sd_number;
  unsigned int number;

  switch (spec->len) {
    case 'h':
      sd_number = (short unsigned int)va_arg(*args, unsigned int);
      s21_hl_to_str(str, sd_number, spec);
      break;
    case 'l':
      ld_number = (long unsigned int)va_arg(*args, unsigned long int);
      s21_hl_to_str(str, ld_number, spec);
      break;
    default:
      number = (unsigned int)va_arg(*args, unsigned int);
      s21_hl_to_str(str, number, spec);
  }
  s21_ll_tolerance(str, spec);
  s21_sign_flag(str, spec);
  s21_ll_width_flag(str, spec);

  return str;
}
