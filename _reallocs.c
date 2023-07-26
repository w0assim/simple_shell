#include "shell.h"



/**
 *
 * ffree - the free of string
 * @pp: the string of strings
 *
 */

void ffree( char **pp )
{
	char **a = pp;

	if ( !pp )
		return;
	while ( *pp )
		free( *pp++ );
	free( a );
}

/**
 *
 * _realloc - the reallocates of a block of memory
 * @ptr: the pointer that can previous a malloc'ated block
 *
 * @old_size: the size of byte to previous block
 * @new_size: the size of byte of a new block
 *
 * Return: the pointer of the ol'block name
 *
 */

void *_realloc( void *ptr, unsigned int old_size, unsigned int new_size )
{
	char *p;

	if ( !ptr )
		return (malloc(new_size));
	if ( !new_size )
		return (free(ptr), NULL);
	if ( new_size == old_size )
		return (ptr);

	p = malloc( new_size );
	if ( !p )
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while ( old_size-- )
		p[old_size] = ( ( char * )ptr )[old_size];
	free( ptr );
	return (p);
}

/**
 *
 * _memset - the fills memory with a constant byte
 * @s: the pointer of the memory area
 *
 * @b: the byte to fill *s with
 * @n: the bytes amount to be filled
 *
 * Return: (s) the pointer of the memory area s
 *
 */

char *_memset( char *s, char b, unsigned int n )
{
	unsigned int i;

	for ( i = 0; i < n; i++ )
		s[i] = b;
	return (s);
}

