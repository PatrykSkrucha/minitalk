/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:34:53 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/07 13:04:13 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	counter;

	counter = 0;
	counter += write(1, &c, 1);
	return (counter);
}

int	ft_putstr(char *s)
{
	int	counter;

	counter = 0;
	if (s == NULL)
	{
		counter += write(1, "(null)", 6);
		return (counter);
	}
	while (s[counter])
		counter++;
	if (s)
		write(1, s, counter);
	return (counter);
}

int	print_pointer(unsigned long int number)
{
	int		counter;

	counter = 0;
	counter += write(1, "0x", 2);
	counter += hex_handler(number, 0);
	return (counter);
}
