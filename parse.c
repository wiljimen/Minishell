#include "minishell.h"

void	ft_signal(int sig)
{
	g_signal = sig; // actualiza la global
}

char	*ft_quote(char *input)
{
	int		i;
	char	quote;
	int		start;
	char	*result;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			printf("encontre comillas\n");
			quote = input[i];
			start = i + 1;
			i = start;
			while (input[i] && input[i] != quote)
				i++;
			if (input[i] != quote)
				return (0);
			result = ft_substr(input, start, (i - start));
			return (result);
		}
		i++;
	}
	return (0);
}

int	header(char **env)
{
	char *input; // puntero para guardar lo que se escribe
	while (1)
	{
		input = readline("minishell> "); // muestra "minishell> " y espera input
		if (!input)
			// si el usuario pulsa Ctrl+D (EOF),salimos
			break ;
		if (strcmp(input, "exit") == 0) // si el usuario escribe "exit", salimos
		{
			free(input);
			break ;
		}
		if (*input) // si la línea no está vacía (no es solo Enter)
		{
			add_history(input); // guarda el comando en el historial
			run_pipex(input, env);
			ft_quote(input);
		}
		free(input);
	}
	return (0);
}

void	run_pipex(char *input, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
	{
		// Proceso hijo: ejecuta el comando
		ft_exec(input, env);
		exit(127);
	}
	else
	{
		// Proceso padre: espera a que termine el hijo para volver a la minishell
		waitpid(pid, &status, 0);
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	header(env);
	return (0);
}
