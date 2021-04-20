#include "cub3d.h"

void	ft_drawstartend(t_cub *cub)
{
	if (cub->ray.side == 0)
		cub->ray.perpWallDist = ((double)cub->ray.mapX - \
				cub->ray.posX + (1 - (double)cub->ray.
				stepX) / 2) / cub->ray.rayDirX;
	else
		cub->ray.perpWallDist = ((double)cub->ray.mapY - \
				cub->ray.posY + (1 - (double)cub->ray.
				stepY) / 2) / cub->ray.rayDirY;
	cub->ray.lineheight = (int)(cub->height / cub->ray.perpWallDist);
	cub->ray.drawstart = -cub->ray.lineheight / 2 + cub->height / 2;
	if (cub->ray.drawstart < 0)
		cub->ray.drawstart = 0;
	cub->ray.drawend = cub->ray.lineheight / 2 + cub->height / 2;
	if (cub->ray.drawend >= cub->height)
		cub->ray.drawend = cub->height - 1;
}

void	ft_incrementray(t_cub *cub)
{
	while (cub->ray.hit == 0)
	{
		if (cub->ray.sideDistX < cub->ray.sideDistY)
		{
			cub->ray.sideDistX += cub->ray.deltaDistX;
			cub->ray.mapX += cub->ray.stepX;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.sideDistY += cub->ray.deltaDistY;
			cub->ray.mapY += cub->ray.stepY;
			cub->ray.side = 1;
		}
		if (cub->map[cub->ray.mapX][cub->ray.mapY] == '1')
			cub->ray.hit = 1;
	}
	ft_drawstartend(cub);
}

void	ft_stepsidedist(t_cub *cub)
{
	if (cub->ray.rayDirX < 0)
	{
		cub->ray.stepX = -1;
		cub->ray.sideDistX = (cub->ray.posX - cub->ray.mapX) \
							* cub->ray.deltaDistX;
	}
	else
	{
		cub->ray.stepX = 1;
		cub->ray.sideDistX = (cub->ray.mapX + 1.0 - cub->ray.posX) \
							* cub->ray.deltaDistX;
	}
	if (cub->ray.rayDirY < 0)
	{
		cub->ray.stepY = -1;
		cub->ray.sideDistY = (cub->ray.posY - cub->ray.mapY) \
							* cub->ray.deltaDistY;
	}
	else
	{
		cub->ray.stepY = 1;
		cub->ray.sideDistY = (cub->ray.mapY + 1.0 - cub->ray.posY) \
							* cub->ray.deltaDistY;
	}
	ft_incrementray(cub);
}