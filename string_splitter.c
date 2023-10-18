#include "header.h"

/**
  * string_splitter - splits string
  * into array of strings
  * @arr: array of strings
  * @str: string to be cut
  * @dlm: delimeter between strings
 */

void string_splitter(char *arr[], char *str, char *dlm)
{
	char *piece;
	int ctr = 0;

	piece = strtok(str, dlm);
	if (piece)
	{
		while (piece)
		{
			arr[ctr] = _strdup(piece);
			piece = strtok(NULL, dlm);
			ctr += 1;
		}
		arr[ctr] = NULL;
		return;
	}
	else
	{
		return;
	}
}
