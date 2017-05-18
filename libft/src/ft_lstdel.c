/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:45:06 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/04 13:31:26 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Prend en paramètre l’adresse d’un pointeur sur un maillon et
**	libère la mémoire de ce maillon et celle de tous ses successeurs l’un après
**	l’autre avec del et free(3). Pour terminer, le pointeur sur le premier
**	maillon maintenant libéré doit être mis à NULL (de manière similaire à la
**	fonction ft_memdel de la partie obligatoire).
*/

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*new_list;

	tmp = *alst;
	while (tmp)
	{
		new_list = tmp->nxt;
		del(tmp->cont, tmp->cont_size);
		free(tmp);
		tmp = new_list;
	}
	*alst = NULL;
}
