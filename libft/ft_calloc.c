/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderose <aderose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:10:56 by aderose           #+#    #+#             */
/*   Updated: 2020/05/15 10:01:07 by aderose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		*ptr;

	if (!(ptr = malloc(size * count)))
		return (NULL);
	ft_bzero(ptr, count * size);
	return ((void*)ptr);
}
