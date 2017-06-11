/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 10:31:13 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/08 15:19:05 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include "get_next_line.h"
#include "minishell.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	next_check(char **s, char ***envcpy, int y)
{
	char	**tmp;

	tmp = tab_cpy(*envcpy);
	if (my_strcmp(ENV, s[0]) == 0)
		line_28(tmp);
	else if (my_strcmp(SETENV, s[0]) == 0)
		y = add_env(tmp, s);
	else if (my_strcmp(UNSETENV, s[0]) == 0)
		y = remove_env(tmp, s);
	else if (my_strcmp(CD, s[0]) == 0)
		y = my_cd(s, tmp);
	else if (my_strcmp(EXIT, s[0]) == 0)
		exit(0);
	else if (my_strncmp(s[0], "./", 2) == 0 || my_strncmp(s[0], "/", 1) == 0
			|| my_strncmp(s[0], "~", 1) == 0)
		y = exe_file(s, tmp);
	else
		return (printf("%s: %s\n", s[0], BAD_COM));
	free_tab(*envcpy, NULL);
	*envcpy = tmp;
	return (y);
}

void	ctrl_c()
{
	write(1, CTRLC, 7);
}

int	main(int ac, char **av, char **env)
{
	char	*s;
	char	**str;
	int	i;
	int	k;

	(void)av;
	(void)ac;
	i = 0;
	k = 0;
	write(1, PROMPT2, 6);
	signal(SIGINT, ctrl_c);
	env = tab_cpy(env);
	while (get_next_line(0, &s) > 0)
	{
	  str = my_strsplit2(s, ';', ft_n(s, ';'), 0);
	  if (str)
	    {
	      while (str[i])
		{
		  k = exe(my_parseur(str[i], count_parse(str[i]), 0), &env, 0,
			  find(env, "PATH="));
		  ++i;
		}
	      free_tab(str, NULL);
	    }
	  write(1, PROMPT2, 6);
	  free(s);
	  i = 0;
	}
	free_tab(env, NULL);
	return (k);
}
