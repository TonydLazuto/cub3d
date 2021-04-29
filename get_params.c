/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:37:17 by tonyd             #+#    #+#             */
/*   Updated: 2021/04/29 16:37:18 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_resolution(char *line, size_t *j, t_cub *cub)
{
	char			*resolution;
	unsigned int	start;

	resolution = NULL;
	*j = skip_space(line, *j);
	start = (unsigned int)*j;
	while (line[*j] && ft_isdigit(line[*j]))
		(*j)++;
	resolution = ft_substr(line, start, (*j) - start);
	if (!resolution)
		ft_error(cub , "Malloc resolution.");
	*j = skip_space(line, *j);
	if (line[*j] != '\0' && cub->width != 0)
	{
		ft_free(&resolution);
		ft_error(cub , "Resolution in .cub file.");
	}
	return (resolution);
}

char	*get_rgb(char *line, size_t *j, int nb, t_cub *cub)
{
	char			*rgb;
	unsigned int	start;

	rgb = NULL;
	*j = skip_space(line, *j);
	start = (unsigned int)*j;
	while (line[*j] && ft_isdigit(line[*j]))
		(*j)++;
	rgb = ft_substr(line, start, (*j) - start);
	if (!rgb)
		ft_error(cub , "Malloc rgb.");
	*j = skip_space(line, *j);
	if ((nb == 2 && line[*j] != '\0') || (nb < 2 && line[*j] != ','))
	{
		ft_free(&rgb);
		ft_error(cub , "Color Floor or/and Ceiling in .cub file.");
	}
	if (line[*j] == ',' && nb < 2)
		(*j)++;
	return (rgb);
}

char	*get_path(char *line, t_cub *cub, char *path)
{
	unsigned int	start;
	size_t			j;

	j = line[1] == ' ' ? 2 : 3;
	j = skip_space(line, j);
	start = (unsigned int)j;
	while (line[j] && line[j] != ' ')
		j++;
	path = ft_substr(line, start, j - start);
	if (!path)
		ft_error(cub , "Malloc path.");
	j = skip_space(line, j);
	if (line[j])
		ft_error(cub , "Incorrect Path Texture.");
	return (path);
}
