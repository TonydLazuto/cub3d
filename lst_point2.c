#include "cub3d.h"

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

int			is_point_in_list(t_point *lstpoint, t_point *point)
{
	t_point *elet;

	elet = lstpoint;
	if (!lstpoint)
		return (0);
	while (elet)
	{
		if (point->x == elet->x && point->y == elet->y)
			return (1);
		elet = elet->next;
	}
	return (0);
}

void        print_points(t_point *point)
{
    static int i = 1;
    if (!point)
        return ;
    //printf("|%d|\n",i);
    i++;
    while (point)
    {
        printf("point->x = %d\npoint->y = %d\npoint->val = %c\n\n",
            point->x, point->y, point->val);
        point = point->next;
    }
}