#include "cub3d.h"

void	ft_forward_back(t_cub *cub)
{
	if (cub->ray.forward == 1)
	{
		if (cub->map[(int)(cub->ray.posX + (cub->ray.dirX * cub->
						ray.moveSpeed * 2))][(int)cub->ray.posY] == '0')
			cub->ray.posX += cub->ray.dirX * cub->ray.moveSpeed;
		if (cub->map[(int)(cub->ray.posX)][(int)(cub->ray.posY +
					(cub->ray.dirY * cub->ray.moveSpeed * 2))] == '0')
			cub->ray.posY += cub->ray.dirY * cub->ray.moveSpeed;
	}
	if (cub->ray.back == 1)
	{
		if (cub->map[(int)(cub->ray.posX - (cub->ray.dirX * cub->
						ray.moveSpeed * 2))][(int)(cub->ray.posY)] == '0')
			cub->ray.posX -= cub->ray.dirX * cub->ray.moveSpeed;
		if (cub->map[(int)(cub->ray.posX)][(int)(cub->ray.posY -
					(cub->ray.dirY * cub->ray.moveSpeed * 2))] == '0')
			cub->ray.posY -= cub->ray.dirY * cub->ray.moveSpeed;
	}
}

void	ft_left_right(t_cub *cub)
{
	if (cub->ray.right == 1)
	{
		if (cub->map[(int)(cub->ray.posX + cub->ray.dirY *
					(cub->ray.moveSpeed * 2))][(int)cub->ray.posY] == '0')
			cub->ray.posX += cub->ray.dirY * cub->ray.moveSpeed;
		if (cub->map[(int)cub->ray.posX][(int)(cub->ray.posY -
					cub->ray.dirX *
					(cub->ray.moveSpeed * 2))] == '0')
			cub->ray.posY -= cub->ray.dirX * cub->ray.moveSpeed;
	}
	if (cub->ray.left == 1)
	{
		if (cub->map[(int)(cub->ray.posX - cub->ray.dirY *
					(cub->ray.moveSpeed * 2))][(int)cub->ray.posY] == '0')
			cub->ray.posX -= cub->ray.dirY * cub->ray.moveSpeed;
		if (cub->map[(int)cub->ray.posX][(int)(cub->ray.posY +
					cub->ray.dirX *
					(cub->ray.moveSpeed * 2))] == '0')
			cub->ray.posY += cub->ray.dirX * cub->ray.moveSpeed;
	}
}

void	ft_rotate_right_left(t_cub *cub)
{
	double oldplaneX;
	double olddirx;

	oldplaneX = cub->ray.planeX;
	olddirx = cub->ray.dirX;
	if (cub->ray.rotate_right == 1)
	{
		cub->ray.dirX = cub->ray.dirX * cos(-cub->ray.rotSpeed / 2) -
			cub->ray.dirY * sin(-cub->ray.rotSpeed / 2);
		cub->ray.dirY = olddirx * sin(-cub->ray.rotSpeed / 2) +
			cub->ray.dirY * cos(-cub->ray.rotSpeed / 2);
		cub->ray.planeX = cub->ray.planeX * cos(-cub->ray.rotSpeed / 2)
			- cub->ray.planeY * sin(-cub->ray.rotSpeed / 2);
		cub->ray.planeY = oldplaneX * sin(-cub->ray.rotSpeed / 2) +
			cub->ray.planeY * cos(-cub->ray.rotSpeed / 2);
	}
	ft_rotate_left(cub, olddirx);
}

void	ft_rotate_left(t_cub *cub, double olddirx)
{
	double oldplanex;

	if (cub->ray.rotate_left == 1)
	{
		olddirx = cub->ray.dirX;
		oldplanex = cub->ray.planeX;
		cub->ray.dirX = cub->ray.dirX * cos(cub->ray.rotSpeed / 2) -
			cub->ray.dirY * sin(cub->ray.rotSpeed / 2);
		cub->ray.dirY = olddirx * sin(cub->ray.rotSpeed / 2) + cub->
			ray.dirY * cos(cub->ray.rotSpeed / 2);
		cub->ray.planeX = cub->ray.planeX * cos(cub->ray.rotSpeed / 2) -
			cub->ray.planeY * sin(cub->ray.rotSpeed / 2);
		cub->ray.planeY = oldplanex * sin(cub->ray.rotSpeed / 2) +
			cub->ray.planeY * cos(cub->ray.rotSpeed / 2);
	}
}