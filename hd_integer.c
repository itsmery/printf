#include "main.h"
/**
 * _print_integer - prints an integer using recursion
 * @n: int to print
 * @ct: pointer to count of chars printed
 * @flag: flag + or space
 * @start: 1 or 0 when recursion starts
 */
void _print_integer(long int n, int *ct, char flag, int start)
{
	if (start)
	{
		if (n < 0)
		{
			_putchar('-');
			(*ct)++;
			n = -n;
		}
		else if (flag == '+' || flag == ' ')
		{
			_putchar(flag);
			(*ct)++;
		}
	}

	if (n / 10)
	{
		_print_integer(n / 10, ct, flag, 0);
	}
	_putchar('0' + (n % 10));
	(*ct)++;
}

/**
 * hd_integer - handles the case d and i specifiers
 * @args: the argument list to get the integer from
 * @flag: flag character
 * @length_modifier: length modifier character
 * Return: the number of chars printed
 */
int hd_integer(va_list args, char flag, char length_modifier)
{
	long int n;
	int ct = 0;

	switch (length_modifier)
	{
	case 'l':
		n = va_arg(args, long int);
		break;
	case 'h':
		n = (short int)va_arg(args, int);
		break;
	default:
		n = va_arg(args, int);
		break;
	}

	if (n == 0)
	{
		if (flag == '+' || flag == ' ')
		{
			_putchar(flag);
			ct++;
		}
		_putchar('0');
		return (ct + 1);
	}

	if (n == LONG_MIN)
	{
		_putchar('-');
		_putchar('9');
		_print_integer(223372036854775808, &ct, flag, 0);
		ct += 2;
		return (ct);
	}

	_print_integer(n, &ct, flag, 1);

	return (ct);
}
