/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderose <aderose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:16:36 by aderose           #+#    #+#             */
/*   Updated: 2020/05/02 18:04:56 by aderose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *tmp;

	if (lst == NULL)
		return ;
	while (lst)
	{
		tmp = lst;
		f(tmp->content);
		lst = lst->next;
	}
}
