#include "cub3d.h"

void		map_frame(t_cub *cub, t_data *data, t_point *map_points)
{
	t_point	*player;
    double cameraX;
    double rayDirX;
    double rayDirY;

    cameraX = 2 * player->x / (double)player->y - 1; //x-coordinate in camera space
    rayDirX = data->dirX + data->planeX * cameraX;
    rayDirY = data->dirY + data->planeY * cameraX;
	if (!(player = new_point(map_points->x, map_points->y, map_points->val)))
		return ;
	//printf("|----------------------|\n");
	//print_points(player);
	map_points = map_points->next;
	while (map_points)
	{
		map_points = get_pos_relative(map_points, player);
		draw_elemt(cub, map_points);
		map_points = map_points->next;
	}
    draw_elemt(cub, player);
}