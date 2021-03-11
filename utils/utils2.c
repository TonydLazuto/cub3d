#include "../cub3d.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		deal_key(int key, void *param)
{
	ft_putnbr_fd(key, 1);
	param = NULL;
	return (0);
}