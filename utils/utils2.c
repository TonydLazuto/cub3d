#include "../cub3d.h"


void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->img->addr + (y * cub->img->line_length + x * (cub->img->bits_per_pixel / 8));
	*(int*)dst = color;
}

int		deal_key(int key, void *param)
{
	(void)(param);
	ft_putnbr_fd(key, 1);
	param = NULL;
	return (0);
}
