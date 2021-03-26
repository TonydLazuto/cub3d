#include "cub3d.h"

void	init_cub(t_cub *cub)
{
    cub->width = 0;
    cub->height = 0;
    cub->img.img = NULL;
    cub->img.addr = NULL;
    cub->north = NULL;
    cub->south = NULL;
    cub->east = NULL;
    cub->west = NULL;
    cub->sprite = NULL;
	cub->map = NULL;
	cub->mlx_ptr = NULL;
	cub->win_ptr = NULL;
}

int     draw_2d_map(t_cub *cub)
{
	t_point	*map_points;
	t_point	*player;

	player = NULL;
	map_points = NULL;
	if (!(player = find_player(cub->map, player)))
		return (0);
	if (!(map_points = spread_map(cub->map, player, map_points)))
		return (0);
	draw(cub, map_points);
    //printf("|-----map_points-----|\n");
    //print_points(map_points);
    return (0);
}

void	destroy_all(t_cub *cub)
{
	//mlx_destroy_window(cub->mlx_ptr, cub->win_ptr); //Handled before?
	//mlx_destroy_display(cub->mlx_ptr); //LINUX
	free(cub->mlx_ptr);
}

int		handle_keypress(int keysym, t_cub *cub)
{
	printf("Keypress |%d|\n", keysym);
	if (keysym == 53)
	{
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
		cub->win_ptr = NULL;
	}
	return (0);
}

int		handle_keyrelease(int keysym)
{
	printf("Keyrelease |%d|\n", keysym);
	return (0);
}
/*
void	get_next_frame(t_img *img)
{
	t_point		*map_points;
	t_point		*player;
	t_cub		cub;
	//t_dir_plane dir_plane;

	player = NULL;
	map_points = NULL;
	if (!(player = find_player(cub.map, player)))
		return ;
	if (!(map_points = spread_map(cub.map, player, map_points)))
		return ;
	//scan(img, cub, map_points);
	return ;
}
*/
int     main(int ac, const char *av[])
{
	t_cub	cub;

    init_cub(&cub);
	if ((check_valid_cub(ac, av, &cub)) == -1)
		return (0);
	if (!(cub.mlx_ptr = mlx_init()))
		return (0);
	if (!(cub.win_ptr = mlx_new_window(cub.mlx_ptr, cub.width, cub.height, "Mon titre")))
	{
		free(cub.win_ptr);
		return (0);
	}
	//cub.img->img = mlx_new_image(cub.mlx_ptr, cub.width, cub.height);
    //cub.img->addr = mlx_get_data_addr(cub.img->img, &(cub.img->bits_per_pixel), &(cub.img->line_length), &(cub.img->endian));
	draw_2d_map(&cub);
	//mlx_loop_hook(cub.mlx_ptr, &draw_2d_map, &cub);
	mlx_hook(cub.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &cub);
	mlx_hook(cub.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &cub);
	
	//mlx_put_image_to_window(cub.mlx_ptr, cub.win_ptr, cub.img->img, 0, 0);
	mlx_loop(cub.mlx_ptr);
	destroy_all(&cub);
	return (0);
}