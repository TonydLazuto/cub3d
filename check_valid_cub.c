#include "cub3d.h"

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
		ft_error(cub, "File .cub -> (Maybe doesn't exists)");
	file = file_to_string(fd);
	close(fd);
	if (!file)
		ft_error(cub, "While malloc the gnl in a string");
	if (split_file(file, cub) == -1)
		return (-1);
	ft_free(&file);
	return (0);
}

static int	cmp_ext(t_cub *cub, const char *av)
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
		ft_error(cub, "File extension.");
	return (res_cmp);
}

int	check_valid_cub(int ac, const char **av, t_cub *cub)
{
	if (ac == 2 || ac == 3)
	{
		if (cmp_ext(cub, av[1]) || ((parse_file(av[1], cub)) == -1))
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
