/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:40:41 by rohidalg          #+#    #+#             */
/*   Updated: 2025/10/01 19:52:57 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	skip_quotes(const char *str, int *i)
{
	char	quote;

	if (str[*i] == '\'' || str[*i] == '"')
	{
		quote = str[*i];
		(*i)++;
		while (str[*i] && str[*i] != quote)
			(*i)++;
		if (str[*i] == quote)
			(*i)++;
		return (1);
	}
	return (0);
}

int	ft_countwords(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (!str[i])
			break ;
		if (!skip_quotes(str, &i)) // si no hay comillas, salto palabra normal
		{
			while (str[i] && str[i] != c && str[i] != '\'' && str[i] != '"')
				i++;
		}
		count++;
	}
	return (count);
}

/*cuenta palabras utilizando el delimitador c,
y count se imcrementa cada vez que encuentra el primer caracter de la palabra*/

char	*ft_words(const char *str, char c, int *i)
{
	int		start;
	int		len;
	char	*word;

	start = *i;
	while (str[*i] == c)
		(*i)++;
	start = *i + 1;
	if (skip_quotes(str, i)) // si hay comillas, i ya avanzó hasta el cierre
		len = *i - start - 1;
	else
	{
		while (str[*i] && str[*i] != c && str[*i] != '\'' && str[*i] != '"')
			(*i)++;
		len = *i - start;
	}
	word = malloc(len + 1);
	if (!word)
		return (0);
	ft_strlcpy(word, str + start, len + 1);
	return (word);
}

/*i rastrea la posicion de la palabra y len coge el tamaño
para el espacio de memoria*/

char	**ft_free(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
	return (0);
}
/*libera memoria asiganada en bucle para las string y luego para la matriz*/

char	**ft_split(char const *str, char c)
{
	int		countwords;
	char	**string;
	int		i_string;
	int		i;

	if (!str)
		return (0);
	countwords = ft_countwords(str, c);
	string = ft_calloc(countwords + 1, sizeof(char *));
	if (string == 0)
		return (0);
	i_string = 0;
	i = 0;
	while (i_string < countwords)
	{
		string[i_string] = ft_words(str, c, &i);
		if (!string[i_string])
			return (ft_free(string));
		i_string++;
	}
	string[i_string] = 0;
	return (string);
}

/*asigno memoria con calloc y sabiendo las palabras que hay, hago el tamaño,
luego con ft_words las agrega a la matriz, y en caso de error uso el free*/








/*solucione este caso:
"echo 'hola mundo'"


pero ya no funciona de normal


SOLUCIONA ESTO PARA QUE FUNCIONE
minishell> echo "hola"
Palabra 0: cho
Palabra 1: hola
command not found: cho*/