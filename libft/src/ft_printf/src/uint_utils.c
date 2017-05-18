/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:36:52 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/13 13:11:14 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_ui(uintmax_t nb, char *str, int base)
{
	int	c;

	if (nb / base > 0)
		get_ui(nb / base, str, base);
	c = nb % base;
	write(1, &str[c], 1);
}

int		get_ui_len(uintmax_t nb, int base)
{
	int		len;

	len = 0;
	while (nb /= base)
		len++;
	return (len + 1);
}

int		get_ui_flag_len(uintmax_t nb, t_flag *flag, int base)
{
	int		len;

	len = get_ui_len(nb, base);
	if (flag->precision > len)
		len += flag->precision - len;
	if (flag->sharp)
	{
		if (base == 16 && nb > 0)
			len += 2;
		if (base == 8 && nb > 0)
			len++;
	}
	if (flag->prec && !flag->precision && !nb)
		len = (flag->sharp && base == 8) ? 1 : 0;
	return (len);
}

void	put_uint_left_space(t_flag *flag, int len, uintmax_t nb, int type)
{
	if (flag->width && !flag->minus && !flag->zero)
		put_space(flag->width, len);
	if (flag->sharp || type == 4)
	{
		if ((type == 1 && len != 0 && nb > 0) || type == 4)
			ft_putstr("0x");
		if ((type == 2 && len != 0 && nb > 0))
			ft_putstr("0X");
		if (type == 3)
			ft_putstr("0");
	}
	if (flag->zero && flag->width && !flag->minus && !flag->precision)
		put_zero(flag->width, len);
	else if (flag->precision)
	{
		if (type == 1 || type == 2 || type == 4)
			put_zero(flag->precision, get_ui_len(nb, 16));
		if (type == 3)
			put_zero(flag->precision, get_ui_len(nb, 8));
		if (type == 0)
			put_zero(flag->precision, get_ui_len(nb, 10));
		if (type == 5)
			put_zero(flag->precision, get_ui_len(nb, 2));
	}
}
