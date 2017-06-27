/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:38:42 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/27 11:25:48 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			is_return(char *buf)
{
	return (buf[0] == 10);
}

int			is_esc(char *buf)
{
	return (buf[0] == 27 && buf[1] == 0);
}

int			is_ctrl_z(char *buf)
{
	return (buf[0] == 26);
}

int			is_ctrl_c(char *buf)
{
	return (buf[0] == 3);
}

int			is_sig(char *buf)
{
	return (buf[0] == -42);
}
