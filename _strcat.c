/**
 * _strcat- this function concatenates 2 strings
 * @dest: this is the test to be appended to
 * @src: this is the text to be appended.
 * Return: @src appended to @dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
	{
		++i;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		++j;
		++i;
	}
	dest[i] = '\0';

	return (dest);
}
