#include "cub3d.h"

char     *get_resolution(char *line, size_t *j, t_cub *cub)
{
    char            *resolution;
    unsigned int    start;

    resolution = NULL;
    *j = skip_space(line, *j);
    start = (unsigned int)*j;
    while (line[*j] && ft_isdigit(line[*j]))
        (*j)++;
    if (!(resolution = ft_substr(line, start, (*j) - start)))
        return (NULL);
    *j = skip_space(line, *j);
    if (line[*j] != '\0' && cub->width != 0)
    {
        ft_putendl_fd("Error\nResolution in .cub file.", 1);
        return (NULL);
    }
    return (resolution);
}

char     *get_rgb(char *line, size_t *j, int nb)
{
    char            *rgb;
    unsigned int    start;

    rgb = NULL;
    *j = skip_space(line, *j);
    start = (unsigned int)*j;
    while (line[*j] && ft_isdigit(line[*j]))
        (*j)++;
    if (!(rgb = ft_substr(line, start, (*j) - start)))
        return (NULL);
    *j = skip_space(line, *j);
    if ((nb == 2 && line[*j] != '\0') || (nb < 2 && line[*j] != ','))
    {
        ft_putendl_fd("Error\nColor Floor or/and Ceiling in .cub file.", 1);
        return (NULL);
    }
    if (line[*j] == ',' && nb < 2)
        (*j)++;
    return (rgb);
}

char     *get_path(char *line, size_t *j)
{
    char            *path;
    unsigned int    start;

    path = NULL;
    *j = skip_space(line, *j);
    start = (unsigned int)*j;
    while (line[*j] && line[*j] != ' ')
            (*j)++;
    if (!(path = ft_substr(line, start, (*j) - start)))
        return (NULL);
    *j = skip_space(line, *j);
    if (line[*j])
    {
        ft_putendl_fd("Error\nIncorrect Path Texture.", 1);
        return (NULL);
    }
    return (path);
}
