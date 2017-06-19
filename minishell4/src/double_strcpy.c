/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_strcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 13:41:00 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 22:47:38 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**free_tab(char **to_free, char **envcpy)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
	return (envcpy);
}

char	**tab_cpy(char **tab)
{
	int		i;
	char	**cpy;

	i = 0;
	while (tab[i])
		++i;
	cpy = malloc(sizeof(char*) * (i + 3));
	i = 0;
	while (tab[i])
	{
		cpy[i] = strdup(tab[i]);
		++i;
	}
	cpy[i] = NULL;
	cpy[i + 1] = NULL;
	return (cpy);
}

int		find(char **envcpy, char *str)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (envcpy[y])
	{
		if (my_strncmp(envcpy[y], str, strlen(str)) == 0)
			return (y);
		++y;
	}
	return (-1);
}
