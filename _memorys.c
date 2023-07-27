#include "shell.h"

/**
 ** bfree - the free of a pointer and the NULL of the address
 * @ptr: the address of the pointer should be free
 * Return: 1 if freed, if not 0.
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
