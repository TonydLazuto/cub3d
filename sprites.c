#include "cub3d.h"

void	ft_dist_order2(t_cub *cub)
{
	int i;

	i = 0;
	while (i < cub->s.nbspr)
	{
		cub->s.order[i] = i;
		cub->s.dist[i] = ((cub->ray.posX - cub->sxy[i].x) *
				(cub->ray.posX - cub->sxy[i].x) + (cub->ray.posY -
					cub->sxy[i].y) * (cub->ray.posY - cub->sxy[i].y));
        i++;
	}
}

void	ft_dist_order(t_cub *cub)
{
	int		i;
	int		j;
	double	tmp;

	ft_dist_order2(cub);
	i = 0;
	while (i < cub->s.nbspr)
	{
		j = 0;
		while (j < cub->s.nbspr - 1)
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
	cub->s.spritex = cub->sxy[cub->s.order[i]].x - cub->ray.posX;
	cub->s.spritey = cub->sxy[cub->s.order[i]].y - cub->ray.posY;
	cub->s.invdet = 1.0 / (cub->ray.planeX * cub->ray.dirY -
			cub->ray.dirX * cub->ray.planeY);
	cub->s.transformx = cub->s.invdet * (cub->ray.dirY *
			cub->s.spritex - cub->ray.dirX * cub->s.spritey);
	cub->s.transformy = cub->s.invdet * (-cub->ray.planeY *
			cub->s.spritex + cub->ray.planeX * cub->s.spritey);
	cub->s.spritescreenx = (int)((cub->width / 2) * (1 + cub->s.transformx
				/ cub->s.transformy));
	cub->s.spriteheight = abs((int)(cub->height / (cub->s.transformy)));
	cub->s.drawstarty = -cub->s.spriteheight / 2 + cub->height / 2;
	if (cub->s.drawstarty < 0)
		cub->s.drawstarty = 0;
	cub->s.drawendy = cub->s.spriteheight / 2 + cub->height / 2;
	if (cub->s.drawendy >= cub->height)
		cub->s.drawendy = cub->height;
	cub->s.spritewidth = abs((int)(cub->height / (cub->s.transformy)));
	cub->s.drawstartx = -cub->s.spritewidth / 2 + cub->s.spritescreenx;
	if (cub->s.drawstartx < 0)
		cub->s.drawstartx = 0;
	cub->s.drawendx = cub->s.spritewidth / 2 + cub->s.spritescreenx;
	if (cub->s.drawendx >= cub->width)
		cub->s.drawendx = cub->width;
}

void	ft_draw_spr(t_cub *cub, int y, int texx, int stripe)
{
	int		d;
	int		texy;

	while (y < cub->s.drawendy)
	{
		d = (y) * 256 - cub->height * 128 + cub->s.spriteheight * 128;
		texy = ((d * cub->texture[4].height) / cub->s.spriteheight) / 256;
		if (cub->texture[4].addr[texy * cub->texture[4].line_length / 4 +
				texx] != -16777216)
		{
			cub->img.addr[y * cub->img.line_length / 4 + stripe] =
				cub->texture[4].addr[texy * cub->texture[4].line_length /
				4 + texx];
		}
		y++;
	}
}

void	ft_sprite(t_cub *cub)
{
	int i;
	int y;
	int stripe;
	int texx;

	i = 0;
	ft_dist_order(cub);
	while (i < cub->s.nbspr)
	{
		ft_calculs(cub, i);
		stripe = cub->s.drawstartx;
		while (stripe < cub->s.drawendx)
		{
			texx = (int)(256 * (stripe - (-cub->s.spritewidth / 2 +
							cub->s.spritescreenx)) * cub->texture[4].width
					/ cub->s.spritewidth) / 256;
			if (cub->s.transformy > 0 && stripe >= 0 && stripe < cub->width
					&& cub->s.transformy < cub->s.zbuffer[stripe])
			{
				y = cub->s.drawstarty;
				ft_draw_spr(cub, y, texx, stripe);
			}
			stripe++;
		}
        i++;
	}
}