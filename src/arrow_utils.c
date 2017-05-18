/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:54:38 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/18 17:20:39 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**      right_key utils
*/

void		right_key(t_cursor ***c, int tty, char buffer[6], t_list ***l)
{
	((**c)->pos_x >= list_size(*l)) ? ((**c)->pos_x = 0) : 0;
	ft_putstr_fd(tgetstr("cl", NULL), tty);
	(**c)->pos_x += 1;
	print_list(*l, *c, buffer);
}

/*
**      left_key utils
*/

void		left_key(t_cursor ***c, int tty, char buffer[6], t_list ***l)
{
	((**c)->pos_x == 0) ? ((**c)->pos_x = list_size((*l))) : 0;
	ft_putstr_fd(tgetstr("cl", NULL), tty);
	(**c)->pos_x -= 1;
	print_list(*l, *c, buffer);
}

/*
**      up_key utils
*/

void		up_key(t_cursor ***c, int tty, char buffer[6], t_list ***l)
{
	int		temp;

	temp = (**c)->pos_x;
	ft_putstr_fd(tgetstr("cl", NULL), tty);
	(**c)->pos_x -= g_va.col;
	if (g_va.col == 0 || g_va.col - 1 == 0 || temp == 0)
		perfect_print(temp, c, l);
	else if ((**c)->pos_x < 0)
	{
		(**c)->pos_x = temp + ((list_size(*l) / g_va.col) * g_va.col);
		if ((**c)->pos_x == list_size(*l))
		{
			if ((**c)->pos_x % temp == 0)
				(**c)->pos_x = (**c)->pos_x - g_va.col;
			else if ((**c)->pos_x == list_size(*l))
				(**c)->pos_x = (**c)->pos_x - g_va.col;
			else
				(**c)->pos_x = (list_size(*l) / g_va.col - 1) * g_va.col;
		}
		else if ((**c)->pos_x >= list_size(*l))
			(**c)->pos_x = (list_size(*l) / g_va.col - 1) * g_va.col + temp;
	}
	print_list(*l, *c, buffer);
}

/*
**      down_key utils
*/

void		down_key(t_cursor ***c, int tty, char buffer[6], t_list ***l)
{
	int		temp;

	temp = (**c)->pos_x;
	ft_putstr_fd(tgetstr("cl", NULL), tty);
	temp = (**c)->pos_x;
	(**c)->pos_x += g_va.col;
	if (list_size(*l) == temp + g_va.col)
		if (list_size(*l) % g_va.col != 0)
			(**c)->pos_x = list_size(*l) % g_va.col;
	if (g_va.col == 0)
		return ;
	if ((**c)->pos_x > list_size(*l))
	{
		(**c)->pos_x = temp - ((list_size(*l) / g_va.col) * g_va.col);
		if ((**c)->pos_x < 0)
			(**c)->pos_x = temp
				- ((list_size(*l) / g_va.col) * g_va.col) + g_va.col;
		if ((**c)->pos_x == list_size(*l))
			perfect_down(&c, &l, temp);
	}
	print_list(*l, *c, buffer);
}
