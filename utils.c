#include "cub3d.h"

int     	create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int			skip_space(char *line, unsigned int i)
{
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}

char		*trim_line(char *line)
{
    char			*line_clean;
	unsigned int	i;
	size_t			k;

	i = 0;
    line_clean = NULL;
    i = skip_space(line, 0);
	k = ft_strlen(line) - 1;
	while (k > 0 && (line[k] == ' ' || line[k] == '\t'))
		k--;
    if (!(line_clean = ft_substr(line, i, k + 1 - (size_t)i)))
        return (NULL);
	ft_free(&line);
    return (line_clean);
}

char		*strjoinfree(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		if (!(str = ft_strdup(s2)))
			return (NULL);
		return (str);
	}
	if (!(str = (char*)malloc(my_strlen(s1) + my_strlen(s2) + 1)))
	{
		ft_free(&s1);
		return (NULL);
	}
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(str) + ft_strlen(s2) + 1);
	ft_free(&s1);
	return (str);
}

/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		deal_key(int key, void *param)
{
	ft_putnbr_fd(key, 1);
	param = NULL;
	return (0);
}*/