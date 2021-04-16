#include "cub3d.h"

/*
void	ft_init_sprite2(t_cub *cub, int i, int j, int v)
{
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '2')
			{
				cub->sxy[v].x = (double)i + 0.5;
				cub->sxy[v].y = (double)j + 0.5;
				v++;
			}
            j++;
		}
        i++;
	}
}

void	ft_init_sprite(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	cub->s.nbspr = 0;
	while (cub->map[i])// a voir
	{
		j = 0;
		while (cub->map[i][j]) // a voir
		{
			if (cub->map[i][j] == '2')
				cub->s.nbspr += 1;
            j++;
		}
        i++;
	}
	if (!(cub->sxy = (t_sprxy *)malloc(sizeof(t_sprxy) * cub->s.nbspr)))
		ft_error(cub, "Malloc sxy*");
	if (!(cub->s.order = (int *)malloc(sizeof(int) * cub->s.nbspr)))
		ft_error(cub, "Malloc s.order*");
	if (!(cub->s.dist = (double *)malloc(sizeof(double) * cub->s.nbspr)))
		ft_error(cub, "Malloc s.dist*");
	ft_init_sprite2(cub, 0, 0, 0);
}*/