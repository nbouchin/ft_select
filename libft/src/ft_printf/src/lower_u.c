/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:45:24 by nbouchin          #+#    #+#             */
/*   Updated: 2017/01/19 17:06:04 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		lower_u(va_list *arg, t_flag *flag)
{
	uintmax_t		nb;
	int				len;

	nb = get_utype(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	len = get_ui_flag_len(nb, flag, 10);
	put_uint_left_space(flag, len, nb, 0);
	if (!(flag->prec && !flag->precision && !nb))
		get_ui(nb, "0123456789", 10);
	if (flag->width && flag->minus)
		put_space(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
