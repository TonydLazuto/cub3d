/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:36:04 by tonyd             #+#    #+#             */
/*   Updated: 2021/04/29 16:36:09 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub(t_cub *cub)
{
	cub->width = 0;
	cub->height = 0;
	cub->img.img = NULL;
	cub->img.addr = NULL;
	cub->north = NULL;
	cub->south = NULL;
	cub->east = NULL;
	cub->west = NULL;
	cub->sprite = NULL;
	cub->map = NULL;
	cub->player = NULL;
	cub->mlx_ptr = NULL;
	cub->win_ptr = NULL;
	cub->texture[0].img = NULL;
	cub->texture[1].img = NULL;
	cub->texture[2].img = NULL;
	cub->texture[3].img = NULL;
	cub->texture[4].img = NULL;
	cub->img.img = NULL;
	cub->s.order = NULL;
	cub->s.dist = NULL;
	cub->s.zBuffer = NULL;
	cub->sxy = NULL;
}

int     main(int ac, const char *av[])
{
	t_cub	cub;

	init_cub(&cub);
	if ((check_valid_cub(ac, av, &cub)) == -1)
		return (0);
	cub.player = find_player(cub.map, cub.player);
	ft_mlx(&cub);
	return (0);
}
