#include "main.h"
/**
 * hd_custom_S - Handles the custom 'S' conversion specifier
 * @args: args list
 *
 * Return: The number of characters printed
 */
int hd_custom_S(va_list args)
{
	char *s = va_arg(args, char *);
	int ct = 0, i;
	char flag = '\0';

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			ct += print_hex_char(s[i], flag);
		}
		else
		{
			_putchar(s[i]);
			ct++;
		}
	}

	return (ct);
}
/**
 * print_hex_char - Prints an unsigned char as its hexadecimal value
 * @c: The character to print as hexadecimal
 * @flag: The flag character, not used in this
 * function, but added for consistency
 *
 * Return: The number of characters printed
 */
int print_hex_char(unsigned char c, char flag)
{
	char hex_digits[] = "0123456789ABCDEF";
	int ct = 0;

	(void)flag;
	_putchar('\\');
	_putchar('x');
	_putchar(hex_digits[(c >> 4) & 0xF]);
	_putchar(hex_digits[c & 0xF]);

	ct += 4;

	return (ct);
}
