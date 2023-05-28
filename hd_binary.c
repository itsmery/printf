#include "main.h"
/**
 * hd_binary - Handles the 'b' specifier
 * @args: args list
 * Return: the number of chars printed
 */
int hd_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int ct = 0;
	unsigned int mask = 1u << 31;

	while ((mask & n) == 0 && mask != 0)
	{
		mask >>= 1;
	}

	while (mask != 0)
	{
		if ((n & mask) == 0)
			ct += _putchar('0');
		else
			ct += _putchar('1');

		mask >>= 1;
	}

	if (ct == 0)
		ct += _putchar('0');

	return (ct);
}
