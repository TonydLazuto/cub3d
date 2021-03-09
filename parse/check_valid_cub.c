#include "../cub3d.h"

static char *file_to_string(int fd)
{
    char    *full_file;
    char	*line;

    line = NULL;
    full_file = NULL;
    while (get_next_line(fd, &line) == 1)
	{
        if (!(full_file = strjoinfree(full_file, line)))
            return (NULL);
        if (!(full_file = strjoinfree(full_file, "\n")))
            return (NULL);
		ft_free(&line);
	}
    if (!(full_file = strjoinfree(full_file, line)))
        return (NULL);
    ft_free(&line);
    return (full_file);
}

static int  parse_file(const char *map_file, t_cub *cub, t_ptr ptr)
{
    int     fd;
    char    *file;

    file = NULL;
    if ((fd = open(map_file, O_RDONLY)) == -1)
    {
        ft_putendl_fd("Error\nFile .cub -> (Maybe doesn't exists)", 1);
        return (-1);
    }
    if (!(file = file_to_string(fd)))
    {
        ft_putendl_fd("Error\nWhile malloc the gnl in a string", 1);
        close(fd);
        return (-1);
    }
    close(fd);
    if (split_params_map(file, cub, ptr) == -1)
        return (-1);
    return (0);
}

static int  cmp_ext(const char *av)
{
    size_t  len;
    char    *ext;
    int     res_cmp;

    len = ft_strlen(av);
    if (!(ext = ft_substr(av, len - 4, len)))
        return (-1);
    res_cmp = ft_strncmp(ext, ".cub", 4);
    ft_free(&ext);
    if (res_cmp)
        ft_putendl_fd("Error\nFile extension.", 1);
    return (res_cmp);
}

int         check_valid_cub(int ac, const char **av, t_cub *cub, t_ptr ptr)
{
    if (ac == 2 || ac == 3)
    {
        if (cmp_ext(av[1]) || ((parse_file(av[1], cub, ptr)) == -1))
            return (-1);
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