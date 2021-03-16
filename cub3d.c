#include "cub3d.h"

void	init_cub(t_cub *cub)
{
	t_res_text	res_text;
	t_path		path;

	res_text.width = 0;
	res_text.height = 0;
	path.north = NULL;
	path.south = NULL;
	path.west = NULL;
	path.east = NULL;
	path.sprite = NULL;
	res_text.floor = 0;
	res_text.ceiling = 0;
	cub->path = path;
	cub->res_text = res_text;
	cub->map = NULL;
	cub->mlx_ptr = NULL;
	cub->win_ptr = NULL;
}

void	draw_2d_map(t_cub cub)
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
	draw(cub, map_points);
	print_points(map_points);
	//start(dir_plane, player);
}

void	destroy_all(t_cub *cub)
{
	//mlx_destroy_window(cub->mlx_ptr, cub->win_ptr); //Handle before?
	//mlx_destroy_display(cub->mlx_ptr); //LINUX
	free(cub->mlx_ptr);
}

int		get_next_frame(void *data)
{
	(void)(data);
	return (0);
}
int		handle_keypress(int keysym, t_cub *cub)
{
	printf("Keypress |%d|\n", keysym);
	if (keysym == 53)
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	return (0);
}
int		handle_keyrelease(int keysym)
{
	printf("Keyrelease |%d|\n", keysym);
	return (0);
}

int     main(int ac, const char *av[])
{
	t_cub	cub;

	init_cub(&cub);
	if ((check_valid_cub(ac, av, &cub)) == -1)
		return (0);
	if (!(cub.mlx_ptr = mlx_init()))
		return (0);
	if (!(cub.win_ptr = mlx_new_window(cub.mlx_ptr, cub.res_text.width, cub.res_text.height, "Mon titre")))
	{
		free(cub.win_ptr);
		return (0);
	}
	draw_2d_map(cub);
	mlx_loop_hook(cub.mlx_ptr, &get_next_frame, &cub);
	mlx_hook(cub.win_ptr, KeyPress, KeyPressMask, &handle_keyrelease, &cub);
	mlx_hook(cub.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &cub);

	mlx_loop(cub.mlx_ptr);
	destroy_all(&cub);
	return (0);
}