/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:45:28 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/08 09:36:23 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Alloue (avec malloc(3)) et retourne une zone de mémoire
**	“fraiche”. La mémoire allouée est initialisée à 0.
**	Si l’allocation échoue, la fonction renvoie NULL.
*/

void	*ft_memalloc(size_t size)
{
	void *result;

	result = malloc(size);
	if (!result)
		return (NULL);
	ft_memset(result, 0, size);
	return (result);
}
