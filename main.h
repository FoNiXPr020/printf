#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - Structure for operation.
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Typedef for struct format.
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int print_argument(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** functions ******************/

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned_number(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal_number(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal_number(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_uppercase_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexadecimal(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

int print_non_printable_chars(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_pointer_value(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int calculate_flags(const char *format, int *i);
int calculate_width(const char *format, int *i, va_list list);
int calculate_precision(const char *format, int *i, va_list list);
int calculate_size(const char *format, int *i);

int print_reverse_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_rot13_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int write_character(char c, char buffer[],
	int flags, int width, int precision, int size);
int p_write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int p_write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int p_write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int p_write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

int is_character_printable(char);
int append_hexadecimal_code(char, char[], int);
int is_character_digit(char);

long int convert_number_to_specified_size(long int num, int size);
long int convert_specified_unsigned_size(unsigned long int num, int size);

#endif

