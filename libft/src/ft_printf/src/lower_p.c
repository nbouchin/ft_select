/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:36:09 by nbouchin          #+#    #+#             */
/*   Updated: 2017/01/18 15:40:08 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		lower_p(va_list *arg, t_flag *flag)
{
	void		*ptr;
	uintmax_t	nb;
	int			len;

	ptr = va_arg(*arg, void*);
	nb = (unsigned long)ptr;
	len = get_ui_flag_len(nb, flag, 16);
	if (!flag->sharp)
		len += 2;
	put_uint_left_space(flag, len, nb, 4);
	if (!(flag->prec && !flag->precision && !nb))
		get_ui(nb, "0123456789abcdef", 16);
	if (flag->minus && flag->width)
		put_space(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
