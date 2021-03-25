#include "../cub3d.h"

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
	if (parse_map(cub->map) == -1)
		return (-1);
	return (0);
}

static int	check_two_char(char first_char, char second_char, int nb_params)
{
	if ((first_char == 'R' && second_char == ' ')
		|| (first_char == 'S' && second_char == ' ')
		|| (first_char == 'F' && second_char == ' ')
		|| (first_char == 'C' && second_char == ' ')
		|| (first_char == 'N' && second_char == 'O')
		|| (first_char == 'S' && second_char == 'O')
		|| (first_char == 'W' && second_char == 'E')
		|| (first_char == 'E' && second_char == 'A'))
		nb_params--;
	return (nb_params);
}

static int	check_nb_params(char **file_lines, size_t len_params)
{
	int		nb_params;
	size_t	i;
	size_t	j;

	nb_params = 8;
	i = 0;
	printf("|%zu|\n", len_params);
	if (len_params != 8)
	{
		ft_putendl_fd("Error\nNumber map paramaters.", 1);
		return (-1);
	}
	while (i < len_params)
	{
		j = skip_space(file_lines[i], 0);
		printf("|%s|\n", file_lines[i]);
		nb_params = check_two_char(file_lines[i][j], file_lines[i][j + 1], nb_params);
		i++;
	}
	if (nb_params != 0)
	{
		ft_putendl_fd("Error\nNumber map paramaters.", 1);
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
	file_lines = NULL;
	file_lines = ft_split(file, '\n');
	if (!file_lines)
		return (-1);
	while (file_lines[len_params])
	{
		j = skip_space(file_lines[len_params], 0);
		printf("|%c|\n", file_lines[len_params][j]);
		if (file_lines[len_params][j] == '1')
			break ;
		len_params++;
	}
	//printf("|%zu|\n", len_params);
	if (check_nb_params(file_lines, len_params) == -1)
		return (-1);
	if (fill_map(file_lines, cub, len_params) == -1)
		return (-1);
	if (fill_params(file_lines, cub, len_params) == -1)
		return (-1);
	ft_free(file_lines);
	return (0);
}
