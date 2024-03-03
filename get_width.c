#include "main.h"

/**
 * calculate_width - Calculates the width for printing.
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Width.
 */
int calculate_width(const char *format, int *i, va_list list)
{
	int iCurrent;
	int iWidth = 0;

	for (iCurrent = *i + 1; format[iCurrent] != '\0'; iCurrent++)
	{
		if (is_character_digit(format[iCurrent]))
		{
			iWidth *= 10;
			iWidth += format[iCurrent] - '0';
		}
		else if (format[iCurrent] == '*')
		{
			iCurrent++;
			iWidth = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = iCurrent - 1;

	return (iWidth);
}

