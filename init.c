#include "cub3d.h"

void	ft_init_more(t_cub *cub)
{
	cub->img.img = NULL;
	cub->texture[0].img = NULL;
	cub->texture[1].img = NULL;
	cub->texture[2].img = NULL;
	cub->texture[3].img = NULL;
	cub->texture[4].img = NULL;
	cub->win_ptr = NULL;
	cub->map = NULL;
	cub->s.order = NULL;
	cub->s.dist = NULL;
	cub->s.zbuffer = NULL;
	cub->sxy = NULL;
}

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