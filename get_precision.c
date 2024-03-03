#include "main.h"

/**
 * calculate_precision - Calculates the precision for printing.
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Precision.
 */
int calculate_precision(const char *format, int *i, va_list list)
{
	int iPrec = -1;
	int iCurrent = *i + 1;

	if (format[iCurrent] != '.')
		return (iPrec);

	iPrec = 0;

	for (iCurrent += 1; format[iCurrent] != '\0'; iCurrent++)
	{
		if (is_character_digit(format[iCurrent]))
		{
			iPrec *= 10;
			iPrec += format[iCurrent] - '0';
		}
		else if (format[iCurrent] == '*')
		{
			iCurrent++;
			iPrec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = iCurrent - 1;

	return (iPrec);
}

