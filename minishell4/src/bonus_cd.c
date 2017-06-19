/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:14:01 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 19:11:43 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cd_u(char *av, char **env, int pwd, int old)
{
	int		ret;
	DIR		*dir;

	ret = -1;
	if (av == NULL)
		return (ft_printf(2, "usage: -u [name in env]\n", -1));
	if ((ret = find_in_env(env, av)) == -1)
		return (ft_printf(2, "no found in env\n", -1));
	if ((dir = opendir(ft_getenv_no_malloc(env, strcat(av, "=")))))
	{
		closedir(dir);
		if (cd_normal(ft_getenv_no_malloc(env, av),
				env, pwd, old) == -1)
			return (ft_printf(2, "error chdir\n", -1));
	}
	else
		return (ft_printf(2, "Bad path\n", -1));
	return (0);
}

char	**bonus_cd(DIR *dir, char *path, char **env)
{
	closedir(dir);
	cd_normal(path, env, find_in_env(env, "PWD="),
				find_in_env(env, "OLDPWD="));
	return (env);
}
