#include <string.h>

#include "../s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  s21_size_t flag = 0, error = 0;
  char *str_start = str;
  char *point_str = str;

  str = s21_strcpy(str, "");
  while (*format && error == 0) {
    Flags spec = {0};
    spec.width = spec.tolerance = -1;
    if (*format == '%') {
      flag = 1;
      format++;
    } else {
      *point_str = *format;
      point_str++;
      *point_str = '\0';
      format++;
    }

    if (flag == 1) {
      if (s21_is_flag(*format))
        while (s21_is_flag(*format)) s21_set_flag(&spec, format++);

      if ((s21_is_digit(*format) || *format == '*'))
        format = s21_str_to_int(format, &spec.width, &args);

      if (*format == '.') {
        spec.tolerance = 0;
        format = s21_str_to_int(++format, &spec.tolerance, &args);
      }

      if (s21_is_len(*format)) spec.len = *(format++);
      if (s21_is_spec(*format)) spec.tem = *(format++);

      s21_format_param_to_str(&point_str, &spec, &args);
      error = spec.flag_error;
      flag = 0;
    }
  }

  va_end(args);
  if (error != 0) *str_start = '\0';
  return error == 0 ? (int)(point_str - str) : -1;
}

void s21_set_flag(Flags *spec, const char *format) {
  switch (*format) {
    case '-':
      spec->flag_minus = 1;
      break;
    case '+':
      spec->flag_plus = 1;
      break;
    case ' ':
      spec->flag_space = 1;
      break;
    case '#':
      spec->flag_sharp = 1;
      break;
    case '0':
      spec->flag_zero = 1;
      break;
  }
}

char *s21_str_to_int(const char *format, int *number, va_list *args) {
  *number = 0;
  while (s21_is_digit(*format)) {
    *number = *format - '0' + *number * 10;
    format++;
  }
  if (*format == '*') {
    *number = va_arg(*args, int);
    format++;
  }
  return (char *)format;
}

char *s21_format_param_to_str(char **point_str, Flags *spec, va_list *args) {
  char *temp_str = S21_NULL;
  temp_str = calloc(1000 + spec->width + 2, sizeof(char));

  int flag_c = 0;
  if (temp_str != S21_NULL) {
    switch (spec->tem) {
      case 'c':
        s21_str_from_c(point_str, args, spec);
        flag_c = 1;
        break;
      case 'd':
      case 'i':
        s21_str_from_d_i(temp_str, args, spec);
        break;
      case 'e':
      case 'E':
        s21_str_from_e_E(temp_str, args, spec);
        break;
      case 'f':
        s21_str_from_f(temp_str, args, spec);
        break;
      case 'g':
      case 'G':
        s21_str_from_g_G(temp_str, args, spec);
        break;
      case 'o':
        s21_str_from_o(temp_str, args, spec);
        break;
      case 's':
        s21_str_from_s(temp_str, args, spec);
        break;
      case 'u':
        s21_str_from_u(temp_str, args, spec);
        break;
      case 'x':
      case 'X':
        s21_str_from_x_X(temp_str, args, spec);
        break;
      case 'p':
        s21_str_from_p(temp_str, args, spec);
        break;
      case '%':
        s21_str_from_perc(temp_str, spec);
        break;
    }

    if (!flag_c) {
      s21_strcat(*point_str, temp_str);
      *point_str += s21_strlen(temp_str);
    }
    free(temp_str);
  }
  return *point_str;
}
