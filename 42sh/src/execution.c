/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:28:07 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/08 15:16:13 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "minishell.h"

int	exe_file(char **s, char **envcpy)
{
	pid_t	pid;

	if (access(s[0], F_OK | X_OK) != -1)
	{
		if ((pid = fork()) == 0)
		{
			if (execve(s[0], s, envcpy) == -1)
				printf("error");
		}
		else
			wait(&pid);
		if (WTERMSIG(pid) == 11)
			return (printf("%s\n", SEGF_DUMP));
	}
	else if (access(s[0], F_OK) == -1)
		return (printf("%s: %s: %s\n", PROMPT, s[0], NOT_FOUND));
	else if (access(s[0], X_OK) == -1)
		return (printf("%s: %s: %s\n", PROMPT, s[0], NO_PERMISSION));
	return (0);
}

int	verif_pipe(char **s)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s[y])
	{
		while (s[y][x])
		{
			if (s[y][x] == '"')
				while (s[y][x + 1] != '"' && s[y][x + 1])
					++x;
			if (s[y][x] == '|')
				return (y);
			++x;
		}
		++y;
		x = 0;
	}
	return (-1);
}

char	**env_exe(char **PATH, char **s, char **envcpy)
{
	int	i;
	pid_t	pid;

	i = 0;
	pid = 0;
	if (s[0][0] == '\0')
	  return (NULL);
	while (PATH[i])
	{
		PATH[i] = strcat(PATH[i], "/");
		if (access(strcat(PATH[i], s[0]), F_OK | X_OK) != -1)
		{
			if ((pid = fork()) == 0)
			{
				if ((s[0]) && execve(PATH[i], s, envcpy) == -1)
					return (envcpy);
			}
			wait(&pid);
			return (envcpy);
		}
		++i;
	}
	return (NULL);
}

int	return_n_free(char **tab, char **s, int y)
{
	if (tab != NULL)
		free_tab(tab, NULL);
	if (s != NULL)
		free_tab(s, NULL);
	if (y >= 1)
		return (1);
	return (0);
}

int	exe(char **s, char ***env, int y, int path_y)
{
	char	**PATH;
	char	**envcpy;

	envcpy = *env;
	if (s == NULL)
		return (0);
	if (path_y == -1)
	{
		y = next_check(s, &envcpy, 0);
		*env = envcpy;
		return (return_n_free(NULL, s, y));
	}
	PATH = my_strsplit2(envcpy[path_y] + 5, ':', ft_n(envcpy[path_y], ':'), 0);
	if ((y = search_double_redir(s)) != -1 && verif_pipe(s) == -1)
		double_redirection(s, envcpy, PATH, y);
	else if ((y = search_simple_redirection(s)) != -1 &&
			verif_pipe(s) == -1)
			{
				if (redirection(s, envcpy, PATH, y) == -1)
					printf("%s: %s\n", s[0], BAD_COM);
			}
	else if (strcmp("cd", s[0]) != 0 && env_exe(PATH, s, envcpy) != NULL);
	else
		y = next_check(s, &envcpy, 0);
	*env = envcpy;
	return (return_n_free(PATH, s, y));
}
