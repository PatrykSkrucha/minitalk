/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:49:16 by pskrucha          #+#    #+#             */
/*   Updated: 2022/10/11 14:49:16 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;
	size_t	i;

	src_ptr = (char *)src;
	dest_ptr = (char *)dest;
	i = 0;
	if (dest_ptr == NULL && src_ptr == NULL)
		return (0);
	if (src_ptr > dest_ptr)
	{
		while (i < n)
		{
			dest_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			dest_ptr[n] = src_ptr[n];
		}
	}
	return ((void *)dest_ptr);
}
