/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:42:18 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/02 14:40:21 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Alloue (avec malloc(3)) et retourne un maillon “frais”. Les champs content
**	et content_size du nouveau maillon sont initialisés par copie des paramètres
**	de la fonction. Si le paramètre content est nul, le champs content est
**	initialisé à NULL et le champs content_size est initialisé à 0 quelque
**	soit la valeur du paramètre content_size. Le champ next est initialisé à
**	NULL. Si l’allocation échoue, la fonction renvoie NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new_elem;
	void		*l_content;

	if (!(new_elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		l_content = NULL;
		content_size = 0;
	}
	else
	{
		if (!(l_content = malloc(content_size)))
		{
			free(new_elem);
			return (NULL);
		}
		ft_memcpy(l_content, content, content_size);
	}
	new_elem->cont = (void *)l_content;
	new_elem->cont_size = content_size;
	new_elem->nxt = NULL;
	return (new_elem);
}
