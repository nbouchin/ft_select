/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:30:32 by nbouchin          #+#    #+#             */
/*   Updated: 2017/01/19 16:49:55 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnstr(char *str, int n)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (n-- > 0 && str[i] != '\0')
		ft_putchar(str[i++]);
}

int		ft_strnlen(char *str, int n)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while ((n-- > 0) && (str[i] != '\0'))
		i++;
	return (i);
}

void	put_str_left_space(t_flag *flag, int len)
{
	if (flag->width && !flag->minus && !flag->zero)
		put_space(flag->width, len);
	if (flag->width && flag->zero && !flag->minus)
		put_zero(flag->width, len);
}
