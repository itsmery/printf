#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

/* Function prototypes */
int _putchar(char c);
int _printf(const char *format, ...);
int hd_char(va_list args);
int hd_string(va_list args);
void _print_integer(long int n, int *ct, char flag, int start);
int hd_integer(va_list args, char flag, char length_m);
int hd_binary(va_list args);
int hd_unsigned_int(va_list args, char length);
int print_unsigned_int(unsigned int num);
int print_unsigned_int_l(unsigned long int num_l);
int print_unsigned_int_h(unsigned short int num_h);
int hd_octal(va_list args, char flag, char length);
int print_octal(unsigned int num, char flag);
int print_octal_h(unsigned short int num_h, char flag);
int print_octal_l(unsigned long int num_l, char flag);
int hd_hex_lower(va_list args, char flag, char length);
int hd_hex_upper(va_list args, char flag, char length);
int print_hex(unsigned int num, int upper, char flag);
int print_hex_h(unsigned short int num, int upper, char flag);
int print_hex_l(unsigned long int num, int upper, char flag);
int hd_specifier(char specifier, va_list args, char flag, char length);
int hd_specifier_ext(char specifier, va_list args, char flag, char length);
int print_hex_char(unsigned char c, char flag);
int hd_custom_S(va_list args);
int hd_pointer(va_list args);
int hd_flag_and_specifier(const char **format, va_list args, int *ct);

#endif
