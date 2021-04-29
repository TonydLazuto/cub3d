/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:37:58 by tonyd             #+#    #+#             */
/*   Updated: 2021/04/29 16:37:59 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		parse_resolution(char *line, t_cub *cub)
{
	char	*digit;
	size_t	j;

	j = 2;
	digit = NULL;
	digit = get_resolution(line, &j, cub);
	if ((cub->width = ft_atoi(digit)) == -1)
	{
		ft_free(&digit);
		ft_error(cub, "atoi width");
	}
	ft_free(&digit);
	digit = get_resolution(line, &j, cub);
	if ((cub->height = ft_atoi(digit)) == -1)
	{
		ft_free(&digit);
		ft_error(cub, "atoi height");
	}
	ft_free(&digit);
}

static void		parse_color(char *line, t_cub *cub)
{
	char	*digit;
	int		rgb[3];
	int		nb;
	size_t	j;

	j = 2;
	nb = 0;
	digit = NULL;
	while (nb < 3)
	{
		digit = get_rgb(line, &j, nb, cub);
		rgb[nb] = ft_atoi(digit);
		if (rgb[nb] < 0 || rgb[nb] > 255)
		{
			ft_free(&digit);
			ft_error(cub, "Range Color Rgb -> Floor or/and \
							Ceiling is incorrect.");
		}
		ft_free(&digit);
		nb++;
	}
	if (line[0] == 'F')
		cub->floor = create_trgb(0,rgb[0],rgb[1],rgb[2]);
	else
		cub->ceiling = create_trgb(0,rgb[0],rgb[1],rgb[2]);
}

static void		parse_path(char *line, t_cub *cub)
{
	if (line[0] == 'N' && line[1] == 'O')
		cub->north = get_path(line, cub, cub->north);
	else if (line[0] == 'S' && line[1] == 'O')
		cub->south = get_path(line, cub, cub->south);
	else if (line[0] == 'W' && line[1] == 'E')
		cub->west = get_path(line, cub, cub->west);
	else if (line[0] == 'E' && line[1] == 'A')
		cub->east = get_path(line, cub, cub->east);
	else if (line[0] == 'S' && line[1] == ' ')
		cub->sprite = get_path(line, cub, cub->sprite);
}

void			parse_param(char *line, t_cub *cub)
{
	if (line[0] == 'R' && line[1] == ' ')
		parse_resolution(line, cub);
	else if ((line[0] == 'F' || line[0] == 'C') && line[1] == ' ')
	   parse_color(line, cub);
	else if (((((line[0] == 'N' && line[1] == 'O') || (line[0] == 'S' && line[1] == 'O')
				|| (line[0] == 'W' && line[1] == 'E') || (line[0] == 'E' && line[1] == 'A'))
				&& line[2] == ' ')) || (line[0] == 'S' && line[1] == ' '))
		parse_path(line, cub);
	else
		ft_error(cub, "Unconventionnal map parameter.");
}
