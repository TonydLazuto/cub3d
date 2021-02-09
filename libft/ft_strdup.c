/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderose <aderose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:28:50 by aderose           #+#    #+#             */
/*   Updated: 2020/05/02 18:26:59 by aderose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1)))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
