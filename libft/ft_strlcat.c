/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:17:46 by pskrucha          #+#    #+#             */
/*   Updated: 2022/10/26 11:03:04 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{	
	size_t		i;
	size_t		j;
	size_t		x;

	j = 0;
	i = 0;
	if (dst)
		i = ft_strlen(dst);
	x = i;
	if (dstsize <= i)
		return (ft_strlen(src) + dstsize);
	if (dstsize > i)
	{
		dstsize -= i;
		while (src[j] != '\0' && j < dstsize - 1)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
	}
	if (dstsize > j)
		return (ft_strlen(src) + x);
	return (ft_strlen(src) + ft_strlen(dst));
}
