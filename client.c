/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:20:51 by pskrucha          #+#    #+#             */
/*   Updated: 2023/02/02 15:54:57 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static	void	send_message(char *str, int pid)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (str[++i])
	{
		while (++j < 8)
		{
			if (str[i] & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			str[i] >>= 1;
			usleep(80);
		}
		j = -1;
	}
	i = -1;
	while (++i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(80);
	}
}

//zaimplementowac handler z servera
int	main(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc < 3)
	{
		ft_printf("Too few arguments");
		return (1);
	}
	while (argv[1][++i])
	{
		if (argv[1][i] < 48 || argv[1][i] > 57) //spr na longa i spr -1 z killa co zwraca
		{
			ft_printf("Incorrect PID.");
			return (1);
		}
	}
	if (argc > 3)
	{
		ft_printf("Too many arguments. Use quotes to send a sentence");
		return (1);
	}
	send_message(argv[2], ft_atoi(argv[1]));
	return (0);
}
