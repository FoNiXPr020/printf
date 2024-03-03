#include "main.h"

/**
 * print_argument - Prints an argument based on its type.
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: Ind.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: 1 or 2.
 */

int print_argument(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, iLen = 0, iPr_char = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned_number},
		{'o', print_octal_number},
		{'x', print_hexadecimal_number},
		{'X', print_uppercase_hexadecimal},
		{'p', print_pointer_value}, {'S', print_non_printable_chars},
		{'r', print_reverse_string}, {'R', print_rot13_string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		iLen += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			iLen += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		iLen += write(1, &fmt[*ind], 1);
		return (iLen);
	}
	return (iPr_char);
}

