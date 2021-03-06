/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 13:42:20 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 20:33:15 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_n(const char *str, char c, int word, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (str[i] == '"')
			{
				++i;
				while (str[i] && str[i] != '"')
					++i;
				if (str[i] == '\0')
					return (-1);
				++i;
			}
			else
				while (str[i] != c && str[i] != 0 && str[i] != '"')
					i++;
			word++;
		}
		else if (str[i])
			++i;
	}
	return (word);
}

int		spe(char *str, char **tabl, int i, int mot)
{
	int	len;

	len = 0;
	++i;
	if (tabl)
	{
		while (str[i] && str[i] != '"')
			tabl[mot][len++] = str[i++];
		tabl[mot][len] = '\0';
	}
	else
		while (str[i] && str[i] != '"')
			++i;
	return (i + 1);
}

int		count_parse(char *str)
{
	int	i;
	int word;

	word = 0;
	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '"')
		{
			if ((i = spe(str, NULL, i, word++)) == -1)
				return (-1);
		}
		else if (str[i] && str[i] != ' ' && str[i] != '\t')
		{
			while (str[i] && str[i] != '\t' && str[i] != ' ')
				++i;
			++word;
		}
		else if (str[i])
			++i;
	}
	return (word);
}

char	**my_parseur(char *str, int mot, int i)
{
	char	**tabl;
	int		len;

	if (mot <= 0)
		return (NULL);
	if (!str || !(tabl = (char **)malloc(sizeof(char*) * (mot + 1))))
		return (NULL);
	while (mot > 0)
		tabl[--mot] = (char *)malloc((sizeof(char)) * strlen(str) + 1);
	while (str[i] != 0)
	{
		len = 0;
		if (str[i] == '"')
			i = spe(str, tabl, i, mot++);
		else if (str[i] != ' ' && str[i] != 0 && str[i] != '\t')
		{
			while (str[i] != ' ' && str[i] != '\0' && str[i] != '\t')
				tabl[mot][len++] = str[i++];
			tabl[mot++][len] = '\0';
		}
		else if (str[i])
			++i;
	}
	tabl[mot] = NULL;
	return (tabl);
}

char	**my_strsplit2(char *str, char c, int mot, int i)
{
	char	**tabl;
	int		len;

	if (mot == -1)
		return (unmatched());
	if (!str || !(tabl = (char **)malloc(sizeof(char*) * (mot + 1))))
		return (NULL);
	tabl[mot] = NULL;
	while (mot > 0)
		if (!(tabl[--mot] = (char *)malloc((sizeof(char)) * strlen(str) + 1)))
			return (NULL);
	mot = 0;
	while (str[i] != 0)
	{
		len = 0;
		if (str[i] != c && str[i] != 0)
		{
			while (str[i] != c && str[i] != '\0')
				tabl[mot][len++] = str[i++];
			tabl[mot++][len] = '\0';
		}
		else if (str[i])
			++i;
	}
	return (tabl);
}
