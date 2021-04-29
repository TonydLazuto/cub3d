/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:38:32 by tonyd             #+#    #+#             */
/*   Updated: 2021/04/29 16:38:33 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_forward_back(t_cub *cub)
{
	if (cub->ray.forward == 1)
	{
		if (cub->map[(int)(cub->ray.posx + (cub->ray.dirx *
					cub->ray.move_speed * 2))][(int)cub->ray.posy] == '0')
			cub->ray.posx += cub->ray.dirx * cub->ray.move_speed;
		if (cub->map[(int)(cub->ray.posx)][(int)(cub->ray.posy +
					(cub->ray.diry * cub->ray.move_speed * 2))] == '0')
			cub->ray.posy += cub->ray.diry * cub->ray.move_speed;
	}
	if (cub->ray.back == 1)
	{
		if (cub->map[(int)(cub->ray.posx - (cub->ray.dirx *
					cub->ray.move_speed * 2))][(int)(cub->ray.posy)] == '0')
			cub->ray.posx -= cub->ray.dirx * cub->ray.move_speed;
		if (cub->map[(int)(cub->ray.posx)][(int)(cub->ray.posy -
					(cub->ray.diry * cub->ray.move_speed * 2))] == '0')
			cub->ray.posy -= cub->ray.diry * cub->ray.move_speed;
	}
}

void	ft_left_right(t_cub *cub)
{
	if (cub->ray.right == 1)
	{
		if (cub->map[(int)(cub->ray.posx + cub->ray.diry *
					(cub->ray.move_speed * 2))][(int)cub->ray.posy] == '0')
			cub->ray.posx += cub->ray.diry * cub->ray.move_speed;
		if (cub->map[(int)cub->ray.posx][(int)(cub->ray.posy -
					cub->ray.dirx * (cub->ray.move_speed * 2))] == '0')
			cub->ray.posy -= cub->ray.dirx * cub->ray.move_speed;
	}
	if (cub->ray.left == 1)
	{
		if (cub->map[(int)(cub->ray.posx - cub->ray.diry *
					(cub->ray.move_speed * 2))][(int)cub->ray.posy] == '0')
			cub->ray.posx -= cub->ray.diry * cub->ray.move_speed;
		if (cub->map[(int)cub->ray.posx][(int)(cub->ray.posy +
					cub->ray.dirx * (cub->ray.move_speed * 2))] == '0')
			cub->ray.posy += cub->ray.dirx * cub->ray.move_speed;
	}
}

void	ft_rotate_left(t_cub *cub, double olddirx, double oldplanex)
{
	cub->ray.dirx = cub->ray.dirx * cos(cub->ray.rot_speed / 2) -
		cub->ray.diry * sin(cub->ray.rot_speed / 2);
	cub->ray.diry = olddirx * sin(cub->ray.rot_speed / 2) +
		cub->ray.diry * cos(cub->ray.rot_speed / 2);
	cub->ray.planex = cub->ray.planex * cos(cub->ray.rot_speed / 2) -
		cub->ray.planey * sin(cub->ray.rot_speed / 2);
	cub->ray.planey = oldplanex * sin(cub->ray.rot_speed / 2) +
		cub->ray.planey * cos(cub->ray.rot_speed / 2);
}

void	ft_rotate_right(t_cub *cub, double olddirx, double oldplanex)
{
	cub->ray.dirx = cub->ray.dirx * cos(-cub->ray.rot_speed / 2) -
		cub->ray.diry * sin(-cub->ray.rot_speed / 2);
	cub->ray.diry = olddirx * sin(-cub->ray.rot_speed / 2) +
		cub->ray.diry * cos(-cub->ray.rot_speed / 2);
	cub->ray.planex = cub->ray.planex * cos(-cub->ray.rot_speed / 2)
		- cub->ray.planey * sin(-cub->ray.rot_speed / 2);
	cub->ray.planey = oldplanex * sin(-cub->ray.rot_speed / 2) +
		cub->ray.planey * cos(-cub->ray.rot_speed / 2);
}

void	ft_rotate_right_left(t_cub *cub)
{
	double oldplanex;
	double olddirx;

	if (cub->ray.rotate_right == 1)
	{
		oldplanex = cub->ray.planex;
		olddirx = cub->ray.dirx;
		ft_rotate_right(cub, olddirx, oldplanex);
	}
	if (cub->ray.rotate_left == 1)
	{
		olddirx = cub->ray.dirx;
		oldplanex = cub->ray.planex;
		ft_rotate_left(cub, olddirx, oldplanex);
	}
}
