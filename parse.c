#include "cub3d.h"
/*
int		parse_line(t_ptr ptr, char *line)
{
	size_t	i;
    int     color;

	i = 0;
	if (line[i] == '\n')
		return (-1);
	while (line[i])
	{
		if (line[i] == '0')
			draw(ptr, i, create_trgb(0, 255, 255, 255));
		else if (line[i] == '1')
			draw(ptr, i, create_trgb(0, 0, 255, 0));
		else if (line[i] == '2')
			draw(ptr, i, create_trgb(0, 0, 0, 255));
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			draw(ptr, i, create_trgb(0, 255, 0, 0));
        else
            return (-1);
		i++;
	}
	return (0);
}

int     parse_file(t_ptr ptr)
{
	int		fd;
	char	*line;

	fd = open("./map1.cub", O_RDONLY);
    //if (parse_data == -1)
    //    return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		if (parse_line(ptr, line) == -1)
            return (-1);
		free(line);
	}
	get_next_line(fd, &line);
    if (parse_line(img, line) == -1)
        return (-1);
	free(line);

	close(fd);
    return (0);
}*/