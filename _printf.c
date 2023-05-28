#include "main.h"

/**
 * _printf - implementation of printf from scratch
 * @format: the string containing specifiers
 * Return: ct of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int ct = 0;
	int rest;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				ct = -1;
				break;
			}
			if (*format == ' ')
			{
				ct = -1;
				break;
			}
			rest = handle_flag_and_specifier(&format, args, &ct);

			if (rest == -1)
			{
				ct = -1;
				break;
			}
		}
		else
		{
			ct += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (ct);
}

/**
 * handle_flag_and_specifier - Handles flag chars and specifiers
 * @format: Pointer to the current position in the format string
 * @args: args list
 * @ct: Pointer to the count of characters printed so far
 *
 * Return: 0 on success, -1 on error
 */
int handle_flag_and_specifier(const char **format, va_list args, int *ct)
{
	char flag = '\0';
	char length = '\0';
	int rest;

	if (**format == '+' || **format == ' ' || **format == '#')
	{
		flag = **format;
		(*format)++;
	}
	else
	{
		flag = '\0';
	}

	if (**format == 'l' || **format == 'h')
	{
		length = **format;
		(*format)++;
	}
	else
	{
		length = '\0';
	}

	rest = handle_specifier(**format, args, flag, length);

	if (rest == -1)
		return (-1);

	*ct += rest;

	return (0);
}
