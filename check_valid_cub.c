/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_cub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:24:22 by tonyd             #+#    #+#             */
/*   Updated: 2021/04/29 18:24:23 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*file_to_string(int fd, t_cub *cub)
{
	char	*full_file;
	char	*line;

	line = NULL;
	full_file = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		full_file = strjoinfree(full_file, line, cub);
		if (!full_file)
			return (NULL);
		full_file = strjoinfree(full_file, "\n", cub);
		if (!full_file)
			return (NULL);
		ft_free(&line);
	}
	if (line[0] != '\0')
	{
		full_file = strjoinfree(full_file, line, cub);
		if (!full_file)
			return (NULL);
	}
	ft_free(&line);
	return (full_file);
}

static int	parse_file(const char *map_file, t_cub *cub)
{
	int		fd;
	char	*file;

	file = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		ft_error(cub, "File .cub -> (Maybe doesn't exists)");
	file = file_to_string(fd, cub);
	close(fd);
	if (!file)
		ft_error(cub, "While malloc the gnl in a string");
	if (split_file(file, cub) == -1)
		ft_error(cub, "Split file");
	return (0);
}

static void	cmp_ext(t_cub *cub, const char *av)
{
	size_t	len;
	char	*ext;
	int		res_cmp;

	len = ft_strlen(av);
	ext = ft_substr(av, len - 4, len);
	if (!ext)
		ft_error(cub, "Malloc extension.");
	res_cmp = ft_strncmp(ext, ".cub", 4);
	ft_free(&ext);
	if (res_cmp)
		ft_error(cub, "File extension.");
}

int			check_valid_cub(int ac, const char **av, t_cub *cub)
{
	if (ac == 2 || ac == 3)
	{
		cmp_ext(cub, av[1]);
		if (parse_file(av[1], cub) == -1)
			return (-1);
		if (ac == 3)
		{
			if (ft_strncmp(av[2], "--save", 6) == 0)
				cub->save = 1;
			else
				ft_error(cub, "Wrong third argument");
		}
	}
	else
		ft_error(cub, "Wrong number of arguments");
	return (0);
}
