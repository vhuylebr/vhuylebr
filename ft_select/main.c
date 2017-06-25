/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhuylebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:13:59 by vhuylebr          #+#    #+#             */
/*   Updated: 2017/06/23 17:17:45 by vhuylebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				ft_get_size(t_window *size)
{
	struct winsize	ws;

	ioctl(FD, TIOCGWINSZ, &ws);
	if ((size->co = (int)ws.ws_col) < 0)
		return (-1);
	if ((size->li = ws.ws_row) < 0)
		return (-1);
	return (1);
}

t_clist			*ft_get_list(char **argv)
{
	t_clist		*ret;
	int			i;

	i = 1;
	ret = ft_clstnew(argv[i]);
	i++;
	while (argv[i])
	{
		ft_clstaddend(&ret, ft_clstnew(argv[i]));
		i++;
	}
	ret->is_cursor = 1;
	return (ret);
}

void			ft_return(t_clist **list)
{
	t_clist		*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->is_selected)
		{
			ft_putstr_fd(tmp->str, 1);
			ft_putstr_fd(" ", 1);
		}
		tmp = tmp->next;
	}
	ft_putstr_fd("\n", 1);
}

int				input(t_window *size,
		t_clist **list, struct termios *term)
{
	char		*read_char;
	int			direction;
	t_clist		*item;

	item = *list;
	read_char = ft_strnew(5);
	while (!(is_return(read_char)))
	{
		ft_bzero(read_char, sizeof(read_char));
		read(0, read_char, 5);
		if ((direction = is_arrow(read_char)))
			item = what_arrow(direction, size, list, item);
		if (is_space(read_char))
			item = ft_select(size, list, item);
		if (is_bspace(read_char) || is_del(read_char))
			item = ft_del_item(size, list, item);
		if (is_esc(read_char) || item == NULL)
			return (0);
		if (is_sig(read_char))
			ft_refresh(size, list, term);
	}
	free(read_char);
	return (1);
}

int				main(int argc, char **argv)
{
	struct termios	term;
	t_window		size;
	t_clist			*list;

	if (argc == 1)
		return (0);
	if ((!ft_set_term(&term)) || (!ft_get_size(&size)))
		return (-1);
	ft_signals();
	list = ft_get_list(argv);
	ft_print_all(&size, &list);
	if (input(&size, &list, &term))
	{
		ft_unset_term(&term);
		ft_return(&list);
		ft_list_del(&list);
		return (1);
	}
	ft_unset_term(&term);
	if (list != NULL)
	  ft_list_del(&list);
	return (0);
}
