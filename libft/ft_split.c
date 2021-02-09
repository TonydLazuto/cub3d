/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderose <aderose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:25:09 by aderose           #+#    #+#             */
/*   Updated: 2020/05/15 21:30:40 by aderose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	strsplit_len(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		if (i > 0)
			words++;
		while (s[i] == c && s[i])
			i++;
	}
	return (words);
}

static char		**fillstrsplit(char **str, char const *s, char c, size_t words)
{
	size_t			i;
	size_t			j;
	unsigned int	start;
	size_t			len;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] == c && s[j])
			j++;
		start = (unsigned int)j;
		while (s[j] != c && s[j])
			j++;
		len = j - start;
		str[i] = ft_substr(s, start, len);
		i++;
	}
	str[i] = NULL;
	return (str);
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	size_t	words;

	if (!s)
		return (NULL);
	words = strsplit_len(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	fillstrsplit(str, s, c, words);
	return (str);
}
