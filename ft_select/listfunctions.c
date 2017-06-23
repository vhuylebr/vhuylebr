/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:38:08 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/23 17:38:25 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_clstadd(t_clist **alst, t_clist *new)
{
	t_clist	*tmp;

	tmp = *alst;
	new->next = *alst;
	tmp->prev = new;
	*alst = new;
}

void	ft_clstaddend(t_clist **alst, t_clist *new)
{
	t_clist	*tmp;

	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

t_clist	*ft_clstnew(char *str)
{
	t_clist	*newlist;

	newlist = (t_clist *)malloc(sizeof(t_clist));
	if (newlist == NULL)
		return (NULL);
	if (str == NULL)
		newlist->str = NULL;
	else
		newlist->str = ft_strdup(str);
	newlist->next = NULL;
	newlist->prev = NULL;
	return (newlist);
}

int		ft_clistcount(t_clist **alst)
{
	t_clist	*tmp;
	int		i;

	tmp = *alst;
	i = 0;
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		ft_list_del(t_clist **alst)
{
	t_clist	*tmp;
	t_clist	*now;

	now = *alst;
	while (now->next)
	{
		tmp = now->next;
		free(now->str);
		free(now);
		now = tmp;
	}
	free(now->str);
	free(now);
	*alst = NULL;
	return (1);
}
