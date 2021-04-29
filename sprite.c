/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:39:30 by tonyd             #+#    #+#             */
/*   Updated: 2021/04/29 16:39:31 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sort_sprites2(t_cub *cub)
{
	int i;

	i = 0;
	while (i < cub->s.num_sprites)
	{
		cub->s.order[i] = i;
		cub->s.dist[i] = ((cub->ray.posx - cub->sxy[i].x) *
				(cub->ray.posx - cub->sxy[i].x) + (cub->ray.posy -
					cub->sxy[i].y) * (cub->ray.posy - cub->sxy[i].y));
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
	while (i < cub->s.num_sprites)
	{
		j = 0;
		while (j < cub->s.num_sprites - 1)
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
	cub->s.spritex = cub->sxy[cub->s.order[i]].x - cub->ray.posx;
	cub->s.spritey = cub->sxy[cub->s.order[i]].y - cub->ray.posy;
	cub->s.inv_det = 1.0 / (cub->ray.planex * cub->ray.diry -
			cub->ray.dirx * cub->ray.planey);
	cub->s.transformx = cub->s.inv_det * (cub->ray.diry *
			cub->s.spritex - cub->ray.dirx * cub->s.spritey);
	cub->s.transformy = cub->s.inv_det * (-cub->ray.planey *
			cub->s.spritex + cub->ray.planex * cub->s.spritey);
	cub->s.spritescreenx = (int)((cub->width / 2) * (1 + cub->s.transformx
				/ cub->s.transformy));
	cub->s.spriteheight = abs((int)(cub->height / (cub->s.transformy)));
	cub->s.draw_starty = -cub->s.spriteheight / 2 + cub->height / 2;
	if (cub->s.draw_starty < 0)
		cub->s.draw_starty = 0;
	cub->s.draw_endy = cub->s.spriteheight / 2 + cub->height / 2;
	if (cub->s.draw_endy >= cub->height)
		cub->s.draw_endy = cub->height;
	cub->s.spritewidth = abs((int)(cub->height / (cub->s.transformy)));
	cub->s.draw_startx = -cub->s.spritewidth / 2 + cub->s.spritescreenx;
	if (cub->s.draw_startx < 0)
		cub->s.draw_startx = 0;
	cub->s.draw_endx = cub->s.spritewidth / 2 + cub->s.spritescreenx;
	if (cub->s.draw_endx >= cub->width)
		cub->s.draw_endx = cub->width;
}

void	ft_sprite2(t_cub *cub, int y, int texx, int stripe)
{
	int		d;
	int		texy;

	while (y < cub->s.draw_endy)
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
	ft_sort_sprites(cub);
	while (i < cub->s.num_sprites)
	{
		ft_calculs(cub, i);
		stripe = cub->s.draw_startx;
		while (stripe < cub->s.draw_endx)
		{
			texx = (int)(256 * (stripe - (-cub->s.spritewidth / 2 + cub->s.spritescreenx))
                    * cub->texture[4].width / cub->s.spritewidth) / 256;
			if (cub->s.transformy > 0 && stripe >= 0 && stripe < cub->width
					&& cub->s.transformy < cub->s.z_buffer[stripe])
			{
				y = cub->s.draw_starty;
				ft_sprite2(cub, y, texx, stripe);
			}
			stripe++;
		}
		i++;
	}
}
