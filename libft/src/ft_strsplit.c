/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 08:56:04 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/29 14:05:57 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Alloue (avec malloc(3)) et retourne un tableau de chaines de caractères
**	“fraiches” (toutes terminées par un ’\0’, le tableau également donc)
**	résultant de la découpe de s selon le caractère c. Si l’allocation echoue,
**	la fonction retourne NULL. Exemple :
**	ft_strsplit("*salut*les***etudiants*", ’*’) renvoie le tableau
**	["salut", "les", "etudiants"].
*/

static int		is_split(char current, char c)
{
	return (current == c || current == '\0');
}

static int		count_words(char const *str, char c)
{
	int result;
	int i;
	int temp;

	temp = 0;
	i = 0;
	result = 0;
	while (str[i])
	{
		if (!is_split(str[i], c) && !temp)
		{
			temp = 1;
			result++;
		}
		else if (is_split(str[i], c))
			temp = 0;
		i++;
	}
	return (result + 1);
}

static int		length(char const *str, int i, char c)
{
	int y;

	y = 0;
	while (!is_split(str[y + i], c))
		y++;
	return (y);
}

static char		**free_result(char **res)
{
	ft_strdel(res);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		i;
	int		y;
	int		word;

	if (!s || !(result = (char**)malloc(sizeof(char *) * (count_words(s, c)))))
		return (NULL);
	i = 0;
	word = 0;
	while (s[i])
	{
		if (is_split(s[i], c))
		{
			i++;
			continue;
		}
		y = 0;
		if (!(result[word] = (char*)malloc(sizeof(char) * (length(s, i, c)))))
			return (free_result(result));
		while (!is_split(s[i], c))
			result[word][y++] = s[i++];
		result[word++][y] = '\0';
	}
	result[word] = 0;
	return (result);
}
