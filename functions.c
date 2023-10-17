#include "main.h"

/**
 * print_char - Function that prints a character.
 * @args: Pointer of arg
 * Return: Num of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}

/**
 * print_str - Function that prints a string
 * @args: Pointer of arg
 * Return: Num of characters printed
 */
int print_str(va_list args)
{
	char *Str = va_arg(args, char *);

	if (!Str)
		return (print_string("(null)"));
	return (print_string(Str));
}

/**
 * print_percent - Function that prints a percent symbol
 * @args: Pointer of arg
 * Return: Num of characters printed
 */
int print_percent(__attribute__((unused))va_list args)
{
	return (_putchar('%'));
}

/**
 * print_int - Function that prints an integer
 * @args: Pointer of arg
 * Return: Num of digits printed
 */
int print_int(va_list args)
{
	int iValue = va_arg(args, int);
	int iLen = 0;

	if (iValue < 0)
	{
		iLen += _putchar('-');
		iValue *= -1;
	}

	return (iLen + print_number((unsigned int)iValue));
}

/**
 * print_unsigned - prints an unsigned integer
 * @args: argument pointer
 * Return: number of digits printed
 */
int print_unsigned(va_list args)
{
	unsigned int iNum = va_arg(args, unsigned int);

	return (print_number(iNum));
}
