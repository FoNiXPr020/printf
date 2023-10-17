#include "main.h"

/**
 * print_number - Function that prints an integer
 * @value: The integer to be printed
 * Return: Num of digits printed
 */
int print_number(unsigned int value)
{
	int String = 1, iLen = 0;

	while ((value / String) > 9)
		String *= 10;

	while (String > 0)
	{
		iLen += _putchar('0' + value / String);
		value %= String;
		String /= 10;
	}

	return (iLen);
}

/**
 * print_string - Function that prints a string
 * @str: The string to be printed
 * Return: Num of characters printed
 */
int print_string(char *str)
{
	int iLen = 0;

	while (*str)
	{
		iLen += _putchar(*str);
		str++;
	}
	return (iLen);
}


/**
 * print_binary - Function that prints a value in binary format, recursively
 * @value: The value to print
 * Return: Num of digits printed
 */
int print_binary(unsigned int value)
{
	int iCount = 0;

	if (value == 0)
	{
		return (0);
	}
	else
	{
		iCount += print_binary(value / 2);
		iCount += _putchar((value % 2) + '0');
	}

	return (iCount);
}
