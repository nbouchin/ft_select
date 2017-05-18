/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:49:54 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/13 10:59:59 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putwchar(wchar_t c)
{
	if (c <= 0x7F)
		ft_putchar(c);
	else if (c <= 0x7FF)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else
	{
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0x3F) + 0x80);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
}

int			wchar_len(wchar_t c)
{
	int		len;

	len = 0;
	if (c <= 0x7F)
		len = 1;
	else if (c <= 0x7FF)
		len = 2;
	else if (c <= 0xFFFF)
		len = 3;
	else
		len = 4;
	return (len);
}

void		ft_putnwstr(wchar_t *s, int n)
{
	int		i;

	i = 0;
	while (s[i] != '\0' & n > 0)
	{
		if (wchar_len(s[i]) > n)
			break ;
		n -= wchar_len(s[i]);
		ft_putwchar(s[i++]);
	}
}

int			wstr_nlen(wchar_t *s, int n)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[i] != '\0' && n > 0)
	{
		if (wchar_len(s[i]) > n)
			break ;
		n -= wchar_len(s[i]);
		len += wchar_len(s[i++]);
	}
	return (len);
}

int			wstr_len(wchar_t *s)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		len += wchar_len(s[i++]);
	return (len);
}
