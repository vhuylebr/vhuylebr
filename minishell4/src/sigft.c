/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:04:38 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 22:56:48 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ctrl_c(int sign)
{
	(void)sign;
	write(1, CTRLC, 7);
}

void		sigft(int sig, char **env)
{
	if (!isatty(0))
	{
		ft_printf(2, "This shell needs a stdin terminal connected.", -1);
		exit(1);
	}
	if (sig == 12)
	{
		ft_putstr("\033[H\033[2J");
		print_prompt(env);
	}
	signal(SIGINT, &ctrl_c);
}
