/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:36:31 by tonyd             #+#    #+#             */
/*   Updated: 2021/04/29 16:36:33 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_texture(t_cub *cub)
{
	if (cub->ray.side == 0 && cub->ray.raydirx < 0)
		cub->t.tex_dir = 0;
	if (cub->ray.side == 0 && cub->ray.raydirx >= 0)
		cub->t.tex_dir = 1;
	if (cub->ray.side == 1 && cub->ray.raydiry < 0)
		cub->t.tex_dir = 2;
	if (cub->ray.side == 1 && cub->ray.raydiry >= 0)
		cub->t.tex_dir = 3;
	if (cub->ray.side == 0)
		cub->t.wallx = cub->ray.posy + cub->ray.perpwalldist \
						* cub->ray.raydiry;
	else
		cub->t.wallx = cub->ray.posx + cub->ray.perpwalldist \
						* cub->ray.raydirx;
	cub->t.wallx -= floor((cub->t.wallx));
}

void	ft_draw_texture(t_cub *cub, int x, int y)
{
	y = cub->ray.drawstart - 1;
	ft_init_texture(cub);
	cub->t.step = 1.0 * cub->texture[0].height / cub->ray.lineheight;
	cub->t.texx = (int)(cub->t.wallx * (double)cub->texture
			[cub->t.tex_dir].width);
	if (cub->ray.side == 0 && cub->ray.raydirx > 0)
		cub->t.texx = cub->texture[cub->t.tex_dir].width -
			cub->t.texx - 1;
	if (cub->ray.side == 1 && cub->ray.raydiry < 0)
		cub->t.texx = cub->texture[cub->t.tex_dir].width -
			cub->t.texx - 1;
	cub->t.tex_pos = (cub->ray.drawstart - cub->height / 2 +
			cub->ray.lineheight / 2) * cub->t.step;
	while (++y <= cub->ray.drawend)
	{
		cub->t.texy = (int)cub->t.tex_pos &
			(cub->texture[cub->t.tex_dir].height - 1);
		cub->t.tex_pos += cub->t.step;
		if (y < cub->height && x < cub->width)
			cub->img.addr[y * cub->img.line_length / 4 + x] =
				cub->texture[cub->t.tex_dir].addr[cub->t.texy *
					cub->texture[cub->t.tex_dir].line_length /
					4 + cub->t.texx];
	}
}

int		ft_color_column(t_cub *cub)
{
	int j;
	int i;

	j = -1;
	cub->ray.drawend = cub->height - cub->ray.drawstart;
	i = cub->ray.drawend;
	while (++j < cub->ray.drawstart)
		cub->img.addr[j * cub->img.line_length / 4 +
			cub->ray.x] = cub->ceiling;
	if (j <= cub->ray.drawend)
		ft_draw_texture(cub, cub->ray.x, j);
	j = i;
	while (++j < cub->height)
		cub->img.addr[j * cub->img.line_length / 4 +
			cub->ray.x] = cub->floor;
	return (0);
}
