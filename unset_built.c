/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_built.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:34:58 by wiljimen          #+#    #+#             */
/*   Updated: 2025/10/09 19:52:42 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_valid_var_name(char *name)
{
	int	i;

	i = 0;
	if (!name || !((name[0] >= 'A' && name[0] <= 'Z') ||
				(name[0] > 'a' && name[0] <= 'z') ||
				name[0] == '_'))
		return (0);
	while (name[i])
	{
		if (!((name[i] >= 'A' && name[i] <= 'Z') ||
			(name[i] >= 'a' && name[i] <= 'z') ||
			(name[i] >= '0' && name[i] <= '9') ||
			(name[i] == '_')))
			return (0);
		i++;
	}
	return (1);
}

char	*var_same(char *var_name, char *name)
{
	int	i;

	i = 0;
	while (var_name[i] && var_name[i] != '=' && name[i])
	{
		if (var_name[i] != name[i])
			return (0);
		i++;
	}
	if ((var_name[i] == '=' || var_name[i] == '\0') && name[i] == '\0')
		return (1);
	return (0);
}

void	built_unset(t_vars *head, char *var_delete)
{
	t_vars	*previous;
	t_vars	*current;

	previous = NULL;
	current = head;
	while(current != NULL)
	{
		if (var_same(current->name, var_delete))
		{
			if (previous == NULL)
			{
				previous = current;
				current = current->next;
			}
			else
				previous->next = current->next;
			free(previous->name);
			free(previous->value);
			return ;
		}
		previous = current;
		current = current->next;
	}
	return ;
}
