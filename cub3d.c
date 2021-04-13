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
    ft_init_more(cub);
}

int     main(int ac, const char *av[])
{
	t_cub	cub;

    init_cub(&cub);
	if ((check_valid_cub(ac, av, &cub)) == -1)
		return (0);
	if (!(cub.mlx_ptr = mlx_init()))
    {
        ft_error(&cub, "mlx_init\n");
		ft_exit(&cub);
    }
    //|  Linux  |
    //mlx_get_screen_size(cub.mlx_ptr, &cub.screen_width, &cub.screen_height);
	//cub.width = (cub.width > cub.screen_width) ? cub.screen_width : cub.width;
	//cub.height = (cub.height > cub.screen_height) ? cub.screen_height : cub.height;
	if (!(cub.win_ptr = mlx_new_window(cub.mlx_ptr, cub.width, cub.height, "Mon titre")))
	{
        ft_error(&cub, "mlx_new_window\n");
		ft_exit(&cub);
	}
    cub.player = find_player(cub.map, cub.player);
    ft_mlx(&cub);
	return (0);
}
