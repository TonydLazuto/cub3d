#include "cub3d.h"

int		get_color(t_point *map_points, t_cub cub)
{
	int color;

	color = 0;
	if (map_points->val == '0' || ft_isalpha(map_points->val)){
		color = cub.floor;}
	else if (map_points->val == '1')
		color = 0x636873;
	else if (map_points->val == '2')
		color = 0x319954;
	return (color);
}
void	draw_elemt(t_cub *cub, t_point *map_points)
{
	int		x;
	int		y;
	int		color;

    x = cub->width / 2;
	y = cub->height / 2;
    color = get_color(map_points, *cub);
    if (ft_isalpha(map_points->val))
    {
	    draw_square(x, y, cub, color);
        color = 0xC11515;
	    draw_little_square(x, y, cub, color);
    }
    else
    {
        x += map_points->y * 20;
	    y += map_points->x * 20;
	    draw_square(x, y, cub, color);
    }
}

t_point		*get_pos_relative(t_point *map_points, t_point *player)
{
	map_points->x = map_points->x - player->x;
	map_points->y = map_points->y - player->y;
	return (map_points);
}

void		draw(t_cub *cub, t_point *map_points)
{
	t_point	*player;

	if (!(player = new_point(map_points->x, map_points->y, map_points->val)))
		return ;
	//printf("|----------------------|\n");
	//print_points(player);
	//cub->img.img = mlx_new_image(cub->mlx_ptr, cub->width, cub->height);
    //cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel, &cub->img.line_length, &cub->img.endian);
	map_points = map_points->next;
	while (map_points)
	{
		map_points = get_pos_relative(map_points, player);
		draw_elemt(cub, map_points);
		map_points = map_points->next;
	}
    draw_elemt(cub, player);
	//mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img.img, 0, 0);
}