#include "main.h"

/**
 * calculate_size - Calculates the size to cast the argument.
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 *
 * Return: Size to cast the argument.
 */
int calculate_size(const char *format, int *i)
{
	int iCurrent = *i + 1;
	int iSize = 0;

	if (format[iCurrent] == 'l')
		iSize = S_LONG;
	else if (format[iCurrent] == 'h')
		iSize = S_SHORT;

	if (iSize == 0)
		*i = iCurrent - 1;
	else
		*i = iCurrent;

	return (iSize);
}

