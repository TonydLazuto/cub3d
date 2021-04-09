#include "cub3d.h"
/*
    Rotation 'E' = 0 or 2PI
*/
void    rotate_sideDist(t_cub *cub, t_point *player)
{
    double oldX;
    double oldY;
    double angle;

    angle = 0.0;
    oldX = cub->data.sideDistX;
    oldY = cub->data.sideDistY;
    if (player->val == 'N')
        angle = PI / 2;
    else if (player->val == 'W')
        angle = PI;
    else if (player->val == 'S')
        angle = 3 * PI / 2;
    cub->data.sideDistX = oldX * cos(angle) - oldY * sin(angle);
    cub->data.sideDistY = oldX * sin(angle) + oldY * cos(angle);
}

void    set_deltaDistY(t_cub *cub, int diff)
{
    double size;

    size = (double)diff;
    cub->data.deltaDistX = 0.0;
    cub->data.deltaDistY = SIZE_SQUARE / 2;
    if (diff > 0)
        cub->data.deltaDistY += size * SIZE_SQUARE;
}

int     find_wall(int var, t_point *player)
{
    if (player->val == 'N' || player->val == 'W')
        var--;
    else
        var++;
    return (var);
}

/*
    get the first Point in front of the player vision
*/

int     check_wall(t_cub *cub, t_point *player)
{
    int j;
    int i;
    int diff;
    
    j = player->y;
    i = player->x;
    print_points(player);
    diff = j;
    while (cub->map[j][i] != '1')
    {
        if (player->val == 'N' || player->val == 'S')
            j = find_wall(j ,player);
        else
            i = find_wall(i ,player);
    }
    if (diff != j)
        diff = j - player->y;
    else
        diff = i - player->x;
    if (diff < 0)
        diff = -diff;
    diff--;
    set_deltaDistY(cub, diff);
    return (diff);
}

/*
    | We assume that the map is 40x40 |

    if (player == NULL)
        return ;
    --> This test is no longer necessary because it has already done.
    --> The map is already valid.
*/
void    draw_map(t_cub *cub)
{
    t_point *player;

    player = NULL;
    player = find_player(cub->map, player);
    cub->data.posX = 20.0;
    cub->data.posY = 20.0;
    cub->data.sideDistX = 20.0;
    cub->data.sideDistY = 0.0;
    rotate_sideDist(cub, player);
    check_wall(cub, player);
}