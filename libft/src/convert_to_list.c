/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:14:26 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/18 16:44:46 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				convert_to_list(t_list **l, char **argv)
{
	int				i;
	t_select		*s;

	i = 1;
	s = (t_select*)ft_memalloc(sizeof(t_select));
	while (argv[i])
	{
		s->arg_name = ft_strdup(argv[i++]);
		ft_lstaddend(l, ft_lstnew(s, sizeof(t_select)));
	}
	(s) ? free(s) : 0;
}
