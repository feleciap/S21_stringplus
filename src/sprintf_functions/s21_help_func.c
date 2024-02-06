#include "../s21_string.h"

int s21_is_flag(char ch) {
  int res =
      ((ch) == '-' || (ch) == '+' || (ch) == ' ' || (ch) == '#' || (ch) == '0');
  return res;
}

int s21_is_digit(char ch) {
  int res = ((ch) >= '0' && (ch) <= '9');
  return res;
}

int s21_is_len(char ch) {
  int res = ((ch) == 'h' || (ch) == 'l' || (ch) == 'L');
  return res;
}

int s21_is_octal_digit(char ch) {
  int res = ((ch) >= '0' && (ch) <= '7');
  return res;
}
int s21_is_hex_digit(char ch) {
  int res = (((ch) >= '0' && (ch) <= '9') || (ch) == 'a' || (ch) == 'b' ||
             (ch) == 'c' || (ch) == 'd' || (ch) == 'e' || (ch) == 'f' ||
             (ch) == 'A' || (ch) == 'B' || (ch) == 'C' || (ch) == 'D' ||
             (ch) == 'E' || (ch) == 'F');
  return res;
}

int s21_is_spec(char ch) {
  int res = ((ch) == 'c' || (ch) == 'd' || (ch) == 'i' || (ch) == 'f' ||
             (ch) == 's' || (ch) == 'u' || (ch) == '%' || (ch) == 'g' ||
             (ch) == 'G' || (ch) == 'e' || (ch) == 'E' || (ch) == 'x' ||
             (ch) == 'X' || (ch) == 'o' || (ch) == 'n' || (ch) == 'p');
  return res;
}

char *s21_wch_to_str(char *str, wchar_t *wstr, s21_size_t len) {
  s21_size_t str_len = s21_strlen(str);
  int cnt = len;
  char *p = str + str_len;

  while (*wstr != '\0' && (cnt-- > 0 || len == 0)) {
    *(p++) = (char)*(wstr++);
  }
  *p = '\0';
  return str;
}

char *s21_ll_width_flag(char *str, Flags *spec) {
  int str_len = (int)s21_strlen(str);
  if (spec->width > (int)str_len) {
    char *num_str = calloc(1000 + spec->width + 2, sizeof(char));
    if (num_str) {
      for (int i = 0; i < spec->width; i++) {
        if (spec->flag_minus == 1) {
          if (i < str_len) {
            num_str[i] = str[i];
          } else {
            num_str[i] = ' ';
          }

        } else {
          if (i < spec->width - str_len) {
            if (spec->flag_zero == 1) {
              num_str[i] = '0';
            } else {
              num_str[i] = ' ';
            }

          } else {
            num_str[i] = str[i - (spec->width - str_len)];
          }
        }
      }
      num_str[spec->width] = '\0';
      str = s21_strcpy(str, num_str);
      free(num_str);
    }
  }
  return str;
}

char *s21_ll_to_str(char *str, long long number) {
  char *p = S21_NULL;
  int flag = 1, sign;

  sign = number < 0 ? -1 : 1;
  number *= sign;
  p = str;

  while (flag) {
    int digit;
    if (number >= 10) {
      digit = (int)(number % 10);
      number = (number - digit) / 10;
    } else {
      digit = (int)number;
      flag = 0;
    }
    *(p++) = (char)(digit + '0');
  }

  if (sign < 0) {
    *(p++) = '-';
  }
  *p = '\0';
  s21_reverse_str(str);
  return str;
}

char *s21_reverse_str(char *str) {
  s21_size_t str_len = s21_strlen(str);
  char ch;
  for (s21_size_t i = 0; i < str_len / 2; i++) {
    ch = str[i];
    str[i] = str[str_len - 1 - i];
    str[str_len - 1 - i] = ch;
  }
  return str;
}

char *s21_leE_to_str(char *str, long double number, Flags *spec) {
  if (spec->tolerance < 0) spec->tolerance = 6;
  long double right = 0.0, mantis;
  int pow = 0;

  mantis = modfl(fabsl(number), &right);
  if (fpclassify(number) > 3) {
    while (right >= 10) {
      pow++;
      modfl(right / 10, &right);
    }
    if (pow == 0 && right < 1) {
      while (truncl(mantis * powl(10, pow * -1)) < 1) {
        pow--;
      }
    }
  }

  if (fpclassify(number) > 2) {
    number = number / powl(10, pow);
    s21_sprintf(str, spec->flag_sharp == 1 ? "%#.*Lfe%+.2d" : "%.*Lfe%+.2d",
                spec->tolerance, number, pow);
  } else {
    s21_sprintf(str, "%.*Lf", spec->tolerance);
    spec->flag_zero = 0;
  }
  if (spec->tem == 'E') {
    char *p = S21_NULL;
    p = s21_strchr(str, 'e');
    if (p) *p = 'E';
  }
  return str;
}
char *s21_sign_flag(char *str, Flags *spec) {
  if (s21_is_digit(*str) || *str == 'i') {
    char num_str[2] = "";
    char *p = S21_NULL;
    p = num_str;
    if (spec->flag_plus)
      *(p++) = '+';
    else if (spec->flag_space)
      *(p++) = ' ';
    *p = '\0';
    s21_reverse_str(str);
    s21_strcat(str, num_str);
    s21_reverse_str(str);
  }
  return str;
}

char *s21_lf_width_flag(char *str, Flags *spec) {
  int str_len = (int)s21_strlen(str);
  char *p = S21_NULL, *p2 = S21_NULL;
  p2 = str;
  if (spec->width > (int)str_len) {
    char *num_str = calloc(1000 + spec->width + 2, sizeof(char));
    if (num_str) {
      p = num_str;
      if (!s21_is_digit(*p2) && spec->flag_zero) {
        *(p++) = *(p2++);
      }
      for (int i = 0; i < spec->width; i++) {
        if (spec->flag_minus == 1) {
          if (i < str_len) {
            *(p++) = *(p2++);
          } else {
            if (spec->flag_zero == 1)
              *(p++) = '0';
            else
              *(p++) = ' ';
          }
        } else {
          if (i < spec->width - str_len) {
            if (spec->flag_zero == 1)
              *(p++) = '0';
            else
              *(p++) = ' ';
          } else {
            *(p++) = *(p2++);
          }
        }
      }
      num_str[spec->width] = '\0';
      str = s21_strcpy(str, num_str);
      free(num_str);
    }
  }
  return str;
}

char *s21_lf_to_str(char *str, long double number, Flags *spec) {
  if (spec->tolerance < 0) spec->tolerance = 6;
  s21_ld_to_a(str, number, spec);
  return str;
}

char *s21_ld_to_a(char *str, long double number, Flags *spec) {
  char num1_str[1000] = "", *p1 = S21_NULL;
  p1 = num1_str;
  char num2_str[1000] = "", *p2 = S21_NULL;
  p2 = num2_str;
  long double mantis, right = 0.0L, pow = 1.0L, pow_t = 1.0L;
  int sign;
  sign = signbit(number) == 0 ? 1 : -1;

  if (fpclassify(number) < 4) {
    s21_d_class_to_str(num1_str, number, spec->tolerance);
    if (sign < 0 && fpclassify(number) != 1) s21_strcat(str, "-");
    s21_strcat(str, num1_str);
    spec->flag_zero = 0;
  } else {
    number = s21_round(number, spec->tolerance);
    mantis = modfl(fabsl(number), &right);

    while (truncl(right / pow) > 0) {
      int digit;
      digit = (int)truncl(fmodl(truncl(right), pow * (long double)10L) / (pow));
      *(p1++) = (char)(digit + '0');
      pow *= 10L;
    }

    if (sign < 0) *(p1++) = '-';
    *p1 = '\0';

    for (int i = 0; i < spec->tolerance; i++) pow_t *= 10;

    mantis = roundl(mantis * pow_t);
    pow = 1.0L;
    while (pow < pow_t) {
      int digit;
      digit =
          (int)truncl(fmodl(truncl(mantis), pow * (long double)10L) / (pow));
      *(p2++) = (char)(digit + '0');
      pow *= 10L;
    }
    *p2 = '\0';
    s21_reverse_str(num1_str);
    if (s21_strlen(num1_str) == 0) s21_strcat(str, "0");
    s21_strcat(str, num1_str);
    if (spec->tolerance > 0 || spec->flag_sharp == 1) s21_strcat(str, ".");
    if (spec->tolerance > 0) {
      s21_reverse_str(num2_str);
      s21_strcat(str, num2_str);
    }
  }
  return str;
}

char *s21_d_class_to_str(char *str, long double x, int tolerance) {
  switch (fpclassify(x)) {
    case FP_NAN:
      s21_strcat(str, "nan");
      break;
    case FP_INFINITE:
      s21_strcat(str, "inf");
      break;
    case FP_ZERO:
      s21_strcat(str, "0");
      if (tolerance > 0) {
        s21_strcat(str, ".");
        while (tolerance--) s21_strcat(str, "0");
      }
      break;
  }
  return str;
}

long double s21_round(long double x, int tolerance) {
  long double right = 0.0;
  long double x1 = modfl(fabsl(x), &right);
  int mul = 0;
  int sign = signbit(x) == 0 ? 1 : -1;
  for (int i = 0; i < tolerance; i++) mul--;

  if (roundl(x1 / powl(10, mul)) > truncl(x1 / powl(10, mul))) {
    x = x + (5 * powl(10, mul - 1)) * sign;
  }
  if (tolerance <= 6 && x1 > 0) {
    x = x / powl(10, mul);
    x = truncl(x) * powl(10, mul);
  }
  return x;
}

char *s21_lgG_to_str(char *str, long double number, Flags *spec) {
  if (spec->tolerance < 0) spec->tolerance = 6;
  long double right = 0.0;
  int pow = 0, pow_m = 0;

  long double mantis = modfl(fabsl(number), &right);
  if (fpclassify(mantis) > 3 && fpclassify(right) == 3) {
    while (truncl(mantis * powl(10, pow * -1)) < 1) {
      pow--;
    }
  }
  mantis = modfl(fabsl(number), &right);
  if (fpclassify(number) > 3) {
    while (right >= 1 && pow >= 0) {
      pow++;
      modfl(right / 10, &right);
    }
    if (fpclassify(mantis) > 3) {
      for (int i = 0; i < spec->tolerance - pow; i++) {
        mantis = modfl(right / 10, &right);
        if (fpclassify(mantis) > 3) {
          pow_m++;
        }
      }
    }
  }

  int flag;
  int tolerance;
  if (pow - 1 < -4 || pow - 1 > spec->tolerance - 1) {
    flag = 1;
    tolerance = spec->tolerance > 0 ? spec->tolerance - 1 : 0;
  } else {
    flag = 0;
    if (pow < 0)
      tolerance = spec->tolerance > 0 ? spec->tolerance : 0;
    else
      tolerance = spec->tolerance > 0 ? spec->tolerance - pow : 0;
  }

  if (flag == 1) {
    if (spec->tem == 'G')
      s21_sprintf(str, spec->flag_sharp == 1 ? "%#.*LE" : "%.*LE", tolerance,
                  number);
    else
      s21_sprintf(str, spec->flag_sharp == 1 ? "%#.*Le" : "%.*Le", tolerance,
                  number);
  } else {
    s21_sprintf(str, spec->flag_sharp == 1 ? "%#.*Lf" : "%.*Lf", tolerance,
                number);
  }

  char *p = S21_NULL;
  if (pow < 0 && flag == 1) {
    p = str;
    s21_size_t str_len =
        (s21_size_t)s21_strpbrk(str, spec->tem == 'G' ? "E" : "e") - *p;
    if (str_len > 2 && (int)str_len - 1 >= spec->tolerance &&
        *(p + str_len - 1) == '0' && spec->flag_sharp == 0) {
      p = p + str_len - 1;
      while (*p == '0') {
        *(p--) = '\0';
      }
      p = str + str_len;
      s21_strcat(str, p);
    }
  }

  p = str;
  p = p + s21_strlen(str) - 1;

  while (*p == '0' && spec->flag_sharp != 1) {
    *p-- = '\0';
  }
  if (*p == '.' && spec->flag_sharp != 1) {
    *p = '\0';
  }

  return str;
}

char *s21_ol_to_str(char *str, unsigned long long number, int prefix) {
  char *p = S21_NULL;
  int flag = 1;

  p = str;

  while (flag) {
    unsigned int digit;
    if (number > 7) {
      digit = number % 8;
      number = (number - digit) / 8;
    } else {
      digit = number;
      flag = 0;
    }
    *(p++) = (char)(digit + '0');
  }

  if (prefix == 1) *(p++) = '0';
  *p = '\0';
  s21_reverse_str(str);
  return str;
}

char *s21_ll_tolerance(char *str, Flags *spec) {
  char *num_str = calloc(1000 + spec->width + 2, sizeof(char));
  if (num_str) {
    s21_size_t str_len = s21_strlen(str);
    int shift;
    char *p = S21_NULL;
    char *s = S21_NULL;
    p = num_str;
    s = str;

    int sign = *s == '-' ? -1 : 0;
    if (spec->flag_zero == 1)
      spec->tolerance =
          (spec->tolerance > spec->width) ? spec->tolerance : spec->width;

    spec->tolerance = spec->tolerance > (int)str_len + sign
                          ? spec->tolerance
                          : (int)str_len + sign;
    shift = spec->tem == 'x' && spec->flag_sharp == 1 ? 32 : 0;

    s21_reverse_str(str);
    for (int i = 0; i < spec->tolerance; i++) {
      if (i < (int)str_len + sign)
        *(p++) = *(s++);
      else
        *(p++) = '0';
    }

    if (spec->flag_sharp == 1 && spec->tem == (char)('X' + shift)) {
      *(p++) = (char)('X' + shift);
      *(p++) = '0';
    }

    if (sign < 0) *(p++) = '-';
    *p = '\0';
    s21_reverse_str(num_str);
    s21_strcpy(str, num_str);
    free(num_str);
  }
  return str;
}

char *s21_ul_to_str(char *str, unsigned long long number) {
  char *p = S21_NULL;
  int flag = 1;

  p = str;

  while (flag) {
    int digit;
    if (number >= 10) {
      digit = (int)(number % 10);
      number = (number - digit) / 10;
    } else {
      digit = (int)number;
      flag = 0;
    }
    *(p++) = (char)(digit + '0');
  }
  *p = '\0';
  s21_reverse_str(str);
  return str;
}

char *s21_hl_to_str(char *str, unsigned long long number, Flags *spec) {
  char *p = S21_NULL;
  int flag = 1, shift;

  p = str;
  shift = spec->tem == 'x' ? 32 : 0;

  while (flag) {
    unsigned int digit;
    if (number > 15) {
      digit = number % 16;
      number = (number - digit) / 16;
    } else {
      digit = number;
      flag = 0;
    }
    if (digit < 10)
      *(p++) = (char)(digit + '0');
    else
      *(p++) = (char)(digit + 'A' + shift - 10);
  }
  *p = '\0';
  s21_reverse_str(str);
  return str;
}