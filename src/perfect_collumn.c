/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_collumn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:57:27 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/18 17:19:12 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**      perfect_print
*/

void	perfect_print(int temp, t_cursor ***c, t_list ***l)
{
	if (g_va.col == 1)
	{
		if (temp == 0)
			(**c)->pos_x = list_size(*l) - 1;
	}
	else if (list_size(*l) % g_va.col == 0)
		(**c)->pos_x = g_va.col * ((list_size(*l) / g_va.col) - 1);
	else
		(**c)->pos_x = temp + ((list_size(*l) / g_va.col) * g_va.col);
}

/*
**      if perfect_down
*/

void	perfect_down(t_cursor ****c, t_list ****l, int temp)
{
	if ((***c)->pos_x % g_va.col == 0)
		(***c)->pos_x = 0;
	else if ((***c)->pos_x == list_size(**l))
		(***c)->pos_x = temp - g_va.col;
	else
		(***c)->pos_x = temp;
}

/*
**	React like ft_putchar but return an int.
*/

int		ft_tputchar(int c)
{
	write(1, &c, 1);
	return (c);
}
