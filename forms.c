#include "cub3d.h"

t_data    draw_square(int x, int y, t_data img, int color)
{
    int		i;
	int		j;

	j = -10;
    while (j < 10)
	{
		i = -10;
        my_mlx_pixel_put(&img, x + i, y + j, color);
        i++;
		while (i < 9)
		{
            if (j == -10 || j == 9)
			    my_mlx_pixel_put(&img, x + i, y + j, color);
            i++;
		}
        my_mlx_pixel_put(&img, x + i, y + j, color);
		j++;
	}
	return (img);
}