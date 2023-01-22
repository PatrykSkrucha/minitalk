/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:45:03 by pskrucha          #+#    #+#             */
/*   Updated: 2022/10/09 14:45:03 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)str;
	if ((int)n < 1)
	{
		return (ptr);
	}
	while (i < (int)n)
	{
		ptr[i] = c;
		i++;
	}
	return ((void *)ptr);
}
