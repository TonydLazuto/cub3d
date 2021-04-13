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
    cub->player = NULL;
	cub->mlx_ptr = NULL;
	cub->win_ptr = NULL;
    cub->texture[0].img = NULL;
	cub->texture[1].img = NULL;
	cub->texture[2].img = NULL;
	cub->texture[3].img = NULL;
	cub->texture[4].img = NULL;
}

void	destroy_all(t_cub *cub)
{
    //mlx_destroy_image(); //des textures
    mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
		cub->win_ptr = NULL;
    //mlx_destroy_display(cub->mlx_ptr); //LINUX
	free(cub->mlx_ptr);
    cub->mlx_ptr = NULL;
}

int		handle_keypress(int keysym, t_cub *cub)
{
	printf("Keypress |%d|\n", keysym);
	if (keysym == 53)
        destroy_all(cub);
    if (keysym == 13 || keysym == 0 || keysym == 1 || keysym == 2) 
        ;
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
	if (!(cub.win_ptr = mlx_new_window(cub.mlx_ptr, cub.width, cub.height, "Mon titre")))
	{
		free(cub.win_ptr);
		return (0);
	}
	cub.img.img = mlx_new_image(cub.mlx_ptr, cub.width, cub.height);
    cub.img.addr = mlx_get_data_addr(cub.img.img, &(cub.img.bits_per_pixel), &(cub.img.line_length), &(cub.img.endian));
    cub.player = find_player(cub.map, cub.player);
    ft_mlx(&cub);
	//mlx_loop_hook(cub.mlx_ptr, &draw_2d_map, &cub);
	mlx_hook(cub.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &cub);

	mlx_put_image_to_window(cub.mlx_ptr, cub.win_ptr, cub.img.img, 0, 0);
	mlx_loop(cub.mlx_ptr);
	destroy_all(&cub);
	return (0);
}
