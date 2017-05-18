/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 10:20:54 by nbouchin          #+#    #+#             */
/*   Updated: 2017/01/25 10:11:24 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int len;

	len = ((int)ft_strlen(s) + 1);
	while (--len >= 0)
		if (s[len] == (char)c)
			return ((char *)&s[len]);
	return (NULL);
}
