/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:38:46 by tonyd             #+#    #+#             */
/*   Updated: 2021/04/29 16:38:47 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_header(t_cub *cub, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * cub->width * cub->height;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &cub->width, 4);
	write(fd, &cub->height, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &cub->img.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void	ft_save(t_cub *cub)
{
	int	fd;
	int	x;
	int	y;

	y = 0;
	if ((fd = open("./map--save.bmp", O_CREAT | O_RDWR)) == -1)
		ft_error(cub, "saving map.\n");
	ft_header(cub, fd);
	while (y < cub->height)
	{
		x = 0;
		while (x < cub->width)
		{
			write(fd, &cub->img.addr[y * cub->img.line_length / 4 + x],
				4);
			x++;
		}
		y++;
	}
	system("chmod 777 map--save.bmp");
	close(fd);
	ft_exit(cub);
}
