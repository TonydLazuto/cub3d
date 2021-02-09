/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderose <aderose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:15:39 by aderose           #+#    #+#             */
/*   Updated: 2020/05/08 15:23:10 by aderose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list *lst;

	if (new == NULL)
		return ;
	if (*alst == NULL)
		new->next = NULL;
	else
	{
		lst = *alst;
		new->next = lst;
	}
	*alst = new;
}
