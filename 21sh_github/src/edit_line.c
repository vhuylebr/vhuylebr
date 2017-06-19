/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:10:57 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/19 17:37:49 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *g_left;
char *g_right;
char	g_buf2[30];
char		*g_ap = g_buf2;

int				ft_set_stage(struct termios *term)
{
	char		buffer[2048];

	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
	g_right = tgetstr("nd", &g_ap);
	g_left = tgetstr("le", &g_ap);
	return (1);
}

static int		arrow_key(char c, char *str, int i)
{
	if (ft_getchar_fd(0) == 91)
	{
		c = ft_getchar_fd(0);
		if (c == 67 && str[i])
		{
			++i;
			ft_printf(1, g_right, 0);
		}
		else if (c == 68 && i > 0)
		{
			--i;
			ft_printf(1, g_left, 0);
		}
	}
	return (i);
}

static int		edit_cmd(char c, char **s, int i)
{
	int		k;
	char	*tmp;
	char	*str;

	str = *s;
	k = 0;
	if (str[i])
	{
		str = *s;
		tmp = strdup(str + i);
		str[i] = c;
		str[i + 1] = 0;
		*s = strjoin(str, tmp);
		ft_putchar_fd(c, 1);
		ft_printf(1, tmp, 0);
		k = strlen(tmp) + 1;
		while (--k)
			ft_printf(1, g_left, 0);
		++i;
		free(str);
		free(tmp);
	}
	else
		i = add_char_to_str(s, i, c);
	return (i);
}

void			clear(char **env, char *str, int i)
{
	int k;

	k = strlen(str);
	ft_putstr("\033[H\033[2J");
	print_prompt(env);
	ft_printf(1, str, 0);
	while (i < k)
	{
		ft_printf(1, g_left, 0);
		--k;
	}
}

char			*edit_line(char **env)
{
	char	c;
	int		i;
	char	*str;

	i = 0;
	str = malloc(2);
	bzero(str, 2);
	while ((c = ft_getchar_fd(0)) != '\n')
	{
		if (c == 12)
			clear(env, str, i);
		if (c == 27)
			i = arrow_key(c, str, i);
		if (c == 127)
			i = ft_delete(&str, i);
		if (c >= 32 && c < 127)
			i = edit_cmd(c, &str, i);
	}
	ft_putstr("\n");
	return (str);
}
