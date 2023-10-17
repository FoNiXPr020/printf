#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

/**
 * struct form_spec - That defines a structure for symbols and functions
 * @c: type
 * @f: function to print
 */
typedef struct format_spec
{
	char *c;
	int (*f)(va_list);
} form_spec;

/* Main functions
 *      _putchar.c
 *      _printf
 */
int _putchar(char);
int _printf(const char *, ...);

/* Print functions */
int print_char(va_list);
int print_str(va_list);
int print_percent(va_list);
int print_int(va_list);
int print_bin(va_list);
int print_unsigned(va_list);
int print_rev(va_list);
int print_rot13(va_list);

/* Specifier handlers functions */
int arg_printer(const char *, form_spec *, va_list);
int print_string(char *);
int print_binary(unsigned int);
int print_number(unsigned int);

/* END IF MAIN_H */
#endif
