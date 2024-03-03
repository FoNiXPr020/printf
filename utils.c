#include "main.h"

/**
 * is_character_printable - Evaluates if a character is printable.
 * @c: Character to be evaluated.
 * Return: 1 if c is printable, 0 otherwise.
 */
int is_character_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexadecimal_code - Appends ASCII in hexadecimal code to buffer.
 * @buffer: Array of characters.
 * @i: Index at which to start appending.
 * @ascii_code: ASCII code.
 * Return: Always 3.
 */
int append_hexadecimal_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_character_digit - Verifies if a character is a digit.
 * @c: Character to be evaluated.
 * Return: 1 if c is a digit, 0 otherwise.
 */
int is_character_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_number_to_specified_size - Casts a number to the specified size.
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 * Return: Casted value of num.
 */
long int convert_number_to_specified_size(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_specified_unsigned_size - Casts a number to the specified size.
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 * Return: Casted value of num.
 */
long int convert_specified_unsigned_size(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

