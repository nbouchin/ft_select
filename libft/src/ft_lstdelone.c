/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:32:59 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/02 14:40:50 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Prend en paramètre l’adresse d’un pointeur sur un maillon et libère la
**	mémoire du contenu de ce maillon avec la fonction del passée en paramètre
**	puis libère la mémoire du maillon en lui même avec free(3) . La mémoire du
**	champ next ne doit en aucun cas être libérée. Pour terminer, le pointeur sur
**	le maillon maintenant libéré doit être mis à NULL (de manière similaire à
**	la fonction ft_memdel de la partie obligatoire).
*/

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	del((*alst)->cont, (*alst)->cont_size);
	free(*alst);
	*alst = NULL;
}
