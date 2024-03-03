#include "main.h"

/**
 * print_unsigned_number - Prints an unsigned number.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int print_unsigned_number(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_specified_unsigned_size(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (p_write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal_number - Prints an unsigned number in octal notation.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int print_octal_number(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_specified_unsigned_size(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (p_write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal_number - Prints an unsigned
 * number in hexadecimal notation.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int print_hexadecimal_number(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexadecimal(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_uppercase_hexadecimal - Prints an unsigned number in
 * upper hexadecimal notation.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int print_uppercase_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexadecimal(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexadecimal - Prints a hexadecimal number
 * in lower or upper case.
 * @types: List of arguments.
 * @map_to: Array of values to map the number to.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags.
 * @flag_ch: Active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int print_hexadecimal(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_specified_unsigned_size(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (p_write_unsgnd(0, i, buffer, flags, width, precision, size));
}

