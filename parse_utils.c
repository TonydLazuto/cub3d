#include "cub3d.h"

int     skip_space(int i, char *line)
{
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}