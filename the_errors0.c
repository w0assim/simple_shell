#include "shell.h"
/**
 *
 * _putsfd - The input string should be printed
 * @str: the string shoule be printed
 *
 * @fd: the filedescriptor should be writed
 *
 * Return: The chars put numbers
 *
 */

int _putsfd( char *str, int fd )
{
	int i = 0;

	if ( !str )
		return (0);
	while ( *str )
	{
		i += _putfd( *str++, fd );
	}
	return (i);
}



/**
 *
 * _eputchar - prints the character c to be stder
 * @c: The character should be print
 *
 *
 * Return: if it's success 1.
 * if it's error, the return is -1, and errno is set the appropriately.
 *
 */

int _eputchar( char c )
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if ( c == BUF_FLUSH || i >= WRITE_BUF_SIZE )
	{
		write( 2, buf, i );
		i = 0;
	}
	if ( c != BUF_FLUSH )
		buf[i++] = c;
	return (1);
}


/**
 *
 * _eputs - The input string should print
 * @str: the string should be printed
 *
 *
 * Return: not a thing
 *
 */

void _eputs( char *str )
{
	int i = 0;

	if ( !str )
		return;
	while ( str[i] != '\0' )
	{
		_eputchar(str[i]);
		i++;
	}
}


/**
 *
 * _putfd - To given fd should write the character c
 * @c: The character should be printed
 *
 * @fd: The filedescriptor should be writed
 *
 * Return: if it's success 1.
 * if it's error, the return is -1, and errno is set the appropriately.
 *
 */

int _putfd( char c, int fd )
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if ( c == BUF_FLUSH || i >= WRITE_BUF_SIZE )
	{
		write( fd, buf, i );
		i = 0;
	}
	if ( c != BUF_FLUSH )
		buf[i++] = c;
	return (1);
}
