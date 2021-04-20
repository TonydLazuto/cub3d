#include "cub3d.h"

void	ft_init_texture(t_cub *cub)
{
	if (cub->ray.side == 0 && cub->ray.rayDirX < 0)
		cub->t.texDir = 0;
	if (cub->ray.side == 0 && cub->ray.rayDirX >= 0)
		cub->t.texDir = 1;
	if (cub->ray.side == 1 && cub->ray.rayDirY < 0)
		cub->t.texDir = 2;
	if (cub->ray.side == 1 && cub->ray.rayDirY >= 0)
		cub->t.texDir = 3;
	if (cub->ray.side == 0)
		cub->t.wallX = cub->ray.posY + cub->ray.perpWallDist \
						* cub->ray.rayDirY;
	else
		cub->t.wallX = cub->ray.posX + cub->ray.perpWallDist \
						* cub->ray.rayDirX;
	cub->t.wallX -= floor((cub->t.wallX));
}

void	ft_draw_texture(t_cub *cub, int x, int y)
{
	y = cub->ray.drawstart - 1;
	ft_init_texture(cub);
	cub->t.step = 1.0 * cub->texture[0].height / cub->ray.lineheight;
	cub->t.texX = (int)(cub->t.wallX * (double)cub->texture
			[cub->t.texDir].width);
	if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
		cub->t.texX = cub->texture[cub->t.texDir].width -
			cub->t.texX - 1;
	if (cub->ray.side == 1 && cub->ray.rayDirY < 0)
		cub->t.texX = cub->texture[cub->t.texDir].width -
			cub->t.texX - 1;
	cub->t.texPos = (cub->ray.drawstart - cub->height / 2 +
			cub->ray.lineheight / 2) * cub->t.step;
	while (++y <= cub->ray.drawend)
	{
		cub->t.texY = (int)cub->t.texPos &
			(cub->texture[cub->t.texDir].height - 1);
		cub->t.texPos += cub->t.step;
		if (y < cub->height && x < cub->width)
			cub->img.addr[y * cub->img.line_length / 4 + x] =
				cub->texture[cub->t.texDir].addr[cub->t.texY *
					cub->texture[cub->t.texDir].line_length /
					4 + cub->t.texX];
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