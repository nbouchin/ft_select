/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:29:51 by nbouchin          #+#    #+#             */
/*   Updated: 2017/01/19 18:27:51 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		upper_s(va_list *arg, t_flag *flag)
{
	wchar_t		*str;
	int			len;
	int			isnull;

	isnull = 0;
	str = va_arg(*arg, wchar_t*);
	len = (flag->precision) ? wstr_nlen(str, flag->precision) : wstr_len(str);
	if (str == NULL)
	{
		isnull = 1;
		len = (flag->precision) ? ft_strnlen("(null)", flag->precision) : 6;
	}
	if (flag->prec && flag->precision == 0)
		len = 0;
	if (flag->width && !flag->minus && !flag->zero)
		put_space(flag->width, len);
	if (flag->width && flag->zero && !flag->minus)
		put_zero(flag->width, len);
	if (!(flag->prec && flag->precision == 0) && isnull == 0)
		ft_putnwstr(str, len);
	else if (isnull == 1)
		ft_putnstr("(null)", len);
	if (flag->minus && flag->width)
		put_space(flag->width, len);
	return ((flag->width) > len ? flag->width : len);
}
