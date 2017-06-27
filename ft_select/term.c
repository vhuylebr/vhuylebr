/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:43:28 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/23 17:43:30 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				ft_unset_term(struct termios *term)
{
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	tcsetattr(0, 0, term);
	ft_putstr_fd(tgetstr("me", NULL), FD);
	ft_putstr_fd(tgetstr("cl", NULL), FD);
	ft_putstr_fd(tgetstr("ve", NULL), FD);
	return (1);
}

int				ft_set_term(struct termios *term)
{
	char	buffer[2048];

	if (tgetent(buffer, "xterm-256color") < 1)
		return (-1);
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
	ft_putstr_fd(tgetstr("vi", NULL), 2);
	return (1);
}
