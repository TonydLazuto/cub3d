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

static char		*trim_line(char *line)
{
	char			*line_clean;
	unsigned int	start;
	size_t			end;

	start = 0;
	line_clean = NULL;
    if (!line)
        return (NULL);
    start = skip_space(line, 0);
    end = ft_strlen(line);
	while (line[--end] == ' ')
        ;
	if (!(line_clean = ft_substr(line, start, end + 1 - (size_t)start)))
		return (NULL);
	return (line_clean);
}

static int		pre_parse_param(t_cub *cub, char **line, size_t *num_param)
{
	int		i;
	char	**param;
	i = 0;
	param = NULL;
	if (!(param = (char**)malloc(sizeof(char*) * (9 + 1))))
		return (-1);
	param[9] = NULL;
	while (i < 8)
	{
		if (!(param[i] = trim_line(line[num_param[i]])))
			return (-1);
		parse_param(param[i], cub);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		free(param[i]);
		i++;
	}	
	free(param);
	return (0);
}

static size_t	*get_num_lines_params(char **line, size_t *nb_lines,
								size_t	*num_param)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	*nb_lines = 0;
	while (line[i])
	{
		if (skip_space(line[i], 0) != (int)ft_strlen(line[i]))
		{
			if (*nb_lines < 9)
			{
				num_param[j] = i;
				j++;
			}
			(*nb_lines)++;
			k = skip_space(line[i], 0);
			if (line[i][k] == '1')
				break ;
		}
		i++;
	}
	return (num_param);
}

static size_t	*start_parse_param(t_cub *cub, char **line)
{
	size_t	nb_lines;
	size_t	*num_param;

	num_param = NULL;
	num_param = (size_t*)malloc(sizeof(size_t) * 9);
	nb_lines = 0;
	num_param = get_num_lines_params(line, &nb_lines, num_param);
	if (nb_lines != 9)
	{
		ft_free(line);
		ft_error(cub, "Nb parameters incorrect");
	}
	if (pre_parse_param(cub, line, num_param) == -1)
	{
		ft_free(line);
		ft_error(cub, "Malloc param");
	}
	return (num_param);
}

int				split_file(char *file, t_cub *cub)
{
	char	**line;
	size_t	*num_param;
	
	num_param = NULL;
	line = ft_split(file, '\n');
	ft_free(&file);
	if (!line)
		ft_error(cub, "split file malloc");
	num_param = start_parse_param(cub, line);
	if (start_parse_map(cub, line, num_param) == -1)
	{
		free(num_param);
		ft_free(line);
		ft_error(cub, "start_parse_param");
	}
	free(num_param);
	ft_free(line);
	return (0);
}
