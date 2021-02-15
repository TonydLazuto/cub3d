#include "cub3d.h"

int				skip_space(char *line, unsigned int i)
{
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}

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

static int		fill_params(char **file_lines, t_cub *cub, size_t len_params)
{
	size_t	i;
	unsigned int j;

	i  = 0;
	j = 0;
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
	return (0);
}

int				split_params_map(char *file, t_cub *cub)
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
	if (fill_params(file_lines, cub, len_params) == -1)
		return (-1);
	ft_free(file_lines);
	return (0);
}