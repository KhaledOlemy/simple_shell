
/**
 * _strcmp- this function compares 2 strings
 * @s1: this is the first input string to be compared.
 * @s2: this is the second input string to be compared.
 * Return:
 * 0 if the 2 strings are the same
 * + if first non matching char is s1 is higher in ascii value than in s2
 * - if first non matching char is s1 is lower in ascii value than in s2
*/
int _strcmp(char *s1, char *s2)
{
	int i, j, out;
	char x;

	out = 999;
	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	for (j = 0; j < i; j++)
	{
		if (s1[j] == s2[j])
		{
			continue;
		}
		else
		{
			x = s1[j] - s2[j];
			out = (int) x;
			break;
		}
	}
	if (out == 999)
	{
		out = 0;
	}
	return (out);
}
