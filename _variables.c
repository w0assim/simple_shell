#include "shell.h"


/**
 ** replace_vars - detected the variables in the tokenized of the string
 * @info: the details struct
 * Return: 1 if existed, 0 if not
 */

int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]), _strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]), _strdup(_strchr(node->str, '=') + 1));
			continue;
		}

		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}


/**
 ** is_chain - if the cahin delimeter of the current char is buffer
 * @info: parameter of struct
 * @buf: the char of buffer
 * @p: the address buffer of position
 * Return: 1 if the delimeter of the chain, 0 if not
 */

int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}


/**
 ** replace_string - the replace of string
 * @old: the address of the old string
 * @new: the new string
 * Return: 1 if existed, 0 if not
 */

int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

/**
 ** replace_alias - the replace of the aliases in the string
 * @info: details struct
 * Return: 1 if existed, 0 if not
 */

int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
		{
			return (0);
		}

		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
		{
			return (0);
		}

		p = _strdup(p + 1);
		if (!p)
		{
			return (0);
		}

		info->argv[0] = p;
	}
	return (1);
}


/**
 ** check_chain -  the continue of chaining based on the last status
 * @info: details struct
 * @buf: the char of buffer
 * @p: the address of position
 * @i: the starting of position in buffer
 * @len: the length of buffer
 * Return: the Void
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}
