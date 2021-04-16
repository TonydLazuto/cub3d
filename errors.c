#include "cub3d.h"

int		ft_exit(t_cub *cub)
{
	if (cub->img.img)
		mlx_destroy_image(cub->mlx_ptr, cub->img.img);
	if (cub->texture[0].img)
		mlx_destroy_image(cub->mlx_ptr, cub->texture[0].img);
	if (cub->texture[1].img)
		mlx_destroy_image(cub->mlx_ptr, cub->texture[1].img);
	if (cub->texture[2].img)
		mlx_destroy_image(cub->mlx_ptr, cub->texture[2].img);
	if (cub->texture[3].img)
		mlx_destroy_image(cub->mlx_ptr, cub->texture[3].img);
	if (cub->texture[4].img)
		mlx_destroy_image(cub->mlx_ptr, cub->texture[4].img);
	if (cub->win_ptr)
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	exit(0);
}

void	ft_error2(t_cub *cub)
{
	if (cub->map)
		free(cub->map);
    /*
	if (cub->s.order)
		free(cub->s.order);
	if (cub->s.dist)
		free(cub->s.dist);
	if (cub->sxy)
		free(cub->sxy);
	if (cub->s.zbuffer)
		free(cub->s.zbuffer);
    */
	ft_exit(cub);
}

void	ft_error(t_cub *cub, const char *str)
{
	int i;

	i = 0;
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	if (cub->north)
		free(cub->north);
	if (cub->south)
		free(cub->south);
	if (cub->west)
		free(cub->west);
	if (cub->east)
		free(cub->east);
	if (cub->sprite)
		free(cub->sprite);
	if (cub->map)
	{
		while (cub->map[i])
        {
			free(cub->map[i]);
            i++;
        }
	}
	ft_error2(cub);
}