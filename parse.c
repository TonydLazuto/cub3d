/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:37:45 by tonyd             #+#    #+#             */
/*   Updated: 2021/04/29 16:37:47 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		fill_params(char **file_lines, t_cub *cub, size_t len_params)
{
	size_t	i;

	i = 0;
	while (i < len_params)
	{
		file_lines[i] = trim_line(file_lines[i]);
		if (!file_lines[i])
			return (-1);
		if (file_lines[i][0] != '\0')
			parse_param(file_lines[i], cub);
		i++;
	}
	return (0);
}

static int		fill_map(char **file_lines, t_cub *cub, size_t len_params)
{
	size_t	len_map;
	size_t	i;

	i = 0;
	len_map = len_params;
	while (file_lines[len_map])
		len_map++;
	len_map -= len_params;
	cub->map = malloc(sizeof(char *) * (len_map + 1));
	if (!cub->map)
		return (-1);
	while (file_lines[len_params])
	{
		cub->map[i] = ft_strdup(file_lines[len_params]);
		if (!cub->map[i])
			return (-1);
		i++;
		len_params++;
	}
	cub->map[i] = NULL;
	if (parse_map(cub, cub->map) == -1)
		return (-1);
	return (0);
}

static void		check_nb_params(t_cub *cub, char **line, size_t len_params)
{
	int		nb_params;
	size_t	i;
	size_t	j;

	nb_params = 8;
	i = 0;
	while (i < len_params)
	{
		j = skip_space(line[i], 0);
		if ((line[i][j] == 'R' && line[i][j + 1] == ' ')
			|| (line[i][j] == 'S' && line[i][j + 1] == ' ')
			|| (line[i][j] == 'F' && line[i][j + 1] == ' ')
			|| (line[i][j] == 'C' && line[i][j + 1] == ' ')
			|| (line[i][j] == 'N' && line[i][j + 1] == 'O')
			|| (line[i][j] == 'S' && line[i][j + 1] == 'O')
			|| (line[i][j] == 'W' && line[i][j + 1] == 'E')
			|| (line[i][j] == 'E' && line[i][j + 1] == 'A'))
			nb_params--;
		i++;
	}
	if (nb_params != 0)
		ft_error(cub, "Number map paramaters.");
}

int				split_file(char *file, t_cub *cub)
{
	size_t	j;
	size_t	len_params;
	char	**file_lines;

	len_params = 0;
	file_lines = ft_split(file, '\n');
	if (!file_lines)
	{
		ft_free(&file);
		ft_error(cub, "file_lines");
	}
	while (file_lines[len_params])
	{
		j = skip_space(file_lines[len_params], 0);
		if (file_lines[len_params][j] == '1')
			break ;
		len_params++;
	}
	check_nb_params(cub, file_lines, len_params);
	if (fill_map(file_lines, cub, len_params) == -1)
		return (-1);
	if (fill_params(file_lines, cub, len_params) == -1)
		return (-1);
	ft_free(file_lines);
	return (0);
}
