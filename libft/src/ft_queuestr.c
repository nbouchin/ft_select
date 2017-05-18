/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuestr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:34:26 by nbouchin          #+#    #+#             */
/*   Updated: 2017/04/06 15:58:18 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*g_buf = NULL;

void		putbuf(void)
{
	ft_putstr(g_buf);
	ft_strclr(g_buf);
}

void		ft_qstr(char *str)
{
	int		len;
	int		i;

	i = 0;
	if (!g_buf)
		g_buf = ft_strnew(BUFF_SIZE);
	len = ft_strlen(g_buf);
	while (str[i])
	{
		if (len == BUFF_SIZE)
		{
			putbuf();
			len = 0;
		}
		g_buf[len++] = str[i++];
	}
}

void		ft_queuenstr(char *str, int n)
{
	int		len;
	int		i;

	i = 0;
	if (!g_buf)
		g_buf = ft_strnew(BUFF_SIZE);
	len = ft_strlen(g_buf);
	while (str[i] && n--)
	{
		if (len == BUFF_SIZE)
		{
			putbuf();
			len = 0;
		}
		g_buf[len++] = str[i++];
	}
}

void		ft_qchar(char c)
{
	int		len;

	if (!g_buf)
		g_buf = ft_strnew(BUFF_SIZE);
	len = ft_strlen(g_buf);
	if (len == BUFF_SIZE)
	{
		putbuf();
		len = 0;
	}
	g_buf[len] = c;
}

void		ft_qnbr(intmax_t nb)
{
	uintmax_t	n;

	if (nb < 0)
	{
		n = -nb;
		ft_qchar('-');
	}
	else
		n = nb;
	if (nb / 10 > 0)
		ft_qnbr(n / 10);
	ft_qchar((n % 10) + '0');
}
