/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 10:31:13 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/17 19:03:26 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "minishell.h"

char buf[1024];
char buf2[30];
char *ap = buf2;
char *clearstr, *gotostr, *left, *right;

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
	else if (my_strcmp(MECHO, s[0]) == 0)
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

int             ft_set_stage(struct termios *term)
{
	char                    buffer[2048];

	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
	clearstr = tgetstr("cl", &ap);
	gotostr = tgetstr("cm", &ap);
	right = tgetstr("nd", &ap);
	left = tgetstr("le", &ap);
	return (1);
}

int		ft_getchar_fd(int fd)
{
	char	c;

	if (1 != read(fd, &c, 1))
		return (-1);
	return ((int)c);
}

char		*edit_line()
{
	char		c;
	int		i;
	char	*tmp;
	char	*str;

	i = 0;
	str = malloc(100);
	bzero(str, 100);
	while ((c = ft_getchar_fd(0)) != '\n')
	{
		if (c == 12)
			ft_putstr("\033[H\033[2J");
		if (c == 27)
		{
			if (ft_getchar_fd(0) == 91)
			{
				c = ft_getchar_fd(0);
				if (c == 67 && str[i])
				{
					++i;
					ft_printf(1, right, 0);
				}
				else if (c == 68 && i > 0)
				{
					--i;
					ft_printf(1, left, 0);
				}
			}
		}
		else
		{
			if (str[i])
			{
				tmp = strdup(str + i);
				str[i] = c;
				str = strjoin(str, tmp);
				ft_putchar_fd(c, 1);
				ft_printf(1, tmp, 0);
				ft_printf(1, tgoto(gotostr, i + 2, 0), 0);
			}
			else
			{
				str[i++] = c;
				ft_putchar_fd(c, 1);
			}
		}
	}
	ft_putstr("\n");
	i = 0;
	while (str[i])
	{
		ft_printf(1, "%i\n", 0, str[i++]);
	}
	ft_putstr(str);
	return (str);
}

int			main(int ac, char **av, char **env)
{
	t_minishell sh;
	struct termios term;

	sh = init_sh(ac, av);
	print_prompt(env);
	env = tab_cpy(env);
	ft_set_stage(&term);
	while ((sh.s = edit_line()))
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
