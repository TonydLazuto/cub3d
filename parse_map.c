#include "cub3d.h"

static int      check_map_chars(char **map)
{
    size_t  i;
    size_t  j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (check_charset(map[i][j], "012NSEW ") == -1)
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

static t_point   *find_player(char **map, t_point *player)
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

int             parse_map(char **map, size_t len_map)
{
    t_point  *player;
    (void)(len_map);

    player = NULL;
    if (check_map_chars(map) == -1)
        return (-1);
    if (!(player = find_player(map, player)))
        return (-1);
    if (spread_map(map, player) == -1)
        return (-1);
    /*
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }*/
    return (0);
}