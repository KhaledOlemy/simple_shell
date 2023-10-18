#include "header.h"

/**
  * free_struct - function to free struct
  * @d: struct to be freed
  */

void free_struct(exit_struct_t *d)
{
	if (d != NULL)
	{
		free(d->exit_1);
		free(d);
	}
}
