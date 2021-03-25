#include "../cub3d.h"

/*
--> delete the comparison inside parse_resolution() in parse_params.c
--> VOIR si mlx_get_screen_size() type "void" returns?
static void		resize_max_screen_size(t_cub *cub)
{
	int screen_width;
	int screen_height;

	screen_width = 0;
	screen_height = 0;
	mlx_get_screen_size(cub->mlx_ptr, &screen_width, &screen_height);
	if (cub->width > screen_width)
		cub->width = screen_width;
	if (cub->height > screen_height)
		cub->height = screen_height;
}
*/
static char	*file_to_string(int fd)
{
	char	*full_file;
	char	*line;

	line = NULL;
	full_file = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		full_file = strjoinfree(full_file, line);
		if (!full_file)
			return (NULL);
		full_file = strjoinfree(full_file, "\n");
		if (!full_file)
			return (NULL);
		ft_free(&line);
	}
	full_file = strjoinfree(full_file, line);
	if (!full_file)
		return (NULL);
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
	{
		ft_putendl_fd("Error\nFile .cub -> (Maybe doesn't exists)", 1);
		return (-1);
	}
	file = file_to_string(fd);
	if (!file)
	{
		ft_putendl_fd("Error\nWhile malloc the gnl in a string", 1);
		close(fd);
		return (-1);
	}
	close(fd);
	if (split_file(file, cub) == -1)
		return (-1);
	return (0);
}

static int	cmp_ext(const char *av)
{
	size_t	len;
	char	*ext;
	int		res_cmp;

	len = ft_strlen(av);
	ext = ft_substr(av, len - 4, len);
	if (!ext)
		return (-1);
	res_cmp = ft_strncmp(ext, ".cub", 4);
	ft_free(&ext);
	if (res_cmp)
		ft_putendl_fd("Error\nFile extension.", 1);
	return (res_cmp);
}

int	check_valid_cub(int ac, const char **av, t_cub *cub)
{
	if (ac == 2 || ac == 3)
	{
		if (cmp_ext(av[1]) || ((parse_file(av[1], cub)) == -1))
			return (-1);
		//resize_max_screen_size(cub);
		if (ac == 3)
		{
			if (ft_strncmp(av[2], "--save", 6) == 0)
				ft_putendl_fd("Your .cub file has been saved successfully", 1);
		}
	}
	else
	{
		ft_putendl_fd("Error\nWrong number of arguments", 1);
		return (-1);
	}
	return (0);
}
