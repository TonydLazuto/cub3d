#include "cub3d.h"

void        del_point(t_point *point)
{
    free(point);
	point->x = 0;
	point->y = 0;	
	point->val = 0;
	point->next = NULL;
}

t_point		*lastpoint(t_point *point)
{
	if (point == NULL)
		return (NULL);
	while (point->next)
		point = point->next;
	return (point);
}

void        clear_points(t_point **point)
{
    t_point *tmp;

    tmp = NULL;
	if (*point == NULL)
		return ;
	while (*point)
	{
        if ((*point)->next)
		    tmp = (*point)->next;
        del_point((*point));
		*point = tmp;
		free(tmp);
	}
	tmp = NULL;
    *point = NULL;
}

int			is_same_point_in(t_point **lstpoint, t_point *point)
{
	if (!*lstpoint || !point)
		return (-1);
	while ((*lstpoint))
	{
		if ((point->x == (*lstpoint)->x) && (point->y == (*lstpoint)->y))
			return (1);
		*lstpoint = (*lstpoint)->next;
	}
	if ((point->x == (*lstpoint)->x) && (point->y == (*lstpoint)->y))
		return (1);
	return (0);
}