/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:15:11 by pskrucha          #+#    #+#             */
/*   Updated: 2022/10/30 12:13:24 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	a;
	int		i;

	i = 0;
	a = c;
	if (a == '\0')
	{
		while (*str)
		{
			str++;
		}
		return ((char *)str);
	}
	while (str[i] != '\0')
	{
		if (str[i] == a)
			return ((char *) str + i);
		i++;
	}
	return (NULL);
}
