#include "main.h"

/**
 * hd_string - Handles the 's' specifier for _printf
 * @args: The argument list to get the string from
 * Return: The number of characters printed
 */
int hd_string(va_list args)
{
	char *str = va_arg(args, char *);
	int ct = 0, i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
	{
		ct += _putchar(str[i]);
		i++;
	}
	return (ct);
}
