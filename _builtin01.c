#include "shell.h"


/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 *
 * Return: Always 0 on success, 1 on error
 */

int print_alias( list_t *node )
{
	char *p = NULL, *a = NULL;

	if ( node )
	{
		p = _strchr( node->str, '=' );
		for ( a = node->str; a <= p; a++ )
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}


/**
 * unset_alias -  the string of a stes alias
 * @info: parameter struct
 *
 * @str: the alias of string
 *
 * Return: the 0 if it s success, 1 if it's error
 *
 */
int unset_alias( info_t *info, char *str )
{
	char *p, c;
	int ret;

	p = _strchr( str, '=' );
	if ( !p )
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index( &( info->alias ),
		get_node_index( info->alias, node_starts_with( info->alias, str, -1 ) ) );
	*p = c;
	return (ret);
}

/**
 * set_alias - the string of the sets alias
 * @info: parameter struct
 *
 * @str: the string alias
 *
 * Return: the 0 if it's success, 1 if it's error
 */

int set_alias( info_t *info, char *str )
{
	char *p;

	p = _strchr( str, '=' );
	if ( !p )
		return (1);
	if ( !*++p )
		return (unset_alias(info, str));

	unset_alias( info, str );
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * _myalias - the alias builtin
 * @info: Structure of a potential arguments.
 * Return: the 0
 *The constant function prototype.
 */

int _myalias( info_t *info )
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if ( info->argc == 1 )
	{
		node = info->alias;
		while ( node )
		{
			print_alias( node );
			node = node->next;
		}
		return (0);
	}
	for ( i = 1; info->argv[i]; i++ )
	{
		p = _strchr( info->argv[i], '=' );
		if ( p )
			set_alias( info, info->argv[i] );
		else
			print_alias( node_starts_with( info->alias, info->argv[i], '=' ) );
	}

	return (0);
}



/**
 * _myhistory - displays the history list gives 1 command by line,
 *  preceded with line numbers it starting at 0.
 *
 * @info: Structure containing potential arguments.
 * The constant function prototype.
 *
 *
 *  Return: the 0
 */

int _myhistory( info_t *info )
{
	print_list( info->history );
	return (0);
}
