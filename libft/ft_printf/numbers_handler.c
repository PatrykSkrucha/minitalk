/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:27:07 by pskrucha          #+#    #+#             */
/*   Updated: 2022/11/07 13:04:18 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
	{
		counter += write(1, "-2147483648", 11);
		return (counter);
	}
	else if (n < 0)
	{
		counter += ft_putchar('-');
		counter += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		counter += ft_putnbr(n / 10);
		counter += ft_putnbr(n % 10);
	}
	else
		counter += ft_putchar(n + '0');
	return (counter);
}

int	print_unsigned(unsigned long int n)
{
	int		counter;

	counter = 0;
	if (n > 9)
	{
		counter += ft_putnbr(n / 10);
		counter += ft_putnbr(n % 10);
	}
	else
		counter += ft_putchar(n + '0');
	return (counter);
}

int	hex_handler(unsigned long int a, int control)
{
	int	counter;

	counter = 0;
	if (a >= 16)
	{
		counter += hex_handler(a / 16, control);
		counter += hex_handler(a % 16, control);
	}
	else if (a < 10)
		counter += ft_putchar(a + '0');
	else
	{
		if (control)
			counter += ft_putchar(a + '7');
		else
			counter += ft_putchar(a + 'W');
	}
	return (counter);
}
