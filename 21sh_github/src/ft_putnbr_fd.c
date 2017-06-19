/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:37:04 by pbernier          #+#    #+#             */
/*   Updated: 2017/06/16 20:35:29 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_len_nbr_fd(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

void		ft_putnbr_fd(int n, int fd)
{
	int	save;
	int len;
	int	tabl[ft_len_nbr_fd(n) + 1];

	len = ft_len_nbr_fd(n);
	save = n;
	tabl[len] = 10;
	len--;
	while (len >= 0)
	{
		tabl[len] = save % 10;
		if (tabl[len] < 0)
			tabl[len] = -tab[len];
		len--;
		save = save / 10;
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (tabl[save] != 10)
		ft_putchar_fd(tabl[save++] + 48, fd);
}
