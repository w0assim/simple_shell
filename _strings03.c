#include "shell.h"

/**
 * _strcat - concat
 * @_dest: output
 * @srcc: input
 * Return: output- pointer
 */

char *_strcat(char *_dest, char *srcc)
{
	char *retur = _dest;

	while (*_dest)
		_dest++;
	while (*srcc)
		*_dest++ = *srcc++;
	*_dest = *srcc;
	return (retur);
}



/**
 * starts_with - check if it starts with..
 * @haystack: what we search for
 * @needle: finding..
 *
 * Return: haystack adress or NULL
 *
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strlen - stringggg
 * @s: check
 * Return: strlen
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

