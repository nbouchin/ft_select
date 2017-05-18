/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:49:33 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/26 14:55:14 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Applique la fonction f à chaque caractère de la chaine de caractères
**	passée en paramètre. Chaque caractère est passé par adresse à la
**	fonction f afin de pouvoir être modifié si nécéssaire.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	size_t i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
		f(&s[i++]);
}
