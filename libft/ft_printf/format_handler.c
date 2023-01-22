/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:33:06 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/07 13:00:10 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_handler(va_list args, int *result, const char *format, int *i)
{
	if (format[*i] == '%')
	{
		if (format[*i + 1] == 'i' || format[*i + 1] == 'd')
			*result += ft_putnbr(va_arg(args, int));
		else if (format[*i + 1] == 'c')
			*result += ft_putchar(va_arg(args, int));
		else if (format[*i + 1] == 's')
			*result += ft_putstr(va_arg(args, char *));
		else if (format[*i + 1] == 'x')
			*result += hex_handler(va_arg(args, unsigned int), 0);
		else if (format[*i + 1] == 'X')
			*result += hex_handler(va_arg(args, unsigned int), 1);
		else if (format[*i + 1] == '%')
			*result += ft_putchar('%');
		else if (format[*i + 1] == 'u')
			*result += print_unsigned(va_arg(args, unsigned int));
		else if (format[*i + 1] == 'p')
			*result += print_pointer(va_arg(args, unsigned long int));
		*i += 2;
	}
	else
	{
		*result += ft_putchar(format[*i]);
		(*i)++;
	}
}
