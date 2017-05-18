/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:31:17 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/10 14:46:52 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (big == little)
		return ((char *)big);
	while (i != len && big[i] != '\0')
	{
		if (big[i] == little[j])
		{
			i++;
			j++;
		}
		else if (little[j] == '\0')
			return (char *)(&(*(big + i - j)));
		else
		{
			i = i + 1 - j;
			j = 0;
		}
		if (little[j] == '\0')
			return (char *)(&(*(big + i - j)));
	}
	return (0);
}
