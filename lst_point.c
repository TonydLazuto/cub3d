#include "cub3d.h"

int			is_empty_lst(t_point *point)
{
    if (point == NULL)
        return (1);
    return (0);
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

t_point		*addfront_point(t_point *list, t_point *elet)
{
	if (!elet)
		return (list);
	if (is_empty_lst(list))
		elet->next = NULL;
	else
		elet->next = list;
	return (elet);
}

void		popback_point(t_point **lst)
{
	t_point *before;
	t_point *tmp;

	tmp = *lst;
	before = *lst;
	if (!*lst)
		return ;
	if (!((*lst)->next))
	{
		free(*lst);
		*lst = NULL;
		return ;
	}
	while (tmp->next)
	{
		before = tmp;
		tmp = tmp->next;
	}
	before->next = NULL;
	free(tmp);
	tmp = NULL;
}
