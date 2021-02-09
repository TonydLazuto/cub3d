/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderose <aderose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:16:56 by aderose           #+#    #+#             */
/*   Updated: 2020/09/08 21:13:15 by tonyd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*elmt;

	if (!lst || !f)
		return (NULL);
	if (!(elmt = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	first = elmt;
	while (lst)
	{
		if (!(elmt->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&first, del);
			return (first);
		}
		elmt = elmt->next;
		lst = lst->next;
	}
	elmt = NULL;
	return (first);
}
