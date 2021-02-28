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
                if (!is_point(player))
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

static int      spread_map(char **map, t_point *stack)
{
    size_t i;
    size_t j;
    t_point  *map_in_game;

    i = 0;
    j = 0;
    map_in_game = NULL;
    while (is_point(stack))
        find_wall(map, map_in_game, stack);
    return (0);
}

int             parse_map(char **map, size_t len_map)
{
    t_point  *stack;
    (void)(len_map);

    stack = NULL;
    if (check_map_chars(map) == -1)
        return (-1);
    if (!(stack = find_player(map, stack)))
        return (-1);
    if (spread_map(map, stack) == -1)
    {
        ft_putendl_fd("Error\nThe player isn't in a close map.", 1);
        return (-1);
    }
    /*
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }*/
    return (0);
}