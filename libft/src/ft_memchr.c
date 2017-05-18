/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:38:12 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/09 15:27:23 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	int				i;

	i = 0;
	ch = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (str[i] == ch)
			return (str + i);
		i++;
	}
	return (NULL);
}
