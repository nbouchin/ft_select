/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:48:32 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/26 14:54:19 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Assigne la valeur ’\0’ à tous les caractères de la chaine passée
**	en paramètre.
*/

void	ft_strclr(char *s)
{
	if (s)
		ft_memset((char*)s, 0, ft_strlen(s) + 1);
}
