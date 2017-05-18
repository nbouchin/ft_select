/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:49:43 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/26 14:56:39 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Applique la fonction f à chaque caractère de la chaine de caractères passée
**	en paramètre en précisant son index en premier argument. Chaque caractère
**	est passé par adresse à la fonction f afin de pouvoir être modifié
**	si nécéssaire.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t i;

	if (!s || !f)
		return ;
	i = -1;
	while (s[++i])
		f(i, &s[i]);
}
