#include "cub3d.h"

void	ft_init_dir(t_cub *cub)
{
	if (cub->player->val == 'N')
		cub->ray.dirX = -1;
	else if (cub->player->val == 'S')
		cub->ray.dirX = 1;
	else if (cub->player->val == 'E')
		cub->ray.dirY = 1;
	else if (cub->player->val == 'W')
		cub->ray.dirY = -1;
	if (cub->player->val == 'N')
		cub->ray.planeY = 0.66;
	else if (cub->player->val == 'S')
		cub->ray.planeY = -0.66;
	else if (cub->player->val == 'E')
		cub->ray.planeX = 0.66;
	else if (cub->player->val == 'W')
		cub->ray.planeX = -0.66;
}


void    ft_initialisation2(t_cub *cub)
{
    cub->ray.posX = (double)cub->player->x + 0.5;
    cub->ray.posY = (double)cub->player->y + 0.5;
    cub->ray.dirX = 0;
    cub->ray.dirY = 0;
    cub->ray.rayDirX = 0;
    cub->ray.rayDirY = 0;
    cub->ray.rotate_right = 0;
	cub->ray.rotate_left = 0;
    cub->ray.time = 0; // tuto
    cub->ray.oldTime = 0; // tuto
    cub->ray.planeX = 0; 
    cub->ray.planeY = 0;
    ft_init_dir(cub);
    return ;
}

void	ft_init_more3(t_cub *cub)
{
	if (cub->ray.rayDirY == 0)
		cub->ray.deltaDistX = 0;
	else if (cub->ray.rayDirX == 0)
		cub->ray.deltaDistX = 1;
	else
		cub->ray.deltaDistX = fabs(1 / cub->ray.rayDirX);
	if (cub->ray.rayDirX == 0)
		cub->ray.deltaDistY = 0;
	else if (cub->ray.rayDirY == 0)
		cub->ray.deltaDistY = 1;
	else
		cub->ray.deltaDistY = fabs(1 / cub->ray.rayDirY);
}

void	ft_initialisation3(t_cub *cub)
{
	cub->ray.hit = 0;
	cub->ray.perpWallDist = 0;
	cub->ray.cameraX = 2 * cub->ray.x / (double)cub->width - 1; //x?
	cub->ray.rayDirX = cub->ray.dirX + cub->ray.planeX * \
						cub->ray.cameraX;
	cub->ray.rayDirY = cub->ray.dirY + cub->ray.planeY * \
						cub->ray.cameraX;
	cub->ray.mapX = (int)cub->ray.posX;
	cub->ray.mapY = (int)cub->ray.posY;
	cub->ray.moveSpeed = 0.1;
	cub->ray.rotSpeed = 0.033 * 1.8;
	ft_init_more3(cub);
}