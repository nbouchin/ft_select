/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:05:50 by nbouchin          #+#    #+#             */
/*   Updated: 2017/01/19 17:09:10 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		lower_d(va_list *arg, t_flag *flag)
{
	intmax_t		nb;
	int				len;

	nb = get_type(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	len = get_flag_len(nb, flag);
	put_int_left_space(flag, len, nb);
	if (!(flag->prec && flag->precision == 0 && nb == 0))
		get_int(nb);
	if (flag->minus && flag->width)
		put_space(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
