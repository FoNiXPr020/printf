#include "main.h"

/**
 * _printf - Custom printf function that prints formatted data
 * @format: The format string.
 * Return: The num of characters printed.
 */
int _printf(const char *format, ...)
{
	int iCount = 0;
	form_spec specifiers[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_bin},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);
	iCount = arg_printer(format, specifiers, args);
	va_end(args);

	return (iCount);
}

/**
 * arg_printer - Function that prints
 * @format: The list of args passed to the function
 * @specifiers: The list of args specifiers
 * @args: The list of args
 * Return: The num of characters printed
 */
int arg_printer(const char *format, form_spec specifiers[], va_list args)
{
	int i = 0, j, iCount = 0, iChecker;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			for (j = 0; specifiers[j].c != NULL; j++)
			{
				if (format[i] == specifiers[j].c[0])
				{
					iChecker = specifiers[j].f(args);
					if (iChecker == -1)
						return (-1);
					iCount += iChecker;
					break;
				}
			}
			if (specifiers[j].c == NULL)
			{
				iCount += print_percent(args);
				iCount += _putchar(format[i]);
			}
		}
		else
		{
			iCount += _putchar(format[i]);
		}
		i++;
	}

	return (iCount);
}
