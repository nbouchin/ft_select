/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:44:34 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/02 14:42:12 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Parcourt la liste lst en appliquant à chaque maillon la fonction f et crée
**	une nouvelle liste “fraiche” avec malloc(3) résultant des applications
**	successives. Si une allocation échoue, la fonction renvoie NULL.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;

	if (lst)
	{
		new_list = f(lst);
		new_list->nxt = ft_lstmap(lst->nxt, f);
		return (new_list);
	}
	return (NULL);
}
