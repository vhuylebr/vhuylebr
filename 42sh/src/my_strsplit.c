/*
 ** my_strsplit.c for l in /home/vhuylebr/Desktop/PSU_2016_minishell1
 **
 ** Made by valerian huylebroeck
 ** Login   <vhuylebr@epitech.net>
 **
 ** Started on  Mon Jan  9 18:06:11 2017 valerian huylebroeck
 ** Last update Wed May 17 14:28:23 2017 Leandro Braga
 */

#include <stdlib.h>
#include "minishell.h"

int	ft_n(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
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

int	spe(char *str, char **tab, int i, int mot)
{
	int	len;

	len = 0;
	++i;
	if (tab)
	{
		while (str[i] && str[i] != '"')
			tab[mot][len++] = str[i++];
		tab[mot][len] = '\0';
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
	char	**tab;
	int	len;

	if (mot == -1)
		return (NULL);
	if (!str || !(tab = (char **)malloc(sizeof(char*) * (mot + 1))))
		return (NULL);
	while (mot > 0)
		tab[--mot] = (char *)malloc((sizeof(char)) * strlen(str) + 1);
	mot = 0;
	while (str[i] != 0)
	{
		len = 0;
		if (str[i] == '"')
			i = spe(str, tab, i, mot++);
		else if (str[i] != ' ' && str[i] != 0 && str[i] != '\t')
		{
			while (str[i] != ' ' && str[i] != '\0' && str[i] != '\t')
				tab[mot][len++] = str[i++];
			tab[mot++][len] = '\0';
		}
		else if (str[i])
			++i;
	}
	tab[mot] = NULL;
	return (tab);
}

char	**my_strsplit2(char *str, char c, int mot, int i)
{
	char	**tab;
	int	len;

	if (mot == -1)
		return (NULL);
	if (!str || !(tab = (char **)malloc(sizeof(char*) * (mot + 1))))
		return (NULL);
	tab[mot] = NULL;
	while (mot > 0)
		tab[--mot] = (char *)malloc((sizeof(char)) * strlen(str) + 1);
	mot = 0;
	while (str[i] != 0)
	{
		len = 0;
		if (str[i] != c && str[i] != 0)
		{
			while (str[i] != c && str[i] != '\0')
					tab[mot][len++] = str[i++];
			tab[mot++][len] = '\0';
		}
		else if (str[i])
			++i;
	}
	return (tab);
}
