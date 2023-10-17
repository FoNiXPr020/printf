#include "main.h"

/**
 * print_bin - Function that prints an unsigned integer in binary format
 * @args: Pointer of arg
 * Return: Num of digits printed
 */
int print_bin(va_list args)
{
	unsigned int value = va_arg(args, unsigned int);

	if (value == 0)
	{
		return (_putchar('0'));
	}

	if (value == 1)
	{
		return (_putchar('1'));
	}
	else
	{
		return (print_binary(value));
	}
}

/**
 * print_rev - Function that prints a string in reverse
 * @args: Pointer of arg
 * Return: Num of characters printed
 */
int print_rev(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0, count = 0;

	if (!str)
		return (-1);

	while (*str)
	{
		str++;
		len++;
	}

	while (len > 0)
	{
		str--;
		count += _putchar(*str);
		len--;
	}

	return (count);
}

/**
 * print_rot13 - Function that prints a string in rot13 format
 * @args: Pointer of arg
 * Return: Num of characters printed
 */
int print_rot13(va_list args)
{
	char *str = va_arg(args, char *);
	int i, count = 0;

	if (!str)
		return (-1);

	for (i = 0; str[i]; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'm') ||
			(str[i] >= 'A' && str[i] <= 'M'))
		{
			count += _putchar(str[i] + 13);
		}
		else if ((str[i] >= 'n' && str[i] <= 'z') ||
			(str[i] >= 'N' && str[i] <= 'Z'))
		{
			count += _putchar(str[i] - 13);
		}
		else
		{
			count += _putchar(str[i]);
		}
	}

	return (count);
}
