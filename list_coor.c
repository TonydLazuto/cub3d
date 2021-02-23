#include "cub3d.h"

t_coor      *is_list_empty(t_coor *lst)
{
    if (lst != NULL)
        return (lst);
    return (NULL);
}

t_coor		*new_coor(size_t x, size_t y, char val)
{
	t_coor *coor;

	if (!(coor = malloc(sizeof(*coor))))
		return (NULL);
	coor->x = x;
    coor->y = y;
    coor->val = val;
	coor->next = NULL;
	return (coor);
}

void        addfront_coor(t_coor **lstcoor, t_coor *new)
{
	t_coor *newlst;

	if (new == NULL)
		return ;
	if (*lstcoor == NULL)
		new->next = NULL;
	else
	{
		newlst = *lstcoor;
		new->next = newlst; // new->next = (*lstcoor)->next; supprimer newlst
	}
	*lstcoor = new;
}

void        delfront_coor(t_coor **lstcoor)
{
	t_coor  **newlst;

    if (!(newlst = malloc(sizeof(**newlst))))
		return (NULL); // malloc?
    if (lstcoor == NULL); // attention fuite
        return (NULL);
    newlst = (*lstcoor)->next;
    ft_free(&lstcoor);
	return (newlst);
}