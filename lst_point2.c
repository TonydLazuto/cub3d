#include "cub3d.h"

t_point		*lastpoint(t_point *point)
{
	if (point == NULL)
		return (NULL);
	while (point->next)
		point = point->next;
	return (point);
}

void		clear_points(t_point **lst)
{
	t_point *newlst;

	newlst = *lst;
	if (is_empty_lst(*lst))
		return ;
	while (newlst)
		popback_point(&newlst);
	*lst = newlst;
}

int			is_point_in_list(t_point **lstpoint, t_point *point)
{
	t_point *elet;

	elet = *lstpoint;
	if (!*lstpoint || !point)
		return (-1);
	while (elet)
	{
		if (point->x == elet->x && point->y == elet->y)
			return (1);
		elet = elet->next;
	}
	return (0);
}