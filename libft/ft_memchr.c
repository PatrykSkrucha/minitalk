/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:49:45 by pskrucha          #+#    #+#             */
/*   Updated: 2022/10/30 12:00:26 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t		i;
	char		*ptr;
	char		a;

	ptr = (char *)str;
	i = 0;
	a = c;
	while (i < n)
	{
		if (ptr[i] == a)
			return ((void *) ptr + i);
		i++;
	}
	return (NULL);
}
