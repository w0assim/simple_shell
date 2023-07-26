#include "shell.h"



/**
 *
 * _strcmp - the performs of a lexicogarphic comparison of two strangs.
 * @s1: first strang
 * @s2: second strang
 *
 * Return: if s1 < s2 will be negative, if s1 > s2 will be positive and zero if s1 == s2 
 *
 */

int _strcmp( char *s1, char *s2 )
{
	while ( *s1 && *s2 )
	{
		if ( *s1 != *s2 )
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if ( *s1 == *s2 )
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}



/**
 *
 * _strcat - the two strings
 * @dest: destination of buffer
 * @src: the buffer source
 *
 * Return: the pointer of the buffer destination
 */
char *_strcat( char *dest, char *src )
{
	char *ret = dest;

	while ( *dest )
		dest++;
	while ( *src )
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}



/**
 *
 * starts_with - the checks will be if needle starts with the haystack
 * @haystack: the string of search
 * @needle: substring of find
 *
 * Return: the address of next char of the haystack or should be NULL
 *
 */

char *starts_with( const char *haystack, const char *needle )
{
	while ( *needle )
		if ( *needle++ != *haystack++ )
			return ( NULL );
	return ((char * )haystack );
}

/**
 *
 * _strlen - the return of the length string
 * @s: the length string should be checked
 *
 * Return: the integration of a lengthstring
 *
 */

int _strlen( char *s )
{
	int i = 0;

	if ( !s )
		return (0);

	while ( *s++ )
		i++;
	return (i);
}

