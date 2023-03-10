/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:20:51 by pskrucha          #+#    #+#             */
/*   Updated: 2023/02/09 15:07:53 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Message delivered.");
		exit(0);
	}
}

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

int	main(int argc, char **argv)
{
	int					i;

	i = -1;
	if ((argc < 3 && ft_printf("Too few arguments"))
		|| (argc > 3 && ft_printf("Use apostrophes to submit a sentence.")))
		return (1);
	while (argv[1][++i])
	{
		if (argv[1][i] < 48 || argv[1][i] > 57 || argv[1][0] == '0')
		{
			ft_printf("Incorrect PID.");
			return (1);
		}
	}
	signal(SIGUSR1, signal_handler);
	send_message(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}
