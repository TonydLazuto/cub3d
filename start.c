#include "cub3d.h"

void    start(t_cub *cub, t_point *player)
{
    int x;
    int y;
    
    x = cub->width / 2;
	y = cub->height / 2;
    cub->data.posX = (double)x;
    cub->data.posY = (double)y;
    cub->data.pdx = cos(cub->data.pa) * 5;
    cub->data.pdy = sin(cub->data.pa) * 5;
    cub->data.mapX = player->x;
    cub->data.mapY = player->y;
    cub->data.dirX = 0;
    cub->data.dirY = 0;
    cub->data.planeX = 0;
    cub->data.planeY = 0.66;
    cub->data.deltaDistX = (cub->data.rayDirY == 0) ? 0 : ((cub->data.rayDirX == 0) ? 1 : fabs(1 / cub->data.rayDirX)); //voir fabs pour float ou abs pour int
    cub->data.deltaDistY = (cub->data.rayDirX == 0) ? 0 : ((cub->data.rayDirY == 0) ? 1 : fabs(1 / cub->data.rayDirX));
    cub->data.hit = 0;
    if (player->val == 'N')
        cub->data.dirY = 1;
    else if (player->val == 'S')
        cub->data.dirY = -1;
    else if (player->val == 'E')
        cub->data.dirX = 1;
    else if (player->val == 'W')
        cub->data.dirX = -1;
    return ;
}