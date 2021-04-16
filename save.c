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
	if ((fd = open("./image.bmp", O_CREAT | O_RDWR)) == -1)
		ft_error(cub, "Impossible de creer .bmp\n");
	//ft_header(cub, fd);
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
	//system("chmod 777 image.bmp");
    close(fd);
    ft_exit(0);
}