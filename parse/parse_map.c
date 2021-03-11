#include "../cub3d.h"

static int          check_map_chars(char **map)
{
    size_t  i;
    size_t  j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (!is_in_charset(map[i][j], "012NSEW "))
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

t_point             *find_player(char **map, t_point *player)
{
    size_t  i;
    size_t  j;
    size_t  nb_players;

    i = 0;
    nb_players = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'S'
                || map[i][j] == 'E' || map[i][j] == 'W')
            {
                nb_players++;
                if (is_empty_lst(player))
                {
                    if (!(player = new_point(i, j, map[i][j])))
                        return (NULL);
                }
            }
            j++;
        }
        i++;
    }
    return (nb_players == 1 ? player : NULL);
}

static t_point      *spread_all_points(char **map, t_point *visited)
{
    size_t  i;
    size_t  j;
    t_point *stack2;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (!(stack2 = new_point(i, j, map[i][j])))
                return (NULL);
            if (!is_point_in_list(visited, stack2) &&
                (map[i][j] == '0' || map[i][j] == '2'))
            {
                if (!(visited = spread_map(map, stack2, visited)))
                    return (NULL);
            }
            j++;
        }
        i++;
    }
    return (visited);
}

int                 parse_map(char **map, size_t len_map)
{
    t_point     *player;
    t_point     *visited;
    (void)(len_map);

    player = NULL;
    visited = NULL;
    if (check_map_chars(map) == -1)
    {
        ft_putendl_fd("Error\nUnexpected characters in total map.", 1);
        return (-1);
    }
    if (!(player = find_player(map, player)))
    {
        ft_putendl_fd("Error\nThe player may not exists or there is multiple players.", 1);
        return (-1);
    }
    if (!(visited = spread_map(map, player, visited)))
        return (-1);
    if (!(visited = spread_all_points(map, visited)))
        return (-1);
    clear_points(&visited);
    return (0);
}