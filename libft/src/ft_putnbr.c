/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:47:16 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/13 13:14:43 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Affiche l’entier n sur la sortie standard.
*/

void	ft_putnbr(intmax_t n)
{
	ft_putnbr_fd(n, 1);
}
