#include "../cub3d.h"

t_point		*last_point(t_point *point)
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
		pop_front_point(&newlst);
	*lst = newlst;
}

int			is_point_in_list(t_point *lstpoint, t_point *point) // try_push_point
{
	t_point *elet;

	elet = lstpoint;
	if (!lstpoint)
		return (0);
	while (elet)
	{
		if (point->x == elet->x && point->y == elet->y)
		{
			/*printf("|-----Visited-----|\n");
			print_points(lstpoint);
			printf("|||||-----Mon-Point-----|||||\npoint->x : %zu\npoint->y : %zu\npoint->val : %c\n", point->x, point->y, point->val);*/
			return (1);
		}
		elet = elet->next;
	}
	return (0);
}