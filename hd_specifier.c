#include "main.h"

/**
 * hd_specifier - Handles conversion specifiers
 * @specifier: The conversion specifier character
 * @args: The variable argument list
 * @flag: The flag character
 * @length: The length modifier character
 * Return: Count of characters printed
 */
int hd_specifier(char specifier, va_list args, char flag, char length)
{
	int ct = 0;

	switch (specifier)
	{
	case 'c':
		ct += hd_char(args);
		break;
	case 's':
		ct += hd_string(args);
		break;
	case '%':
		ct += _putchar('%');
		break;
	case 'd':
	case 'i':
		ct += hd_integer(args, flag, length);
		break;
	default:
		ct += hd_specifier_ext(specifier, args, flag, length);
		break;
	}

	return (ct);
}

/**
 * hd_specifier_ext - Handles extra conversion specifiers
 * @specifier: The conversion specifier character
 * @args: args list
 * @flag: The flag character
 * @length: The length modifier character
 * Return: Count of characters printed
 */
int hd_specifier_ext(char specifier, va_list args, char flag, char length)
{
	int ct = 0;

	switch (specifier)
	{
	case 'b':
		ct += hd_binary(args);
		break;
	case 'u':
		ct += hd_unsigned_int(args, length);
		break;
	case 'o':
		ct += hd_octal(args, flag, length);
		break;
	case 'x':
		ct += hd_hex_lower(args, flag, length);
		break;
	case 'X':
		ct += hd_hex_upper(args, flag, length);
		break;
	case 'S':
		ct += hd_custom_S(args);
		break;
	case 'p':
		ct += hd_pointer(args);
		break;
	default:
		ct += _putchar('%');
		ct += _putchar(specifier);
		break;
	}

	return (ct);
}
