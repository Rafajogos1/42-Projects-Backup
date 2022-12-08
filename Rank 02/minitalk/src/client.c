#include "minitalk.h"

void	mt_send_char(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c <<= 1;
		bit++;
		pause();
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	char	*str;

	if (ac != 3)
		ft_printf("Please input the PID and a string.\n");
	else
	{
		i = 0;
		pid = ft_atoi(av[1]);
		str = av[2];
		while (str[i])
		{
			mt_send_char(str[i], pid);
			i++;
		}
		mt_send_char('\0', pid);
	}
}
