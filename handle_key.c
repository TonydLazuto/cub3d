/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:37:24 by tonyd             #+#    #+#             */
/*   Updated: 2021/04/29 16:37:25 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_key_press(int keycode, t_cub *cub)
{
	if (keycode == FORWARD_W_Z)
		cub->ray.forward = 1;
	else if (keycode == BACK_S_S)
		cub->ray.back = 1;
	else if (keycode == LEFT_A_Q)
		cub->ray.left = 1;
	else if (keycode == RIGHT_D_D)
		cub->ray.right = 1;
	else if (keycode == ROTATE_LEFT)
		cub->ray.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		cub->ray.rotate_right = 1;
	else if (keycode == ESCAPE_E)
		ft_exit(cub);
	return (1);
}

int		ft_key_release(int keycode, t_cub *cub)
{
	if (keycode == FORWARD_W_Z)
		cub->ray.forward = 0;
	else if (keycode == BACK_S_S)
		cub->ray.back = 0;
	else if (keycode == LEFT_A_Q)
		cub->ray.left = 0;
	else if (keycode == RIGHT_D_D)
		cub->ray.right = 0;
	else if (keycode == ROTATE_LEFT)
		cub->ray.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		cub->ray.rotate_right = 0;
	return (1);
}
