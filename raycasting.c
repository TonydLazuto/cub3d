#include "cub3d.h"

void	ft_get_texture_adress(t_cub *cub)
{
	cub->texture[0].addr = (int *)mlx_get_data_addr(cub->texture[0].img,
			&cub->texture[0].bits_per_pixel,
			&cub->texture[0].line_length, &cub->texture[0].endian);
	cub->texture[1].addr = (int *)mlx_get_data_addr(cub->texture[1].img,
			&cub->texture[1].bits_per_pixel,
			&cub->texture[1].line_length, &cub->texture[1].endian);
	cub->texture[2].addr = (int *)mlx_get_data_addr(cub->texture[2].img,
			&cub->texture[2].bits_per_pixel,
			&cub->texture[2].line_length, &cub->texture[2].endian);
	cub->texture[3].addr = (int *)mlx_get_data_addr(cub->texture[3].img,
			&cub->texture[3].bits_per_pixel,
			&cub->texture[3].line_length, &cub->texture[3].endian);
	cub->texture[4].addr = (int *)mlx_get_data_addr(cub->texture[4].img,
			&cub->texture[4].bits_per_pixel,
			&cub->texture[4].line_length, &cub->texture[4].endian);
}

void	ft_get_texture(t_cub *cub)
{
	if (!(cub->texture[0].img = mlx_xpm_file_to_image(cub->mlx_ptr,
					cub->north, &(cub->texture[0].width),
					&(cub->texture[0].height))))
		ft_error(cub, "Texture NO\n");
	if (!(cub->texture[1].img = mlx_xpm_file_to_image(cub->mlx_ptr,
					cub->south, &(cub->texture[1].width),
					&(cub->texture[1].height))))
		ft_error(cub, "Texture SO\n");
	if (!(cub->texture[2].img = mlx_xpm_file_to_image(cub->mlx_ptr,
					cub->west, &(cub->texture[2].width),
					&(cub->texture[2].height))))
		ft_error(cub, "Texture WE\n");
	if (!(cub->texture[3].img = mlx_xpm_file_to_image(cub->mlx_ptr,
					cub->east, &(cub->texture[3].width),
					&(cub->texture[3].height))))
		ft_error(cub, "Texture EA\n");
	if (!(cub->texture[4].img = mlx_xpm_file_to_image(cub->mlx_ptr,
					cub->sprite, &(cub->texture[4].width),
					&(cub->texture[4].height))))
		ft_error(cub, "Texture S\n");
	ft_get_texture_adress(cub);
}

int		ft_raycasting(t_cub *cub)
{
	cub->ray.x = 0;
	while (cub->ray.x < cub->width)
	{
		ft_init2(cub);
		ft_stepsidedist(cub);
		ft_color_column(cub);
		cub->s.zBuffer[cub->ray.x] = cub->ray.perpWallDist;
		cub->ray.x++;
	}
    ft_sprite(cub);
	if (cub->save == 1)
		ft_save(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img.img, 0, 0);
	ft_forward_back(cub);
	ft_left_right(cub);
	ft_rotate_right_left(cub);
	return (0);
}

int     ft_resize()
{
    return (1);
}

int		ft_mlx(t_cub *cub)
{
    ft_init_sprite(cub);
    if (!(cub->mlx_ptr = mlx_init()))
        ft_error(cub, "mlx_init\n");
    //|  Linux  |
    mlx_get_screen_size(cub->mlx_ptr, &cub->screen_width, &cub->screen_height);
	cub->width = (cub->width > cub->screen_width) ? cub->screen_width : cub->width;
	cub->height = (cub->height > cub->screen_height) ? cub->screen_height : cub->height;
    cub->win_ptr = mlx_new_window(cub->mlx_ptr, cub->width, cub->height, "Cub3d");
    ft_get_texture(cub);
	cub->img.img = mlx_new_image(cub->mlx_ptr, cub->width, cub->height);
	cub->img.addr = (int *)mlx_get_data_addr(cub->img.img, &cub->img.
			bits_per_pixel, &cub->img.line_length, &cub->img.endian);
    ft_init(cub);
    if (cub->save == 1)
		ft_raycasting(cub);
    mlx_loop_hook(cub->mlx_ptr, ft_raycasting, cub);
    mlx_hook(cub->win_ptr, 33, 1L << 17, ft_exit, cub);
    mlx_hook(cub->win_ptr, 9, 1L << 21, ft_resize, cub);
	mlx_hook(cub->win_ptr, 2, 1L << 0, ft_key_press, cub);
	mlx_hook(cub->win_ptr, 3, 1L << 1, ft_key_release, cub);
	mlx_loop(cub->mlx_ptr);
	return (0);
}
