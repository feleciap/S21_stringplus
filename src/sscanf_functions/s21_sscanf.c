#include "../s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  int rez = 0;
  if (format) {
    va_list arg;
    va_start(arg, format);
    int len = s21_strlen(format);
    int n = 0;
    for (int i = 0; i < len; i++) {
      if (format[i] == '%') {
        struct specificator struct_format = {0, -1, 0, 0};
        i = s21_str_format(format, &struct_format, i);
        n += s21_space(str + n, struct_format);
        if (struct_format.spec == 'c') {
          n += s21_rec_char(arg, str + n, struct_format, &rez);
        } else if (struct_format.spec == 's') {
          n += s21_rec_str(arg, str + n, struct_format, &rez);
        } else if (struct_format.spec == 'i' || struct_format.spec == 'd') {
          n += s21_rec_int_signed(arg, str + n, struct_format, &rez);
        } else if (s21_strchr("ouXxp", struct_format.spec)) {
          n += s21_rec_int_unsigned(arg, str + n, struct_format, &rez);
        } else if (s21_strchr("eEgGf", struct_format.spec)) {
          n += s21_rec_float(arg, str + n, struct_format, &rez);
        } else if (struct_format.spec == 'n') {
          *va_arg(arg, int *) = n;
        } else {
          if (str[n] == '%') n++;
        }
      } else if (s21_strchr(" \n\t\r\f", format[i]) && format[i]) {
        while (s21_strchr(" \n\t\r\f", str[n]) && str[n]) n++;
      } else {
        if (format[i] == str[n]) n++;
      }
    }
    va_end(arg);
    if (rez == 0) rez = -1;
  }
  return rez;
}

int s21_str_format(const char *format, struct specificator *struct_format,
                   int i) {
  char *nums = "0123456789", *spec = "cdieEfgGosuxXpn%";
  i++;
  if (format[i] == '*') {
    struct_format->aster = 1;
    i++;
  } else if (s21_strchr(nums, format[i])) {
    char buff[128];
    int j = 0;
    while (s21_strchr(nums, format[i]) && j < 10) {
      buff[j] = format[i];
      i++;
      j++;
    }
    buff[j] = '\0';
    struct_format->width = s21_char_to_int(buff, 10);
  }
  if (s21_strchr("lLh", format[i])) {
    struct_format->length = format[i];
    i++;
  }
  if (s21_strchr(spec, format[i])) struct_format->spec = format[i];
  return i;
}

int s21_space(const char *str, struct specificator struct_format) {
  int i = 0;
  if (struct_format.spec != 'c')
    while (s21_strchr(" \n\t\r\f", str[i]) && str[i]) i++;
  return i;
}

int s21_rec_char(va_list arg, const char *str,
                 struct specificator struct_format, int *rez) {
  int i = 0;
  if (!struct_format.aster) {
    *va_arg(arg, char *) = str[0];
    if (str[0]) {
      *rez = *rez + 1;
      i++;
    }
  }
  return i;
}

int s21_rec_str(va_list arg, const char *str, struct specificator struct_format,
                int *rez) {
  int i = 0;
  char *buff = S21_NULL;
  if (!struct_format.aster) {
    buff = va_arg(arg, char *);
    if (str[0]) *rez = *rez + 1;
  }
  while (!s21_strchr(" \n\t\r\f", str[i]) && str[i] &&
         i != (struct_format.width)) {
    if (buff) buff[i] = str[i];
    i++;
  }
  buff[i] = '\0';
  return i;
}

int s21_rec_int_signed(va_list arg, const char *str,
                       struct specificator struct_format, int *rez) {
  int i = 0;
  char *buff = calloc(s21_strlen(str) + 1, sizeof(char));
  if (buff) {
    int j = 0;
    int base = 10;
    if (str[i] == '+' || str[i] == '-') {
      buff[j] = str[i];
      i++;
      j++;
    }
    if (str[i] == '0' && struct_format.spec == 'i') {
      base = 8;
      i++;
      if (str[i] == 'x' || str[i] == 'X') {
        base = 16;
        i++;
      }
    }
    char *numstr = (base == 8)    ? "01234567"
                   : (base == 10) ? "0123456789"
                                  : "0123456789abcdefxABCDEFX";
    while (s21_strchr(numstr, str[i]) && str[i] && i != struct_format.width) {
      buff[j] = str[i];
      i++;
      j++;
    }
    buff[i + 1] = '\0';
    if (!struct_format.aster) {
      if (struct_format.length == 'h')
        *va_arg(arg, short int *) = s21_char_to_int(buff, base);
      else if (struct_format.length == 'l')
        *va_arg(arg, long int *) = s21_char_to_int(buff, base);
      else
        *va_arg(arg, int *) = s21_char_to_int(buff, base);
      if (str[0]) *rez = *rez + 1;
    }
  }
  free(buff);
  return i;
}

int s21_rec_int_unsigned(va_list arg, const char *str,
                         struct specificator struct_format, int *rez) {
  int i = 0;
  char *buff = calloc(s21_strlen(str) + 1, sizeof(char));
  if (buff) {
    int j = 0;
    int base = 10;
    if (str[i] == '+' || str[i] == '-') {
      buff[j] = str[i];
      i++;
      j++;
    }
    if (struct_format.spec == 'o') base = 8;
    if (struct_format.spec == 'u') base = 10;
    if (struct_format.spec == 'x' || struct_format.spec == 'X' ||
        struct_format.spec == 'p')
      base = 16;
    char *numstr = (base == 8)    ? "01234567"
                   : (base == 10) ? "0123456789"
                                  : "0123456789abcdefxABCDEFX";
    while (s21_strchr(numstr, str[i]) && str[i] && i != struct_format.width) {
      buff[j] = str[i];
      i++;
      j++;
    }
    buff[i + 1] = '\0';
    if (!struct_format.aster) {
      if (struct_format.spec == 'p') {
        unsigned long int *p_void = va_arg(arg, void *);
        *p_void = s21_char_to_int(buff, base);
      } else if (struct_format.length == 'h')
        *va_arg(arg, unsigned short int *) = s21_char_to_int(buff, base);
      else if (struct_format.length == 'l')
        *va_arg(arg, unsigned long int *) = s21_char_to_int(buff, base);
      else
        *va_arg(arg, unsigned int *) = s21_char_to_int(buff, base);
      if (str[0]) *rez = *rez + 1;
    }
  }
  free(buff);
  return i;
}

int s21_rec_float(va_list arg, const char *str,
                  struct specificator struct_format, int *rez) {
  int i = 0;
  char *buff = calloc(s21_strlen(str) + 1, sizeof(char));
  if (buff) {
    if (str[i] == '+' || str[i] == '-') i++;

    if (s21_strchr("nNiI", str[i])) {
      int nan = i + 3;
      while (s21_strchr("NAIFnaif", str[i]) && str[i] &&
             i != struct_format.width && i < nan)
        i++;
    } else {
      char *numstr = "0123456789";
      int point_count = 0;
      while ((s21_strchr(numstr, str[i]) || str[i] == '.') && str[i] &&
             point_count < 2 && i != struct_format.width) {
        if (str[i] == '.') point_count++;
        i++;
      }
      if (str[i] == 'e' || str[i] == 'E') {
        i++;
        if (str[i] == '+' || str[i] == '-') i++;
        while (s21_strchr(numstr, str[i]) && str[i]) i++;
      }
    }
    int j = 0;
    while (j < i) {
      buff[j] = str[j];
      j++;
    }
    buff[j + 1] = '\0';
  }
  if (!struct_format.aster) {
    if (struct_format.length == 'l') {
      *va_arg(arg, double *) = s21_char_to_float(buff);
    } else if (struct_format.length == 'L') {
      *va_arg(arg, long double *) = s21_char_to_float(buff);
    } else {
      *va_arg(arg, float *) = s21_char_to_float(buff);
    }
    if (str[0]) *rez = *rez + 1;
  }
  free(buff);
  return i;
}

long int s21_char_to_int(char *buff, int base) {
  long int rez = 0;
  int znak = 1;
  int len = s21_strlen(buff);
  for (int i = 0; i < len; i++) {
    long int digit = 0;
    if (buff[i] == '-') {
      i++;
      znak = -1;
    } else if (buff[i] == '+')
      i++;
    if (buff[i] >= '0' && buff[i] <= '9')
      digit = buff[i] - '0';
    else if (buff[i] >= 'a' && buff[i] <= 'f')
      digit = buff[i] - 'a' + 10;
    else if (buff[i] >= 'A' && buff[i] <= 'F')
      digit = buff[i] - 'A' + 10;
    rez = rez * base + digit;
  }
  return rez * znak;
}

long double s21_char_to_float(char *buff) {
  long double rez = 0;
  int i = 0, znak = 1, znak_exp = 1, len = s21_strlen(buff), exp = 0;
  if (buff[0] == '-') {
    znak = -1;
    i++;
  } else if (buff[0] == '+') {
    i++;
  }
  if (s21_strchr("nNiI", buff[i]) && buff[i]) {
    if (s21_strchr("nN", buff[i])) {
      if (s21_strchr("aA", buff[i + 1])) {
        if (s21_strchr("nN", buff[i + 2])) rez = NAN;
      }
    }
    if (s21_strchr("iI", buff[i])) {
      if (s21_strchr("nN", buff[i + 1])) {
        if (s21_strchr("fF", buff[i + 2])) rez = INFINITY;
      }
    }
  } else {
    int point = 0;
    long double decimal = 1;
    int br = 0;
    while (i < len && br == 0) {
      if (buff[i] >= '0' && buff[i] <= '9') {
        if (point) {
          decimal *= 0.1;
          rez = rez + (buff[i] - '0') * decimal;
        } else
          rez = rez * 10 + (buff[i] - '0');
      } else if (buff[i] == '.')
        point = 1;
      else
        br = 1;
      if (br == 0) i++;
    }
    if (buff[i] == 'e' || buff[i] == 'E') {
      i++;
      if (buff[i] == '-') znak_exp = -1;
      if (buff[i]) exp = labs(s21_char_to_int(buff + i, 10));
    }
  }
  return rez * znak * pow(10, znak_exp * exp);
}