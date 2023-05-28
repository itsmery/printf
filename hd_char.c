#include "main.h"
/**
 * hd_char - handles the case c specifier
 * @args: args list
 * Return: the number of chars printed
 */
int hd_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}
