/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:38:58 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/23 17:39:30 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		print_header(t_window *size)
{
	if (size->co > 62 && size->li > 11 + size->listcount)
	{
		size->arg_printed = size->arg_printed + 11;
		ft_putstr_fd(C_GREEN, 1);
		ft_putstr_fd(C_BOLD, 1);
		ft_putstr_fd(LINE1, 2);
		ft_putstr_fd(LINE2, 2);
		ft_putstr_fd(LINE3, 2);
		ft_putstr_fd(LINE4, 2);
		ft_putstr_fd(LINE5, 2);
		ft_putstr_fd(LINE6, 2);
		ft_putstr_fd(LINE7, 2);
		ft_putstr_fd(LINE8, 2);
		ft_putstr_fd(LINE9, 2);
		ft_putstr_fd(LINEA, 2);
		ft_putstr_fd(LINEB, 2);
		ft_putstr_fd(C_NONE, 1);
		return (11);
	}
	return (0);
}
