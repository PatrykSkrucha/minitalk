/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:51:23 by pskrucha          #+#    #+#             */
/*   Updated: 2022/10/26 11:13:23 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_size(int n)
{
	int	i;

	i = 0;
	if (n > 0)
	{
		while (n >= 1)
		{
			n /= 10;
			i++;
		}
	}
	else
	{
		i++;
		while (n <= -1)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}

static void	create_string(int n, int sign, char *str, int s)
{
	if (n < 0)
	{
		n *= -1;
		sign++;
	}
	while (n >= 1)
	{	
		s--;
		str[s] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
	{
		s--;
		str[s] = '-';
	}
}

char	*ft_itoa(int n)
{
	int		s;
	char	*str;
	int		sign;

	if (n == 0)
		return (ft_strdup("0"));
	s = str_size(n) + 1;
	str = (char *) malloc((s));
	if (str == NULL)
		return (NULL);
	sign = 0;
	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	s--;
	str[s] = '\0';
	create_string(n, sign, str, s);
	return (str);
}
