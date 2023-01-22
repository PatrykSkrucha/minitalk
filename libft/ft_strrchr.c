/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:02:08 by pskrucha          #+#    #+#             */
/*   Updated: 2022/10/26 12:42:14 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	a;

	i = ft_strlen(str);
	a = c;
	while ((int)i >= 0)
	{
		if (str[i] == a)
			return ((char *) str + i);
		i--;
	}
	return (NULL);
}
