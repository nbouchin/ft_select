/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:48:48 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/18 17:22:42 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	free_node
*/

void	free_node(t_list *n)
{
	ft_putstr_fd(tgetstr("cl", NULL), g_va.tty);
	reset_termios();
	close(g_va.tty);
	free(n);
	exit(0);
}

/*
**	Remove node from list and free it
*/

void	delete_node(t_list *head, t_list *n)
{
	t_list	*prev;

	if (head == n)
	{
		if (head->nxt == NULL)
			free_node(n);
		head->cont = head->nxt->cont;
		n = head->nxt;
		head->nxt = head->nxt->nxt;
		free(n);
		return ;
	}
	prev = head;
	while (prev->nxt != NULL && prev->nxt != n)
		prev = prev->nxt;
	if (prev->nxt == NULL)
		return ;
	prev->nxt = prev->nxt->nxt;
	free(n);
	return ;
}

/*
**	Remove the actual node
*/

void	del_node(t_list ***l, t_cursor ***c, char buffer[6])
{
	t_list	*save;
	int		i;

	i = 0;
	save = (**l);
	while (**l)
	{
		if (((t_select*)(**l)->cont)->index == (**c)->pos_x)
		{
			free(((t_select*)(**l)->cont)->argn);
			free((**l)->cont);
			delete_node(save, **l);
			break ;
		}
		(**l) = (**l)->nxt;
	}
	(**l) = save;
	while (**l)
	{
		((t_select*)(**l)->cont)->index = i++;
		(**l) = (**l)->nxt;
	}
	(**l) = save;
	ft_putstr_fd(tgetstr("cl", NULL), g_va.tty);
	print_list(*l, *c, buffer);
}
