/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:39:42 by tonyd             #+#    #+#             */
/*   Updated: 2021/04/29 16:39:44 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		skip_space(char *line, unsigned int i)
{
	while (line[i] && line[i] == ' ')
		i++;
	return (i);
}

char	*strjoinfree(char *s1, char *s2, t_cub *cub)
{
	char	*str;

	str = NULL;
	if (!s2 && !s1)
		ft_error(cub, "Le fichier est vide");
	if (!s2)
		return (NULL);
	if (!s1)
	{
		if (!(str = ft_strdup(s2)))
			return (NULL);
		return (str);
	}
	if (!(str = (char*)malloc(my_strlen(s1) + my_strlen(s2) + 1)))
	{
		ft_free(&s1);
		return (NULL);
	}
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(str) + ft_strlen(s2) + 1);
	ft_free(&s1);
	return (str);
}

int		is_in_charset(char c, char const *set)
{
	while (*set && *set != c)
		set++;
	if (!*set)
		return (0);
	return (1);
}
