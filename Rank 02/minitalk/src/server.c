#include "minitalk.h"

static void	mt_recieve(int signal)
{
	static int	c = 0;
	static int	bit = 0;
	static char	*str = 0;
	static int	i = 0;

	if (signal == SIGUSR2)
		c += ft_power(2, bit);
	if (bit == 7)
	{	
		bit = 0;
		if (c == 0)
			ft_printf("%s\n", str);
		c = 0;
		return ;
	}
	bit++;
}

int main(void)
{
	char				*pid;

	pid = ft_itoa(getpid());
	ft_printf("PID: %s\n", pid);
	signal(SIGUSR1, mt_recieve);
	signal(SIGUSR2, mt_recieve);
	while (1)
		usleep(100);
}
