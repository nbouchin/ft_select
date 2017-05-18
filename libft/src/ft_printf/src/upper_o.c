/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:37:00 by nbouchin          #+#    #+#             */
/*   Updated: 2017/01/19 15:52:33 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			upper_o(va_list *arg, t_flag *flag)
{
	unsigned long int	nb;
	int					len;

	nb = va_arg(*arg, unsigned long int);
	if (flag->prec)
		flag->zero = 0;
	len = get_ui_flag_len(nb, flag, 8);
	if (flag->sharp && flag->precision > 0)
	{
		flag->precision--;
		len--;
	}
	put_uint_left_space(flag, len, nb, 3);
	if (!(flag->prec && !flag->precision && !nb) &&
			!(flag->sharp && !nb))
		get_ui(nb, "012345678", 8);
	if (flag->width && flag->minus)
		put_space(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
