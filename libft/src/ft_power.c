/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:51:16 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/19 12:02:47 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_power(double n, int pow)
{
	double	res;

	res = 1;
	if (pow >= 0)
		while (pow--)
			res *= n;
	else
		while (pow++)
			res *= (1 / n);
	return (res);
}
