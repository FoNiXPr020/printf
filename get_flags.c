#include "main.h"

/**
 * calculate_flags - Calculates active flags.
 * @format: Formatted string in which to print the arguments.
 * @i: Parameter.
 * Return: Flags.
 */
int calculate_flags(const char *format, int *i)
{
	int j, iCurrent;
	int iFlags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (iCurrent = *i + 1; format[iCurrent] != '\0'; iCurrent++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[iCurrent] == FLAGS_CH[j])
			{
				iFlags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = iCurrent - 1;

	return (iFlags);
}

