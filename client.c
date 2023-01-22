#include "libft/libft.h"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		ft_printf("Too few arguments");
		return (1);
	}
	if (ft_atoi(argv[1]) < 0)
	{
		ft_printf("Incorrect PID.");
		return (1);
	}
	ft_printf("cos tu robie niby");
	return (0);
}