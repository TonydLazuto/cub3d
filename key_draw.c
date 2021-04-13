#include "cub3d.h"

int		ft_key_press(int keycode, t_cub *cub)
{
	if (keycode == FORWARD_W_Z)
		cub->ray.forward = 1;
	else if (keycode == BACK_S_S)
		cub->ray.back = 1;
	else if (keycode == LEFT_A_Q)
		cub->ray.left = 1;
	else if (keycode == RIGHT_D_D)
		cub->ray.right = 1;
	else if (keycode == ROTATE_LEFT)
		cub->ray.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		cub->ray.rotate_right = 1;
	return (1);
}

int		ft_key_release(int keycode, t_cub *cub)
{
	if (keycode == FORWARD_W_Z)
		cub->ray.forward = 0;
	else if (keycode == BACK_S_S)
		cub->ray.back = 0;
	else if (keycode == LEFT_A_Q)
		cub->ray.left = 0;
	else if (keycode == RIGHT_D_D)
		cub->ray.right = 0;
	else if (keycode == ROTATE_LEFT)
		cub->ray.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		cub->ray.rotate_right = 0;
	return (1);
}

void	ft_draw_texture(t_cub *cub, int x, int y)
{
	y = cub->ray.drawstart - 1;
	ft_init_texture(cub);
	cub->t.step = 1.0 * cub->texture[0].height / cub->ray.lineheight;
	cub->t.texx = (int)(cub->t.wallx * (double)cub->texture
			[cub->t.texdir].width);
	if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
		cub->t.texx = cub->texture[cub->t.texdir].width -
			cub->t.texx - 1;
	if (cub->ray.side == 1 && cub->ray.rayDirY < 0)
		cub->t.texx = cub->texture[cub->t.texdir].width -
			cub->t.texx - 1;
	cub->t.texpos = (cub->ray.drawstart - cub->height / 2 +
			cub->ray.lineheight / 2) * cub->t.step;
	while (++y <= cub->ray.drawend)
	{
		cub->t.texy = (int)cub->t.texpos &
			(cub->texture[cub->t.texdir].height - 1);
		cub->t.texpos += cub->t.step;
		if (y < cub->height && x < cub->width)
			cub->img.addr[y * cub->img.line_length / 4 + x] =
				cub->texture[cub->t.texdir].addr[cub->t.texy *
					cub->texture[cub->t.texdir].line_length /
					4 + cub->t.texx];
	}
}

int		ft_color_column(t_cub *cub)
{
	int j;
	int i;

	j = -1;
	cub->ray.drawend = cub->height - cub->ray.drawstart;
	i = cub->ray.drawend;
	while (++j < cub->ray.drawstart)
		cub->img.addr[j * cub->img.line_length / 4 +
			cub->ray.x] = cub->ceiling;
	if (j <= cub->ray.drawend)
		ft_draw_texture(cub, cub->ray.x, j);
	j = i;
	while (++j < cub->height)
		cub->img.addr[j * cub->img.line_length / 4 +
			cub->ray.x] = cub->floor;
	return (0);
}