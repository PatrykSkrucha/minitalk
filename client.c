#include "libft/libft.h"
#include <signal.h>

static void send_message(char *str, int pid)
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
			usleep(10);
		}
		j = -1;
	}
	i = -1;
	while(++i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(10);
	}
}

//static void send_len(char *message, int pid)
//{
//	int	len;
//	int	i;

//	len = (int)ft_strlen(message);
//	ft_printf("len: %i", len);
//	i = -1;
//	while (++i < 8)
//	{
//		if (len & 1)
//			kill(pid, SIGUSR1);
//		else
//			kill(pid, SIGUSR2);
//		len >>= 1;
//		usleep(10);
//	}
//}

int main(int argc, char **argv)
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
		if (argv[1][i] < 48 || argv[1][i] > 57)
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
	//send_len(argv[2], ft_atoi(argv[1]));
	send_message(argv[2], ft_atoi(argv[1]));
	return (0);
}
