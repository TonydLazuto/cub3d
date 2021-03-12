#include "cub3d.h"

void    start(t_dir_plane *dir_plane, t_point *player)
{
    dir_plane->dirX = 0;
    dir_plane->dirY = 0;
    dir_plane->planeX = 0;
    dir_plane->planeY = 0.66;
    if (player->val == 'N')
        dir_plane->dirY = 1;
    else if (player->val == 'S')
        dir_plane->dirY = -1;
    else if (player->val == 'E')
        dir_plane->dirX = 1;
    else if (player->val == 'W')
        dir_plane->dirX = -1;
    return ;
}