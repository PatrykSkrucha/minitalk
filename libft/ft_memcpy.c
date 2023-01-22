/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:19:11 by pskrucha          #+#    #+#             */
/*   Updated: 2022/10/30 12:00:47 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	char		*dest;
	char		*src;

	dest = (char *)destination;
	src = (char *)source;
	if (dest == NULL && src == NULL)
		return (0);
	while (num)
	{
		num--;
		dest[num] = src[num];
	}
	return (dest);
}
