/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:37:30 by pskrucha          #+#    #+#             */
/*   Updated: 2022/10/25 18:42:41 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s1, char c)
{
	int	i;
	int	counter;
	int	check;

	check = 0;
	counter = 0;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
		{
			check = 1;
		}
		if ((s1[i] != c && check) || (!check && i == 0))
		{
			counter++;
			check = 0;
		}
		i++;
	}
	return (counter);
}

static int	count_position(char const *s1, char c, int i, int control)
{
	while (s1[i])
	{
		if (control)
		{
			if (s1[i] != c)
				return (i);
		}
		else
		{
			if (s1[i] == c)
				return (i);
		}
			i++;
	}
	if (!control)
		return (ft_strlen(s1));
	return (0);
}

static void	clearall(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

static int	fill_string(int words, char const *s, char c, char **str)
{
	int	start;
	int	end;
	int	i;

	i = 0;
	start = 0;
	end = 0;
	while (i < words)
	{
		start = count_position(s, c, end, 1);
		end = count_position(s, c, start, 0);
		str[i] = ft_substr(s, start, end - start);
		if (!str[i])
		{
			clearall(str, i);
			return (0);
		}
		i++;
	}
	str[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	str = (char **) malloc((words + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	if (!fill_string(words, s, c, str))
		return (NULL);
	return (str);
}
