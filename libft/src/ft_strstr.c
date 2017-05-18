/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:37:20 by nbouchin          #+#    #+#             */
/*   Updated: 2017/02/06 12:56:52 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (big == little || !*little)
		return ((char *)big);
	while (big[i] != '\0')
	{
		if (big[i] == little[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i + 1 - j;
			j = 0;
		}
		if (little[j] == '\0')
			return (((char *)big + i - j));
	}
	return (0);
}
