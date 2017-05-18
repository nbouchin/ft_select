/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:50:48 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/26 15:01:06 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Compare lexicographiquement s1 et s2 jusqu’à n caractères maximum ou bien
**	qu’un ’\0’ ait été rencontré. Si les deux chaines sont égales, la fonction
**	retourne 1, ou 0 sinon.
*/

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while ((*s1 || *s2) && n--)
		if (*s1++ != *s2++)
			return (0);
	return (1);
}
