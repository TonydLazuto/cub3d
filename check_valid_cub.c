#include "cub3d.h"
/*
int     check_line(char *line, t_cub *cub)
{
    unsigned int    i;
    
    i = 0;
    i = skip_space(i, line);
    if ((line[i] == 'R' || line[i] == 'F' || line[i] == 'C' || line[i] == 'S')
            && line[i + 1] == ' ')
    {
        if (check_rfcs(i, line, cub) == -1)
            return (-1);
    }
    else if (((line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'S' && line[i + 1] == 'O')
                || (line[i] == 'W' && line[i + 1] == 'E') || (line[i] == 'E' && line[i + 1] == 'A'))
                && line[i + 2] == ' ')
    {
        if (check_txt(i, line, cub) == -1)
            return (-1);
    }
    else
        return (-1);
    return (0);
}
*/

static char *free_space_front_line(char *line)
{
    unsigned int    i;
    char            *line_clean;

    i = 0;
    line_clean = NULL;
    i = skip_space(i, line);
    if (!line)
        return (NULL);
    if (i != 0)
    {
        if (!(line_clean = ft_substr(line, i, ft_strlen(line) - (size_t)i)))
            return (NULL);
    }
    else
    {
        if (!(line_clean = ft_strdup(line)))
            return (NULL);
    }
    ft_free(&line);
    return (line_clean);
}

static int  parse_line(int fd, t_cub *cub)
{
    char    *full_file;
    char	*line;
    char	*line_clean;

    cub->map = NULL;
    line = NULL;
    while (get_next_line(fd, &line) == 1)
	{
        if (!(line_clean = free_space_front_line(line)))
            return (-1);
        if (!(full_file = my_strjoin(full_file, line_clean)))
            return (-1);
        if (!(full_file = my_strjoin(full_file, "\n")))
            return (-1);
		ft_free(&line_clean);
	}
    if (!(line_clean = free_space_front_line(line)))
            return (-1);
    if (!(full_file = my_strjoin(full_file, line_clean)))
            return (-1);
    printf("%s\n", full_file);
    //printf("%d| %s\n", res, line);
	ft_free(&line_clean);
//    if (check_line(full_file, cub) == -1)
//        return (-1);
    return (0);
}

static int  parse_file(const char *file, t_cub *cub)
{
    int     fd;

    // check_if_file_exist()
    fd = open(file, O_RDONLY);
    if (parse_line(fd, cub) == -1)
    {
        close(fd);
        return (-1);
    }
    close(fd);
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

int         check_valid_cub(int ac, const char **av, t_cub *cub)
{
    if (ac == 2 || ac == 3)
    {
        if (cmp_ext(av[1])) // Y a t il un ordre dans le OU logique?
            return (-1);
        if ((parse_file(av[1], cub)) == -1)
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