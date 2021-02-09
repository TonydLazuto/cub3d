/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderose <aderose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:17:10 by aderose           #+#    #+#             */
/*   Updated: 2020/05/02 18:06:27 by aderose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void *content)
{
	t_list *lst;

	if (!(lst = (t_list*)malloc(sizeof(*lst))))
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
