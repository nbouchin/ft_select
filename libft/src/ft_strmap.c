/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:50:18 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/26 14:57:48 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Applique la fonction f à chaque caractère de la chaine de caractères passée
**	en paramètre pour créer une nouvelle chaine “fraiche” (avec malloc(3))
**	résultant des applications successives de f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		s_len;
	int		i;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	if (!(result = ft_strnew(s_len)))
		return (NULL);
	i = -1;
	while (++i < s_len)
		result[i] = f(s[i]);
	return (result);
}
