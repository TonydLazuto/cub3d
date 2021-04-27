#include "cub3d.h"

void	ft_freemore(t_cub *cub)
{
	int		i;

	i = 0;
	if (cub->map)
	{
		while (cub->map[i])
        {
			free(cub->map[i]);
            i++;
        }
	}
	if (cub->map)
		free(cub->map);
	if (cub->s.order)
		free(cub->s.order);
	if (cub->s.dist)
		free(cub->s.dist);
	if (cub->sxy)
		free(cub->sxy);
	if (cub->s.zBuffer)
		free(cub->s.zBuffer);
}

void	ft_freetext(t_cub *cub)
{
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
}

int		ft_exit(t_cub *cub)
{
	ft_freetext(cub);
	ft_freemore(cub);
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
	if (cub->img.img)
		mlx_destroy_image(cub->mlx_ptr, cub->img.img);
	if (cub->win_ptr)
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	if (cub->mlx_ptr)
		mlx_destroy_display(cub->mlx_ptr);
	free(cub->mlx_ptr);
	exit(0);
}

void	ft_error(t_cub *cub, char *str)
{
	//write(1, "Error\n", 6);
    ft_putendl_fd("Error", 1);
    ft_putendl_fd(str, 1);
	//write(1, str, ft_strlen(str));
	ft_exit(cub);
}
