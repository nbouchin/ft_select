/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:16:49 by nbouchin          #+#    #+#             */
/*   Updated: 2017/02/20 13:42:34 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	function(char **sb, char *buff, char **line)
{
	*line = ft_strdup(buff);
	if (*line[0] != '\0')
	{
		*sb = NULL;
		ft_strdel(&buff);
		return (1);
	}
	else
	{
		*sb = NULL;
		ft_strdel(&buff);
		return (0);
	}
}

int			get_next_line(const int fd, char **line)
{
	char			*buff;
	char static		*sb;
	int				i;

	i = 0;
	if (!line || fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	if (sb)
		buff = ft_strdup(sb);
	else
		buff = ft_strnew(0);
	buff = ft_realloc(buff, BUFF_SIZE);
	while (!ft_strchr(buff, '\n'))
	{
		if (read(fd, buff + ft_strlen(buff), BUFF_SIZE) <= 0)
			break ;
		buff = ft_realloc(buff, BUFF_SIZE);
	}
	i = ft_strchr(buff, '\n') ? ft_strchr(buff, '\n') - buff : -1;
	if (i < 0)
		return (function(&sb, buff, line));
	*line = ft_strsub(buff, 0, i);
	sb = ft_strsub(buff, i + 1, ft_strlen(buff) + i);
	ft_strdel(&buff);
	return (1);
}
