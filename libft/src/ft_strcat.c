/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 08:37:38 by nbouchin          #+#    #+#             */
/*   Updated: 2017/02/06 12:57:34 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char const *s2)
{
	int len;
	int y;

	y = -1;
	len = ft_strlen(s1);
	while (s2[++y])
		s1[len + y] = s2[y];
	s1[len + y] = '\0';
	return (s1);
}
