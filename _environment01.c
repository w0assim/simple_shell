#include "shell.h"

/**
 * _setenv - the modification of an existing environment variable or Initialization a new one
 * @info: Structure of the  potential arguments
 * the constant function prototype.
 * @var: the string of a environment variable property
 * @value: the value string
 * Return: the 0
 *
 */

int _setenv( info_t *info, char *var, char *value )
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if ( !var || !value )
		return (0);

	buf = malloc( _strlen( var ) + _strlen( value ) + 2 );
	if ( !buf )
		return (1);
	_strcpy( buf, var );
	_strcat( buf, "=" );
	_strcat( buf, value );
	node = info->env;
	while ( node )
	{
		p = starts_with( node->str, var );
		if ( p && *p == '=' )
		{
			free( node->str );
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end( &( info->env ), buf, 0 );
	free( buf );
	info->env_changed = 1;
	return (0);
}


/**
 * get_environ - the return of the array's string copy of the environ
 * @info: Structure of the potential arguments
 * the constant function prototype.
 * Return: the 0
 *
 */

char **get_environ( info_t *info )
{
	if ( !info->environ || info->env_changed )
	{
		info->environ = list_to_strings( info->env );
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - delete the environment variable
 * @info: Structure of the potential arguments
 * @var: the environment variable's string property
 * the constant function prototype
 * Return: if it's 1 should delete it , if it's not 0
 */

int _unsetenv( info_t *info, char *var )
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if ( !node || !var )
		return (0);

	while ( node )
	{
		p = starts_with( node->str, var );
		if ( p && *p == '=' )
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}
