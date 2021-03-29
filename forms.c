#include "cub3d.h"

void    draw_square(int x, int y, t_cub *cub, int color)
{
    int		i;
	int		j;

	j = -10;
    while (j < 9)
	{
		i = -10;
		while (i < 9)
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

	j = -2;
    while (j < 1)
	{
		i = -2;
		while (i < 1)
		{
			my_mlx_pixel_put(&cub->img, x + i, y + j, color);
            i++;
		}
		j++;
	}
}