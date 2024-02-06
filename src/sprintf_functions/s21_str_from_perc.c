#include "../s21_string.h"

char *s21_str_from_perc(char *str, Flags *spec) {
  spec->tolerance = 0;
  s21_strcat(str, "%");
  s21_ll_tolerance(str, spec);
  s21_ll_width_flag(str, spec);
  return str;
}
