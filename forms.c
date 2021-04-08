#include "cub3d.h"

void    draw_square(int x, int y, t_cub *cub, int color)
{
    int		i;
	int		j;

    while (j < 19)
	{
		i = -20;
		while (i < 19)
		{
			my_mlx_pixel_put(&cub->img, x + i, y + j, color);
            i++;
		}
		j++;
	}
}

void    draw_little_square(int x, int y, t_cub *cub, int color)
{
    int		i;
	int		j;

	j = -4;
    while (j <= 3)
	{
		i = -4;
		while (i <= 3)
		{
			my_mlx_pixel_put(&cub->img, x + i, y + j, color);
            i++;
		}
		j++;
	}
}