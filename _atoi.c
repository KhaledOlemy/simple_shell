#include "header.h"
/**
 * _atoi- this function prints out the first number it sees
 * positive or negative in a string
 * @s: this is the input string to be extracted from
 * Return: int, the number we're seeking
 */
int _atoi(char *s)
{
	unsigned int num = 0;
	int sign = 1;

	do {
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');
		else if (num > 0)
			break;
	} while (*s++);
	return (num * sign);
}
