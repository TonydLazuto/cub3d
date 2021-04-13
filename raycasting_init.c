#include "cub3d.h"

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

void	ft_initialisation3(t_cub *cub)
{
	cub->ray.hit = 0;
	cub->ray.perpWallDist = 0;
	cub->ray.cameraX = 2 * cub->ray.x / (double)cub->width - 1;
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

void	ft_init_texture(t_cub *cub)
{
	if (cub->ray.side == 0 && cub->ray.rayDirX < 0)
		cub->t.texdir = 0;
	if (cub->ray.side == 0 && cub->ray.rayDirX >= 0)
		cub->t.texdir = 1;
	if (cub->ray.side == 1 && cub->ray.rayDirY < 0)
		cub->t.texdir = 2;
	if (cub->ray.side == 1 && cub->ray.rayDirY >= 0)
		cub->t.texdir = 3;
	if (cub->ray.side == 0)
		cub->t.wallx = cub->ray.posY + cub->ray.perpWallDist \
						* cub->ray.rayDirY;
	else
		cub->t.wallx = cub->ray.posX + cub->ray.perpWallDist \
						* cub->ray.rayDirX;
	cub->t.wallx -= floor((cub->t.wallx));
}

void	ft_init_sprite2(t_cub *cub, int i, int j, int v)
{
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '2')
			{
				cub->sxy[v].x = (double)i + 0.5;
				cub->sxy[v].y = (double)j + 0.5;
				v++;
			}
            j++;
		}
        i++;
	}
}

void	ft_init_sprite(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	cub->s.nbspr = 0;
	while (cub->map[i])// a voir
	{
		j = 0;
		while (cub->map[i][j]) // a voir
		{
			if (cub->map[i][j] == '2')
				cub->s.nbspr += 1;
            j++;
		}
        i++;
	}
	if (!(cub->sxy = (t_sprxy *)malloc(sizeof(t_sprxy) * cub->s.nbspr)))
		ft_error(cub, "Malloc sxy*");
	if (!(cub->s.order = (int *)malloc(sizeof(int) * cub->s.nbspr)))
		ft_error(cub, "Malloc s.order*");
	if (!(cub->s.dist = (double *)malloc(sizeof(double) * cub->s.nbspr)))
		ft_error(cub, "Malloc s.dist*");
	ft_init_sprite2(cub, 0, 0, 0);
}