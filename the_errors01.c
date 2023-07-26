#include "shell.h"

/**
 *
 * remove_comments - function that should replace the first instance of '#' with '\0'
 * @buf: address of the string should be modify
 *
 *
 * Return: the 0
 *
 */

void remove_comments( char *buf )
{
	int i;

	for ( i = 0; buf[i] != '\0'; i++ )
		if ( buf[i] == '#' && ( !i || buf[i - 1] == ' ' ) )
		{
			buf[i] = '\0';
			break;
		}
}


/**
 *
 * print_d - function prints of a decimal number
 * @input: the input
 *
 * @fd: the filedescriptor should be write
 *
 *
 * Return: number of characters should be printed
 */
int print_d( int input, int fd )
{
	int ( *__putchar )( char ) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if ( fd == STDERR_FILENO )
		__putchar = _eputchar;
	if ( input < 0 )
	{
		_abs_ = -input;
		__putchar( '-' );
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for ( i = 1000000000; i > 1; i /= 10 )
	{
		if ( _abs_ / i )
		{
			__putchar( '0' + current / i );
			count++;
		}
		current %= i;
	}
	__putchar( '0' + current );
	count++;

	return (count);
}

/**
 *
 * print_error - shows the error message
 * @info: the parameter and the return information struct
 *
 * @estr: string of the specify error type
 * Return: if no numbers in string should be 0, converted number and -1 if it's error
 *
 */

void print_error( info_t *info, char *estr )
{
	_eputs( info->fname );
	_eputs( ": " );
	print_d( info->line_count, STDERR_FILENO );
	_eputs( ": " );
	_eputs( info->argv[0] );
	_eputs( ": " );
	_eputs( estr );
}



/**
 *
 * _erratoi - converts the string to be integer
 * @s: the string should be converted
 *
 * Return: if no numbers in string should be 0, converted number and -1 if it's error
 * 
 *
 */

int _erratoi( char *s )
{
	int i = 0;
	unsigned long int result = 0;

	if ( *s == '+' )
		s++;
	for ( i = 0;  s[i] != '\0'; i++ )
	{
		if ( s[i] >= '0' && s[i] <= '9' )
		{
			result *= 10;
			result += (s[i] - '0');
			if ( result > INT_MAX )
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 *
 * convert_number - the converter function, the clone of itoa
 * @num: the number
 *
 * @base: the base
 * @flags: the argument flags
 *
 * Return: the string
 *
 */

char *convert_number( long int num, int base, int flags )
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if ( !( flags & CONVERT_UNSIGNED ) && num < 0 )
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while ( n != 0 );

	if ( sign )
		*--ptr = sign;
	return (ptr);
}
