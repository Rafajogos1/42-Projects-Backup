#include "minitalk.h"

static void	mt_send_len(int len, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 32)
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		bit++;
		usleep(100);
	}
}

static void	mt_send_char(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		bit++;
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
		if (pid <= 0)
			return (-1);
		mt_send_len(ft_strlen(str), pid);
		while (str[i])
		{
			mt_send_char(str[i], pid);
			i++;
		}
		mt_send_char(str[i], pid);
	}
}
