/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonyd <aderose73@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:37:32 by tonyd             #+#    #+#             */
/*   Updated: 2021/04/29 16:37:33 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			is_empty_lst(t_point *point)
{
	if (point == NULL)
		return (1);
	return (0);
}

t_point		*new_point(int x, int y, char val)
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

void		push_back_point(t_point **list, t_point *elet)
{
	t_point	*tmp;

	tmp = *list;
	if (!elet)
		return ;
	if (!*list)
	{
		*list = elet;
		return ;
	}
	tmp = last_point(tmp);
	tmp->next = elet;
}

void		pop_front_point(t_point **lst)
{
	t_point *first;

	first = *lst;
	if (!*lst)
		return ;
	*lst = (*lst)->next;
	free(first);
	first = NULL;
}
