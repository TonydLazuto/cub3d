#include "cub3d.h"

int     check_line(char *line, t_cub *cub)
{
    unsigned int    i;
    
    i = 0;
    i = skip_space(line);
    if ((line[i] == 'R' || line[i] == 'F' || line[i] == 'C' || line[i] == 'S')
            && line[i + 1] == ' ')
    {
        if (check_rfcs(i, line, cub) == -1)
            return (-1);
    }
    else if (((line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'S' && line[i + 1] == 'O')
                || (line[i] == 'W' && line[i + 1] == 'E') || (line[i] == 'E' && line[i + 1] == 'A'))
                && line[i + 2] == ' ')
    {
        if (check_txt(i, line, cub) == -1)
            return (-1);
    }
    else
        return (-1);
    return (0);
}

int     check_txt(unsigned int i, char *line, t_cub *cub)
{
    if (line[i] == 'N' && line[i + 1] == 'O')
    {
        if (check_north_texture(i, line, cub) == -1)
            return (-1);
    }
    else if (line[i] == 'S' && line[i + 1] == 'O')
    {
        if (check_south_texture(i, line, cub) == -1)
            return (-1);
    }
    else if (line[i] == 'W' && line[i + 1] == 'E')
    {
        if (check_west_texture(i, line, cub) == -1)
            return (-1);
    }
    else if (line[i] == 'E' && line[i + 1] == 'A')
    {
        if (check_east_texture(i, line, cub) == -1)
            return (-1);
    }
}

int     check_rfcs(unsigned int i, char *line, t_cub *cub)
{
    if (line[i] == 'R')
    {
        if (check_resolution(i, line, cub) == -1)
            return (-1);
    }
    else if (line[i] == 'F')
    {
        if (check_floor(i, line, cub) == -1)
            return (-1);
    }
    else if (line[i] == 'C')
    {
        if (check_ceiling(i, line, cub) == -1)
            return (-1);
    }
    else if (line[i] == 'S')
    {
        if (check_sprite(i, line, cub) == -1)
            return (-1);
    }
}