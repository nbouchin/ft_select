/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:08:18 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/18 17:22:30 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**      print selection
*/

void		print_select(t_list ***l, t_cursor ***c, int tty, char buffer[6])
{
	(void)c;
	(void)buffer;
	(void)tty;
	reset_termios();
	close(g_va.tty);
	while (**l)
	{
		if (((t_select*)(**l)->cont)->hl)
		{
			ft_putstr_fd(((t_select*)(**l)->cont)->argn, 1);
			ft_putchar_fd(' ', 1);
		}
		(**l) = (**l)->nxt;
	}
	exit(0);
}

/*
**	pace in function of the max_size
*/

void		print_space(t_list **l)
{
	int		i;

	i = (((t_select*)(*l)->cont)->max_size
			- ((t_select*)(*l)->cont)->nsize) + 1;
	while (i-- > 0)
		ft_putchar_fd(' ', g_va.tty);
}

/*
**	Hl and ul mod
*/

void		put_mod(t_cursor **c, t_list **l,
		int ls, t_list *save)
{
	((*c)->pos_x + 1 == (((t_select*)(*l)->cont)->index)
	&& g_va.buffer[0] == 32)
		? (((t_select*)(*l)->cont)->ul = 1) : 0;
	((*c)->pos_x + 1 == ls && g_va.buffer[0] == 32)
		? ((t_select*)save->cont)->ul = 1 : 0;
	(((t_select*)(*l)->cont)->ul) ?
		(ft_putstr_fd(tgetstr("us", NULL), g_va.tty)) : 0;
	(((t_select*)(*l)->cont)->hl) ?
		(ft_putstr_fd(tgetstr("mr", NULL), g_va.tty)) : 0;
	((t_select*)(*l)->cont)->ul = 0;
	ft_putstr_fd(((t_select*)(*l)->cont)->argn, g_va.tty);
	ft_putstr_fd(tgetstr("me", NULL), g_va.tty);
	ft_putstr_fd(tgetstr("ue", NULL), g_va.tty);
	((*c)->pos_x + 1 == ls && g_va.buffer[0] == 32)
		? ((t_select*)save->cont)->ul = 0 : 0;
	print_space(l);
}

/*
**	print_perfect
*/

void		print_perfect(char buffer[6], t_cursor **c,
		t_list **l, int i)
{
	(i == (*c)->pos_x) ? ((t_select*)(*l)->cont)->ul = 1 : 0;
	if ((buffer[0] == 32) && i
			== (*c)->pos_x && ((t_select*)(*l)->cont)->hl == 0)
	{
		((t_select*)(*l)->cont)->hl = 1;
		((t_select*)(*l)->cont)->ul = 0;
	}
	else if ((buffer[0] == 32) && i
			== (*c)->pos_x && ((t_select*)(*l)->cont)->hl == 1)
	{
		((t_select*)(*l)->cont)->hl = 0;
		((t_select*)(*l)->cont)->ul = 0;
	}
}

/*
**	Print the list on the tty.
*/

void		print_list(t_list **l, t_cursor **c, char buffer[6])
{
	int				i;
	t_list			*save;
	int				ls;
	struct winsize	ws;
	int				x;

	i = 0;
	save = *l;
	ls = list_size(l);
	ioctl(g_va.tty, TIOCGWINSZ, &ws);
	if (((t_select*)(*l)->cont)->max_size == 0)
		return ;
	x = ws.ws_col / ((((t_select*)(*l)->cont)->max_size));
	if ((g_va.col = x - 2) == 0)
		return ;
	while (*l)
	{
		((*c)->pos_x == ls) ? ((*c)->pos_x = 0) : 0;
		print_perfect(buffer, c, l, i);
		put_mod(c, l, ls, save);
		(*l) = (*l)->nxt;
		i++;
		(i % (x - 2) == 0 || x <= 0) ? ft_putendl_fd("", g_va.tty) : 0;
	}
	*l = save;
}
