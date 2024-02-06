#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S21_NULL ((void *)0)
#define s21_size_t unsigned long

struct specificator {
  int aster, width;
  char spec, length;
};

typedef struct Format {
  int flag_minus;
  int flag_plus;
  int flag_space;
  int flag_sharp;
  int flag_zero;
  int flag_error;
  int width;      //  ширина
  int tolerance;  //  точность
  char len;       //  h, l
  char tem;       // Спецификаторы: c, d, i, f, s, u, %
} Flags;

/********* SPRINTF FUNCTIONS *********/
int s21_is_flag(char ch);
int s21_is_digit(char ch);
int s21_is_len(char ch);
int s21_is_octal_digit(char ch);
int s21_is_hex_digit(char ch);
int s21_is_spec(char ch);
void s21_set_flag(Flags *spec, const char *format);
char *s21_strcpy(char *dest, const char *src);
char *s21_strcat(char *destination, const char *append);

int s21_sprintf(char *str, const char *format, ...);
char *s21_format_param_to_str(char **point_str, Flags *spec, va_list *args);
char **s21_str_from_c(char **point_str, va_list *args, Flags *spec);
char *s21_str_to_int(const char *format, int *number, va_list *args);
char *s21_str_from_d_i(char *str, va_list *args, Flags *spec);
char *s21_str_from_f(char *str, va_list *args, Flags *spec);
char *s21_str_from_g_G(char *str, va_list *args, Flags *spec);
char *s21_str_from_s(char *str, va_list *args, Flags *spec);
char *s21_str_from_u(char *str, va_list *args, Flags *spec);
char *s21_str_from_o(char *str, va_list *args, Flags *spec);
char *s21_str_from_x_X(char *str, va_list *args, Flags *spec);
char *s21_str_from_p(char *str, va_list *argList, Flags *spec);
void s21_str_from_n(s21_size_t const str_len, va_list *args);
char *s21_str_from_perc(char *str, Flags *spec);

long double s21_round(long double x, int tolerance);
char *s21_wch_to_str(char *str, wchar_t *wstr, s21_size_t len);
char *s21_ll_width_flag(char *str, Flags *spec);
char *s21_reverse_str(char *str);
char *s21_str_from_e_E(char *str, va_list *args, Flags *spec);
char *s21_leE_to_str(char *str, long double number, Flags *spec);
char *s21_sign_flag(char *str, Flags *spec);
char *s21_lf_width_flag(char *str, Flags *spec);
char *s21_lf_to_str(char *str, long double number, Flags *spec);
char *s21_ld_to_a(char *str, long double number, Flags *spec);
char *s21_d_class_to_str(char *str, long double x, int tolerance);
char *s21_lgG_to_str(char *str, long double number, Flags *spec);
char *s21_ol_to_str(char *str, unsigned long long number, int prefix);
char *s21_ll_tolerance(char *str, Flags *spec);
char *s21_ul_to_str(char *str, unsigned long long number);
char *s21_hl_to_str(char *str, unsigned long long number, Flags *spec);
char *s21_ll_to_str(char *str, long long number);

/********* SCANF FUNCTIONS *********/
int s21_sscanf(const char *str, const char *format, ...);
int s21_str_format(const char *format, struct specificator *struct_format,
                   int i);
int s21_space(const char *str, struct specificator struct_format);
int s21_rec_char(va_list arg, const char *str,
                 struct specificator struct_format, int *rez);
int s21_rec_str(va_list arg, const char *str, struct specificator struct_format,
                int *rez);
int s21_rec_int_signed(va_list arg, const char *str,
                       struct specificator struct_format, int *rez);
int s21_rec_int_unsigned(va_list arg, const char *str,
                         struct specificator struct_format, int *rez);
int s21_rec_float(va_list arg, const char *str,
                  struct specificator struct_format, int *rez);
long int s21_char_to_int(char *buff, int base);
long double s21_char_to_float(char *buff);

/********* STRING FUNCTIONS *********/
int s21_memcmp(const void *arr1, const void *arr2, s21_size_t num);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strerror(int errnum);
char *s21_strchr(const char *str, int ch);
char *s21_strrchr(const char *str, int c);
char *s21_strtok(char *str, const char *delim);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strncat(char *destination, const char *append, s21_size_t n);
char *s21_strncpy(char *destination, const char *source, s21_size_t n);
void *s21_memset(void *destination, int c, s21_size_t n);
void *s21_memchr(const void *arr, int value, s21_size_t num);
void *s21_memcpy(void *destination, const void *source, s21_size_t n);
s21_size_t s21_strcspn(const char *str, const char *sym);
s21_size_t s21_strlen(const char *str);

/********* SPECIAL FUNCTIONS *********/
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_str_i);
void *s21_trim(const char *src, const char *trim_chars);

#endif  // SRC_S21_STRING_H_
