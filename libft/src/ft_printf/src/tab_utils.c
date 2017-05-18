/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:24:47 by nbouchin          #+#    #+#             */
/*   Updated: 2017/01/19 16:51:35 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	put_space(int width, int len)
{
	int	n;

	n = width - len;
	while (n-- > 0)
		ft_putchar(' ');
}

void	put_zero(int width, int len)
{
	int	n;

	n = width - len;
	while (n-- > 0)
		ft_putchar('0');
}
