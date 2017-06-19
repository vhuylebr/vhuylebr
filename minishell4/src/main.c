/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 10:31:13 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 22:55:43 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "minishell.h"

int			len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int			ft_env(char **tmp, char **s)
{
	int		i;

	i = 0;
	if (s[1] == NULL)
		aff_tab(tmp, 1);
	else if (my_strcmp(s[1], "-i") == 0)
		return (0);
	else if (my_strcmp(s[1], "-u") == 0)
	{
		if (s[2] == NULL)
			ft_putstr_fd("Too few argument\n", 2);
		else
			while (tmp[i])
			{
				if (i != find_in_env(tmp, s[2]))
					ft_printf(1, "%s\n", 0, tmp[i]);
				++i;
			}
	}
	return (0);
}

int			next_check(char **s, char ***envcpy, int y)
{
	char	**tmp;

	tmp = tab_cpy(*envcpy);
	if (my_strcmp(ENV, s[0]) == 0)
		y = ft_env(tmp, s);
	else if (my_strcmp(SETENV, s[0]) == 0)
		y = add_env(tmp, s);
	else if (my_strcmp(UNSETENV, s[0]) == 0)
		y = remove_env(tmp, s);
	else if (my_strcmp(CD, s[0]) == 0)
		y = my_cd(s, tmp);
	else if (my_strcmp(EXIT, s[0]) == 0)
		exit(0);
	else if (my_strncmp(s[0], "./", 2) == 0 || my_strncmp(s[0], "/", 1) == 0)
		y = exe_file(s, tmp);
	else if (my_strcmp(ECHO, s[0]) == 0)
		y = ft_echo(s);
	else
	{
		free_tab(tmp, NULL);
		return (ft_printf(2, "%s: %s\n", -1, s[0], BAD_COM));
	}
	free_tab(*envcpy, NULL);
	*envcpy = tmp;
	return (y);
}

t_minishell	init_sh(int ac, char **av)
{
	t_minishell sh;

	(void)av;
	(void)ac;
	sh.i = 0;
	sh.k = 0;
	return (sh);
}

int			main(int ac, char **av, char **env)
{
	t_minishell sh;

	sh = init_sh(ac, av);
	print_prompt(env);
	env = tab_cpy(env);
	while (get_next_line(0, &sh.s) > 0)
	{
		sh.str = my_strsplit2(sh.s, ';', ft_n(sh.s, ';', 0, 0), 0);
		if (sh.str)
		{
			while (sh.str[sh.i])
			{
				sh.k = exe(my_parseur(sh.str[sh.i], count_parse(sh.str[sh.i]),
							0), &env, 0, find(env, "PATH="));
				++sh.i;
			}
			free_tab(sh.str, NULL);
		}
		print_prompt(env);
		sigft(sh.s[0], env);
		free(sh.s);
		sh.i = 0;
	}
	free_tab(env, NULL);
	return (sh.k);
}
