#include "minitalk.h"

static void	mt_recieve_char(int sig, siginfo_t *info, void *context)
{
	static int	client_pid;
	static int	bit;
	static char	c;
	static int	current_pid;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (client_pid != current_pid)
	{
		client_pid = current_pid;
		bit = 0;
		c = 0;
	}
	c |= (sig == SIGUSR2);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
	}
	c <<= 1;
	usleep(100);
}

int main(void)
{
	char				*pid;
	struct sigaction	action;

	pid = ft_itoa(getpid());
	action.sa_sigaction = mt_recieve_char;
	action.sa_flags = SA_SIGINFO;
	ft_printf("PID: %s\n", pid);
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
		pause();
	return (0);
}
