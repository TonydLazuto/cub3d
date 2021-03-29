#include "cub3d.h"

void    start(t_data *data, t_point *player)
{
    data->posX = (double)player->x;
    data->posY = (double)player->y;
    data->dirX = 0;
    data->dirY = 0;
    data->planeX = 0;
    data->planeY = 0.66;
    data->deltaDistX = abs(1 / data->rayDirX);
    data->deltaDistY = abs(1 / data->rayDirY);
    data->hit = 0;
    if (player->val == 'N')
        data->dirY = 1;
    else if (player->val == 'S')
        data->dirY = -1;
    else if (player->val == 'E')
        data->dirX = 1;
    else if (player->val == 'W')
        data->dirX = -1;
    return ;
}