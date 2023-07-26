#include "shell.h"

/**
 *
 *_strchr - The locate of a character in a string
 *@s: string should be parsed
 *
 *@c: character which look for it
 *
 *Return: (s) the pointer of the memory area s
 *
 */

char *_strchr( char *s, char c )
{
	do {
		if ( *s == c )
			return (s);
	} while ( *s++ != '\0' );

	return (NULL);
}

/**
 *
 *_strncpy - the copie of string
 *@dest: the destination string should be copied
 *
 *@src: the source of string
 *@n: the amount of characters should be copied
 *
 *Return: the concatenated of string
 *
 */

char *_strncpy( char *dest, char *src, int n )
{
	int i, j;
	char *s = dest;

	i = 0;
	while ( src[i] != '\0' && i < n - 1 )
	{
		dest[i] = src[i];
		i++;
	}
	if ( i < n )
	{
		j = i;
		while ( j < n )
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 *
 *_strncat - concatenates of two strings
 *@dest: first string
 *@src: second string
 *
 *@n: the amount of a bytes should be maximally used
 *
 *Return: the concatenated strings
 *
 */

char *_strncat( char *dest, char *src, int n )
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while ( dest[i] != '\0' )
		i++;
	while ( src[j] != '\0' && j < n )
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if ( j < n )
		dest[i] = '\0';
	return (s);
}
