#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig)
{
	static char a = 0;
	static int i = 0;
	if (sig == SIGUSR2)
		i++;
	if (sig == SIGUSR1)
	{
		a |= 1 << i;
		i++;
	}
	if (i == 8)
	{
		ft_printf("%c", a);
		a = 0;
		i = 0;
	}
}

int main()
{
	struct sigaction	st_sa;

	st_sa.sa_handler = signal_handler;
	st_sa.sa_flags = SA_RESTART;
	ft_printf("PID: %i", getpid());
	sigaction(SIGUSR1, &st_sa, NULL);
	sigaction(SIGUSR2, &st_sa, NULL);
	while(1)
	{
		pause();
	}
    return 0;
}