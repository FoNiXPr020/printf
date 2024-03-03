#include "main.h"

/**
 * write_character - Prints a character.
 * @c: The character to be printed.
 * @buffer: Buffer array to store the output.
 * @flags: Active flags used for formatting.
 * @width: Width specifier for formatting.
 * @precision: Precision specifier for formatting.
 * @size: Size specifier for formatting.
 *
 * This function handles the printing of a single character.
 * It takes into account
 * the active formatting flags, width, precision, and size
 * specifiers to properly
 * format the output. The character is printed into the provided buffer array.
 *
 * Return: The number of characters printed.
 */
int write_character(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}


/**
 * p_write_number - Prints a number.
 * @is_negative: Flag indicating if the number is negative.
 * @ind: Index at which the number starts in the buffer.
 * @buffer: Buffer array to store the output.
 * @flags: Active flags used for formatting.
 * @width: Width specifier for formatting.
 * @precision: Precision specifier for formatting.
 * @size: Size specifier for formatting.
 *
 * This function handles the printing of a number.
 * the active formatting flags, width, precision,
 * format the output. The number is printed into the provided buffer array.
 *
 * Return: The number of characters printed.
 */

int p_write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (p_write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * p_write_num - Writes a number using a buffer.
 * @ind: Index at which the number starts in the buffer.
 * @buffer: Buffer array to store the output.
 * @flags: Active flags used for formatting.
 * @width: Width specifier for formatting.
 * @prec: Precision specifier for formatting.
 * @length: Length of the number.
 * @padd: Padding character.
 * @extra_c: Extra character.
 *
 * This function writes a number into a buffer array.
 * the active formatting flags, width, precision,
 * format the output. The formatted number
 * is written into the provided buffer array.
 *
 * Return: The number of characters written.
 */

int p_write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * p_write_unsgnd - Writes an unsigned number.
 * @is_negative: Flag indicating if the number is negative.
 * @ind: Index at which the number starts in the buffer.
 * @buffer: Buffer array to store the output.
 * @flags: Active flags used for formatting.
 * @width: Width specifier for formatting.
 * @precision: Precision specifier for formatting.
 * @size: Size specifier for formatting.
 *
 * This function writes an unsigned number
 * into a buffer array. It considers the number's
 * sign, the active formatting flags, width, precision,
 * and size specifiers to properly
 * format the output. The formatted number is written
 * into the provided buffer array.
 *
 * Return: The number of characters written.
 */
int p_write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * p_write_pointer - Writes a memory address.
 * @buffer: Buffer array to store the output.
 * @ind: Index at which the number starts in the buffer.
 * @length: Length of the number.
 * @width: Width specifier for formatting.
 * @flags: Active flags used for formatting.
 * @padd: Padding character.
 * @extra_c: Extra character.
 * @padd_start: Index at which padding should start.
 *
 * This function writes a memory address
 * into a buffer array. It considers the address's
 * length, the active formatting flags, width, precision,
 * and padding character to properly
 * format the output. The formatted address
 * is written into the provided buffer array.
 *
 * Return: The number of characters written.
 */
int p_write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

