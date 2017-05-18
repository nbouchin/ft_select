/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:46:12 by nbouchin          #+#    #+#             */
/*   Updated: 2017/02/02 15:11:44 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		length;
	int		i;
	char	swap;

	length = ft_strlen(s) - 1;
	i = 0;
	while (i < length)
	{
		swap = s[i];
		s[i] = s[length];
		s[length] = swap;
		i++;
		length--;
	}
	return (s);
}
