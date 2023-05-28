#include "main.h"

/**
 * hd_hex_lower - Handles the lowercase '%x' hex conversion specifier
 * @args: List of arguments
 * @flag: The flag character
 * @length: The length modifier (l, h, or '\0' for none)
 * Return: The number of characters printed
 */
int hd_hex_lower(va_list args, char flag, char length)
{
	unsigned long int num_l;
	unsigned short int num_h;
	unsigned int num;

	if (length == 'l')
	{
		num_l = va_arg(args, unsigned long int);
		return (print_hex_l(num_l, 0, flag));
	}
	else if (length == 'h')
	{
		num_h = (unsigned short int)va_arg(args, unsigned int);
		return (print_hex_h(num_h, 0, flag));
	}
	else
	{
		num = va_arg(args, unsigned int);
		return (print_hex(num, 0, flag));
	}
}

/**
 * hd_hex_upper - Handles the uppercase '%X' hex conversion specifier
 * @args: List of arguments
 * @flag: The flag character
 * @length: The length modifier (l, h, or '\0' for none)
 * Return: The number of characters printed
 */
int hd_hex_upper(va_list args, char flag, char length)
{
	unsigned long int num_l;
	unsigned short int num_h;
	unsigned int num;

	if (length == 'l')
	{
		num_l = va_arg(args, unsigned long int);
		return (print_hex_l(num_l, 1, flag));
	}
	else if (length == 'h')
	{
		num_h = (unsigned short int)va_arg(args, unsigned int);
		return (print_hex_h(num_h, 1, flag));
	}
	else
	{
		num = va_arg(args, unsigned int);
		return (print_hex(num, 1, flag));
	}
}

/**
 * print_hex - Prints an unsigned integer in hexadecimal
 * @num: The unsigned integer to print
 * @upper: 1 for uppercase letters, 0 for lowercase letters
 * @flag: The flag character
 * Return: The number of characters printed
 */
int print_hex(unsigned int num, int upper, char flag)
{
	unsigned int n = num;
	int ct = 0;
	char offset = upper ? 'A' - 10 : 'a' - 10;

	if (flag == '#')
	{
		_putchar('0');
		_putchar(upper ? 'X' : 'x');
		ct += 2;
	}

	if (n / 16)
		ct += print_hex(n / 16, upper, '\0');
	ct += _putchar((n % 16) < 10 ? (n % 16) + '0' : (n % 16) + offset);

	return (ct);
}

/**
 * print_hex_l - Prints an unsigned long integer in hexadecimal
 * @num: The unsigned long integer to print
 * @upper: 1 for uppercase letters, 0 for lowercase letters
 * @flag: The flag character
 * Return: The number of characters printed
 */
int print_hex_l(unsigned long int num, int upper, char flag)
{
	unsigned long int n = num;
	int ct = 0;
	char offset = upper ? 'A' - 10 : 'a' - 10;

	if (flag == '#')
	{
		_putchar('0');
		_putchar(upper ? 'X' : 'x');
		ct += 2;
	}

	if (n / 16)
		ct += print_hex_l(n / 16, upper, '\0');
	ct += _putchar((n % 16) < 10 ? (n % 16) + '0' : (n % 16) + offset);

	return (ct);
}

/**
 * print_hex_h - Prints an unsigned short integer in hexadecimal
 * @num: The unsigned short integer to print
 * @upper: 1 for uppercase letters, 0 for lowercase letters
 * @flag: The flag character
 * Return: The number of characters printed
 */
int print_hex_h(unsigned short int num, int upper, char flag)
{
	unsigned short int n = num;
	int ct = 0;
	char offset = upper ? 'A' - 10 : 'a' - 10;

	if (flag == '#')
	{
		_putchar('0');
		_putchar(upper ? 'X' : 'x');
		ct += 2;
	}

	if (n / 16)
		ct += print_hex_h(n / 16, upper, '\0');
	ct += _putchar((n % 16) < 10 ? (n % 16) + '0' : (n % 16) + offset);

	return (ct);
}
