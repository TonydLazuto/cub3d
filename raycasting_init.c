/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:38:24 by tonyd             #+#    #+#             */
/*   Updated: 2021/04/29 16:38:25 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_init_mvt(t_cub *cub)
{
	cub->ray.forward = 0;
	cub->ray.back = 0;
	cub->ray.left = 0;
	cub->ray.right = 0;
	cub->ray.rotate_left = 0;
	cub->ray.rotate_right = 0;
}

static void		ft_init_dir(t_cub *cub)
{
	if (cub->player->val == 'N')
		cub->ray.dirx = -1;
	else if (cub->player->val == 'S')
		cub->ray.dirx = 1;
	else if (cub->player->val == 'E')
		cub->ray.diry = 1;
	else if (cub->player->val == 'W')
		cub->ray.diry = -1;
	if (cub->player->val == 'N')
		cub->ray.planey = 0.66;
	else if (cub->player->val == 'S')
		cub->ray.planey = -0.66;
	else if (cub->player->val == 'E')
		cub->ray.planex = 0.66;
	else if (cub->player->val == 'W')
		cub->ray.planex = -0.66;
	ft_init_mvt(cub);
}

void			ft_init(t_cub *cub)
{
	cub->ray.posx = (double)cub->player->y + 0.5;
	cub->ray.posy = (double)cub->player->x + 0.5;
	cub->map[cub->player->y][cub->player->x] = '0';
	if (!(cub->s.z_buffer = (double *)malloc(sizeof(double) * cub->width)))
		exit(0);
	cub->ray.dirx = 0;
	cub->ray.diry = 0;
	cub->ray.raydirx = 0;
	cub->ray.raydiry = 0;
	cub->ray.rotate_right = 0;
	cub->ray.rotate_left = 0;
	cub->ray.time = 0;
	cub->ray.oldtime = 0;
	cub->ray.planex = 0;
	cub->ray.planey = 0;
	ft_init_dir(cub);
	return ;
}

static void		ft_init_delta_dist(t_cub *cub)
{
	if (cub->ray.raydiry == 0)
		cub->ray.deltadistx = 0;
	else if (cub->ray.raydirx == 0)
		cub->ray.deltadistx = 1;
	else
		cub->ray.deltadistx = fabs(1 / cub->ray.raydirx);
	if (cub->ray.raydirx == 0)
		cub->ray.deltadisty = 0;
	else if (cub->ray.raydiry == 0)
		cub->ray.deltadisty = 1;
	else
		cub->ray.deltadisty = fabs(1 / cub->ray.raydiry);
}

void			ft_init2(t_cub *cub)
{
	cub->ray.hit = 0;
	cub->ray.perpwalldist = 0;
	cub->ray.camerax = 2 * cub->ray.x / (double)cub->width - 1;
	cub->ray.raydirx = cub->ray.dirx + cub->ray.planex * \
						cub->ray.camerax;
	cub->ray.raydiry = cub->ray.diry + cub->ray.planey * \
						cub->ray.camerax;
	cub->ray.mapx = (int)cub->ray.posx;
	cub->ray.mapy = (int)cub->ray.posy;
	cub->ray.move_speed = 0.1;
	cub->ray.rot_speed = 0.033 * 3.5;
	ft_init_delta_dist(cub);
}
