#include "cub3d.h"

int     skip_space(char *line)
{
    int i;

    i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}

char	*free_space_front_line(char *line)
{
    unsigned int    i;
    char            *line_clean;

    i = 0;
    line_clean = NULL;
    if ((i = skip_space(line)) != 0)
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
