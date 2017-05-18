/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:50:06 by nbouchin          #+#    #+#             */
/*   Updated: 2017/01/19 17:07:36 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		upper_x(va_list *arg, t_flag *flag)
{
	uintmax_t	hex;
	int			len;

	hex = get_utype(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	len = get_ui_flag_len(hex, flag, 16);
	put_uint_left_space(flag, len, hex, 2);
	if (!(flag->prec && !flag->precision && !hex))
		get_ui(hex, "0123456789ABCDEF", 16);
	if (flag->width && flag->minus)
		put_space(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
