/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 14:49:19 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/18 17:26:11 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	set ul
*/

void		set_ul(int i, t_list ****l)
{
	t_list *save;

	save = (***l);
	while (***l)
	{
		(((t_select*)(***l)->cont)->index == i)
			? (((t_select*)(***l)->cont)->ul = 1) : 0;
		(***l) = (***l)->nxt;
	}
	(***l) = save;
}

/*
**	space_key utils
*/

void		space_key(t_cursor ***c, int tty, char buffer[6], t_list ***l)
{
	ft_putstr_fd(tgetstr("cl", NULL), tty);
	print_list(*l, *c, buffer);
	(**c)->pos_x += 1;
}

/*
**	Clear the buffer tab
*/

void		clear_tab(char buffer[6])
{
	int		i;

	i = 0;
	while (buffer[i])
		buffer[i++] = '\0';
}

/*
**	arrow_gesture
*/

void		arrow_gesture(t_cursor ***c, t_list ***l, int tty)
{
	(g_va.buffer[2] == 'A')
		? up_key(c, tty, g_va.buffer, l) : 0;
	(g_va.buffer[2] == 'B')
		? down_key(c, tty, g_va.buffer, l) : 0;
	(g_va.buffer[2] == 'D')
		? left_key(c, tty, g_va.buffer, l) : 0;
	(g_va.buffer[2] == 'C')
		? right_key(c, tty, g_va.buffer, l) : 0;
}

/*
**	Catch key strokes and react depending of them
*/

int			catch_key(t_list **l, t_cursor **c, int tty)
{
	while (1)
	{
		signal_gesture();
		read(0, g_va.buffer, 6);
		if (g_va.buffer[0] == 27)
		{
			(g_va.buffer[1] == 0)
				? ft_putstr_fd(tgetstr("cl", NULL), tty) : 0;
			if (g_va.buffer[1] == 0)
				return (0);
			arrow_gesture(&c, &l, tty);
		}
		if (g_va.buffer[0] == 4)
			return (0);
		(g_va.buffer[0] == 127 ||
		(g_va.buffer[0] == 27 &&
		g_va.buffer[1] == 91 && g_va.buffer[2] == 51))
			? del_node(&l, &c, g_va.buffer) : 0;
		(g_va.buffer[0] == 32)
			? space_key(&c, tty, g_va.buffer, &l) : 0;
		(g_va.buffer[0] == 10 &&
		g_va.buffer[1] == 0) ?
			print_select(&l, &c, tty, g_va.buffer) : 0;
	}
	return (0);
}
