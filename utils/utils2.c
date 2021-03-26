#include "../cub3d.h"


void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int*)dst = color;
}

int		deal_key(int key, void *param)
{
	(void)(param);
	ft_putnbr_fd(key, 1);
	param = NULL;
	return (0);
}
