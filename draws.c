#include "cub3d.h"

int		get_color(t_point *map_points)
{
	int color;

	color = 0;
	if (map_points->val == '0')
		color = 0xEAEDF4;
	else if (map_points->val == '1')
		color = 0x636873;
	else if (map_points->val == '2')
		color = 0x4B0399;
	return (color);
}
void	draw_elemt(t_cub cub, t_point *map_points, t_data img)
{
	int		x;
	int		y;
	int		color;

	x = cub.width / 2 + map_points->y * 20;
	y = cub.height / 2 + map_points->x * 20;
	color = get_color(map_points);
	img = draw_square(x, y, img, color);
}
void	draw_pers(t_cub cub, t_data img)
{
	int		x;
	int		y;
	int		color;

	x = cub.width / 2;
	y = cub.height / 2;
	color = 0xC11515;
	my_mlx_pixel_put(&img, x, y, create_trgb(0, 31, 133, 222));
	img = draw_square(x, y, img, color);
}

t_point		*get_pos_relative(t_point *map_points, t_point *player)
{
	map_points->x = map_points->x - player->x;
	map_points->y = map_points->y - player->y;
	return (map_points);
}

void		draw(t_ptr ptr, t_cub cub, t_point *map_points)
{
	t_point	*player;
	t_data	img;

	if (!(player = new_point(map_points->x, map_points->y, map_points->val)))
		return ;
	//printf("|----------------------|\n");
	//print_points(player);
	img.img = mlx_new_image(ptr.mlx, cub.width, cub.height);
    img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pixel), &(img.line_length), &(img.endian));
	draw_pers(cub, img);
	map_points = map_points->next;
	print_points(map_points);
	while (map_points)
	{
		map_points = get_pos_relative(map_points, player);
		draw_elemt(cub, map_points, img);
		map_points = map_points->next;
	}
	mlx_put_image_to_window(ptr.mlx, ptr.win, img.img, 0, 0);
}