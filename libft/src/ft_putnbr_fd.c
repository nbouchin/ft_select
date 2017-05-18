/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:47:32 by nbouchin          #+#    #+#             */
/*   Updated: 2017/05/02 17:26:36 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Ecrit l’entier n sur le descripteur de fichier fd.
*/

void	ft_putnbr_fd(intmax_t nb, int fd)
{
	int			c;
	uintmax_t	n;

	if (nb < 0)
		n = -nb;
	else
		n = nb;
	if (n / 10 > 0)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + 48;
	write(fd, &c, 1);
}
