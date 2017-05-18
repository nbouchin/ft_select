/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:52:02 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/16 09:30:31 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Alloue (avec malloc(3)) et retourne une copie de la chaine
**	passée en paramètre sans les espaces blancs au debut et à la fin de cette
**	chaine. On considère comme espaces blancs les caractères ’ ’, ’\n’ et ’\t’.
**	Si s ne contient pas d’espacesblancs au début ou à la fin, la fonction
**	renvoie une copie de s. Si l’allocation echoue, la fonction renvoie NULL.
*/

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	unsigned int	west;
	unsigned int	east;

	if (!s)
		return ("");
	east = ft_strlen(s) - 1;
	west = 0;
	while (ft_is_space(s[west]))
		west++;
	if (!s[west])
		return (ft_strnew(1));
	while (ft_is_space(s[east]))
		east--;
	east = (ft_strlen(s) - 1) - east;
	return (ft_strsub(s, west, (size_t)(ft_strlen(s) - (west + east))));
}
