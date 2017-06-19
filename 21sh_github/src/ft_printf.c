/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:37:34 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/16 19:12:42 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdarg.h>

void	aff_arg(char spe, va_list ap, int fd)
{
	if (spe == 's')
		ft_putstr_fd(va_arg(ap, char*), fd);
	if (spe == 'i')
		ft_putnbr_fd(va_arg(ap, int), fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int		ft_printf(int fd, char *str, int ret, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, ret);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar_fd(str[i], fd);
		else
			aff_arg(str[++i], ap, fd);
		++i;
	}
	va_end(ap);
	return (ret);
}
