#include "../s21_string.h"

char *s21_str_from_o(char *str, va_list *args, Flags *spec) {
  unsigned long int ld_number;
  unsigned short int sd_number;
  unsigned int number;

  if (spec->flag_space) spec->flag_space = 0;

  switch (spec->len) {
    case 'h':
      sd_number = (unsigned short int)va_arg(*args, unsigned int);
      s21_ol_to_str(str, sd_number, spec->flag_sharp);
      break;
    case 'l':
      ld_number = (unsigned long int)va_arg(*args, unsigned long int);
      s21_ol_to_str(str, ld_number, spec->flag_sharp);
      break;
    default:
      number = va_arg(*args, unsigned int);
      s21_ol_to_str(str, number, spec->flag_sharp);
  }
  s21_ll_tolerance(str, spec);
  s21_sign_flag(str, spec);
  s21_ll_width_flag(str, spec);
  return str;
}
