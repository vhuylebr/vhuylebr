/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:20:46 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/23 17:21:59 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	resize(int i)
{
	char	str[2];

	(void)i;
	str[0] = -42;
	str[1] = '\0';
	ioctl(0, TIOCSTI, str);
}

void	cont(int i)
{
	char	str[2];
	char	str2[2];

	(void)i;
	str[0] = -42;
	str[1] = '\0';
	str2[0] = 10;
	str2[1] = '\0';
	ioctl(0, TIOCSTI, str);
	ioctl(0, TIOCSTI, str2);
}

void	ctrl_c(int i)
{
	struct termios term;

	tcgetattr(0, &term);
	(void)i;
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
	ft_putstr_fd(tgetstr("me", NULL), FD);
	ft_putstr_fd(tgetstr("cl", NULL), FD);
	ft_putstr_fd(tgetstr("ve", NULL), FD);
	exit(0);
}

void	ft_signals(void)
{
	void	*res;
	void	*con;
	void	*ctrlc;

	con = &cont;
	res = &resize;
	ctrlc = &ctrl_c;
	signal(SIGWINCH, res);
	signal(SIGCONT, con);
	signal(SIGINT, ctrlc);
}
