/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 07:44:51 by tonyd             #+#    #+#             */
/*   Updated: 2021/05/02 07:44:54 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		start_parse_map(t_cub *cub, char **line, size_t *num_param)
{
	size_t	len_map;
	size_t	i;
	size_t	j;

	j = 0;
	i = num_param[8];
	len_map = i;
	while (line[len_map])
		len_map++;
	if (!(cub->map = malloc(sizeof(char *) * (len_map - i + 1))))
		return (-1);
	while (line[i])
	{
		cub->map[j] = ft_strdup(line[i]);
		if (!cub->map[j])
			return (-1);
		i++;
		j++;
	}
	cub->map[j] = NULL;
	if (parse_map(cub, cub->map) == -1)
		return (-1);
	return (0);
}
