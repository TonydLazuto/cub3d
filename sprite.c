#include "cub3d.h"

void	ft_sort_sprites2(t_cub *cub)
{
	int i;

	i = 0;
	while (i < cub->s.numSprites)
	{
		cub->s.order[i] = i;
		cub->s.dist[i] = ((cub->ray.posX - cub->sxy[i].x) *
				(cub->ray.posX - cub->sxy[i].x) + (cub->ray.posY -
					cub->sxy[i].y) * (cub->ray.posY - cub->sxy[i].y));
        i++;
	}
}

void	ft_sort_sprites(t_cub *cub)
{
	int		i;
	int		j;
	double	tmp;

	ft_sort_sprites2(cub);
	i = 0;
	while (i < cub->s.numSprites)
	{
		j = 0;
		while (j < cub->s.numSprites - 1)
		{
			if (cub->s.dist[j] < cub->s.dist[j + 1])
			{
				tmp = cub->s.dist[j];
				cub->s.dist[j] = cub->s.dist[j + 1];
				cub->s.dist[j + 1] = tmp;
				tmp = cub->s.order[j];
				cub->s.order[j] = cub->s.order[j + 1];
				cub->s.order[j + 1] = (int)tmp;
			}
            j++;
		}
        i++;
	}
}

void	ft_calculs(t_cub *cub, int i)
{
	cub->s.spriteX = cub->sxy[cub->s.order[i]].x - cub->ray.posX;
	cub->s.spriteY = cub->sxy[cub->s.order[i]].y - cub->ray.posY;
	cub->s.invDet = 1.0 / (cub->ray.planeX * cub->ray.dirY -
			cub->ray.dirX * cub->ray.planeY);
	cub->s.transformX = cub->s.invDet * (cub->ray.dirY *
			cub->s.spriteX - cub->ray.dirX * cub->s.spriteY);
	cub->s.transformY = cub->s.invDet * (-cub->ray.planeY *
			cub->s.spriteX + cub->ray.planeX * cub->s.spriteY);
	cub->s.spritescreenX = (int)((cub->width / 2) * (1 + cub->s.transformX
				/ cub->s.transformY));
	cub->s.spriteHeight = abs((int)(cub->height / (cub->s.transformY)));
	cub->s.drawStartY = -cub->s.spriteHeight / 2 + cub->height / 2;
	if (cub->s.drawStartY < 0)
		cub->s.drawStartY = 0;
	cub->s.drawEndY = cub->s.spriteHeight / 2 + cub->height / 2;
	if (cub->s.drawEndY >= cub->height)
		cub->s.drawEndY = cub->height;
	cub->s.spriteWidth = abs((int)(cub->height / (cub->s.transformY)));
	cub->s.drawStartX = -cub->s.spriteWidth / 2 + cub->s.spritescreenX;
	if (cub->s.drawStartX < 0)
		cub->s.drawStartX = 0;
	cub->s.drawEndX = cub->s.spriteWidth / 2 + cub->s.spritescreenX;
	if (cub->s.drawEndX >= cub->width)
		cub->s.drawEndX = cub->width;
}

void	ft_sprite2(t_cub *cub, int y, int texX, int stripe)
{
	int		d;
	int		texY;

	while (y < cub->s.drawEndY)
	{
		d = (y) * 256 - cub->height * 128 + cub->s.spriteHeight * 128;
		texY = ((d * cub->texture[4].height) / cub->s.spriteHeight) / 256;
		if (cub->texture[4].addr[texY * cub->texture[4].line_length / 4 +
				texX] != -16777216)
		{
			cub->img.addr[y * cub->img.line_length / 4 + stripe] =
				cub->texture[4].addr[texY * cub->texture[4].line_length /
				4 + texX];
		}
		y++;
	}
}

void	ft_sprite(t_cub *cub)
{
	int i;
	int y;
	int stripe;
	int texX;

	i = 0;
	ft_sort_sprites(cub);
	while (i < cub->s.numSprites)
	{
		ft_calculs(cub, i);
		stripe = cub->s.drawStartX;
		while (stripe < cub->s.drawEndX)
		{
			texX = (int)(256 * (stripe - (-cub->s.spriteWidth / 2 +
							cub->s.spritescreenX)) * cub->texture[4].width
					/ cub->s.spriteWidth) / 256;
			if (cub->s.transformY > 0 && stripe >= 0 && stripe < cub->width
					&& cub->s.transformY < cub->s.zBuffer[stripe])
			{
				y = cub->s.drawStartY;
				ft_sprite2(cub, y, texX, stripe);
			}
			stripe++;
		}
        i++;
	}
}