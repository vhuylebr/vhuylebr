/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:14:26 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 19:17:47 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(char **env)
{
	ft_putstr("\033[36m");
	ft_putstr("\033[1m");
	if (find_in_env(env, "USER=") != -1)
	{
		ft_putstr(ft_getenv_no_malloc(env, "USER="));
		ft_putstr("\033[32m");
		ft_putstr("\033[1m");
		if (find_in_env(env, "PWD=") != -1)
		{
			ft_putstr(":[");
			ft_putstr(ft_getenv_no_malloc(env, "PWD="));
			ft_putstr("]\n");
		}
	}
	ft_putstr("\033[32m");
	ft_putstr("\033[1m");
	ft_putstr("$");
	ft_putstr(">");
	ft_putstr("\033[0m");
	ft_putstr("\033[1m");
}
