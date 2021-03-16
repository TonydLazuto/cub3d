#include "../cub3d.h"

static int      parse_resolution(char *line, t_cub *cub, size_t j)
{
    char    *digit;
    
    digit = NULL;
    if (!(digit = get_resolution(line, &j, cub)))
        return (-1);
    if ((cub->res_text.width = ft_atoi(digit)) == -1)
        return (-1);
    ft_free(&digit);
    if (!(digit = get_resolution(line, &j, cub)))
        return (-1);
    if ((cub->res_text.height = ft_atoi(digit)) == -1)
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
        if (!(digit = get_rgb(line, &j, nb)))
            return (-1);
        rgb[nb] = ft_atoi(digit);
        if (rgb[nb] < 0 || rgb[nb] > 255)
        {
            ft_putendl_fd("Error\nRange Color Rgb -> Floor or/and Ceiling is incorrect.", 1);
            return (-1);
        }
        nb++;
    }
    if (line[0] == 'F')
        cub->res_text.floor = create_trgb(0,rgb[0],rgb[1],rgb[2]);//Voir la transparence
    else
        cub->res_text.ceiling = create_trgb(0,rgb[0],rgb[1],rgb[2]);//Voir la transparence
    ft_free(&digit);
    return (0);
}

static int      parse_path(char *line, t_cub *cub, size_t j)
{
    if (line[0] == 'N' && line[1] == 'O')
    {
        if (!(cub->path.north = get_path(line, &j)))
            return (-1);
    }
    else if (line[0] == 'S' && line[1] == 'O')
    {
        if (!(cub->path.south = get_path(line, &j)))
            return (-1);
    }
    else if (line[0] == 'W' && line[1] == 'E')
    {
        if (!(cub->path.west = get_path(line, &j)))
            return (-1);
    }
    else if (line[0] == 'E' && line[1] == 'A')
    {
        if (!(cub->path.east = get_path(line, &j)))
            return (-1);
    }
    else if (line[0] == 'S' && line[1] == ' ')
    {
        if (!(cub->path.sprite = get_path(line, &j)))
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
        ft_putendl_fd("Error\nUnconventionnal map parameter.", 1);
        return (-1);
    }
    return (0);
}