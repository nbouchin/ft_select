/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:51:51 by nbouchin          #+#    #+#             */
/*   Updated: 2017/01/30 10:25:41 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Alloue (avec malloc(3)) et retourne la copie “fraiche” d’un
**	tronçon de la chaine de caractères passée en paramètre. Le
**	tronçon commence à l’index start et à pour longueur len.
**	Si start et len ne désignent pas un tronçon de chaine valide,
**	le comportement est indéterminé. Si l’allocation échoue, la
**	fonction renvoie NULL.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s || start > ft_strlen(s))
		return (NULL);
	if (!(result = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
		result[i++] = *(s++ + start);
	return (result);
}
