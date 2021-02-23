#include "cub3d.h"

static char     find_player(char **map, t_coor *point)
{
    size_t  i;
    size_t  j;
    size_t  nb_players;
    char    player;

    i = 0;
    nb_players = 0;
    player = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'S'
                || map[i][j] == 'E' || map[i][j] == 'W')
            {
                nb_players++;
                player = map[i][j];
            }
            j++;
        }
        i++;
    }
    return (nb_players == 1 ? player : 0);
}

static int      check_mini_map(char **map, char player)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while ((j = get_col_player(map[i], player)) == -1)
        i++;
    printf("%c\n%zu, %zu\n", map[i][j], i, j);
    return (0);
}

int             parse_map(char **map, size_t len_map)
{
    t_coor  point;
    char    player;
    (void)(len_map);

    if (!(find_player(map, &point)))
        return (-1);
    if (check_mini_map(map, player) == -1)
        return (-1);
    /*
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }*/
    return (0);
}