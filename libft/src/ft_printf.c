/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:33:41 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/16 09:31:21 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/includes/libftprintf.h"

void	reset_flag(t_flag *flag)
{
	flag->precision = 0;
	flag->prec = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->sharp = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->e_length = 0;
}

int		get_specifier(char **format, t_flag *flag, va_list *arg)
{
	static int	(*f[])(va_list*, t_flag*) = {lower_s, upper_s,
			lower_p, lower_d, upper_d, lower_i, lower_o, upper_o,
			lower_u, upper_u, lower_x, upper_x, lower_c, upper_c,
			modulo, 0};
	static char	spec[] = {'s', 'S', 'p', 'd', 'D', 'i', 'o', 'O', 'u', 'U',
	'x', 'X', 'c', 'C', '%', 0};
	int			i;
	int			ret;

	i = 0;
	while (spec[i] != **format && spec[i])
		i++;
	if (**format != '\0' && spec[i] == **format)
	{
		ret = f[i](arg, flag);
		(*format)++;
		return (ret);
	}
	if (**format != '\0')
	{
		(*format)++;
		return (undefined(*(*format - 1), flag));
	}
	return (0);
}

int		parser(char **format, t_flag *flag, va_list *arg)
{
	int		ret;

	ret = 0;
	while (**format)
	{
		if (**format == '%')
		{
			reset_flag(flag);
			(*format)++;
			get_option(format, flag, arg);
			ret += get_specifier(format, flag, arg);
		}
		else if (**format != '\0')
		{
			ft_putchar(**format);
			(*format)++;
			ret++;
		}
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	t_flag		*flag;
	int			ret;

	ret = 0;
	flag = ft_memalloc(sizeof(t_flag));
	va_start(arg, format);
	ret = parser((char**)&format, flag, &arg);
	va_end(arg);
	ft_memdel((void**)&flag);
	return (ret);
}
