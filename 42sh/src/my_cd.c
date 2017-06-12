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

#include "minishell.h"

static int		find_in_env(char **env, char *to_find)
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

char *ft_getenv(char **env, char *to_find)
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

char *ft_getenv_no_malloc(char **env, char *to_find)
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

static int	cd_normal(char *av, char **env, int ref_pwd, int ref_oldpwd)
{
  char buff[1000];

  if (ref_pwd == -1)
    return (printf("cd : no pwd in env\n"));
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

int     cd_back(char **env, int ref_pwd, int ref_oldpwd, DIR *dir)
{
  char *tmp;
  char buff[1000];

  if (ref_pwd == -1)
    return (printf("cd -: no PWD in env\n"));
  if (ref_oldpwd == -1)
    {
      printf("cd -: no OLDPWD in env\n");
      return (-1);
    }
  tmp = ft_getenv(env, "OLDPWD=");
  if ((dir = opendir(tmp)) == NULL)
    {
      printf("cd -: fail of OLDPWD in env\n");
      free(env[ref_oldpwd]);
      env[ref_oldpwd] = strjoin("OLDPWD=", getcwd(buff, 1000));
      free(tmp);
      return (-1);
    }
  closedir(dir);
  free(env[ref_oldpwd]);
  env[ref_oldpwd] = strjoin("OLDPWD=", getcwd(buff, 1000));
  if (chdir(tmp) == -1)
    return (-1);
  free(env[ref_pwd]);
  env[ref_pwd] = strjoin("PWD=", getcwd(buff, 1000));
  free(tmp);
  return (0);
}

int cd_home(char **env, int pwd, int oldpwd, DIR *dir)
{
  char buff[1000];

  if (pwd == -1)
    return (printf("cd : no PWD in env\n"));
  if (oldpwd == -1)
    return (printf("cd : no oldpwd in env\n"));
  if (find_in_env(env, "HOME=") == -1)
    {
      printf("cd : no HOME directory\n");
      return (-1);
    }
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
  printf("cd : HOME directory in env fail\n");
  return (-1);
}

int		my_cd(char **argv, char **env)
{
  DIR *dir;

  dir = NULL;
	if (argv[1] == NULL)
	  return (cd_home(env, find_in_env(env, "PWD="), find_in_env(env, "OLDPWD=") , dir));
	else if (my_strcmp("-", argv[1]) == 0)
	  return (cd_back(env, find_in_env(env, "PWD="), find_in_env(env, "OLDPWD="), dir));
	else if (my_strcmp("--", argv[1]) == 0)
	  return (0);
	else if ((dir = opendir(argv[1])))
	  {
	    closedir(dir);
	    return (cd_normal(argv[1], env, find_in_env(env, "PWD="),
			      find_in_env(env, "OLDPWD=")));
	  }
	else
	  return (printf("%s: %s\n", argv[1], NOT_DIR));
	return (0);
}
