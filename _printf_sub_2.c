#include "header.h"
/**
 * _print_string - sub function of _printf to print strings
 * @s: input string to print
 *
 * Return: length of characters printed
 */
int _print_string(char *s)
{
	int i = 0;

	if (!s)
	{
		_print_string("(null)");
		return (6);
	}
	while (s[i] != '\0')
	{
		_print_char(s[i]);
		i++;
	}
	return (i);
}

/**
 * _print_rot13 - this function applies cyfer of rot13 type
 * and prints it
 * @s: this is the input string
 *
 * Return: length of characters printed
 */
int _print_rot13(char *s)
{
	int i = 0, l = 0;

	if (!s)
	{
		return (_print_string("(nil)"));
	}
	while (s[i] != '\0')
	{
		if ((s[i] >= 'A' && s[i] <= 'M') || (s[i] >= 'a' && s[i] <= 'm'))
		{
			l += _print_char(s[i] + 13);
		}
		else if ((s[i] >= 'N' && s[i] <= 'Z') || (s[i] >= 'n' && s[i] <= 'z'))
		{
			l += _print_char(s[i] - 13);
		}
		else
		{
			l += _print_char(s[i]);
		}
		i++;
	}
	return (l);
}

/**
 * _print_rev - this function print the string in reverse
 * @s: this is the input string
 *
 * Return: length of characters printed
 */
int _print_rev(char *s)
{
	int i, length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}

	for (i = length - 1; i >= 0; i--)
	{
		_print_char(s[i]);
	}
	return (length);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_char - sub function of _printf to print chars
 * @c: input char to print
 *
 * Return: length of characters printed (always 1)
 */
int _print_char(char c)
{
	_putchar(c);
	return (1);
}
