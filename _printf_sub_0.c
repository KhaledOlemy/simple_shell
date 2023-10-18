#include "header.h"
/**
 * _print_int - sub function of _printf to print integers
 * @num: input decimal number to print
 * @iter: highest divisible number to convert decimal to split
 * the number into 1 digit value to print.
 * @flag: to tell the code, are we still overhead getting zeros (to neglect),
 * or are we in the number boundaries
 *
 * Return: length of characters printed
 */
int _print_int(unsigned int num, unsigned int iter, int flag)
{
	int i = 0;

	if (iter != 1)
	{
		iter /= 10;
		if (num / iter == 0 && flag == 0)
		{
			i += _print_int(num, iter, 0);
		}
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
				if ((num / iter) > 10)
				{
					i += 2;
					_putchar((num / iter) / 10 + '0');
					_putchar((num / iter) % 10 + '0');
				}
				else
				{
					i += 1;
					_putchar((num / iter) + '0');
				}
			}
			num %= iter;
			i += _print_int(num, iter, 1);
		}
	}
	return (i);
}

/**
 * _print_signed_int - sub function of _printf to print negative
 * numbers and then calls other function with positive value
 * @num: input decimal number to print
 *
 * Return: length of characters printed
 */
int _print_signed_int(int num)
{
	int l = 0, temp;

	if (num < 0)
	{
		_putchar('-');
		l += 1;
		num *= -1;
	}
	else if (num == 0)
	{
		_putchar(0 + '0');
	}
	temp = _print_int((unsigned int) num, 1000000000, 0);
	if (temp == 0)
	{
		l += 1;
	}
	else
	{
		l += temp;
	}
	return (l);
}

/**
 * _special_str - sub function of _printf to print special strings
 * @s: input string to print
 *
 * Return: length of characters printed
 */
int _special_str(char *s)
{
	int i = 0, j, l = 0;

	while (s[i] != '\0')
	{
		j = (int) s[i];
		if (j < 32 || j >= 127)
		{
			_print_string("\\x");
			if (j < 16)
			{
				_putchar('0');
			}
			_print_hexa((int) j, 268435456, 0, 'X');
			l += 1;
		}
		else
		{
			_print_char(s[i]);
		}
		i++;
	}
	return (i + (l * 3));
}

/**
 * _string_navigator - sub function of _printf to choose
 * whether it's a special string or a normal one
 * @c: modifier for normal/special string
 * @s: input string to print
 *
 * Return: length of characters printed
 */
int _string_navigator(char c, char *s)
{
	if (c == 's')
	{
		return (_print_string(s));
	}
	else if (c == 'r')
	{
		return (_print_rev(s));
	}
	else if (c == 'R')
	{
		return (_print_rot13(s));
	}
	else
	{
		return (_special_str(s));
	}
}

/**
 * _unsigned_checker - checks if input num is NULL or not
 * and takes action based on that
 * @num: input number to be printed
 *
 * Return: length of characters printed
*/
int _unsigned_checker(unsigned int num)
{
	int len = 0;

	if (!num)
	{
		_putchar('0');
		len += 1;
	}
	else
	{
		len += _print_int(num, 1000000000, 0);
	}
	return (len);
}
