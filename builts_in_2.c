/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builts_in_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: will <will@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:31:44 by will              #+#    #+#             */
/*   Updated: 2025/11/25 20:34:02 by will             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    built_cd(char **cmd)
{
    if (cmd[1] == NULL)
        chdir(getenv("HOME"));
    else if(cmd[1] != 0)
        perror("cd");
}

char	**get_entire_env(char **env)
{
	int i;
	int j;
	char *sub;
	char **new_env;

	i = 0;
	if (!*env)
		exit(EXIT_FAILURE);
	while(env[i])
		i++;
	new_env = ft_calloc(i, sizeof(char));
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
			j++;
		sub = ft_substr(env[i], 0, j);
		free(sub);
		i++;
	}
	return (new_env);
}

void	built_pwd(void)
{
	char *cwd;

	cwd = malloc(1024);
	if (!cwd)
	{
		free(cwd);
		exit(EXIT_FAILURE);
	}
    if (getcwd(cwd, 1024) != NULL)
		printf("%sAA\n", cwd);
	else
		perror("pwd");
	free(cwd);
}

void	built_env(char **g_env)
{
	int	i;

	i = 0;
	while (g_env[i])
	{
		printf("%s\n", g_env[i]);
		i++;
	}
}
