#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

char	*message;

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

static	void	*create_message(char a)
{

	if (a == -1)
	{
		ft_printf("%s\n", message);
		free(message);
		message = NULL;
	}
	else if (!message)
	{
		message = malloc(2);
		if (!message)
			return (NULL);
		message[0] = a;
		message[1] = '\0';
	}
	else
		message = next_char(message, a);
	return (NULL);
}

static	void	signal_handler(int sig)
{
	static char	a = 0;
	static int	i = 0;

	if (sig == SIGUSR1)
	{
		a |= 1 << i;
		i++;
	}
	if (sig == SIGUSR2)
		i++;
	if (i == 8)
	{
		create_message(a);
		a = 0;
		i = 0;
	}
}

int main(void)
{

	struct sigaction	st_sa;

	st_sa.sa_handler = signal_handler;
	st_sa.sa_flags = SA_RESTART;
	ft_printf("PID: %i\n", getpid());
	sigaction(SIGUSR1, &st_sa, NULL);
	sigaction(SIGUSR2, &st_sa, NULL);
	while (1)
	{
		pause();
	}
	if(message)
		free(message);
	return (0);
}
