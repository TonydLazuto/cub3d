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
static char		*trim_line(char *line)
{
    char			*line_clean;
	unsigned int	i;
	size_t			k;

	i = 0;
    line_clean = NULL;
    i = skip_space(line, 0);
	k = ft_strlen(line) - 1;
	while (k > 0 && (line[k] == ' ' || line[k] == '\t'))
		k--;
    if (!(line_clean = ft_substr(line, i, k + 1 - (size_t)i)))
        return (NULL);
	ft_free(&line);
    return (line_clean);
}

static int		fill_check_params(char **file_lines, t_cub *cub, size_t len_params, t_ptr ptr)
{
	size_t	i;

	i = 0;
	if (len_params != 8)
	{
		ft_putendl_fd("Error\nMap's parmaters number incorrect", 1);
		return (-1);
	}
	while (i < len_params)
	{
		if (!(file_lines[i] = trim_line(file_lines[i])))
			return (-1);
		if (parse_param(file_lines[i], cub) == -1)
			return (-1);
		i++;
	}
	(void)(ptr);
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
		if (!(cub->map[i] = ft_strdup(file_lines[len_params])))
			return (-1);
		len_params++;
		i++;
	}
	cub->map[i] = NULL;
	/*
		check param par ici
		!! checker les leaks !!
	*/
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
	if (fill_map(file_lines, cub, len_params) == -1)
		return (-1);
//	if (check_map(file_lines, cub, len_params) == -1)
//		return (-1);
	if (fill_check_params(file_lines, cub, len_params, ptr) == -1)
		return (-1);
	ft_free(file_lines);
	return (0);
}