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

void	draw_2d_map(t_cub cub, t_ptr ptr)
{
	t_point *map_points;
	t_point *player;
	//t_dir_plane *dir_plane;

	player = NULL;
	map_points = NULL;
	if (!(player = find_player(cub.map, player)))
		return ;
	if (!(map_points = spread_map(cub.map, player, map_points)))
		return ;
	draw(ptr, cub, map_points);
	print_points(map_points);
	//start(dir_plane, player);
}

void	destroy_all(t_ptr *ptr)
{
	//mlx_destroy_window(ptr->mlx, ptr->win); //Handle before?
	//mlx_destroy_display(ptr->mlx); //LINUX
	free(ptr->mlx);
}

/*
int		handle_event(t_ptr *ptr)
{
	mlx_hook(ptr->win, 33, 1L << 17, &mlx_loop_end, ptr->mlx);
	//gestion croix rouge
	
	return (1);
}
*/
int		handle_no_event(void *data)
{
	(void)(data);
	return (0);
}
int		handle_keypress(int keysym, t_ptr *ptr)
{
	printf("Keypress |%d|\n", keysym);
	if (keysym == XK_Escape)
		mlx_destroy_window(ptr->mlx, ptr->win);
	return (0);
}
int		handle_keyrelease(int keysym)
{
	printf("Keyrelease |%d|\n", keysym);
	return (0);
}

int     main(int ac, const char *av[])
{
	t_ptr	ptr;
	t_cub	cub;

	init_cub_ptr(&cub, &ptr);
	if ((check_valid_cub(ac, av, &cub, ptr)) == -1)
		return (0);
	if (!(ptr.mlx = mlx_init()))
		return (0);
	if (!(ptr.win = mlx_new_window(ptr.mlx, cub.width, cub.height, "Mon titre")))
	{
		free(ptr.win);
		return (0);
	}
	draw_2d_map(cub, ptr);
	mlx_loop_hook(ptr.mlx, &handle_no_event, &ptr);
	mlx_hook(ptr.win, KeyPress, KeyPressMask, &handle_keyrelease, &ptr);
	mlx_hook(ptr.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &ptr);

	mlx_loop(ptr.mlx);
	destroy_all(&ptr);
	return (0);
}