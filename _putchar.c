#include "main.h"

/**
 * _putchar - Function that writes the character c to stdout
 * @c: Character to print
 * Return: (Success 1)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
