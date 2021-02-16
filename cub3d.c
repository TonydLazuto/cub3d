#include "cub3d.h"

void	init_cub(t_cub *cub)
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
}

int     main(int ac, const char *av[])
{
	t_ptr	ptr;
	t_cub	cub;

	init_cub(&cub);
	if ((check_valid_cub(ac, av, &cub)) == -1)
		return (0);
	ptr.mlx = mlx_init();
	if (!(ptr.win = mlx_new_window(ptr.mlx, cub.width, cub.height, "Mon titre")))
		return (0);
//	img.img = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	parse_file(ptr);
//	mlx_put_image_to_window(ptr.mlx, ptr.win, img.img, 10, 0);
//	mlx_key_hook(ptr.win, deal_key, ptr.win);
	mlx_loop(ptr.mlx);
//	mlx_clear_window(mlx_ptr, win_ptr);
	return (0);
}