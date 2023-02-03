/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:20:42 by pskrucha          #+#    #+#             */
/*   Updated: 2023/02/02 15:55:00 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

char	*g_message;

char	*next_char(char *old_message, char a)
{
	char	*new_message;
	int		i;
	size_t	len;

	len = ft_strlen(old_message);
	i = -1;
	new_message = malloc(len + 2);
	if (!new_message)
	{
		free(old_message);
		old_message = NULL;
		return (NULL);
	}
	while (old_message[++i])
		new_message[i] = old_message[i];
	new_message[i] = a;
	new_message[++i] = '\0';
	free(old_message);
	old_message = NULL;
	return (new_message);
}

static	void	*message_handler(char a, __pid_t client_pid)
{
	if (a == -1) //dopisac tu handler na zwrot sygnalu
	{
		ft_printf("%s\n", g_message);
		free(g_message);
		kill(client_pid, SIGUSR1);
		g_message = NULL;
	}
	else if (!g_message)
	{
		g_message = malloc(2);
		if (!g_message)
			return (NULL);
		g_message[0] = a;
		g_message[1] = '\0';
	}
	else
		g_message = next_char(g_message, a);
	return (NULL);
}

static	void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static __pid_t	client_pid = 0;
	static char	a = 0;
	static int	i = 0;
	(void)context;
	if (info->si_pid)
		client_pid = info->si_pid;
	if (sig == SIGUSR1)
	{
		a |= 1 << i;
		i++;
	}
	if (sig == SIGUSR2)
		i++;
	if (i == 8)
	{
		message_handler(a, client_pid);
		a = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	st_sa;

	st_sa.sa_sigaction = signal_handler;
	st_sa.sa_flags = SA_RESTART;
	ft_printf("PID: %i\n", getpid());
	sigaction(SIGUSR1, &st_sa, NULL);
	sigaction(SIGUSR2, &st_sa, NULL);
	while (1)
	{
		pause();
	}
	if (g_message)
	{
		free(g_message);
		g_message = NULL;
	}
	return (0);
}

