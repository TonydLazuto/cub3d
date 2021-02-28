#include "cub3d.h"

t_point		*is_point(t_point *point)
{
    if (point == NULL)
        return (NULL);
    return (point);
}

t_point		*new_point(size_t x, size_t y, char val)
{
	t_point *point;

	if (!(point = malloc(sizeof(*point))))
		return (NULL);
	point->x = x;
    point->y = y;
    point->val = val;
	point->next = NULL;
	return (point);
}

void		addfront_point(t_point **lstpoint, t_point *new)
{
	if (new == NULL)
		return ;
	if (*lstpoint == NULL)
		new->next = NULL;
	else
		new->next = (*lstpoint)->next;
	*lstpoint = new;
}

void		delback_point(t_point *lst)
{
	if (lst == NULL)
		return ;
	if (!(lastpoint(lst)))
		return ;
	del_point(lst);
}
