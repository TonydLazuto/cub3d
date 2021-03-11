#include "cub3d.h"
/*
void	draw_sprite(t_cub cub, t_ptr ptr, t_point *player, t_point *map_points)
{
	int		x;
	int		y;
	t_data	img;
	int		color;

	x = cub.width / 2 + ((map_points->x - player->x) * 20);
	y = cub.height / 2 + ((map_points->y - player->y) * 20);
	color = 0x4B0399;
	img.img = mlx_new_image(ptr.mlx, cub.width, cub.height);
    img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pixel), &(img.line_length), &(img.endian));
	img = draw_square(x, y, img, color);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img.img, 0, 0);
}

void	draw_wall(t_cub cub, t_ptr ptr, t_point *player, t_point *map_points)
{
	int		x;
	int		y;
	t_data	img;
	int		color;

	x = cub.width / 2 + ((map_points->x - player->x) * 20);
	y = cub.height / 2 + ((map_points->y - player->y) * 20);
	color = 0x636873;
	img.img = mlx_new_image(ptr.mlx, cub.width, cub.height);
    img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pixel), &(img.line_length), &(img.endian));
	img = draw_square(x, y, img, color);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img.img, 0, 0);
}
*/
void	draw_floor(t_cub cub, t_ptr ptr, int *pos_relative)
{
	int		x;
	int		y;
	t_data	img;
	int		color;

	x = cub.width / 2 + pos_relative[0];
	y = cub.height / 2 + pos_relative[1];
	color = 0xEAEDF4;
	printf("Hey\n");
	img.img = mlx_new_image(ptr.mlx, cub.width, cub.height);
	printf("Hey\n");
    img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pixel), &(img.line_length), &(img.endian));
	printf("Hey\n");
	img = draw_square(x, y, img, color);
	printf("Hey\n");
	mlx_put_image_to_window(ptr.mlx, ptr.win, img.img, 0, 0);
	printf("Hey\n");
}
void	draw_pers(t_cub cub, t_ptr ptr)
{
	int		x;
	int		y;
	t_data	img;
	int		color;

	x = cub.width / 2;
	y = cub.height / 2;
	color = 0xC11515;
	img.img = mlx_new_image(ptr.mlx, cub.width, cub.height);
    img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pixel), &(img.line_length), &(img.endian));
	my_mlx_pixel_put(&img, x, y, create_trgb(0, 31, 133, 222));
	img = draw_square(x, y, img, color);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img.img, 0, 0);
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

	if (!(player = new_point(map_points->x, map_points->y, map_points->val)))
		return ;
	draw_pers(cub, ptr);
	pop_front_point(&map_points);
	printf("|----------------------|\n");
	print_points(map_points);
	//while (map_points)
	//{
		//map_points = get_pos_relative(map_points, player);
		//if (map_points->val == '0')
			//draw_floor(cub, ptr, pos_relative);
		/*else if (map_points->val == '1')
			draw_wall(cub, ptr, pos_relative);
		else if (map_points->val == '2')
			draw_sprite(cub, ptr, pos_relative);*/
		pop_front_point(&map_points);
	//}
}