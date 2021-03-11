#include "cub3d.h"

void	init_cub_ptr(t_cub *cub, t_ptr *ptr)
{
	cub->width = 0;
	cub->height = 0;
	cub->north_path = NULL;
	cub->south_path = NULL;
	cub->west_path = NULL;
	cub->east_path = NULL;
	cub->sprite_path = NULL;
	cub->floor = 0;
	cub->ceiling = 0;
	cub->map = NULL;
	ptr->mlx = NULL;
	ptr->win = NULL;
}

void	draw_map(t_cub cub, t_ptr ptr)
{
	t_point *map_points;
	t_point *player;

	player = NULL;
	map_points = NULL;
	if (!(player = find_player(cub.map, player)))
		return ;
	if (!(map_points = spread_map(cub.map, player, map_points)))
		return ;
	draw(ptr, cub, map_points);
}

int     main(int ac, const char *av[])
{
	t_ptr	ptr;
	t_cub	cub;

	init_cub_ptr(&cub, &ptr);
	if ((check_valid_cub(ac, av, &cub, ptr)) == -1)
		return (0);
	ptr.mlx = mlx_init();
	if (!(ptr.win = mlx_new_window(ptr.mlx, cub.width, cub.height, "Mon titre")))
		return (0);
	draw_map(cub, ptr);
//	mlx_key_hook(ptr.win, deal_key, ptr.win);
	mlx_loop(ptr.mlx);
//	mlx_clear_window(mlx_ptr, win_ptr);
	return (0);
}