/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:37:53 by tonyd             #+#    #+#             */
/*   Updated: 2021/04/29 16:37:54 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		check_map_chars(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (!is_in_charset(map[j][i], "012NSEW "))
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

t_point			*find_player(char **map, t_point *player, int nb_players)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S'
					|| map[j][i] == 'E' || map[j][i] == 'W')
			{
				nb_players++;
				if (is_empty_lst(player))
				{
					if (!(player = new_point(i, j, map[j][i])))
						return (NULL);
				}
			}
			i++;
		}
		j++;
	}
	return (nb_players == 1 ? player : NULL);
}

static t_point	*spread_one(t_cub *cub, char **map,
						t_point *stack2, t_point *visited)
{
	if ((stack2->val == '0' || stack2->val == 2)
			&& !is_point_in_list(visited, stack2))
		visited = spread_map(cub, map, stack2, visited);
	else
	{
		free(stack2);
		stack2 = NULL;
	}
	return (visited);
}

static t_point	*spread_all_points(t_cub *cub, char **map, t_point *visited)
{
	int		i;
	int		j;
	t_point	*stack2;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (!(stack2 = new_point(i, j, map[j][i])))
				ft_error(cub, "Malloc stack2 --> spread_all_points()");
			visited = spread_one(cub, map, stack2, visited);
			i++;
		}
		j++;
	}
	return (visited);
}

int				parse_map(t_cub *cub, char **map)
{
	t_point	*player;
	t_point	*visited;
	int		nb_players;

	player = NULL;
	visited = NULL;
	nb_players = 0;
	if (check_map_chars(map) == -1)
		ft_error(cub, "Unexpected characters in total map.");
	player = find_player(map, player, nb_players);
	if (!player)
		ft_error(cub, "The player may not exists \
							or there is multiple players.");
	visited = spread_map(cub, map, player, visited);
	if (!visited)
		return (-1);
	visited = spread_all_points(cub, map, visited);
	if (!visited)
		return (-1);
	clear_points(&visited);
	return (0);
}
