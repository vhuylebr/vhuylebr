/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 02:44:56 by pbernier          #+#    #+#             */
/*   Updated: 2017/06/16 17:16:35 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(int size)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(*str) * size + 1)))
		return (0);
	str[size] = '\0';
	while (size > 0)
		str[size-- - 1] = '\0';
	return (str);
}
