#include "../s21_string.h"

char **s21_str_from_c(char **point_str, va_list *args, Flags *spec) {
  wchar_t wchar;
  wchar_t wchar_s[10] = {0};

  char *temp_str = S21_NULL;
  temp_str = calloc(1000 + spec->width + 2, sizeof(char));

  if (temp_str != S21_NULL) {
    switch (spec->len) {
      case 'l':
        wchar = va_arg(*args, wchar_t);
        wchar_s[0] = wchar;
        s21_wch_to_str(temp_str, wchar_s, 0);
        break;
      default:
        temp_str[0] = va_arg(*args, int);
        temp_str[1] = '\0';
    }

    s21_ll_width_flag(temp_str, spec);

    if (*temp_str != '\0') {
      for (s21_size_t i = 0; temp_str[i] != '\0'; i++) {
        **point_str = temp_str[i];
        *point_str += 1;
      }
      **point_str = '\0';
    } else {
      **point_str = temp_str[0];
      *point_str += 1;
      **point_str = '\0';
    }
  }

  free(temp_str);
  return point_str;
}
