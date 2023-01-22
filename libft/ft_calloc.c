/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:47:28 by pskrucha          #+#    #+#             */
/*   Updated: 2022/10/26 10:59:56 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*a;

	if ((nelem == SIZE_MAX && elsize > 1) || (elsize == SIZE_MAX && nelem > 1))
		return (NULL);
	a = (void *)malloc(nelem * elsize);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, nelem * elsize);
	return (a);
}
