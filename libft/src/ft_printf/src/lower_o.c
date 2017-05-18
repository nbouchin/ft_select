/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:40:32 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/13 13:10:15 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		lower_o(va_list *arg, t_flag *flag)
{
	uintmax_t		nb;
	int				len;

	nb = get_utype(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	len = get_ui_flag_len(nb, flag, 8);
	if (flag->sharp && flag->precision > 0)
	{
		flag->precision--;
		len--;
	}
	put_uint_left_space(flag, len, nb, 3);
	if (!(flag->prec && !flag->precision && !nb)
			&& !(flag->sharp && !nb))
		get_ui(nb, "012345678", 8);
	if (flag->width && flag->minus)
		put_space(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
