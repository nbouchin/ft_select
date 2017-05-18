/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:11:33 by nbouchin          #+#    #+#             */
/*   Updated: 2017/02/16 16:47:16 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		get_option(char **str, t_flag *flag, va_list *arg)
{
	if (**str != '0' && ft_isdigit(**str))
		get_width(str, flag, arg);
	if (**str == '.')
		get_precision(str, flag, arg);
	if (**str == 'h' || **str == 'l' || **str == 'j' || **str == 'z')
		get_length(str, flag, arg);
	if (**str == '#' || **str == '0' || **str == '-' || **str == '+'
			|| **str == ' ')
		get_flag(str, flag, arg);
}

void		get_flag(char **str, t_flag *flag, va_list *arg)
{
	while (**str == '#' || **str == '0' || **str == '-' || **str == '+'
			|| **str == ' ')
	{
		if (**str == '#')
			flag->sharp = 1;
		if (**str == '0')
			flag->zero = 1;
		if (**str == '-')
			flag->minus = 1;
		if (**str == '+')
			flag->plus = 1;
		if (**str == ' ')
			flag->space = 1;
		(*str)++;
	}
	get_option(str, flag, arg);
}

void		get_width(char **str, t_flag *flag, va_list *arg)
{
	int		width;

	width = 0;
	flag->width = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	get_option(str, flag, arg);
}

void		get_precision(char **str, t_flag *flag, va_list *arg)
{
	int		precision;

	precision = 0;
	while (**str == '.')
	{
		flag->prec = 1;
		(*str)++;
		flag->precision = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	get_option(str, flag, arg);
}

void		get_length(char **str, t_flag *flag, va_list *arg)
{
	if (**str == 'h')
	{
		if (*(*str + 1) == 'h' && flag->e_length < 3)
			flag->e_length = hh;
		else if (flag->e_length < 2)
			flag->e_length = h;
	}
	if (**str == 'l')
	{
		if (*(*str + 1) == 'l' && flag->e_length < 5)
			flag->e_length = ll;
		else if (flag->e_length < 4)
			flag->e_length = l;
	}
	if (**str == 'j' && flag->e_length < 6)
		flag->e_length = j;
	if (**str == 'z')
		flag->e_length = z;
	if (flag->e_length)
		(*str)++;
	if (flag->e_length == hh || flag->e_length == ll)
		(*str)++;
	get_option(str, flag, arg);
}
