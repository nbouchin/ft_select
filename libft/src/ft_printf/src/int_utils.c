/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:09:42 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/13 13:16:51 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_int(intmax_t nb)
{
	int			c;
	uintmax_t	n;

	if (nb < 0)
		n = -nb;
	else
		n = nb;
	if (n / 10 > 0)
		get_int(n / 10);
	c = n % 10 + 48;
	write(1, &c, 1);
}

int		get_flag_len(intmax_t nb, t_flag *flag)
{
	int		len;

	len = get_len(nb);
	if (flag->precision > len)
		len += flag->precision - len;
	if (flag->plus && nb >= 0)
		len++;
	if (flag->space && !flag->plus && nb >= 0)
		len++;
	if (nb < 0)
		len++;
	if (flag->prec && !flag->precision && !nb)
		len = flag->space ? 1 : 0;
	return (len);
}

int		get_len(intmax_t nb)
{
	int			len;
	uintmax_t	n;

	len = 0;
	if (nb < 0)
		n = -nb;
	else
		n = nb;
	while (n /= 10)
		len++;
	return (len + 1);
}

void	put_int_left_space(t_flag *flag, int len, intmax_t nb)
{
	if (flag->space && !flag->plus && nb >= 0)
		ft_putchar(' ');
	if (flag->width && !flag->minus && !flag->zero)
		put_space(flag->width, len);
	if (flag->plus && nb >= 0 && len != 0)
		ft_putchar('+');
	if (nb < 0 && len != 0)
		ft_putchar('-');
	if (flag->zero && flag->width && !flag->minus && !flag->precision)
		put_zero(flag->width, len);
	else if (flag->precision)
		put_zero(flag->precision, get_len(nb));
}
