/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:11:32 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/08 15:21:03 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

static char	*find_where_start(char **env)
{
	int		i;

	i = 0;
	while (env[i] && my_strncmp(env[i], "PWD=", 4) != 0)
		++i;
	if (env[i] == NULL)
		return (NULL);
	return (strdup(env[i] + 4));
}


static char		*find_home(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], "HOME=", 5) == 0)
			return (env[i] + 5);
		++i;
	}
	return ("./");
}

char	*no_leaks_cd(char **old, char **env, char *av, int i)
{
	char *path;
	char *tmp;

	if (old)
		{
			free(*old);
			*old = strdup(env[i] + 7);
		}
	else
	{
		free(env[i]);
		if (!(env[i] = strjoin("OLDPWD=", find_where_start(env))))
			env[i] = strdup("OLDPWD=");
	}
		tmp = strjoin(env[i], "/");
		path = strjoin(tmp, av);
		free(tmp);
		return (path);
}

static void 	cd_back(char **old, char *av, char **env)
{
	int	i;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], "OLDPWD=", 7) == 0)
		{
			tmp = no_leaks_cd(old, env, av, i);
			break ;
		}
		++i;
	}
	if (env[i] == NULL)
		return ;
	free(env[i]);
	if (av[0] != '/')
		env[i] = tmp;
	else if (av[0] == '/')
		env[i] = strjoin("OLDPWD=", av);
}

int		my_cd(char **argv, char **env, int ref)
{
	static char *old;

	if (argv[1] == NULL)
		ref = chdir(find_home(env));
	else if (my_strcmp("-", argv[1]) == 0)
	{
		if (old == NULL)
			return (printf("%s: %s\n", argv[1], NOT_DIR));
		else
			ref = chdir(old);
			printf("%s\n", old);
	}
	else if (my_strcmp("--", argv[1]) == 0)
		return (0);
	else if (chdir(argv[1]) == 0)
		cd_back(&old, argv[1], env);
	else
		return (printf("%s: %s\n", argv[1], NOT_DIR));
	if (ref == -1)
		return (printf("%s\n", NO_HOME));
	return (0);
}
