#include "cub3d.h"
/*
--> delete the comparison inside parse_resolution() in parse_params.c
--> VOIR si mlx_get_screen_size() type "void" returns?
static void		check_max_screen_size(t_cub *cub, t_ptr ptr)
{
	int screen_width;
	int screen_height;

	screen_width = 0;
	screen_height = 0;
	mlx_get_screen_size(ptr.mlx, &screen_width, &screen_height);
	if (cub->width > screen_width)
		cub->width = screen_width;
	if (cub->height > screen_height)
		cub->height = screen_height;
}
*/

static int		fill_params(char **file_lines, t_cub *cub, size_t len_params, t_ptr ptr)
{
	size_t	i;

	i = 0;
	while (i < len_params)
	{
		if (!(file_lines[i] = trim_line(file_lines[i])))
			return (-1);
		if (file_lines[i][0] != '\0')
		{
			printf("%s\n", file_lines[i]);
			if (parse_param(file_lines[i], cub) == -1)
				return (-1);
		}
		i++;
	}
	(void)(ptr); // a suppr
	//check_max_screen_size(ptr);
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
	if (!(cub->map = malloc(sizeof(char*) * (len_map + 1))))
		return (-1);
	while (file_lines[len_params])
	{
		if (!(cub->map[i++] = ft_strdup(file_lines[len_params++])))
			return (-1);
	}
	cub->map[i] = NULL;
	if (parse_map(cub->map, len_map) == -1)
	{
		ft_putendl_fd("Error\nMap parsing", 1);
		return (-1);
	}
	return (0);
}

static int		check_nb_params(char** line, size_t len_params)
{
	int nb_params;
	size_t i;
	size_t j;

	nb_params = 8;
	i = 0;
	while (i < len_params)
	{
		j = skip_space(line[i], 0);
		if ((line[i][j] == 'R' && line[i][j + 1] == ' ') || (line[i][j] == 'S' && line[i][j + 1] == ' ')
			|| (line[i][j] == 'F' && line[i][j + 1] == ' ') || (line[i][j] == 'C' && line[i][j + 1] == ' ')
			|| (line[i][j] == 'N' && line[i][j + 1] == 'O') || (line[i][j] == 'S' && line[i][j + 1] == 'O')
			|| (line[i][j] == 'W' && line[i][j + 1] == 'E') || (line[i][j] == 'E' && line[i][j + 1] == 'A'))
			nb_params--;
		i++;
	}
	if (nb_params != 0)
	{
		ft_putendl_fd("Error\nNumber map paramaters", 1);
		return (-1);
	}
	return (0);
}

int				split_params_map(char *file, t_cub *cub, t_ptr ptr)
{
	size_t	j;
	size_t	len_params;
	char	**file_lines;

	len_params = 0;
	if (!(file_lines = ft_split(file, '\n')))
		return (-1);
	while (file_lines[len_params])
	{
		j = skip_space(file_lines[len_params], 0);
		if (file_lines[len_params][j] == '1')
			break;
		len_params++;
	}
	if (check_nb_params(file_lines, len_params) == -1)
		return (-1);
	if (fill_map(file_lines, cub, len_params) == -1)
		return (-1);
	if (fill_params(file_lines, cub, len_params, ptr) == -1)
		return (-1);
	ft_free(file_lines);
	return (0);
}