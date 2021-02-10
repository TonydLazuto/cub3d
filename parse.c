#include "cub3d.h"

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
	return (0);
}

int				split_params_map(char *file, t_cub *cub)
{
	size_t	j;
	size_t	len_params;
	char	**file_lines;

	len_params = 0;
	cub->height = 300;
	cub->width = 300;
	if (!(file_lines = ft_split(file, '\n')))
		return (-1);
	while (file_lines[len_params])
	{
		j = skip_space(file_lines[len_params]);
		if (file_lines[len_params][j] == '1')
			break;
		len_params++;
	}
	if (fill_map(file_lines, cub, len_params) == -1)
		return (-1);
	
	return (0);
}