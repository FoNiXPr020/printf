#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function.
 * @format: The format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, iPrinted = 0, iPrinted_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			iPrinted_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			iPrinted = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (iPrinted == -1)
				return (-1);
			iPrinted_chars += iPrinted;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (iPrinted_chars);
}

/**
 * print_buffer - Print the contents of the buffer if it exists.
 * @buffer: An array of characters.
 * @buff_ind: The index at which the next character should be added,
 * representing the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
