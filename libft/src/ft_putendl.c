/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:46:32 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/13 16:29:59 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Affiche la chaine s sur la sortie standard suivi d’un ’\n’.
*/

void	ft_putendl(char const *s)
{
	ft_putstr_fd(s, 1);
	ft_putchar_fd('\n', 1);
}
