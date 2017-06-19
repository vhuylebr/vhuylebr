/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:04:38 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 23:23:27 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ctrl_c()
{
	write(1, CTRLC, 7);
}

void		sigft(int sig, char **env)
{
	if (sig == 12)
	{
		ft_putstr("\033[H\033[2J");
		print_prompt(env);
	}
	signal(SIGINT, ctrl_c);
}
