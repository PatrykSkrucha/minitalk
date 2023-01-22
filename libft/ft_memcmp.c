/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:14:35 by pskrucha          #+#    #+#             */
/*   Updated: 2022/10/26 11:01:59 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	unsigned const char	*s1;
	unsigned const char	*s2;

	i = 0;
	s1 = (unsigned const char *)str1;
	s2 = (unsigned const char *)str2;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] == s2[i] && i < n - 1)
	{
			i++;
	}
	return (s1[i] - s2[i]);
}
