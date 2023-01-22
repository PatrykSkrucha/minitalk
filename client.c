#include "libft/libft.h"

int main(int argc, char **argv)
{
	int	i;
	i = -1;
	if (argc < 3)
	{
		ft_printf("Too few arguments");
		return (1);
	}
	while(argv[1][++i])
	{
		if (argv[1][i] < 48 || argv[1][i] > 57)
		{
			ft_printf("Incorrect PID.");
			return (1);
		}
	}
	ft_printf("%i", ft_atoi("a123a"));
	return (0);
}