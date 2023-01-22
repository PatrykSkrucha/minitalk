/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:40:07 by pskrucha          #+#    #+#             */
/*   Updated: 2022/10/30 12:22:02 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	move_pointer(char const *s1, char const *set, int index)
{
	int	i;

	i = 0;
	while (s1[index] && set[i])
	{
		if (s1[index] == set[i])
		{
			i = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (move_pointer(s1, set, start))
	{
		start++;
	}
	while (move_pointer(s1, set, end))
	{
		end--;
	}
	if (start >= end + 1)
		return (ft_strdup(""));
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
