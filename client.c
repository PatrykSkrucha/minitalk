#include "libft/libft.h"
#include <signal.h>

void send_message(char *str, int pid)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while(str[++i])
	{
		while (++j < 8)
		{
			if (str[i] & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			str[i] >>= 1;
			usleep(77);
		}
		j = -1;
	}
}
//void send_char(int c, int pid)
//{
//	if (c > 1)
//	{
//		send_char(c/2, pid);
//		send_char(c%2, pid);
//	}
//	else
//	{
//		if(c == 1)
//			kill(pid, SIGUSR1);
//		else
//			kill(pid, SIGUSR2);
//		usleep(50);
//	}
//}

int main(int argc, char **argv)
{
	//(void)argc;
	//(void)argv;
	//int i = 254;
	//ft_printf("I przed: %i\n", i);
	////i >>= 2;
	////i == i >> 2;
	//if(i & 1)
	//	ft_printf("0");
	//i = i>>1;
	////i |= 1 << 4;
	////i == i | 1 >> 2;
	//ft_printf("I po: %i\n", i);
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
	if (argc < 3)
	{
		ft_printf("Too many arguments.");
		return (1);
	}
	send_message(argv[2], ft_atoi(argv[1]));
	return (0);
}
