/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 13:30:04 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 18:58:54 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		find_in_env(char **env, char *to_find)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], to_find, strlen(to_find)) == 0)
			return (i);
		++i;
	}
	return (-1);
}

char	*ft_getenv(char **env, char *to_find)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], to_find, strlen(to_find)) == 0)
			return (strdup(env[i] + strlen(to_find)));
		++i;
	}
	return (NULL);
}

char	*ft_getenv_no_malloc(char **env, char *to_find)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], to_find, strlen(to_find)) == 0)
			return (env[i] + strlen(to_find));
		++i;
	}
	return (NULL);
}
