/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:33:42 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/18 16:43:47 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	Return the list size
*/

int				list_size(t_list **l)
{
	int			i;
	t_list		*save;

	i = 0;
	save = (*l);
	while (*l)
	{
		(*l) = (*l)->nxt;
		i++;
	}
	(*l) = save;
	return (i);
}

/*
**	Set max_size
*/

void			set_maxsize(t_list ***l, int max_size)
{
	t_list *save;

	save = (**l);
	while (**l)
	{
		((t_select*)(**l)->cont)->max_size = max_size;
		(**l) = (**l)->nxt;
	}
	(**l) = save;
}

/*
**	Init all linked list cont data.
*/

void			init_list(t_list **l)
{
	int			i;
	t_list		*save;
	int			max_size;

	i = 0;
	save = (*l);
	max_size = 0;
	while (*l)
	{
		((t_select*)(*l)->cont)->nsize =
			ft_strlen(((t_select*)(*l)->cont)->argn);
		((t_select*)(*l)->cont)->index = i++;
		((t_select*)(*l)->cont)->hl = 0;
		((t_select*)(*l)->cont)->ul = 0;
		(max_size < ((t_select*)(*l)->cont)->nsize)
			? max_size = ((t_select*)(*l)->cont)->nsize : 0;
		(*l) = (*l)->nxt;
	}
	(*l) = save;
	set_maxsize(&l, max_size);
}

/*
**	Convert a pointer to char adress to a linked list.
*/

void			convert_to_list(t_list **l, char **argv)
{
	int			i;
	t_select	*s;

	i = 1;
	s = (t_select*)ft_memalloc(sizeof(t_select));
	while (argv[i])
	{
		s->argn = ft_strdup(argv[i++]);
		ft_lstaddend(l, ft_lstnew(s, sizeof(t_select)));
	}
	(s) ? free(s) : 0;
}
