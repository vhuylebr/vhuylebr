/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:11:32 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 19:18:36 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	error_cd(char *str)
{
	ft_putstr_fd(str, 2);
	return (-1);
}

int			cd_normal(char *av, char **env, int ref_pwd, int ref_oldpwd)
{
	char buff[1000];

	if (ref_pwd == -1)
		return (error_cd("cd : no pwd in env\n"));
	if (ref_oldpwd != -1)
	{
		free(env[ref_oldpwd]);
		env[ref_oldpwd] = strjoin("OLDPWD=", getcwd(buff, 1000));
	}
	if (chdir(av) == -1)
		return (-1);
	free(env[ref_pwd]);
	env[ref_pwd] = strjoin("PWD=", getcwd(buff, 1000));
	return (0);
}

static int	cd_back(char **env, int ref_pwd, int ref_oldpwd, DIR *dir)
{
	t_cd_back cd_back;

	if (ref_pwd == -1)
		return (error_cd("cd -: no PWD in env\n"));
	if (ref_oldpwd == -1)
		return (error_cd("cd -: no OLDPWD in env\n"));
	cd_back.tmp = ft_getenv(env, "OLDPWD=");
	if ((dir = opendir(cd_back.tmp)) == NULL)
	{
		free(env[ref_oldpwd]);
		env[ref_oldpwd] = strjoin("OLDPWD=", getcwd(cd_back.buff, 1000));
		free(cd_back.tmp);
		return (error_cd("cd -: fail of OLDPWD in env\n"));
	}
	closedir(dir);
	free(env[ref_oldpwd]);
	env[ref_oldpwd] = strjoin("OLDPWD=", getcwd(cd_back.buff, 1000));
	chdir(cd_back.tmp);
	free(env[ref_pwd]);
	env[ref_pwd] = strjoin("PWD=", getcwd(cd_back.buff, 1000));
	free(cd_back.tmp);
	return (0);
}

static int	cd_home(char **env, int pwd, int oldpwd, DIR *dir)
{
	char buff[1000];

	if (pwd == -1)
		return (error_cd("cd : no PWD in env\n"));
	if (oldpwd == -1)
		return (error_cd("cd : no oldpwd in env\n"));
	if (find_in_env(env, "HOME=") == -1)
		return (error_cd("cd : no HOME directory\n"));
	if ((dir = opendir(ft_getenv_no_malloc(env, "HOME="))))
	{
		closedir(dir);
		free(env[oldpwd]);
		env[oldpwd] = strjoin("OLDPWD=", getcwd(buff, 1000));
		if (chdir(ft_getenv_no_malloc(env, "HOME=")) == 0)
		{
			free(env[pwd]);
			env[pwd] = strjoin("PWD=", getcwd(buff, 1000));
			return (0);
		}
	}
	return (error_cd("cd : HOME directory in env fail\n"));
}

int			my_cd(char **argv, char **env)
{
	DIR *dir;

	dir = NULL;
	if (argv[1] == NULL)
		return (cd_home(env, find_in_env(env, "PWD="),
					find_in_env(env, "OLDPWD="), dir));
	else if (my_strcmp("-", argv[1]) == 0)
		return (cd_back(env, find_in_env(env, "PWD="),
					find_in_env(env, "OLDPWD="), dir));
	else if (my_strcmp("--", argv[1]) == 0)
		return (0);
	else if ((dir = opendir(argv[1])))
	{
		closedir(dir);
		return (cd_normal(argv[1], env, find_in_env(env, "PWD="),
					find_in_env(env, "OLDPWD=")));
	}
	else if (my_strcmp(argv[1], "-e") == 0)
		cd_u(argv[2], env, find_in_env(env, "PWD="),
					find_in_env(env, "OLDPWD="));
	else
		return (ft_printf(2, "%s: %s\n", -1, argv[1], NOT_DIR));
	return (0);
}
