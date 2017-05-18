/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefined.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:04:18 by nbouchin          #+#    #+#             */
/*   Updated: 2017/01/19 15:54:36 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		undefined(char c, t_flag *flag)
{
	int		len;

	len = 1;
	if (flag->width && !flag->zero && !flag->minus)
		put_space(flag->width, len);
	if (flag->width && flag->zero && !flag->minus)
		put_zero(flag->width, len);
	ft_putchar(c);
	if (flag->width && flag->minus)
		put_space(flag->width, len);
	return (flag->width > len ? flag->width : len);
}
