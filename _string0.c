#include "shell.h"



/**
 ** _strcmp - the performs of a lexicogarphic comparison of two strangs.
 * @s1: first strang
 * @s2: second strang
 * Return: if s1 < s2 will be negative,
 * if s1 > s2 will be positive and zero if s1 == s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
