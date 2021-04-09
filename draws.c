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

void    check_wall(t_cub *cub, t_point *player)
{
    int next;
    int direction;

    direction = 1;
    if (player->val == 'W' || player->val == 'S')
        direction = -1;
    if (player->val == 'N' || player->val == 'S')
    {
        next = player->y;
        while (cub->map[next][player->y] != '1')
            next += direction;
        printf("cub->map[%d][%d] = %c\n", player->x, next, cub->map[player->x][next]);
    }
    else if (player->val == 'W' || player->val == 'E')
    {
        next = player->x;
        while (cub->map[next][player->y] != '1')
            next += direction;
        printf("cub->map[%d][%d] = %c\n", next, player->y, cub->map[next][player->y]);
    }
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
    print_points(player);
    cub->data.posX = 20.0;
    cub->data.posY = 20.0;
    cub->data.sideDistX = 20.0;
    cub->data.sideDistY = 0.0;
    rotate_sideDist(cub, player);
    //check_wall(cub, player);
}