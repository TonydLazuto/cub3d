#include "cub3d.h"

static int      parse_resolution(char *line, t_cub *cub, size_t j)
{
    char    *digit;
    
    digit = NULL;
    if (!(digit = get_resolution(line, &j, cub)))
        return (-1);
    if ((cub->width = ft_atoi(digit)) == -1)
        return (-1);
    ft_free(&digit);
    if (!(digit = get_resolution(line, &j, cub)))
        return (-1);
    if ((cub->height = ft_atoi(digit)) == -1)
        return (-1);
    ft_free(&digit);
    return (0);
}

static int      parse_color(char *line, t_cub *cub, size_t j)
{
    char    *digit;
    int     rgb[3];
    int     nb;

    nb = 0;
    digit = NULL;
    while (nb < 3)
    {
        if (!(digit = get_rgb(line, &j, nb, cub)))
            return (-1);
        rgb[nb] = ft_atoi(digit);
        if (rgb[nb] < 0 || rgb[nb] > 255)
        {
            ft_error(cub , "Range Color Rgb -> Floor or/and Ceiling is incorrect.");
            return (-1);
        }
        nb++;
    }
    if (line[0] == 'F')
        cub->floor = create_trgb(0,rgb[0],rgb[1],rgb[2]);
    else
        cub->ceiling = create_trgb(0,rgb[0],rgb[1],rgb[2]);
    ft_free(&digit);
    return (0);
}

static int      parse_path(char *line, t_cub *cub, size_t j)
{
    if (line[0] == 'N' && line[1] == 'O')
    {
        if (!(cub->north = get_path(line, &j, cub)))
            return (-1);
    }
    else if (line[0] == 'S' && line[1] == 'O')
    {
        if (!(cub->south = get_path(line, &j, cub)))
            return (-1);
    }
    else if (line[0] == 'W' && line[1] == 'E')
    {
        if (!(cub->west = get_path(line, &j, cub)))
            return (-1);
    }
    else if (line[0] == 'E' && line[1] == 'A')
    {
        if (!(cub->east = get_path(line, &j, cub)))
            return (-1);
    }
    else if (line[0] == 'S' && line[1] == ' ')
    {
        if (!(cub->sprite = get_path(line, &j, cub)))
            return (-1);
    }
    return (0);
}

int     parse_param(char *line, t_cub *cub)
{
    size_t  j;

    j = line[1] == ' ' ? 2 : 3;
    if (line[0] == 'R' && line[1] == ' ')
    {
        if (parse_resolution(line, cub, j) == -1)
            return (-1);
    }
    else if ((line[0] == 'F' || line[0] == 'C') && line[1] == ' ')
    {
        if (parse_color(line, cub, j) == -1)
            return (-1);
    }
    else if (((((line[0] == 'N' && line[1] == 'O') || (line[0] == 'S' && line[1] == 'O')
                || (line[0] == 'W' && line[1] == 'E') || (line[0] == 'E' && line[1] == 'A'))
                && line[2] == ' ')) || (line[0] == 'S' && line[1] == ' '))
    {
        if (parse_path(line, cub, j) == -1)
            return (-1);
    }
    else
    {
        ft_error(cub , "Unconventionnal map parameter.");
        return (-1);
    }
    return (0);
}
