#include "header.h"
/**
 * _print_address - sub function of _printf to print addresses
 * @addr: input address to print
 *
 * Return: length of characters printed
 */
int _print_address(unsigned long int addr)
{
	char hex[16];
	int i = 0, out = 0, digit;

	if (addr == 0)
	{
		return (_print_string("(nil)"));
	}
	while (addr > 0)
	{
		digit = addr % 16;
		if (digit < 10)
		{
			hex[i] = '0' + digit;
		}
		else
		{
			hex[i] = 'a' + (digit - 10);
		}
		addr /= 16;
		i++;
	}
	out += _print_char('0');
	out += _print_char('x');
	for (i--; i >= 0; i--)
	{
		out += _print_char(hex[i]);
	}
	return (out);
}

/**
 * _print_binary - sub function of _printf to print binary numbers
 * @n: decimal number to print in binary
 *
 * Return: length of characters printed
*/
int _print_binary(unsigned int n)
{
	int i = 0, j;
	unsigned int binary[64], l = 0;

	if (n == 0)
	{
		_putchar(0 + '0');
		return (1);
	}
	while (n > 0)
	{
		binary[i] = n % 2;
		n /= 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(binary[j] + '0');
		l += 1;
	}
	return (l);
}

/**
 * _print_hex_item - sub function of _printf to print literals on hexadecimals
 * @num: decimal number to print in hexadecimal
 * @casing: X or x, to print in uppercase or lowecase.
 *
 * Return: length of characters printed
 */
int _print_hex_item(int num, char casing)
{
	int l = 0;

	if (num < 10)
	{
		_putchar(num + '0');
		l += 1;
	}
	else
	{
		if (casing == 'x')
		{
			_putchar(num + 87);
			l += 1;
		}
		else if (casing == 'X')
		{
			_putchar(num + 55);
			l += 1;
		}
	}
	return (1);
}

/**
 * _print_hexa - sub function of _printf to print hexadecimals
 * @num: input decimal number to print in hexadecimal
 * @iter: highest divisible number to convert decimal to hexadecimal
 * @casing: X or x, to print in uppercase or lowecase.
 * @flag: to tell the code, are we still overhead getting zeros (to neglect),
 * or are we in the number boundaries
 *
 * Return: length of characters printed
 */
int _print_hexa(unsigned int num, unsigned int iter, int flag, char casing)
{
	int i = 0;

	if (iter != 16)
	{
		iter /= 16;
		if (num / iter == 0 && flag == 0)
		{i += _print_hexa(num, iter, 0, casing); }
		else
		{
			flag = 1;
			if (num / iter == 0)
			{
				i += 1;
				_print_hex_item(0, casing);
			}
			else
			{
				if ((num / iter) > 16)
				{
					i += 2;
					_print_hex_item((num / iter) / 16, casing);
					_print_hex_item((num / iter) % 16, casing);
				}
				else
				{
					i += 1;
					_print_hex_item((num / iter), casing);
				}
			}
			num %= iter;
			i += _print_hexa(num, iter, 1, casing);
		}
	}
	else
	{
		_print_hex_item((num % iter), casing);
		i += 1;
	}
	return (i);
}

/**
 * _print_octal - sub function of _printf to print in octal
 * @num: input decimal number to print in octal
 * @iter: highest divisible number to convert decimal to octals
 * to split the number into 1 digit value to print.
 * @flag: to tell the code, are we still overhead getting zeros (to neglect),
 * or are we in the number boundaries
 *
 * Return: length of characters printed
 */
int _print_octal(unsigned int num, unsigned int iter, int flag)
{
	int i = 0;

	if (iter != 8)
	{
		iter /= 8;
		if (num / iter == 0 && flag == 0)
		{i += _print_octal(num, iter, 0); }
		else
		{
			flag = 1;
			if (num / iter == 0)
			{
				i += 1;
				_putchar(0 + '0');
			}
			else
			{
				if ((num / iter) >= 8)
				{
					i += 2;
					_putchar((num / iter) / 8 + '0');
					_putchar((num / iter) % 8 + '0');
				}
				else
				{
					i += 1;
					_putchar((num / iter) + '0');
				}
			}
			num %= iter;
			i += _print_octal(num, iter, 1);
		}
	}
	else
	{
	_putchar(num + '0');
	i += 1;
	}
	return (i);
}
