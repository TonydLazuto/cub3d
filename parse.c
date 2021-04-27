#include "cub3d.h"
/*
--> delete the comparison inside parse_resolution() in parse_params.c
--> VOIR si mlx_get_screen_size() type "void" returns?
static void		check_max_screen_size(t_cub *cub)
{
	int screen_width;
	int screen_height;

	screen_width = 0;
	screen_height = 0;
	mlx_get_screen_size(cub->mlx_ptr, &screen_width, &screen_height);
	if (cub->width > screen_width)
		cub->width = screen_width;
	if (cub->height > screen_height)
		cub->height = screen_height;
}
*/
static int	fill_params(char **file_lines, t_cub *cub, size_t len_params)
{
	size_t	i;

	i = 0;
	while (i < len_params)
	{
		file_lines[i] = trim_line(file_lines[i]);
		if (!file_lines[i])
			return (-1);
		if (file_lines[i][0] != '\0')
		{
			if (parse_param(file_lines[i], cub) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

static int	fill_map(char **file_lines, t_cub *cub, size_t len_params)
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
		cub->map[i++] = ft_strdup(file_lines[len_params++]);
		if (!cub->map[i])
			return (-1);
	}
	cub->map[i] = NULL;
	if (parse_map(cub, cub->map) == -1)
		return (-1);
	return (0);
}

static int		check_nb_params(t_cub *cub, char** line, size_t len_params)
{
	int nb_params;
	size_t i;
	size_t j;

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
	{
		ft_error(cub , "Number map paramaters.");
		return (-1);
	}
	return (0);
}

int	split_file(char *file, t_cub *cub)
{
	size_t	j;
	size_t	len_params;
	char	**file_lines;

	len_params = 0;
	file_lines = ft_split(file, '\n');
	if (!file_lines)
		return (-1);
	while (file_lines[len_params])
	{
		j = skip_space(file_lines[len_params], 0);
		if (file_lines[len_params][j] == '1')
			break ;
		len_params++;
	}
	if (check_nb_params(cub, file_lines, len_params) == -1)
		return (-1);
	if (fill_map(file_lines, cub, len_params) == -1)
		return (-1);
	if (fill_params(file_lines, cub, len_params) == -1)
		return (-1);
	ft_free(file_lines);
	return (0);
}