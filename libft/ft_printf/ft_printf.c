/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:41:01 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/07 13:04:09 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		result;
	int		len;
	va_list	args;

	if (!format)
		return (0);
	len = 0;
	i = 0;
	result = 0;
	va_start(args, format);
	while (format[len])
		len++;
	while (i < len)
		format_handler(args, &result, format, &i);
	va_end(args);
	return (result);
}
