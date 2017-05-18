/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:42:48 by nbouchin          #+#    #+#             */
/*   Updated: 2017/02/16 16:45:08 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		lower_s(va_list *arg, t_flag *flag)
{
	char	*str;
	int		len;
	int		isnull;

	isnull = 0;
	if (flag->e_length == l)
		return (upper_s(arg, flag));
	str = va_arg(*arg, char *);
	len = (flag->precision) ? ft_strnlen(str, flag->precision) : ft_strlen(str);
	if (str == NULL)
	{
		isnull = 1;
		len = (flag->precision) ? ft_strnlen("(null)", flag->precision) : 6;
	}
	if (flag->prec && flag->precision == 0)
		len = 0;
	put_str_left_space(flag, len);
	if (!(flag->prec && !flag->precision) && !isnull)
		ft_putnstr(str, len);
	else if (isnull)
		ft_putnstr("(null)", len);
	if (flag->minus && flag->width)
		put_space(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
