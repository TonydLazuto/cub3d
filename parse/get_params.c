#include "../cub3d.h"

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
		return (NULL);
	*j = skip_space(line, *j);
	if (line[*j] != '\0' && cub->width != 0)
	{
		ft_error(cub , "Resolution in .cub file.");
		return (NULL);
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
		return (NULL);
	*j = skip_space(line, *j);
	if ((nb == 2 && line[*j] != '\0') || (nb < 2 && line[*j] != ','))
	{
		ft_error(cub , "Color Floor or/and Ceiling in .cub file.");
		return (NULL);
	}
	if (line[*j] == ',' && nb < 2)
		(*j)++;
	return (rgb);
}

char	*get_path(char *line, size_t *j, t_cub *cub)
{
	char			*path;
	unsigned int	start;

	path = NULL;
	*j = skip_space(line, *j);
	start = (unsigned int)*j;
	while (line[*j] && line[*j] != ' ')
		(*j)++;
	path = ft_substr(line, start, (*j) - start);
	if (!path)
		return (NULL);
	*j = skip_space(line, *j);
	if (line[*j])
	{
		ft_error(cub , "Incorrect Path Texture.");
		return (NULL);
	}
	return (path);
}
